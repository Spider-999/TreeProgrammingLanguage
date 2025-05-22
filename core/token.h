#ifndef TOKEN_H
#define TOKEN_H

/************************************************************
* ENUMS
************************************************************/
typedef enum TokenType
{
    ILLEGAL,    // Reserved for unknown tokens.
    EOF,        // Reserved for end-of-file, tells the parser it can stop parsing.
    // Identifiers and literals
    IDENTIFIER,
    INT,
    // Operators
    ASSIGN,
    PLUS,
    // Delimiters
    COMMA,
    SEMICOLON,
    LEFT_PARENTHESIS,
    RIGHT_PARENTHESIS,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    // Keywords
    FUNCTION,
    LET
} TokenType;

/************************************************************
* STRUCTURES
************************************************************/
typedef struct Token
{
    TokenType type; // Holds the type of the token
    char *literal;  // The literal is the value this token might hold
} Token;

#endif //TOKEN_H
