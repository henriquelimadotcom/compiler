#include <string.h>
#include <ctype.h>

#include "global.h"
#include "lex.h"

//variável que passará por cada caractere do arquivo
static int c;

void proximo_token()
{
    while (1)
    {
        c = fgetc(file);

        if (c == EOF)
            break;
        
        else
            printf("%c", c);
    }
}