/************************************************************
* INCLUDES
************************************************************/
#include "statement_tests.h"
#include <stdio.h>
#include <string.h>
#include "../core/lexer.h"
#include "../core/parser.h"

/************************************************************
* FUNCTIONS
************************************************************/
void testSetStatements()
{
    char input[] =
        "set x = 1;"
        "set y = 2;"
        "set z = 123";

    Lexer  lexer  = newLexer(input);
    Parser parser = newParser(&lexer);

    astProgram program = parseProgram(&parser);

    char tests[] =
        "x"
        "y"
        "z";
    for (size_t i = 0; i < 3; ++i)
    {
        astStatement statement = program.statements[i];
        if (strcmp(statement.token.literal,"set") != 0)
        {
            fprintf(stderr, "Expected 'set', got '%s'\n", statement.token.literal);
        }
    }

}
