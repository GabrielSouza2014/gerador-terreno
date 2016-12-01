/* © copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>*/

#include "gerar_Img.h"
#include <stdio.h>

void geraImg (int tam, PIXEL img[tam][tam], char *nomeArq){

	//strcpy -> copia
	//strcat -> concatena
	//strlen -> pega o tamanho
	
	int max = 255;
	char *tipo = "P3"; 
	
	// char *destino = "/home/gabriel_2016/Imagens/";//saída padrão das imagens geradas
	char *destino = "./";//saída padrão das imagens geradas
	char *enderImg = malloc(strlen(destino)+strlen(nomeArq)+1);//aloca o tamanho do destino

	strcpy(enderImg, destino);
	strcat(enderImg, nomeArq);

	FILE *arq;
	arq = fopen (enderImg, "w");

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