#include <string.h>
#include <ctype.h>

#include "global.h"
#include "lex.h"

//variável que passará por cada caractere do arquivo
static int c;

void makeToken(char *nome, int val) //mostrar o token
{
    printf("<%s, %d>", nome, val);
}

void voltaPonteiro() // volta um caracter se necessário
{
    if(c != EOF)
        fseek(file, ftell(file)-1, SEEK_SET);
}

void proximo_token()
{
    while (1)
    {
        c = fgetc(file);

        if (c == EOF)
            break;
        
        else if (c == ' ' || c == '\t')
            continue;
        
        else if (c == '\n')
        {
            linha++;
            continue;
        }
    }
}
