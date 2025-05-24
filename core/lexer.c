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

/************************************************************
* DESCRIPTION:
* This function reads all the letters in an identifier
* and then reallocates memory for it and returns it to
* make a new token.
************************************************************/
char *readIdentifier(Lexer *lexer, char *identifier)
{
    size_t identifierSize = 0;
    size_t startPosition = lexer->position;

    while (isLetter(lexer->currentChar) || isDigit(lexer->currentChar))
    {
        identifierSize++;
        readChar(lexer);
    }

    if (identifierSize > MAX_IDENTIFIER_SIZE)
    {
        fprintf(stderr, "[MEMORY ERROR] You cant have identifiers bigger than 32 characters!\n");
        exit(1);
    }

    identifier = realloc(identifier,sizeof(char) * identifierSize);
    if (identifier == NULL)
    {
        fprintf(stderr, "[MEMORY ERROR] Could not reallocate memory for identifier\n");
        exit(1);
    }

    strncpy(identifier, lexer->input + startPosition, identifierSize);
    identifier[identifierSize] = '\0';

    return identifier;
}