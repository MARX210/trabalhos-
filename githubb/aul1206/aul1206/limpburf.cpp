#include "bibliotecas.h"

void LbuffTec(void)//Fun��o criada para limpar o Buffer do Teclado
{
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) {}
	return;
}