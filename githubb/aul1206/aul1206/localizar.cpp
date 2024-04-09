#include "bibliotecas.h"

void localizar(struct LISTADUPLA** Localiza, int pos, int codigo, struct LISTADUPLA** RetornaElem) {
	struct LISTADUPLA* P_Loc;
	if (pos == 1) { // Se escolher fazer a localiza��o a partir do primeiro elemento
		P_Loc = *Localiza;
		if (codigo == P_Loc->chave) { // Se j� for o primeiro elemento
			printf("Dados Encontrados\n");
			printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
			*RetornaElem = P_Loc;//Retorna, se necess�rio o endere�o do elemento encontrado
		}
		else {//Caso o elemento procurado n�o seja o primeiro da lista
			while (codigo != P_Loc->chave) {
				P_Loc = (*P_Loc).prox;//Recebe o endere�o do pr�ximo elemento
				if (P_Loc == NULL) {
					break;
				}
			}
			if (P_Loc == NULL) {
				printf("Codigo nao existe!!! Cadastre-o\n");
			}
			else { //Se existir e for encontrado pelo Enquanto
				printf("Dados Encontrados\n");
				printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
				*RetornaElem = P_Loc;//Retorna o endere�o do c�digo encontrado
			}
		}
	}
	else { //FIM OP == 1  --- Caso a procura for inicial pelo �ltimo elemento da lista
		P_Loc = *Localiza;
		if (codigo == P_Loc->chave) { //Se o c�digo procurado for o c�digo do �ltimo elemento da lista
			printf("Dados Encontrados\n");
			printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
			*RetornaElem = P_Loc;//retorna o endere�o do elemento
		}
		else {//Caso n�o seja o �ltimo elemento e tenha que procurar onde est�
			while (codigo != P_Loc->chave) {//Enquanto o c�digo for diferente do procurado
				P_Loc = (*P_Loc).ant;//Recebe o endere�o do elemento anterior
				if (P_Loc == NULL) {
					break;
				}
			}
			if (P_Loc == NULL) {
				printf("Codigo nao existe!!! Cadastre-o\n");
			}
			else {// caso o c�digo tenha sido encontrado pelo WHILE
				printf("Dados Encontrados\n");
				printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
				*RetornaElem = P_Loc;//Retorna o endere�o do elemento encontrado
			}
		}
	}
}






void localizarPosIni(int ch, struct LISTADUPLA** PauxAnt, struct LISTADUPLA** PauxPost) {
	struct LISTADUPLA* encontrou;
	if (ch < (*PauxAnt)->chave) {
		*PauxAnt = NULL;
	}
	else {
		if (ch >= (*PauxPost)->chave) {
			*PauxPost = NULL;
		}
		else {
			encontrou = *PauxAnt;
			while (ch >= encontrou->prox->chave) {
				encontrou = encontrou->prox;
			}
			*PauxAnt = encontrou;
			*PauxPost = encontrou->prox;
		}
	}
}

void localizarPosFim(int ch, struct LISTADUPLA** PauxAnt, struct LISTADUPLA** PauxPost) {
	struct LISTADUPLA* encontrou;
	if (ch > (*PauxPost)->chave) {
		*PauxPost = NULL;
	}
	else {
		if (ch <= (*PauxAnt)->chave) {
			*PauxAnt = NULL;
		}
		else {
			encontrou = *PauxPost;
			while (ch <= encontrou->ant->chave) {
				encontrou = encontrou->ant;
			}
			*PauxPost = encontrou;
			*PauxAnt = encontrou->ant;
		}
	}
}


void buscarPosicao(int ch, struct LISTADUPLA** PauxIni, struct LISTADUPLA** PauxFim) {
	struct LISTADUPLA* P_Ant = NULL;
	struct LISTADUPLA* P_Post = NULL;
	int pos, chave = ch, parar = 0;
	if (*PauxIni == *PauxFim) {
		P_Ant = *PauxIni;
		P_Post = *PauxIni;
	}
	else {
		P_Ant = *PauxIni;
		P_Post = *PauxFim;
	}
	do {
		system("CLS");
		printf("Localizar a posicao de insercao a partir de qual extremidade?\n");
		printf("<1> Inicio\n");
		printf("<2> Final\n");
		printf("Informe sua opcao: ");
		scanf_s("%d", &pos);
		switch (pos) {
		case 1:
			localizarPosIni(chave, &P_Ant, &P_Post);
			parar = 1;
			break;
		case 2:
			localizarPosFim(chave, &P_Ant, &P_Post);
			parar = 1;
			break;
		default:
			printf("ERRO!! Informe 1 ou 2!!\n");
		}//FIM DO SWITCH
	} while (parar != 1);
	*PauxIni = P_Ant;
	*PauxFim = P_Post;
}