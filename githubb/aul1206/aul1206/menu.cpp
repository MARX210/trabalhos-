#include "bibliotecas.h"

void menuP() {
	char op = '1';
	/*Estes dois Ponteiros serão responsáveis por guardar a LISTA INTEIRA*/
	struct LISTADUPLA* Ini = NULL;
	struct LISTADUPLA* Fim = NULL;
	while (op != '\x1b') {
		system("cls");
		printf("*****  MENU PRINCIPAL ******\n");
		printf("<I>nserir \n");
		printf("<R>emover\n");
		printf("<L>ocalizar\n");
		printf("<M>ostrar\n");
		printf("<ESC> Sair\n");
		printf("Informe a Opcao Desejada: ");
		op = _getche();
		printf("\n");
		switch (op) {
		case 'i':
		case 'I':
			/*Enviando os Endereços de Memória dos dois ponteiros que gerenciam a Lista*/
			inserir(&Ini, &Fim);
			break;
		case 'r':
		case 'R':
			if (Ini == NULL) {
				printf("\nLista Ainda Nao Existe, Insira Nos!!!\n");
			}
			else {
				/*Enviando os Endereços de Memória dos dois ponteiros que gerenciam a Lista*/
				remover(&Ini, &Fim);
			}
			system("pause");
			break;
		case 'm':
		case 'M':
			if (Ini == NULL) {
				printf("\nLista Ainda Nao Existe, Insira Nos!!!\n");
			}
			else {
				int pos;
				if (Ini == Fim) {
					pos = 0;
					/*Enviando o Endereço de Memória do primeiro Nó e a Posição 0 (indica início da Lista)*/
					mostrar(&Ini, pos);
				}
				else {
					printf("Deseja iniciar por qual extremindade (1 - Inicio, 2 - Fim): ");
					scanf_s("%d", &pos);
					if (pos == 1) {
						/*Enviando o Endereço de Memória do primeiro Nó e a Posição 1 (indica início da Lista)*/
						mostrar(&Ini, pos);
					}
					else {
						/*Enviando o Endereço de Memória do último Nó e a Posição 2 (indica fim da Lista)*/
						mostrar(&Fim, pos);
					}
				}
			}
			system("pause");
			break;
		case 'l':
		case 'L':
			if (Ini == NULL) {
				printf("Lista Nao Existe!!! Insira Nos!!!\n");
			}
			else {
				int ch, pos;
				struct LISTADUPLA* RetornaNo = NULL;
				printf("Deseja iniciar por qual extremindade (1 - Inicio, 2 - Fim): ");
				scanf_s("%d", &pos);
				printf("Informe a Chave: ");
				scanf_s("%d", &ch);
				if (pos == 1) {
					/*Enviando o Endereço de Memória do primeiro Nó e a Posição a partir de onde ocorrerá a Busca,
					o valor da Chave a ser Localizada e o Endereço do Nó em que está essa chave, se existir*/
					localizar(&Ini, pos, ch, &RetornaNo);
				}
				else {
					/*Enviando o Endereço de Memória do último Nó e a Posição a partir de onde ocorrerá a Busca,
					o valor da Chave a ser Localizada e o Endereço do Nó em que está essa chave, se existir*/
					localizar(&Fim, pos, ch, &RetornaNo);
				}
			}
			system("pause");
			break;
		case 27:
			printf("TTCHAAUU!!!\n");
			printf("FECHANDO O PROGRAMA\n");
			system("pause");
			break;
		default:
			printf("\nERRO!! Informe [i/I], [r/R],[b/B],[m/M] ou [ESC]\n");
			system("pause");
		}//FIM Switch
	}//FIM DO WHILE 1
}