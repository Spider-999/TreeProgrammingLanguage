#ifndef PARSER_H
#define PARSER_H
/************************************************************
* INCLUDES
************************************************************/
#include "lexer.h"
#include "token.h"

/************************************************************
* STRUCTURES
************************************************************/
typedef struct Parser
{
    Lexer *lexer;
    Token currentToken;
    Token peekToken;
} Parser;

/************************************************************
* FUNCTIONS
************************************************************/
Parser      newParser(Lexer *);
void        updateParserTokens(Parser *);
astProgram  *parseProgram(Parser *);


#endif //PARSER_H
