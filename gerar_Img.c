/* © copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>*/

#include "gerar_Img.h"
#include <stdio.h>

/**
	* Aqui a função que cria e gera o arquivo imagem
	* @param tam     Tamanho da matriz imagem
	* @param img     Matriz com dados da imagem a ser gerada
	* @param nomeArq Referência do nome da imagem
*/

void geraImg (int tam, PIXEL img[tam][tam], char *nomeArq){

	//TODO strcpy -> copia
	//TODO strcat -> concatena
	//TODO strlen -> pega o tamanho
	
	//TODO Aqui variáveis do tipo Imagem
	int max = 255;
	char *tipo = "P3"; 
	
	//TODO Aqui aloca o tamanho do endereço em que a imagem será gerada
	char *destino = "./";//saída padrão das imagens geradas
	char *enderImg = malloc(strlen(destino)+strlen(nomeArq)+1);

	strcpy(enderImg, destino);
	strcat(enderImg, nomeArq);

	FILE *arq;
	arq = fopen (enderImg, "w");

	//TODO Aqui gera o arquivo da imagem 
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