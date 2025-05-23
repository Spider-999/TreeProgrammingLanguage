#ifndef TOKEN_H
#define TOKEN_H
/************************************************************
* INCLUDES
************************************************************/
#include "lexer.h"

/************************************************************
* ENUMS
************************************************************/
typedef enum TokenType
{
    ILLEGAL_TOK,    // Reserved for unknown tokens.
    EOF_TOK,        // Reserved for end-of-file, tells the parser it can stop parsing.
    // Identifiers and literals
    IDENTIFIER_TOK,
    INTEGER_TOK,
    // Operators
    ASSIGN_TOK,
    PLUS_TOK,
    // Delimiters
    COMMA_TOK,
    SEMICOLON_TOK,
    LEFT_PARENTHESIS_TOK,
    RIGHT_PARENTHESIS_TOK,
    LEFT_BRACKET_TOK,
    RIGHT_BRACKET_TOK,
    // Keywords
    FUNCTION_TOK,
    LET_TOK
} TokenType;

/************************************************************
* STRUCTURES
************************************************************/
typedef struct Token
{
    TokenType type; // Holds the type of the token
    char  *literal; // The literal is the value this token might hold
} Token;

/************************************************************
* DEFINES
************************************************************/
#define MAX_IDENTIFIER_SIZE 32

/************************************************************
* VARIABLES
************************************************************/
static const char *tokenStrings[] =
{
    "ILLEGAL",
    "EOF",
    "IDENTIFIER",
    "INTEGER",
    "=",
    "+",
    ",",
    ";",
    "(",
    ")",
    "{",
    "}"
};

/************************************************************
* FUNCTIONS
************************************************************/
Token       getTokenFromLexer(Lexer* );
Token       createToken(TokenType , char *);
const char *tokenTypeToString(TokenType);

#endif //TOKEN_H
