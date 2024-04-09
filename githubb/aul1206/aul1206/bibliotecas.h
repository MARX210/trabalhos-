#pragma once

#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <cctype>

typedef struct LISTADUPLA {
	int chave;
	/*Os dois ponteiros internos da Estrutura define que ela, nesse caso, � uma Lista duplamente encadeada*/
	struct LISTADUPLA* prox;
	struct LISTADUPLA* ant;
};

/*
	Quando criamos os arquivos sendo ".cpp" ou ".c", n�o podemos utilizar a Diretiva #include.
	Para utilizar as Fun��es que est�o nos outros arquivos, necessita-se criar a Diretiva EXTERN
	dizendo que a Fun��o � Externa ao arquivo que est� utilizando-a.
	No EXTERN tem que colocar o Escopo completo da Fun��o que ser� utilizada, finalizando com um ponto e v�rgula ";" no final do escopo.
	Por�m, tem que ser em ordem hier�rquica, ou seja, se uma fun��o chamar� outra em outro arquivo, aquela que ser� chamada
	dever� ter sua diretiva EXTERN colocada antes daquela que a chama.
*/
extern void buscarPosicao(int ch, struct LISTADUPLA** PauxIni, struct LISTADUPLA** PauxFim);
extern void localizar(struct LISTADUPLA** Localiza, int pos, int codigo, struct LISTADUPLA** RetornaElem);
extern void inserir(struct LISTADUPLA** inicio, struct LISTADUPLA** fim);
extern void remover(struct LISTADUPLA** Ini, struct LISTADUPLA** Fim);
extern void mostrar(struct LISTADUPLA** Mostrar, int pos);


