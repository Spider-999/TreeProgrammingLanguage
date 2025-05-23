/************************************************************
* INCLUDES
************************************************************/
#include "token.h"

#include <ctype.h>
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
    char character;

    // If the lexer's currentChar pointers is on a
    // whitespace, traverse until we find chars that aren't whitespaces.
    while (isspace(lexer->currentChar))
    {
        readChar(lexer);
    }

    character = lexer->currentChar;

    // For simple literals we need only 2 bytes, one for the character and one for the
    // null terminator
    token.literal = (char*)malloc(sizeof(char) * 2);
    if (token.literal == NULL)
    {
        fprintf(stderr, "[MEMORY ERROR] Token literal memory allocation failed!\n");
        exit(1);
    }

    switch (character)
    {
        case '=':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(ASSIGN_TOK, token.literal);
            break;
        case '+':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(PLUS_TOK, token.literal);
            break;
        case ',':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(COMMA_TOK, token.literal);
            break;
        case ';':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(SEMICOLON_TOK, token.literal);
            break;
        case '(':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(LEFT_PARENTHESIS_TOK, token.literal);
            break;
        case ')':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(RIGHT_PARENTHESIS_TOK, token.literal);
            break;
        case '{':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(LEFT_BRACKET_TOK, token.literal);
            break;
        case '}':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(RIGHT_BRACKET_TOK, token.literal);
            break;
        case '\0':
            token.literal[0] = '\0';
            token = createToken(EOF_TOK, token.literal);
            break;
        default:
            if (isLetter(character))
            {
                token.literal = readIdentifier(lexer, token.literal);
                token = createToken(IDENTIFIER_TOK, token.literal);
            }
            else
            {
                token.literal[0] = character;
                token.literal[1] = '\0';
                token = createToken(ILLEGAL_TOK, token.literal);
            }
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