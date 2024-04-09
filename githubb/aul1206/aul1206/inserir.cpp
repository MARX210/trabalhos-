#include "bibliotecas.h"
/*Recebe os Endere�os do Primeiro e �ltimo N�s*/
void inserir(struct LISTADUPLA** inicio, struct LISTADUPLA** fim) {
	struct LISTADUPLA* AuxINI;//Auxiliar para o Ponteiro In�cio
	struct LISTADUPLA* AuxFIM;//Auxiliar para o Ponteiro Fim
	struct LISTADUPLA* NovoNo;//Sempre ser� um Novo N� na Inser��o.
	AuxFIM = *fim;//Fazendo o Auxiliar apontar para o �ltimo N�
	AuxINI = *inicio;//Fazendo o Auxiliar apontar para o Primeiro N�
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
			buscarPosicao(NovoNo->chave, &AuxINI, &AuxFIM);//Buscar a Posi��o de Inser��o
			if (AuxINI == NULL) {//AuxINI NULL significa que o Novo N� ser� inserido como Primeiro N�
				NovoNo->prox = *inicio;
				(*inicio)->ant = NovoNo;
				*inicio = NovoNo;
			}
			else {
				if (AuxFIM == NULL) {//AuxFIM NULL significa que o Novo N� ser� inserido como �ltimo N�
					NovoNo->ant = *fim;
					(*fim)->prox = NovoNo;
					*fim = NovoNo;
				}
				else {//Ser� inserido entre Dois outros N�s
					NovoNo->ant = AuxINI;
					NovoNo->prox = AuxFIM;
					AuxINI->prox = NovoNo;
					AuxFIM->ant = NovoNo;
				}
			}
		}
	}
}