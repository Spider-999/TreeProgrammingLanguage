/************************************************************
* INCLUDES
************************************************************/
#include "utilities.h"
#include <ctype.h>

/************************************************************
* FUNCTIONS
************************************************************/

int isLetter(const char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_';
}

int isDigit(const char d)
{
    return (d >= '0' && d <= '9');
}

void eatWhitespace(Lexer *lexer)
{
    while (isspace(lexer->currentChar))
    {
        readChar(lexer);
    }
}