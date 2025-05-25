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
    char *input =
        "set x = 1;"
        "set    y = 2;"
        "set z = 123";

    Lexer  lexer  = newLexer(input);
    Parser parser = newParser(&lexer);

    astProgram *program = parseProgram(&parser);

    if (program == NULL)
    {
        fprintf(stderr, "[PARSER ERROR] Parsing the program failed!\n");
        exit(1);
    }
    /*
    for (size_t i = 0; i < 3; ++i)
    {
        astStatement statement = program->statements[i];

        if (strcmp(statement.token.literal, "set") != 0)
        {
            fprintf(stderr, "[PARSER ERROR] Wrong statement, expected '%s' got '%s'\n", "set", statement.token.literal);
            exit(1);
        }

        fprintf(stdout, "[STATEMENT] Statement %d:%s\n", i,statement.name->value);

    }
    */
}
