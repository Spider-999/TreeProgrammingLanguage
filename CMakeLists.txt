cmake_minimum_required(VERSION 3.31)
project(TreeProgrammingLanguage C)

set(CMAKE_C_STANDARD 11)

add_executable(TreeProgrammingLanguage main.c
        core/token.h
        core/lexer.c
        core/lexer.h
        core/token.c
        tests/lexer_tests.c
        tests/lexer_tests.h
        core/utilities.c
        core/utilities.h
        core/repl.c
        core/repl.h
        core/ast.c
        core/ast.h
        core/parser.c
        core/parser.h
        tests/statement_tests.c
        tests/statement_tests.h)
