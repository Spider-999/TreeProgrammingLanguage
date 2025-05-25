#ifndef AST_H
#define AST_H
/************************************************************
* INCLUDES
************************************************************/
#include "token.h"

/*
 * The AST(abstract syntax tree) implemented here consists of nodes
 * connected to each other. Some nodes implement the statements, while
 * other nodes implement the expression.
 */
/************************************************************
* STRUCTURES
************************************************************/
typedef struct Identifier
{
    Token  token;
    char  value[100];
}Identifier;

typedef struct astExpression
{
    Token token;
}astExpression;

typedef struct astStatement
{
    Token         token;
    Identifier    name;
    astExpression value;
}astStatement;

/*
 * Every program is a series of statements. These
 * statements are nodes in the AST.
 */
typedef struct astProgram
{
    astStatement  statements[1000];
    size_t        numberOfStatements;
}astProgram;


/************************************************************
* FUNCTIONS
************************************************************/



#endif //AST_H
