#ifndef LEXER_H
#define LEXER_H

/************************************************************
* INCLUDES
************************************************************/
#include <stdlib.h>

/************************************************************
* STRUCTURES
************************************************************/
typedef struct Lexer
{
    char     *input;       // The input we want to break down into tokens
    char     currentChar;  // Current character being analyzed
    size_t   position;     // Current position in input(position of the current character)
    size_t   readPosition; // Current reading position(position after the current character)
}Lexer;

/************************************************************
* FUNCTIONS
************************************************************/
Lexer  newLexer(char *);
void   readChar(Lexer *);
char*  readDigits(Lexer *, char *);
char*  readIdentifier(Lexer *, char *);

#endif //LEXER_H
