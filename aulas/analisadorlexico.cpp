//*********************************************************
// Nome: Analisador lexico
// O presente algoritmo faz a analise lexica de expressões 
// artimeticas simples incluindo os paranteses 
//
// Exemplo
// compilador_lexico 2+2*3
//
// O retorno do programa retorna se a expressão está 
// bem formulada ou não 
//*********************************************************
 
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define SIZE 7
 
const int cant[SIZE]= {5,2,1,8,1,2,6};
int ptros[SIZE];
const char crteres[] = {'D','+','-','(','$','D','(','D','D','.','+','-','*','/',')','$','D','D','(','+','-','*','/',')','$'};
const int  eestados[] = {3,2,2,1,7,3,1,3,3,4,5,5,5,5,6,7,3,3,1,5,5,5,5,6,7};
 
void llenar_ptros();
int get_eestado(int estado, char crter);
 
int main(int argc, char *argv[])
{
	if (argc !=  2) return 1;
	llenar_ptros();
	char crter;
	int resp, estado= 0;
	printf("\n\nParametro %s\n\n", argv[1] );
	char *cuenta= argv[1];
	strcat(cuenta, "$");
	while (crter= *cuenta++) 
	{
		printf("estado:%d crter:%c \n", estado, crter);
		estado = get_eestado(estado, crter);
		if (estado == 'E' || estado == 7) break;
	}	
	switch (estado) 
	{
		case 'E': 
			 printf("Existe um erro lexico\n"); 
			 break;
		case   7: 
             printf("A expressao esta formulado corretamente\n"); 
			 break;
		default : 
		     printf("ops..."); 
			 break;
	}
	return 0;
}
 
void llenar_ptros()
{
	int i, acum = 0;
	int tamano = SIZE;
	for (i=0; i<tamano; i++) 
	{
		ptros[i] = acum;
		acum     = acum + cant[i];
	}
}
 
int get_eestado(int estado, char crter)
{
	int cont;
	char valor;
	if (isdigit(crter))
		valor = 'D';
	else
		valor = crter;	
	int i;
	int max   = cant[estado];
	int posic = ptros[estado];
	char resp = 'E';
	for (i = 0; i < max; i++) 
	{
		if (crteres[posic] == valor) 
		{
			resp = eestados[posic];
			break;
		}
		else
		{
		    posic++;
		}
	}
	return resp;
}
