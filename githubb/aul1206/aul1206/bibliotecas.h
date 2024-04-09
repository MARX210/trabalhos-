#pragma once

#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <cctype>

typedef struct LISTADUPLA {
	int chave;
	/*Os dois ponteiros internos da Estrutura define que ela, nesse caso, é uma Lista duplamente encadeada*/
	struct LISTADUPLA* prox;
	struct LISTADUPLA* ant;
};

/*
	Quando criamos os arquivos sendo ".cpp" ou ".c", não podemos utilizar a Diretiva #include.
	Para utilizar as Funções que estão nos outros arquivos, necessita-se criar a Diretiva EXTERN
	dizendo que a Função é Externa ao arquivo que está utilizando-a.
	No EXTERN tem que colocar o Escopo completo da Função que será utilizada, finalizando com um ponto e vírgula ";" no final do escopo.
	Porém, tem que ser em ordem hierárquica, ou seja, se uma função chamará outra em outro arquivo, aquela que será chamada
	deverá ter sua diretiva EXTERN colocada antes daquela que a chama.
*/
extern void buscarPosicao(int ch, struct LISTADUPLA** PauxIni, struct LISTADUPLA** PauxFim);
extern void localizar(struct LISTADUPLA** Localiza, int pos, int codigo, struct LISTADUPLA** RetornaElem);
extern void inserir(struct LISTADUPLA** inicio, struct LISTADUPLA** fim);
extern void remover(struct LISTADUPLA** Ini, struct LISTADUPLA** Fim);
extern void mostrar(struct LISTADUPLA** Mostrar, int pos);


