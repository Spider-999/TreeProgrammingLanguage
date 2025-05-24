#ifndef UTILITIES_H
#define UTILITIES_H
/************************************************************
* INCLUDES
************************************************************/
#include "lexer.h"

/************************************************************
* FUNCTIONS
************************************************************/
int isLetter(char);
int isDigit(char);
void eatWhitespace(Lexer*);

#endif //UTILITIES_H
