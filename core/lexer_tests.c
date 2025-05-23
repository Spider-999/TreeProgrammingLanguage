/************************************************************
* INCLUDES
************************************************************/
#include "lexer_tests.h"
#include <stdio.h>
#include <string.h>

void TestNextToken()
{
    char input[] = "=+,;(){}";
    Lexer lexer = newLexer(input);

    size_t testSize = sizeof(testTokens) / sizeof(testTokens[0]);

    for (int i = 0; i < testSize; i++)
    {
        Token token = getTokenFromLexer(&lexer);
        const char *tokenTypeStr = tokenTypeToString(token.type);
        const char *expectedTokenTypeStr = tokenTypeToString(testTokens[i].expectedTokenType);

        if (token.type != testTokens[i].expectedTokenType)
        {
            fprintf(stderr, "Expected type \'%s\', got \'%s\'\n", expectedTokenTypeStr, tokenTypeStr);
        }

        if (strcmp(token.literal, testTokens[i].expectedLiteral) != 0)
        {
            fprintf(stderr, "Expected literal \'%s\', got \'%s\'\n", testTokens[i].expectedLiteral, token.literal);
        }
    }
}
