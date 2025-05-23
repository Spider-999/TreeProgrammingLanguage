/************************************************************
* INCLUDES
************************************************************/
#include "token.h"

#include <stdio.h>
#include <string.h>

/************************************************************
* FUNCTIONS
************************************************************/
Token getTokenFromLexer(Lexer *lexer)
{
    Token token;
    char character = lexer->currentChar;
    char literal[2] = {character, '\0'};

    switch (character)
    {
        case '=':
            token = createToken(ASSIGN_TOK, literal);
            break;
        case '+':
            token = createToken(PLUS_TOK, literal);
            break;
        case ',':
            token = createToken(COMMA_TOK, literal);
            break;
        case ';':
            token = createToken(SEMICOLON_TOK, literal);
            break;
        case '(':
            token = createToken(LEFT_PARENTHESIS_TOK, literal);
            break;
        case ')':
            token = createToken(RIGHT_PARENTHESIS_TOK, literal);
            break;
        case '{':
            token = createToken(LEFT_BRACKET_TOK, literal);
            break;
        case '}':
            token = createToken(RIGHT_BRACKET_TOK, literal);
            break;
        case '\0':
            token = createToken(EOF_TOK, literal);
            break;
        default:
            token = createToken(ILLEGAL_TOK, literal);
            break;
    }

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