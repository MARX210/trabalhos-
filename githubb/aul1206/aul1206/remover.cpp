#include "bibliotecas.h"

void remover(struct LISTADUPLA** Ini, struct LISTADUPLA** Fim) {
    struct LISTADUPLA* AuxRemove = NULL;
    struct LISTADUPLA* Localiza = NULL;
    int cod, pos;
    printf("Deseja iniciar por qual extremindade (1 - Inicio, 2 - Fim): ");
    scanf_s("%d", &pos);
    printf("Informe o Codigo: ");
    scanf_s("%d", &cod);
    if (pos == 1) {
        Localiza = *Ini;
    }
    else {
        Localiza = *Fim;
    }
    /*Vai Localizar a chave, trazendo o Endereço do Nó que será removido*/
    localizar(&Localiza, pos, cod, &AuxRemove);
    if (AuxRemove != NULL) {
        printf("O Dado da Posicao: %p, Codigo: %d foi removido\n", AuxRemove, AuxRemove->chave);
        if (*Ini == *Fim) {
            AuxRemove = NULL;
            *Ini = *Fim = NULL;
            free(AuxRemove);
        }
        else {
            if (AuxRemove == *Ini) {
                *Ini = AuxRemove->prox;
                (*Ini)->ant = NULL;
                AuxRemove = NULL;
                free(AuxRemove);
            }
            else {
                if (AuxRemove == *Fim) {
                    *Fim = AuxRemove->ant;
                    (*Fim)->prox = NULL;
                    AuxRemove = NULL;
                    free(AuxRemove);
                }
                else {
                    //Criando os ponteiros apenas para ajudar na remoção de um Nó que fica entre 2 outros Nós.
                    struct LISTADUPLA* AuxAnt, * AuxProx;
                    AuxAnt = AuxRemove->ant;
                    AuxProx = AuxRemove->prox;
                    AuxAnt->prox =AuxProx;
                    AuxProx->ant = AuxAnt;
                    AuxRemove = NULL;
                    free(AuxRemove);
                }
            }
        }
    }
    else {
        printf("Impossivel Remover, Codigo Nao Existe!!!\n");
    }
}