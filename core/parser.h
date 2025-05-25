#ifndef PARSER_H
#define PARSER_H
/************************************************************
* INCLUDES
************************************************************/
#include "ast.h"
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
Parser       newParser(Lexer *);
void         nextParserToken(Parser *);
size_t       countNumberOfStatements(Parser *);
int          expectedTokenType(Parser *, TokenType);
astProgram   newParseProgram();
astProgram   parseProgram(Parser *);
astStatement *parseStatement(Parser *, astStatement *);
astStatement *parseSetStatement(Parser *, astStatement *);
void          freeProgramMemory(astProgram *);


#endif //PARSER_H
