#include "bibliotecas.h"

void localizar(struct LISTADUPLA** Localiza, int pos, int codigo, struct LISTADUPLA** RetornaElem) {
	struct LISTADUPLA* P_Loc;
	if (pos == 1) { // Se escolher fazer a localização a partir do primeiro elemento
		P_Loc = *Localiza;
		if (codigo == P_Loc->chave) { // Se já for o primeiro elemento
			printf("Dados Encontrados\n");
			printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
			*RetornaElem = P_Loc;//Retorna, se necessário o endereço do elemento encontrado
		}
		else {//Caso o elemento procurado não seja o primeiro da lista
			while (codigo != P_Loc->chave) {
				P_Loc = (*P_Loc).prox;//Recebe o endereço do próximo elemento
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
				*RetornaElem = P_Loc;//Retorna o endereço do código encontrado
			}
		}
	}
	else { //FIM OP == 1  --- Caso a procura for inicial pelo último elemento da lista
		P_Loc = *Localiza;
		if (codigo == P_Loc->chave) { //Se o código procurado for o código do último elemento da lista
			printf("Dados Encontrados\n");
			printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
			*RetornaElem = P_Loc;//retorna o endereço do elemento
		}
		else {//Caso não seja o último elemento e tenha que procurar onde está
			while (codigo != P_Loc->chave) {//Enquanto o código for diferente do procurado
				P_Loc = (*P_Loc).ant;//Recebe o endereço do elemento anterior
				if (P_Loc == NULL) {
					break;
				}
			}
			if (P_Loc == NULL) {
				printf("Codigo nao existe!!! Cadastre-o\n");
			}
			else {// caso o código tenha sido encontrado pelo WHILE
				printf("Dados Encontrados\n");
				printf("Posicao: %p, Codigo: %d\n", P_Loc, P_Loc->chave);
				*RetornaElem = P_Loc;//Retorna o endereço do elemento encontrado
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