#include <stdlib.h>

#include "lex.h"
#include "global.h"

int main (int arc, char *argv[])
{
    //abrir o arquivo
    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    proximo_token();

    fclose(file);
    return EXIT_SUCCESS;
}