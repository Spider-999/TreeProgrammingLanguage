/************************************************************
* INCLUDES
************************************************************/
#include "parser.h"
#include <stdio.h>

/************************************************************
* FUNCTIONS
************************************************************/
Parser newParser(Lexer *lexer)
{
    Parser parser = { .lexer = lexer };

    updateParserTokens(&parser);

    return parser;
}

void updateParserTokens(Parser *parser)
{
    parser->currentToken = parser->peekToken;
    parser->peekToken = getTokenFromLexer(parser->lexer);
}

/************************************************************
* DESCRIPTION: Count the number of statements in order
* to know how much memory to allocate for the program's
* statements array.
************************************************************/
size_t countNumberOfStatements(Parser *parser)
{
    size_t count = 0;
    // TODO: Fix this function
    while (parser->currentToken.type != EOF_TOK)
    {
        updateParserTokens(parser);
        count++;
    }
    return count;
}

int expectedTokenType(Parser *parser, TokenType type)
{
    if (parser->peekToken.type != type)
        return 0;

    updateParserTokens(parser);
    return 1;
}

/************************************************************
* DESCRIPTION: Create a new parse program.
************************************************************/
astProgram *newParseProgram(size_t numberOfStatements)
{
    astProgram *program = (astProgram *)malloc(sizeof(astProgram));
    program->numberOfStatements = numberOfStatements;
    program->statements = (astStatement*)malloc(sizeof(astStatement) * numberOfStatements);

    if(program->statements == NULL)
    {
        fprintf(stderr,"[MEMORY ERROR] Couldn't allocate memory for the AST program\n");
        exit(1);
    }
    return program;
}

astProgram *parseProgram(Parser *parser)
{
    size_t numberOfStatements = countNumberOfStatements(parser);
    size_t i = 0;
    astProgram *program = newParseProgram(numberOfStatements);

    while (parser->currentToken.type != EOF_TOK)
    {
        astStatement *statement = parseStatement(parser);
        if (statement != NULL)
        {
            program->statements[i++] = *statement;
            fprintf(stdout, "statement %i: %s\n", i, statement[i].name->value);
        }
        updateParserTokens(parser);
    }

    return program;
}

astStatement *parseStatement(Parser *parser)
{
    astStatement *statement;
    switch (parser->currentToken.type)
    {
        case SET_TOK:
            statement = parseSetStatement(parser);
            break;
        default:
            statement = NULL;
            break;
    }

    return statement;
}

astStatement *parseSetStatement(Parser *parser)
{
    astStatement *setStatement = malloc(sizeof(astStatement));
    if (setStatement == NULL)
    {
        fprintf(stderr, "[MEMORY ERROR] Failed to allocated memory for set statement\n");
        exit(1);
    }
    setStatement->token = parser->currentToken;

    if (!expectedTokenType(parser, IDENTIFIER_TOK))
        return NULL;

    Identifier *name = (Identifier*)malloc(sizeof(Identifier));
    if (name == NULL)
    {
        fprintf(stderr, "[MEMORY ERROR] Failed to allocated memory for identifier in set statement\n");
        exit(1);
    }
    name->token = parser->currentToken;
    name->value = parser->currentToken.literal;
    setStatement->name = name;

    if (!expectedTokenType(parser, ASSIGN_TOK))
        return NULL;

    while (parser->currentToken.type != SEMICOLON_TOK)
        updateParserTokens(parser);

    return setStatement;
}

