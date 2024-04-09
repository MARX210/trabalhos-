#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//ponteiros
/*--- int*P em C++ não aceita P= 200.---- */


//ESTRUTURA HETEROGÊNEA
typedef struct PRIMEIRA{
    int var1;
    float var2;
    double var3;
    char nome[48];
};

int main(int argv, char** argc)
{
    setlocale(LC_ALL, "");
    int x;
    int* p;
    struct PRIMEIRA ME;
    x = 200;

    //p= 200; // apenas em c em c++ não; // ponteiros não aceita valores inteiros // erro de sintaxe
    // p = x; erro de sintaxe
    // ponteiros só aceita endereço de memória para valores inteiros

    p = &x;
    x = 350;
    printf("\n");
    //Alocação Dinâmica
    int* a;
    // CASTING- CONVERSÃO DE TIPO
    //Sizeof = retorna a quantidade de bytes de uma memória
    // ou variável ou tipo de dado.


    printf("BYTES: %d\n", sizeof(ME.var1));
    printf("BYTES: %d\n", sizeof(ME.var2));
    printf("BYTES: %d\n", sizeof(ME.var3));
    printf("BYTES: %d\n", sizeof(ME.nome));
    printf("BYTES: %d\n", sizeof(ME));

    a = (float*) malloc(sizeof(int));
  // a = (int*) malloc(120);
  // a = (int*) malloc (30*sizeof(int));
}
