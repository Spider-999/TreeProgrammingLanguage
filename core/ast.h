#ifndef AST_H
#define AST_H
#include "token.h"

/*
 * The AST(abstract syntax tree) implemented here consists of nodes
 * connected to each other. Some nodes implement the statements, while
 * other nodes implement the expression.
 */

/************************************************************
* STRUCTURES
************************************************************/
typedef struct astNode
{
    char *tokenLiteral;
}astNode;

typedef struct astStatement
{
    astNode node;
}astStatement;

typedef struct astExpression
{
    astNode node;
}astExpression;

/*
 * Every program is a series of statements. These
 * statements are nodes in the AST.
 */
typedef struct astProgram
{
    astStatement  *statements;
    size_t        numberOfStatements;
}astProgram;

/************************************************************
* FUNCTIONS
************************************************************/



#endif //AST_H
