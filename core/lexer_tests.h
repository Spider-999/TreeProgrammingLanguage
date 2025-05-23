#ifndef LEXER_TESTS_H
#define LEXER_TESTS_H
/************************************************************
* INCLUDES
************************************************************/
#include "token.h"

/************************************************************
* STRUCTURES
************************************************************/
typedef struct TestTokens
{
    TokenType expectedTokenType;
    char      *expectedLiteral;
}TestTokens;

/************************************************************
* VARIABLES
************************************************************/
static TestTokens testTokens[] =
{
    {ASSIGN_TOK           , "="},
    {PLUS_TOK             , "+"},
    {COMMA_TOK            , ","},
    {SEMICOLON_TOK        , ";"},
    {LEFT_PARENTHESIS_TOK , "("},
    {RIGHT_PARENTHESIS_TOK, ")"},
    {LEFT_BRACKET_TOK     , "{"},
    {RIGHT_BRACKET_TOK    , "}"},
};

/************************************************************
* FUNCTIONS
************************************************************/
void TestNextToken();

#endif //LEXER_TESTS_H
