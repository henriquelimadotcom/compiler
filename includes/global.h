#ifndef art_global_h
#define art_global_h

#include <stdio.h>
#include <stdlib.h>

FILE *file;

//linha atual
static int linha = 1;

//tipos de tokens
enum {
    //palavras chave
    PC_INIT, PC_END, PC_INPUT, PC_VAR, PC_IF, PC_ELSE,

    //numeros
    T_INIT,

    //operadores
    OP_MAIS, OP_MENOS, OP_MULT, OP_DIV,

    //( ) := < > <= >= =
    T_LPARENT, T_RPARENT, T_ATRIB, T_MENOR, T_MAIOR, T_MENOR_I,
    T_MAIOR_I, T_IGUAL,

    //identificador
    ID

};

typedef struct {
    int tipo;
    int val;
} Token;

Token tok;

#endif
