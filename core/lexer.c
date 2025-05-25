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
    lexer.currentChar = '\0';
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
* This function returns the next character after the current
* character.
************************************************************/
char peekChar(Lexer *lexer)
{
    if (lexer->readPosition >= strlen(lexer->input))
        return '\0';

    return lexer->input[lexer->readPosition];
}

/************************************************************
* DESCRIPTION:
* This function reads all the letters in an identifier
* and then reallocates memory for it and returns it to
* make a new token.
************************************************************/
char *readIdentifier(Lexer *lexer, char *identifier)
{
    size_t identifierSize = 1;
    size_t startPosition = lexer->position;

    /*
     * I found that it is better to check if the peek character is
     * a digit or letter because if we check the current char and
     * read it, then at the end of the function we have to rewind
     * the last readChar function call to not jump over a character.
     * That is because after reading the identifier, in getTokenFromLexer
     * we call readChar() at the end of the switch, thus we would lose
     * a character in the process.
     */
    while (isLetter(peekChar(lexer)) || isDigit(peekChar(lexer)))
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
        fprintf(stderr, "[MEMORY ERROR] Could not reallocate memory for identifier!\n");
        exit(1);
    }

    strncpy(identifier, lexer->input + startPosition, identifierSize);
    identifier[identifierSize] = '\0';

    return identifier;
}