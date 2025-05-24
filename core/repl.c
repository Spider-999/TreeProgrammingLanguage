/************************************************************
* INCLUDES
************************************************************/
#include "repl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "token.h"

/************************************************************
* FUNCTIONS
************************************************************/
void runInteractiveMode()
{
    char input[128];
    Lexer lexer;
    while (1)
    {
        fprintf(stdout, "[tree-lang]$");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            exit(0);
        }

        if (strcmp(input , "exit\n") == 0)
        {
            exit(0);
        }

        input[strlen(input) - 1] = '\0';

        lexer = newLexer(input);

        for (Token token = getTokenFromLexer(&lexer); token.type != EOF_TOK; token = getTokenFromLexer(&lexer))
        {
            const char *tokenTypeString = tokenTypeToString(token.type);
            fprintf(stdout, "[TYPE: \'%s\' , LITERAL: \'%s\']\n",tokenTypeString, token.literal);
        }
    }
}