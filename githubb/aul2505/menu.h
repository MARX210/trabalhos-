#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "bibliotecas.h"

void menu(){
    struct LISTASIMPLES* Pri =NULL;
    struct LISTASIMPLES* Ult =NULL;
    int op;
    do{
        system("cls");
        printf("\t\t\t\t MENU LISTA SIMPLES \t\t\t\n");
        printf(" <1> INSERIR\n");
        printf(" <2> REMOVER\n");
        printf(" <3> MOSTRAR\n");
        printf(" <4> LOCALIZAR\n");
        printf(" <5> SAIR\n");
        printf(" INFORME SUA OPÇÃO: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            f_inserir(&Pri, &Ult);
            break;
        case 2:
            f_remover(&Pri, &Ult);
            break;
        case 3:
            f_apresentar(&Pri, &Ult);
            break;
        case 4:
            F_localizar(&Pri, &Ult);
            break;
        case 5:
            printf("TCHAU!!! SAINDO\n");

        default:
            printf("ERRO!!! INFORME 1,2,3,4 OU 5\n");
        }

    }while(op != 5);
}

#endif // MENU_H_INCLUDED
