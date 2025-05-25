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

    for (size_t i = 0; i < 3 ; ++i)
    {
        astStatement statement = program.statements[i];
        if (strcmp(statement.token.literal,"set") != 0)
        {
            fprintf(stderr, "Expected 'set', got '%s'\n", statement.token.literal);
        }

        if (strcmp(statement.name.value,setTest[i].expectedIdentifier) != 0)
        {
            fprintf(stderr, "Expected '%s', got '%s'\n", setTest[i].expectedIdentifier, statement.name.value);
        }

        if (strcmp(statement.name.token.literal,setTest[i].expectedIdentifier) != 0)
        {
            fprintf(stderr, "Expected '%s', got '%s'\n", setTest[i].expectedIdentifier, statement.name.token.literal);
        }

        /*
        fprintf(stdout, "statement.name.value:%s\n", statement.name.value);
        fprintf(stdout, "statement.name.token.literal:%s\n", statement.name.token.literal);
        fprintf(stdout, "statement.name.token.type:%d\n", statement.name.token.type);
        fprintf(stdout, "statement.token.literal:%s\n", statement.token.literal);
        fprintf(stdout, "statement.token.type:%d\n", statement.token.type);
        */
    }

    freeProgramMemory(&program);
}
