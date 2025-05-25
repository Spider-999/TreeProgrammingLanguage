#ifndef TOKEN_H
#define TOKEN_H
/************************************************************
* INCLUDES
************************************************************/
#include "ast.h"
#include "lexer.h"

/************************************************************
* ENUMS
************************************************************/
typedef enum TokenType
{
    NOT_ALLOWED_TOK,    // Reserved for unknown tokens.
    EOF_TOK,            // Reserved for end-of-file, tells the parser it can stop parsing.
    // Identifiers and literals
    IDENTIFIER_TOK,
    INTEGER_TOK,
    // Operators
    ASSIGN_TOK,
    PLUS_TOK,
    MINUS_TOK,
    NOT_TOK,
    MULTIPLY_TOK,
    DIVIDE_TOK,
    LESS_THAN_TOK,
    GREATER_THAN_TOK,
    // Delimiters
    COMMA_TOK,
    SEMICOLON_TOK,
    LEFT_PARENTHESIS_TOK,
    RIGHT_PARENTHESIS_TOK,
    LEFT_BRACKET_TOK,
    RIGHT_BRACKET_TOK,
    // LOGIC
    EQUAL_TOK,
    NOT_EQUAL_TOK,
    // Keywords
    BLOCK_TOK,
    SET_TOK,
    TRUE_TOK,
    FALSE_TOK,
    IF_TOK,
    ELSE_TOK,
    RETURN_TOK
} TokenType;

/************************************************************
* STRUCTURES
************************************************************/
typedef struct Token
{
    TokenType type; // Holds the type of the token
    char  *literal; // The literal is the value this token might hold
} Token;

typedef struct KeywordsMap
{
    char      *identifier;
    TokenType type;
} KeywordsMap;

typedef struct Identifier
{
    Token  token;
    char*  value;
}Identifier;

typedef struct setStatement
{
    Token         token;
    Identifier    *name;
    astExpression value;
}setStatement;

/************************************************************
* DEFINES
************************************************************/
#define MAX_IDENTIFIER_SIZE 32

/************************************************************
* VARIABLES
************************************************************/
static const char *tokenStrings[] =
{
    "NOT ALLOWED",
    "EOF",
    "IDENTIFIER",
    "INTEGER",
    "EQUAL",
    "PLUS",
    "MINUS",
    "NOT",
    "MULTIPLY",
    "DIVIDE",
    "LESS THAN",
    "GREATER THAN",
    "COMMA",
    "SEMICOLON",
    "LEFT PARENTHESIS",
    "RIGHT PARENTHESIS",
    "LEFT BRACKET",
    "RIGHT BRACKET",
    "EQUALS",
    "NOT EQUALS",
    "BLOCK",
    "SET"
};

static const KeywordsMap keywordsMap[] =
{
    {"block", BLOCK_TOK},
    {"set"  , SET_TOK},
    {"true" , TRUE_TOK},
    {"false", FALSE_TOK},
    {"if"   , IF_TOK},
    {"else" , ELSE_TOK},
    {"return",RETURN_TOK}
};

/************************************************************
* FUNCTIONS
************************************************************/
Token       getTokenFromLexer(Lexer* );
Token       createToken(TokenType , char *);
const char *tokenTypeToString(TokenType);
TokenType   getKeywordFromIdentifier(const char *);

#endif //TOKEN_H
