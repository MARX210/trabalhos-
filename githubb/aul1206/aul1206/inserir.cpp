#include "bibliotecas.h"
/*Recebe os Endereços do Primeiro e Último Nós*/
void inserir(struct LISTADUPLA** inicio, struct LISTADUPLA** fim) {
	struct LISTADUPLA* AuxINI;//Auxiliar para o Ponteiro Início
	struct LISTADUPLA* AuxFIM;//Auxiliar para o Ponteiro Fim
	struct LISTADUPLA* NovoNo;//Sempre será um Novo Nó na Inserção.
	AuxFIM = *fim;//Fazendo o Auxiliar apontar para o Último Nó
	AuxINI = *inicio;//Fazendo o Auxiliar apontar para o Primeiro Nó
	if ((NovoNo = (LISTADUPLA*)malloc(sizeof(LISTADUPLA))) == NULL) {
		printf("ERRO!! Nao foi possivel alocar memoria\n");
	}
	else {
		printf("\nInforme um valor para Chave: ");
		scanf_s("%d", &NovoNo->chave);
		NovoNo->prox = NULL;
		NovoNo->ant = NULL;
		if (*inicio == NULL) {
			printf("Lista ainda nao existe, vou inserir o primeiro no\n");
			*inicio = *fim = NovoNo;
		}
		else {
			buscarPosicao(NovoNo->chave, &AuxINI, &AuxFIM);//Buscar a Posição de Inserção
			if (AuxINI == NULL) {//AuxINI NULL significa que o Novo Nó será inserido como Primeiro Nó
				NovoNo->prox = *inicio;
				(*inicio)->ant = NovoNo;
				*inicio = NovoNo;
			}
			else {
				if (AuxFIM == NULL) {//AuxFIM NULL significa que o Novo Nó será inserido como Último Nó
					NovoNo->ant = *fim;
					(*fim)->prox = NovoNo;
					*fim = NovoNo;
				}
				else {//Será inserido entre Dois outros Nós
					NovoNo->ant = AuxINI;
					NovoNo->prox = AuxFIM;
					AuxINI->prox = NovoNo;
					AuxFIM->ant = NovoNo;
				}
			}
		}
	}
}