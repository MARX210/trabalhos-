#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

void LBTeclado(){
    int c = 0;
    while((c = getchar()) != '\n' && c != EOF){}
    return;
}
//strlen(nomes[i])
// fun��o principal do programa
int main(int argv, char** argc){

     setlocale(LC_ALL,"");

  // quantidade de nomes
  int quantnomes = 3;

  // matriz de nomes de 50 caracteres cada
  char nomes[quantnomes][50];

  // vetor de soma de decimal das letras
  int vetsoma[quantnomes];

  // vari�veis adicionais
  int i, j, soma;

  for(i = 0; i < quantnomes; i++){
  	printf("Informe o %d� nome: ",i + 1);
    scanf("%[^\n]",nomes[i]);
    LBTeclado();
  }

  // efetua os somat�rios das letras de cada palavra
  for(i = 0; i < quantnomes; i++){
  	soma = 0;

	// faz o somat�rio dos caracteres deste nome
	for(j = 0; j < strlen(nomes[i]); j++){//strlen retorna o valor inteiro sem contar o NULL
	  if(nomes[i][j] != ' '){
		soma = soma + toupper(nomes[i][j]);
	  }
	}
	// guarda este somat�rio no vetor
	vetsoma[i] = soma;
  }

  // mostra os somat�rios das letras dos nomes
  printf("\n");
  for(i = 0; i < quantnomes; i++){
  	printf("%s = %d\n", nomes[i], vetsoma[i]);
  }

  printf("\n\n");
  return 0;
}
