cmake_minimum_required(VERSION 3.31)
project(TreeProgrammingLanguage C)

set(CMAKE_C_STANDARD 11)

add_executable(TreeProgrammingLanguage main.c
        core/token.h
        core/lexer.c
        core/lexer.h
        core/token.c
        core/lexer_tests.c
        core/lexer_tests.h)
