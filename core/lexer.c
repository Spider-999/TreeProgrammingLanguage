/************************************************************
* INCLUDES
************************************************************/
#include "lexer.h"
#include <stdio.h>
#include <string.h>

#include "token.h"
#include "utilities.h"

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
        lexer->currentChar = '\0';
    else
        lexer->currentChar = lexer->input[lexer->readPosition];

    lexer->position = lexer->readPosition;
    lexer->readPosition++;
}

char *readIdentifier(Lexer *lexer)
{
    size_t identifierSize = 0;
    size_t startPosition = lexer->position;
    char *identifier = NULL;

    while (isLetter(lexer->currentChar))
    {
        identifierSize++;
        readChar(lexer);
    }

    identifier = (char*)malloc(sizeof(char) * identifierSize + 1);
    if (identifier == NULL)
    {
        fprintf(stderr, "Error: Could not allocate memory for identifier\n");
        exit(1);
    }

    strncpy(identifier, lexer->input + startPosition, identifierSize);
    identifier[identifierSize] = '\0';

    return identifier;
}