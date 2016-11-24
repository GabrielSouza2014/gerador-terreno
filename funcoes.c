//funções 
#include "tipos.h"
#include <string.h>


void contorno(int *v, int ext_1, int ext_2, int limite, int tamanho){
	
	int delta;
	if (limite>=2){
		delta = (-limite)+2*(rand()%limite);
	}else {
		delta = 0;
	}
			
	int metade = (ext_2-ext_1)/2; //apenas para evitar repetição

	if (metade > 0){

		int aux = ((v[ext_1]+v[ext_2])/2 + delta);
		v[ext_1+metade] = aux;

		//verificação de segmentation fault
		if (aux > tamanho-1){
			v[ext_1+metade] = tamanho-1;
		}else if (aux < 0){
			v[ext_1+metade] = 0;
		}
		
		//divide direita
		contorno(v,ext_1,ext_1+metade, limite/2, tamanho);
		//divide esquerda
		contorno(v,ext_1+metade,ext_2, limite/2, tamanho);
	}
}

void preencheMatriz(int tam, PIXEL img[tam][tam], int v[tam]){
	int i, j;
	int aux;

	/*for (i=0; i<tam; i++){
		aux = v[i];
		for(j=0; j<10; j++){
			//if contra segmentation fault
			if (aux+j < tam-1 && i+j < tam-1 && aux+j>0 && i+j>0){ 
				img[aux+j][i+j].r = 50;
				img[aux+j][i+j].g = 205;
				img[aux+j][i+j].b = 50;
			}			
		}
		
	}*/
	
	//pintar céu 
	for (j=0; j<tam; j++){
		aux = v[j];
		for (i=aux; i>0; i--){
			img[i][j].r = 126;
			img[i][j].g = 192;
			img[i][j].b = 238;
		}
	}
	//pintar montanha
	for (j=0; j<tam; j++){
		aux = v[j];
		for (i=aux; i< tam; i++){
			img[i][j].r = 139;
			img[i][j].g = 115;
			img[i][j].b = 85;
		}
	}

	//corrigir falhas 
	/*for (i=0; i<tam; i++){
		for (j=0; j<tam; j++){
			if (img[i][j].r == 0 && img[i][j].g == 0 && img[i][j].b == 0){
				img[i][j].r = 50;
				img[i][j].g = 205;
				img[i][j].b = 50;
			}
		}
	}*/

}

void geraImg (int tam, PIXEL img[tam][tam], char *nomeArq){

	int max = 255;
	char *tipo = "P3"; 
	//char *nomeArq = "img.ppm";

	char *destino = "/home/ubuntu/Pictures/";//saída padrão das imagens geradas
	char *enderImg = malloc(strlen(destino)+strlen(nomeArq)+1);//aloca o tamanho do destino

	strcpy(enderImg, destino);
	strcat(enderImg, nomeArq);

	FILE *arq;
	arq = fopen (enderImg, "w");

	//strcpy -> copia
	//strcat -> concatena
	//strlen -> pega o tamanho
	//printf("%s\n", enderImg);

	int i, j;
	fprintf(arq,"%s\n%i %i\n%i\n",tipo, tam, tam, max);
	for(i=0;i<tam;i++){
		for (j=0;j<tam;j++){
			fprintf(arq,"%i %i %i\n", img[i][j].r,
								 	  img[i][j].g,
								 	  img[i][j].b);
		}
	}
	free (enderImg);
	fclose(arq);
}

