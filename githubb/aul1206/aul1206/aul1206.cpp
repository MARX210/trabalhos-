#include "bibliotecas.h"
extern void menuP();

int main(int argv, char** argc) {
	menuP();
}

/*
	Observa��o: Esta lista duplamente encadeada est� colocando as Chaves em Ordem Num�rica Crescente
*/

/*
	L�GICA DA IMPLEMENTA��O DA LISTA DUPLAMENTE ENCADEADA
	1) Definir uma Estrutura que contenha os Dados pertercentes ao problema a ser tratado. Definir dois ponteiros do mesmo
	tipo que a estrutura. Um ponteiro para a mem�ria que estar� na posi��o ANTERIOR e outro na posi��o POSTERIOR ao N� que estamos analisando(inserindo ou removendo).
	Por Exmpl: struct LISTADULPA* P_Ant; (P de Ponteiro e Ant de Anterior), struct LISTADUPLA* P_Post (P de ponteiro e Post de Posterior)

	2) Criar duas Vari�veis de Manipula��o da Estrutura. Por exemplo: um ponteiro para o IN�CIO e outro para o FIM da estrtura

	3) INSER��O
		a) Verificar se a Lista Existe. Caso ela n�o exista, o N� criado (Novo N�) dever� ser apontado pelos ponteiros de manipula��o (In�cio e Fim).
		b) Se a lista j� existir. Verificar se existe apenas 1 N�. Verificar em qual posi��o o Novo N� entrar�, no in�cio ou fim da Lista.
			I) se escolher colocar no In�cio, manipular os ponteiros internos da estrutura (como no exmpl: P_Ant e P_Post). Como o Novo N� se tornar� o primeiro
			Manipula-se o ponteiro P_Post do Novo N� e o ponteiro P_Ant do N� que est� na Primeira posi��o da Lista. E posteriormente o ponteiro de manipula��o IN�CIO.
			II) se escolher colocar no Fim, manipular os ponteiros internos da estrutura (como no exmpl: P_Ant e P_Post). Como o Novo N� se tornar� o �ltimo
			Manipula-se o ponteiro P_Ant do Novo N� e o ponteiro P_Post do N� que est� na �ltima posi��o da Lista. E posteriormente o ponteiro de manipula��o FIM.
		c) Se j� existirem ao menos 2 N�s e a escolha for colocar o Novo N� entre dois (no meio), deve-se manipular os ponteiros internos dos 3 N�s envolvidos.
		O P_Post do N� que ficar� antes do Novo N� inserido, o P_Ant do N� que ficar� depois do Novo N� inserido e o P_Ant e P_Post do Novo N�.
		Primeiro Liga-se o Novo N� na Lista, fazendo os ponteiros internos P_Ant e P_Post receberem os endere�os dos N�s que j� est�o na Lista. Para Isso, deve-se
		percorrer a Lista at� encontrar a Posi��o de Inser��o. Quando encontrar a posi��o, pode-se colocar dois ponteiros auxiliares, para facilitar a inser��o.
		Um ponteiro coloca-se no N� Anterior � posi��o de inser��o e outro ponteiro no N� Posterior � inser��o. Assim, o P_Ant do Novo N� receber� o endere�o
		para o qual o ponteiro Auxiliar est� apontando (N� Anterior) e o P_Post do Novo N� receber� o endere�o para o qual o segundo ponteiro Auxiliar est�
		apontando (N� Posterior).
		Ap�s isso, os ponteiros internos: P_Post, do n� apontado pelo ponteiro Auxiliar (N� Anterior ao que ser� inserido) receber� o endere�o do Novo N�; P_Ant, do N� apontado
		pelo ponteiro Auxiliar (N� Posterior ao que ser� inserido) receber� o endere�o do Novo N�.

	4) REMO��O
	  a) Verificar se a Lista Existe. Caso ela n�o exista, informar que � imposs�vel remover.
	  b) Se a lista existir, verificar se existe apenas 1 N�. Informar que a lista deixar� de existir.
	  c) Se existirem mais de 1 N�, pedir qual ser� removido.
		 I) se a escolha for o Primeiro N�. Fazer o ponteiro Auxiliar da Remo��o apontar para o Primeiro N�. Ap�s isso, fazer o Ponteiro que aponta para o Primeiro N�,
		 apontar para o Segundo. Fazer o Ponteiro Interno para o N� Anteiror, do Atual Primeiro, apontar para NULO (P_Ant do Primeiro recebe NULL).
		 II) Remover os dados do Ponteiro Auxiliar e Liberar a Mem�ria.
		 III) Se a Escolha for o �ltimo N�. Fazer o ponteiro Auxiliar da Remo��o apontar para o �ltimo N�. Ap�s isso, fazer o Ponteiro que aponta para o �ltimo N�,
		 apontar para o Pen�ltimo. Fazer o Ponteiro Interno para o N� Posteiror, do Atual �ltimo, apontar para NULO (P_Post do �ltimo recebe NULL).
		 IV) Remover os dados do Ponteiro Auxiliar e Liberar a Mem�ria.
		 V) Se a remo��o n�o for o Primeiro ou �ltimo, percorrer a Lista, usando um ponteiro Auxiliar, para encontrar aquele N� que ser� removido. Para isso, perguntar se a Busca ser� a Partir
		 do primeiro ou do �ltimo.
		 Assim que encontrar o N�, manipular os ponteiros internos dos N�s envolvidos (Anteiror ao N�, Posterior ao N� e o Auxiliar).
		 Os passos s�o:
			Fazer o ponteiro interno do Anterior (P_Post do anterior) apontar para o N� Posterior ao que ser� removido (apontado pelo Auxiliar).
			Fazer o ponteiro interno do Posterior (P_Ant do posterior) apontar para o N�s Anterior ao que ser� removido (apontado pelo Auxiliar).
			Limpar os Dados do N� que ser� removido (apontado pelo Auxiliar).
			Liberar a Mem�ria do Auxiliar.

*/