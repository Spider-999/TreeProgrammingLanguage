#ifndef STATEMENT_TESTS_H
#define STATEMENT_TESTS_H
/************************************************************
* STRUCTS
************************************************************/
typedef struct setStatementTests
{
    char *expectedIdentifier;
}setStatementTests;

/************************************************************
* VARIABLES
************************************************************/
static setStatementTests setTest[] =
{
    {"x"},
    {"y"},
    {"z"}
};
/************************************************************
* FUNCTIONS
************************************************************/
void testSetStatements();

#endif //STATEMENT_TESTS_H
