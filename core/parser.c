/************************************************************
* INCLUDES
************************************************************/
#include "parser.h"

/************************************************************
* FUNCTIONS
************************************************************/
void updateParserTokens(Parser *parser)
{
    parser->currentToken = parser->peekToken;
    parser->peekToken = getTokenFromLexer(parser->lexer);
}

Parser newParser(Lexer *lexer)
{
    Parser parser = { .lexer = lexer };

    updateParserTokens(&parser);

    return parser;
}

astProgram *parseProgram()
{
    return NULL;
}

