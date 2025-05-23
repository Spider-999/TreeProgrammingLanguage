/************************************************************
* INCLUDES
************************************************************/
#include "token.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utilities.h"

/************************************************************
* FUNCTIONS
************************************************************/
Token getTokenFromLexer(Lexer *lexer)
{
    Token token;
    char character = lexer->currentChar;
    char *literal = "";
    size_t literalSize = 1;

    while (lexer->currentChar == ' ')
    {
        literalSize++;
    }

    literal = (char*)malloc(sizeof(char) * literalSize);
    if (literal == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(1);
    }
    literal[0] = character;
    literal[1] = '\0';

    token.literal = strdup(literal);
    switch (character)
    {
        case '=':
            token = createToken(ASSIGN_TOK, token.literal);
            break;
        case '+':
            token = createToken(PLUS_TOK, token.literal);
            break;
        case ',':
            token = createToken(COMMA_TOK, token.literal);
            break;
        case ';':
            token = createToken(SEMICOLON_TOK, token.literal);
            break;
        case '(':
            token = createToken(LEFT_PARENTHESIS_TOK, token.literal);
            break;
        case ')':
            token = createToken(RIGHT_PARENTHESIS_TOK, token.literal);
            break;
        case '{':
            token = createToken(LEFT_BRACKET_TOK, token.literal);
            break;
        case '}':
            token = createToken(RIGHT_BRACKET_TOK, token.literal);
            break;
        case '\0':
            token = createToken(EOF_TOK, '\0');
            break;
        default:
            if (isLetter(character))
            {
                literal = readIdentifier(lexer);
                token.literal = strdup(literal);
                token = createToken(IDENTIFIER_TOK, token.literal);
            }
            else
            {
                token = createToken(ILLEGAL_TOK, token.literal);
            }
            break;
    }

    free(literal);
    readChar(lexer);
    return token;
}

Token createToken(const TokenType tokenType, char *literal)
{
    const Token token = {tokenType, literal};
    return token;
}

const char* tokenTypeToString(TokenType tokenType)
{
    return tokenStrings[tokenType];
}