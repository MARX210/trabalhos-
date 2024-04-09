#include "bibliotecas.h"
extern void menuP();

int main(int argv, char** argc) {
	menuP();
}

/*
	Observação: Esta lista duplamente encadeada está colocando as Chaves em Ordem Numérica Crescente
*/

/*
	LÓGICA DA IMPLEMENTAÇÃO DA LISTA DUPLAMENTE ENCADEADA
	1) Definir uma Estrutura que contenha os Dados pertercentes ao problema a ser tratado. Definir dois ponteiros do mesmo
	tipo que a estrutura. Um ponteiro para a memória que estará na posição ANTERIOR e outro na posição POSTERIOR ao Nó que estamos analisando(inserindo ou removendo).
	Por Exmpl: struct LISTADULPA* P_Ant; (P de Ponteiro e Ant de Anterior), struct LISTADUPLA* P_Post (P de ponteiro e Post de Posterior)

	2) Criar duas Variáveis de Manipulação da Estrutura. Por exemplo: um ponteiro para o INÍCIO e outro para o FIM da estrtura

	3) INSERÇÃO
		a) Verificar se a Lista Existe. Caso ela não exista, o Nó criado (Novo Nó) deverá ser apontado pelos ponteiros de manipulação (Início e Fim).
		b) Se a lista já existir. Verificar se existe apenas 1 Nó. Verificar em qual posição o Novo Nó entrará, no início ou fim da Lista.
			I) se escolher colocar no Início, manipular os ponteiros internos da estrutura (como no exmpl: P_Ant e P_Post). Como o Novo Nó se tornará o primeiro
			Manipula-se o ponteiro P_Post do Novo Nó e o ponteiro P_Ant do Nó que está na Primeira posição da Lista. E posteriormente o ponteiro de manipulação INÍCIO.
			II) se escolher colocar no Fim, manipular os ponteiros internos da estrutura (como no exmpl: P_Ant e P_Post). Como o Novo Nó se tornará o último
			Manipula-se o ponteiro P_Ant do Novo Nó e o ponteiro P_Post do Nó que está na Última posição da Lista. E posteriormente o ponteiro de manipulação FIM.
		c) Se já existirem ao menos 2 Nós e a escolha for colocar o Novo Nó entre dois (no meio), deve-se manipular os ponteiros internos dos 3 Nós envolvidos.
		O P_Post do Nó que ficará antes do Novo Nó inserido, o P_Ant do Nó que ficará depois do Novo Nó inserido e o P_Ant e P_Post do Novo Nó.
		Primeiro Liga-se o Novo Nó na Lista, fazendo os ponteiros internos P_Ant e P_Post receberem os endereços dos Nós que já estão na Lista. Para Isso, deve-se
		percorrer a Lista até encontrar a Posição de Inserção. Quando encontrar a posição, pode-se colocar dois ponteiros auxiliares, para facilitar a inserção.
		Um ponteiro coloca-se no Nó Anterior à posição de inserção e outro ponteiro no Nó Posterior à inserção. Assim, o P_Ant do Novo Nó receberá o endereço
		para o qual o ponteiro Auxiliar está apontando (Nó Anterior) e o P_Post do Novo Nó receberá o endereço para o qual o segundo ponteiro Auxiliar está
		apontando (Nó Posterior).
		Após isso, os ponteiros internos: P_Post, do nó apontado pelo ponteiro Auxiliar (Nó Anterior ao que será inserido) receberá o endereço do Novo Nó; P_Ant, do Nó apontado
		pelo ponteiro Auxiliar (Nó Posterior ao que será inserido) receberá o endereço do Novo Nó.

	4) REMOÇÃO
	  a) Verificar se a Lista Existe. Caso ela não exista, informar que é impossível remover.
	  b) Se a lista existir, verificar se existe apenas 1 Nó. Informar que a lista deixará de existir.
	  c) Se existirem mais de 1 Nó, pedir qual será removido.
		 I) se a escolha for o Primeiro Nó. Fazer o ponteiro Auxiliar da Remoção apontar para o Primeiro Nó. Após isso, fazer o Ponteiro que aponta para o Primeiro Nó,
		 apontar para o Segundo. Fazer o Ponteiro Interno para o Nó Anteiror, do Atual Primeiro, apontar para NULO (P_Ant do Primeiro recebe NULL).
		 II) Remover os dados do Ponteiro Auxiliar e Liberar a Memória.
		 III) Se a Escolha for o Último Nó. Fazer o ponteiro Auxiliar da Remoção apontar para o Último Nó. Após isso, fazer o Ponteiro que aponta para o Último Nó,
		 apontar para o Penúltimo. Fazer o Ponteiro Interno para o Nó Posteiror, do Atual Último, apontar para NULO (P_Post do Último recebe NULL).
		 IV) Remover os dados do Ponteiro Auxiliar e Liberar a Memória.
		 V) Se a remoção não for o Primeiro ou Último, percorrer a Lista, usando um ponteiro Auxiliar, para encontrar aquele Nó que será removido. Para isso, perguntar se a Busca será a Partir
		 do primeiro ou do último.
		 Assim que encontrar o Nó, manipular os ponteiros internos dos Nós envolvidos (Anteiror ao Nó, Posterior ao Nó e o Auxiliar).
		 Os passos são:
			Fazer o ponteiro interno do Anterior (P_Post do anterior) apontar para o Nó Posterior ao que será removido (apontado pelo Auxiliar).
			Fazer o ponteiro interno do Posterior (P_Ant do posterior) apontar para o Nós Anterior ao que será removido (apontado pelo Auxiliar).
			Limpar os Dados do Nó que será removido (apontado pelo Auxiliar).
			Liberar a Memória do Auxiliar.

*/