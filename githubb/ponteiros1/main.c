#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//ponteiros
/*--- int*P em C++ n�o aceita P= 200.---- */


//ESTRUTURA HETEROG�NEA
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

    //p= 200; // apenas em c em c++ n�o; // ponteiros n�o aceita valores inteiros // erro de sintaxe
    // p = x; erro de sintaxe
    // ponteiros s� aceita endere�o de mem�ria para valores inteiros

    p = &x;
    x = 350;
    printf("\n");
    //Aloca��o Din�mica
    int* a;
    // CASTING- CONVERS�O DE TIPO
    //Sizeof = retorna a quantidade de bytes de uma mem�ria
    // ou vari�vel ou tipo de dado.


    printf("BYTES: %d\n", sizeof(ME.var1));
    printf("BYTES: %d\n", sizeof(ME.var2));
    printf("BYTES: %d\n", sizeof(ME.var3));
    printf("BYTES: %d\n", sizeof(ME.nome));
    printf("BYTES: %d\n", sizeof(ME));

    a = (float*) malloc(sizeof(int));
  // a = (int*) malloc(120);
  // a = (int*) malloc (30*sizeof(int));
}
