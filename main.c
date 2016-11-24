#include "tipos.h"
#include "funcoes.h"
#include <string.h>

int main (int arg, char *argc[]){

	//variáveis iniciadas com o default
	char *nomeArq = "terreno.ppm";
	int tam=513, limit=128, i;

	//recebe os parametros digitados pelo usuário
	for (i=1; i<arg; i++){	
		if (strcmp(argc[i], "-s") == 0){
			if ((i+1) < arg){ //evita passar do tamanho
				tam = atoi(argc[i+1]);
			}			
		}
		if (strcmp(argc[i], "-d") == 0){
			if ((i+1) < arg){
				limit = atoi(argc[i+1]);
			}			
		}
		if (strcmp(argc[i], "-o") == 0){
			if((i+1) < arg){
				nomeArq = argc[i+1];
			}			
		}
	}		
	
	int vetor[tam];
	PIXEL terreno[tam][tam];
	
	srand((unsigned) time(NULL));

	//adicionar valores aos extremos do vetor
	vetor[0] = 20+(rand()%(tam-20));
	vetor[tam-1] = 20+(rand()%(tam-20));

	//define a posição do ultimo extremo
	int ext2 = tam-1;
	contorno(vetor, 0, ext2, limit, tam);
	preencheMatriz(tam, terreno, vetor);
	geraImg(tam, terreno, nomeArq);
	
	return 0;
}