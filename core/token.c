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

/************************************************************
* DESCRIPTION:
* This function creates tokens out of the given input.
************************************************************/
Token getTokenFromLexer(Lexer *lexer)
{
    Token token;
    char character = '\0';

    // If the lexer's currentChar pointers is on a
    // whitespace, tab, carriage return or end line
    // traverse until we find chars that aren't whitespaces.
    eatWhitespace(lexer);

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
            if (peekChar(lexer) == '=')
            {
                token.literal = realloc(token.literal, sizeof(char) * 3);
                if (token.literal == NULL)
                {
                    fprintf(stderr, "[MEMORY ERROR] Token literal memory allocation failed!\n");
                    exit(1);
                }

                token.literal[0] = '=';
                token.literal[1] = '=';
                token.literal[2] = '\0';
                readChar(lexer);
                token = createToken(EQUAL_TOK, token.literal);
            }
            else
            {
                token.literal[0] = character;
                token.literal[1] = '\0';
                token = createToken(ASSIGN_TOK, token.literal);
            }
            break;
        case '+':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(PLUS_TOK, token.literal);
            break;
        case '-':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(MINUS_TOK, token.literal);
            break;
        case '!':
            if (peekChar(lexer) == '=')
            {
                token.literal = realloc(token.literal, sizeof(char) * 3);
                if (token.literal == NULL)
                {
                    fprintf(stderr, "[MEMORY ERROR] Token literal memory allocation failed!\n");
                    exit(1);
                }

                token.literal[0] = '!';
                token.literal[1] = '=';
                token.literal[2] = '\0';
                readChar(lexer);
                token = createToken(NOT_EQUAL_TOK, token.literal);
            }
            else
            {
                token.literal[0] = character;
                token.literal[1] = '\0';
                token = createToken(NOT_TOK, token.literal);
            }
            break;
        case '*':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(MULTIPLY_TOK, token.literal);
            break;
        case '/':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(DIVIDE_TOK, token.literal);
            break;
        case '<':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(LESS_THAN_TOK, token.literal);
            break;
        case '>':
            token.literal[0] = character;
            token.literal[1] = '\0';
            token = createToken(GREATER_THAN_TOK, token.literal);
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
                token.type = getKeywordFromIdentifier(token.literal);
            }
            else if (isDigit(character))
            {
                token.literal = readIdentifier(lexer, token.literal);
                token.type = INTEGER_TOK;
            }
            else
            {
                token.literal[0] = character;
                token.literal[1] = '\0';
                token = createToken(NOT_ALLOWED_TOK, token.literal);
            }
            break;
    }

    readChar(lexer);

    return token;
}

/************************************************************
* DESCRIPTION:
* Creates a new token from the given literal and token type.
************************************************************/
Token createToken(const TokenType tokenType, char *literal)
{
    const Token token = {tokenType, literal};
    return token;
}

/************************************************************
* DESCRIPTION:
* Maps the token type to the corresponding string, this is
* used for debugging.
************************************************************/
const char* tokenTypeToString(const TokenType tokenType)
{
    return tokenStrings[tokenType];
}

/************************************************************
* DESCRIPTION:
* This function determines if an identifier that has been
* read is a keyword and returns the appropriate type, otherwise
* it just returns an IDENTIFIER_TOK type.
************************************************************/
TokenType getKeywordFromIdentifier(const char *identifier)
{
    const size_t keywordsSize = sizeof(keywordsMap) / sizeof(keywordsMap[0]);
    for (size_t i = 0; i < keywordsSize; i++)
    {
        if (strcmp(identifier, keywordsMap[i].identifier) == 0)
            return keywordsMap[i].type;
    }
    return IDENTIFIER_TOK;
}