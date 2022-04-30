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

        if (c == EOF){
            break;
        }

        else if (c == '+'){
            makeToken("+", 0);
        }

        else if (c == '-'){
            makeToken("-", 0);
        }

        else if (c == '*'){
            makeToken("*", 0);
        }

        else if (c == '/'){
            makeToken("/", 0);
        }

        else if (c == '('){
            makeToken("(", 0);
        }

        else if (c == ')'){
            makeToken(")", 0);
        }

        else if (c == ':')
        {
            c = fgetc(file); //pega o proximo caractere

            if (c == '=') //se for '=' sabemos que é o token ':='
                makeToken(":=", 0);
        }

        else if (c == '<')
        {
            c = fgetc(file); //pega o proximo caractere

            if (c == '=') //se for '=' sabemos que é o token '<='
                makeToken("<=", 0);

        else
            makeToken("<", 0);
        }

        else if (c == '>')
        {
            c = fgetc(file);

            if (c == '=')
                makeToken(">=", 0);
            
            else 
                makeToken(">", 0);
        }

        else if (c == '='){
            makeToken("=", 0);
        }

        else if (isdigit(c)){
            numero();
        }

        else if (isalpha(c)){
            palavra();
        }

        else if (c == ' ' || c == '\t'){
            continue;
        }
        
        else if (c == '\n')
        {
            linha++;
            continue;
        }

        else
        {
            printf("Caracter '%c' na linha %d não reconhecido.\n", c, linha);
            exit(EXIT_FAILURE);
        }
    }
}

void palavra()
{
    char palavra[100] = "";
    int pos = 0;

    while (isalnum(c))
    {
        palavra[pos++] = c;
        c = fgetc(file);
    }

voltaPonteiro();

if(strcmp(palavra, "INIT") == 0)
    makeToken("INIT", 0);

else if(strcmp(palavra, "PRINT") == 0)
    makeToken("PRINT", 0);

else if(strcmp(palavra, "INPUT") == 0)
    makeToken("INPUT", 0);

else if(strcmp(palavra, "VAR") == 0)
    makeToken("VAR", 0);

else if(strcmp(palavra, "IF") == 0)
    makeToken("IF", 0);

else if(strcmp(palavra, "ELSE") == 0)
    makeToken("ELSE", 0);

else if(strcmp(palavra, "END") == 0)
    makeToken("END", 0);

else
    makeToken("ID", 0);
}

void numero()
{
    int k = 0;
    while(isdigit(c))
    {
        k = k * 10 + c - '0';
        c = fgetc(file);
    }

voltaPonteiro();

makeToken("T_INIT", k);
}