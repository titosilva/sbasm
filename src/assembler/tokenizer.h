#pragma once

typedef enum {
    LABEL = 1,
    INSTRUCTION = 2,
    ARGUMENT = 3,
    COMMENT = 4,
    DIRECTIVE = 5,
} TokenTypes;

typedef struct {
    TokenTypes type;
    char* content;
} Token;

typedef struct {
    Token* tokens;
    char* error; // Lexical and syntactic errors
} TokenizedLine;

typedef struct {
    TokenizedLine* lines;
} TokenizedProgram;

TokenizedProgram tokenize(const char* program);

