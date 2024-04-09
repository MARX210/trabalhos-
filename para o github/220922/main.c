#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>


/*
DESVIO DE FLUXO
SWITCH_CASE.
    SINTAXE:
     switch(<variavel>){
        case?:
         <bloco de comandos>
         break;
         *
         *
         *
         case 'N':
            <bloco de comandos>
            break;
            defaut:
                <bloco de comandos>
     }
*/

int main()
{
    setlocale(LC_ALL, "");
    int op;
    float n1, n2;
    float resut;

    printf("DIGITE UM NUMERO: ");
    scanf("%f", &n1);
    printf("DIGITE UM NUMERO: ");
    scanf("%f", &n2);

    printf("< 1 > ADIÇÃO\n");
    printf("< 2 > SUBTRAÇÃO\n");
    printf("< 3 > MULTIPLICAÇÃO\n");
    printf("< 4 > DIVISÃO\n");
    printf("INFORME SUA OPÇÃO: ");
    scanf("%s", &op);

    switch(op){
    case 1:
        resut = n1+n2;
        printf("o resultado da adição é: %.0f", resut);
        break;
    case 2:
        resut = n1-n2;
        printf("o resultado da subtração é: %.0f", resut);
        break;
    case 3:
        resut = n1*n2;
        printf("o resultado da multiplicação é: %.2f", resut);
        break;
    case 4:
        resut = n1/n2;
        printf("o resultado da divisão é: %.2f", resut);
        break;
    default:
        printf("\t\t\t\t\tERRO!!! INFORME 1, 2, 3 OU 4!\t\t\t");

    }

    return 0;
}
