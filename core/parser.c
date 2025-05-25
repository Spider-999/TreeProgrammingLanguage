/************************************************************
* INCLUDES
************************************************************/
#include "parser.h"
#include <stdio.h>
#include <string.h>

/************************************************************
* FUNCTIONS
************************************************************/
Parser newParser(Lexer *lexer)
{
    Parser parser = {.lexer = lexer};
    nextParserToken(&parser);
    nextParserToken(&parser);

    return parser;
}

void nextParserToken(Parser *parser)
{
    parser->currentToken = parser->peekToken;

    if (parser->currentToken.type != EOF_TOK)
        parser->peekToken = getTokenFromLexer(parser->lexer);
}

int expectedTokenType(Parser *parser, TokenType type)
{
    if (parser->peekToken.type == type)
    {
        nextParserToken(parser);
        return 1;
    }

    return 0;
}

/************************************************************
* DESCRIPTION: Create a new parse program.
************************************************************/
astProgram newParseProgram()
{

}

astProgram parseProgram(Parser *parser)
{
    size_t i = 0;
    astProgram program;
    program.statements = NULL;

    while (parser->currentToken.type != EOF_TOK)
    {
        astStatement statement;
        parseStatement(parser, &statement);
        program.statements = (astStatement *)realloc(program.statements,sizeof(astStatement) * (i + 1));

        if (program.statements == NULL)
        {
            fprintf(stderr, "[MEMORY ERROR] Failed to reallocate memory for statements\n");
            exit(1);
        }
        program.statements[i++] = statement;
        nextParserToken(parser);
    }

    return program;
}

astStatement *parseStatement(Parser *parser, astStatement *statement)
{
    switch (parser->currentToken.type)
    {
        case SET_TOK:
            return parseSetStatement(parser, statement);
        default:
            return NULL;
    }
}

astStatement *parseSetStatement(Parser *parser, astStatement *statement)
{
    statement->token = parser->currentToken;
    if (!expectedTokenType(parser, IDENTIFIER_TOK))
        return NULL;

    Identifier identifier = {.token=parser->currentToken};
    identifier.value = parser->currentToken.literal;
    statement->name = identifier;

    if (!expectedTokenType(parser, ASSIGN_TOK))
        return NULL;

    while (parser->currentToken.type != SEMICOLON_TOK && parser->currentToken.type != EOF_TOK)
        nextParserToken(parser);

    return statement;
}

void freeProgramMemory(astProgram *program)
{
    free(program->statements);
}


