/************************************************************
* INCLUDES
************************************************************/
#include "statement_tests.h"

#include <stdio.h>

#include "../core/lexer.h"
#include "../core/parser.h"

/************************************************************
* FUNCTIONS
************************************************************/
void testSetStatements()
{
    char *input =
        "set x = 1;"
        "set y = 2;"
        "set z = 123";

    Lexer  lexer  = newLexer(input);
    Parser parser = newParser(&lexer);

    astProgram *program = parseProgram(&parser);

    if (program == NULL)
    {
        fprintf(stderr, "[PARSER ERROR] Parsing the program failed!\n");
    }
}
