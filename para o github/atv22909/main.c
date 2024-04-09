#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

/*

ATIVIDADE 2
SIMULAÇÃO DE JUROS COMPOSTO

*/

int main()
{
    setlocale(LC_ALL, "");

    float val, m;
    int op;

    printf(" INFORME O VALOR QUE DESEJA APLICAR: ");
    scanf("%f",&val);

    printf("\n\t\t\t MESES \t\t\t\n");
    printf(" < 1 > 12 meses\n");
    printf(" < 2 > 24 meses\n");
    printf(" < 3 > 36 meses\n");
    printf(" qual sua escolha? ");
    scanf("%d", &op);

    switch(op){

    case 1:
        m = val*pow((1+0.15),1);
        printf("o resultado é: %.2f\n",m);

        break;

    case 2:
        m = val*pow((1+0.25),2);
        printf("o resultado é: %.2f\n",m);

        break;

    case 3:
        m = val*pow((1+0.3),3);
        printf("o resultado é: %.2f",m);

         break;

    default:
        printf("ERRO!!! INFORME 1,2 OU 3\n");

        break;

    }
}
