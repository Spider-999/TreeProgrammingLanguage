#ifndef LEXER_TESTS_H
#define LEXER_TESTS_H
/************************************************************
* INCLUDES
************************************************************/
#include "../core/token.h"

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
    {SET_TOK              ,  "set"},
    {IDENTIFIER_TOK       ,  "number1"},
    {ASSIGN_TOK           ,  "="},
    {INTEGER_TOK       ,  "5"},
    {SEMICOLON_TOK ,  ";"},
    {SET_TOK,  "set"},
    {IDENTIFIER_TOK       ,  "number2"},
    {ASSIGN_TOK           ,  "="},
    {INTEGER_TOK       ,  "6"},
    {SEMICOLON_TOK ,  ";"},
    {BLOCK_TOK ,  "block"},
    {LEFT_PARENTHESIS_TOK ,  "("},
    {IDENTIFIER_TOK ,  "x"},
    {COMMA_TOK ,  ","},
    {IDENTIFIER_TOK ,  "y"},
    {RIGHT_PARENTHESIS_TOK ,  ")"},
    {LEFT_BRACKET_TOK ,  "{"},
    {IDENTIFIER_TOK ,  "x"},
    {MULTIPLY_TOK ,  "*"},
    {IDENTIFIER_TOK ,  "y"},
    {SEMICOLON_TOK ,  ";"},
    {RIGHT_BRACKET_TOK ,  "}"},
    {SEMICOLON_TOK ,  ";"},
    {IF_TOK ,  "if"},
    {LEFT_PARENTHESIS_TOK ,  "("},
    {IDENTIFIER_TOK       ,  "number1"},
    {GREATER_THAN_TOK       ,  ">"},
    {IDENTIFIER_TOK       ,  "number2"},
    {RIGHT_PARENTHESIS_TOK ,  ")"},
    {RETURN_TOK ,  "return"},
    {TRUE_TOK ,  "true"},
    {SEMICOLON_TOK ,  ";"},
    {ELSE_TOK ,  "else"},
    {RETURN_TOK ,  "return"},
    {FALSE_TOK ,  "false"},
    {SEMICOLON_TOK ,  ";"},
    {IDENTIFIER_TOK       ,  "number1"},
    {EQUAL_TOK           ,  "=="},
    {IDENTIFIER_TOK       ,  "number2"},
    {SEMICOLON_TOK ,  ";"},
    {IDENTIFIER_TOK       ,  "number1"},
    {NOT_EQUAL_TOK       ,  "!="},
    {IDENTIFIER_TOK       ,  "number2"},
    {SEMICOLON_TOK ,  ";"},
    {EOF_TOK ,  ""}
};

/************************************************************
* FUNCTIONS
************************************************************/
void testNextToken();

#endif //LEXER_TESTS_H
