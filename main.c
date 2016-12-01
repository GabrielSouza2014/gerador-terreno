#include "tipos.h"
#include "funcoes.h"
#include <string.h>

int main (int arg, char *argc[]){

	//variáveis iniciadas com o default
	char *nomeArq = "terreno.ppm";
	int tam=513, limit=128, i;
	int lim_v2 = limit;//deslocamento da 2º montanha

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
				lim_v2 = limit;
			}			
		}
		if (strcmp(argc[i], "-o") == 0){
			if((i+1) < arg){
				nomeArq = argc[i+1];
			}			
		}
	}		
	
	int vetor[tam];//primeira montanha
	int vetor2[tam];//segunda montanha
	PIXEL terreno[tam][tam];
	
	srand((unsigned) time(NULL));

	//adicionar valores aos extremos do vetor
	vetor[0] = 20+(rand()%(tam-20));
	vetor[tam-1] = 20+(rand()%(tam-20));

	//adicionar valores aos extremos da segunda montanha
	vetor2[0] = (vetor[0]/3)+(rand()%(tam-20));
	vetor2[tam-1] = (vetor[tam-1]/3)+(rand()%(tam-20));

	//define a posição do ultimo extremo
	int ext2 = tam-1;
	contorno(vetor, 0, ext2, limit, tam);//1º montanha
	contorno(vetor2, 0, ext2, lim_v2, tam); // 2º montanha
	preencheMatriz(tam, terreno, vetor, vetor2);
	geraImg(tam, terreno, nomeArq);
	
	return 0;
}