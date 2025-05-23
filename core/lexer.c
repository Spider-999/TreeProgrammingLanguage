/************************************************************
* INCLUDES
************************************************************/
#include "lexer.h"
#include <stdio.h>
#include <string.h>

/************************************************************
* FUNCTIONS
************************************************************/

/************************************************************
* DESCRIPTION:
* This function updates the lexer.
************************************************************/
Lexer newLexer(char *input)
{
    Lexer lexer;
    lexer.input = input;
    lexer.readPosition = 0;
    lexer.position = 0;
    lexer.currentChar = "";
    readChar(&lexer);
    return lexer;
}

/************************************************************
* DESCRIPTION:
* This function gives the next character in the
* input string and advances the positions to the next
* characters.
************************************************************/
void readChar(Lexer *lexer)
{
    if (lexer->readPosition >= strlen(lexer->input))
        lexer->currentChar = "";
    else
        lexer->currentChar = lexer->input[lexer->readPosition];

    lexer->position = lexer->readPosition;
    lexer->readPosition++;
}