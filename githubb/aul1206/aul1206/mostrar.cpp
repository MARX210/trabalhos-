#include "bibliotecas.h"


void mostrar(struct LISTADUPLA** Mostrar, int pos) {
    struct LISTADUPLA* AuxMostrar;
    AuxMostrar = *Mostrar;
    printf("\n\nMOSTRAR LISTA INTEIRA\n\n");
    if (pos == 0) { // Caso tenha apenas 1 elemento na Lista
        printf("ANTERIOR: NULO \t\t CODIGO:%d \t <-- Primeiro <-- Ultimo \t\t PROXIMO: NULO  \n\n", AuxMostrar->chave);
    }
    else {
        if (pos == 1) { // Se escolher fazer a apresentação a partir do primeiro elemento
            while (1) { // Looping Eterno -- Parará quando a variável Auxiliar da Lista chegar em NULL a partir do primeiro elemento
                if (AuxMostrar->ant == NULL) { //ANT igual a NULL significa que este é o primeiro elemento
                    printf("ANTERIOR: NULO \t\t CODIGO: %d \t <-- Primeiro \t\t PROXIMO: %d  \n", AuxMostrar->chave, AuxMostrar->prox->chave);
                    AuxMostrar = AuxMostrar->prox; // Recebe o endereço do próximo elemento
                }
                else {
                    if (AuxMostrar->prox == NULL) {//PROX igual a NULL significa que este é o último elemento
                        printf("ANTERIOR: %d \t\t CODIGO: %d \t <-- Ultimo \t\t PROXIMO: NULO  \n\n", AuxMostrar->ant->chave, AuxMostrar->chave);
                        AuxMostrar = AuxMostrar->prox;// Recebe o endereço do próximo elemento
                    }
                    else { // Para todos os elementos intermediários
                        printf("ANTERIOR: %d \t\t CODIGO: %d \t\t\t\t PROXIMO: %d \n", AuxMostrar->ant->chave, AuxMostrar->chave, AuxMostrar->prox->chave);
                        AuxMostrar = AuxMostrar->prox;// Recebe o endereço do próximo elemento
                    }
                }
                if (AuxMostrar == NULL) {// Condição de Parada do WHILE
                    break;
                }
            }
        }
        else { // Se escolher fazer a apresentação a partir do último elemento
            while (1) {
                if (AuxMostrar->prox == NULL) {//Significa que este é o último elemento da lista
                    printf("ANTERIOR: %d \t\t CODIGO: %d \t <-- Ultimo \t\t PROXIMO: NULO  \n", AuxMostrar->ant->chave, AuxMostrar->chave);
                    AuxMostrar = AuxMostrar->ant;// Recebe o endereço do elemento anterior
                }
                else {
                    if (AuxMostrar->ant == NULL) {//Significa que este é o primeiro elemento da lista
                        printf("ANTERIOR: NULO \t\t CODIGO: %d \t <-- Primeiro \t\t PROXIMO: %d \n\n", AuxMostrar->chave, AuxMostrar->prox->chave);
                        AuxMostrar = AuxMostrar->ant;// Recebe o endereço do elemento anterior
                    }
                    else {// Para todos os elementos intermediários
                        printf("ANTERIOR: %d \t\t CODIGO: %d \t\t\t\t PROXIMO: %d \n", AuxMostrar->ant->chave, AuxMostrar->chave, AuxMostrar->prox->chave);
                        AuxMostrar = AuxMostrar->ant;// Recebe o endereço do elemento anterior
                    }
                }
                if (AuxMostrar == NULL) {
                    break;
                }
            }
        }
    }
}
