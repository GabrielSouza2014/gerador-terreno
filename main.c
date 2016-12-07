/* © copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>*/
 
#include "tipos.h"
#include "funcoes.h"
#include "gerar_Img.h"
#include <string.h>

/**
	* Aqui temos a função principal do programa
	* @param arg  tamanho da string digitada pelo usuário
	com os valores de referência
	* @param argc referência da string digitada pelo usuário
	(contém todos os parâmetros que foram solicitados)

*/
int main (int arg, char *argc[]){

	/**
		* @param nomeArq Nome da imagem que será gerada (Default: terreno.ppm)
		* @param tam     Tamanho da imagem (que é quadrada, Default: 513)
		* @param limit   Valor máximo inicial que pode ser atribuído ao 
		deslocamento (Default: 128)
		* @param lim_v2  Valor máximo inicial que pode ser atribuído ao 
		deslocamento da montanha auxiliar (Default: 128)
	*/

	//variáveis iniciadas com o default
	char *nomeArq = "terreno.ppm";
	int tam=513, limit=128, i;
	int lim_v2 = limit;

	// TODO procura por parâmetros digitados pelo usuário

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
	//TODO Controle de segmentation fault
	if (tam >= 1025){
		tam = 513;
		limit = 128;
		lim_v2 = limit;
	}
	/*
		* @param vetor   Vetor que armazenará o contorno da montanha principal
		* @param vetor2  Vetor que armazenará o contorno da montanha secundária
		* @param terreno Matriz que receberá os dados da imagem
	**/	
	
	int vetor[tam];//primeira montanha
	int vetor2[tam];//segunda montanha
	PIXEL terreno[tam][tam];
	
	srand((unsigned) time(NULL));

	//TODO Adicionar valores aleatórios aos extremos do vetor
	vetor[0] = 20+(rand()%(tam-20));
	vetor[tam-1] = 20+(rand()%(tam-20));

	//TODO Adicionar valores aleatórios aos extremos da segunda montanha
	vetor2[0] = (vetor[0]/3)+(rand()%(tam-20));
	vetor2[tam-1] = (vetor[tam-1]/3)+(rand()%(tam-20));

	//TODO Define a posição do ultimo extremo
	int ext2 = tam-1;

	//TODO chamada de funções 
	/**
		* @param contorno 		Chama a função que gera o contorno da montanha
		* @param preencheMatriz Aplica os efeitos gráficos na matriz imagem
		* @param geraImg        Gera o arquivo da imagem
	*/
	contorno(vetor, 0, ext2, limit, tam);//1º montanha
	contorno(vetor2, 0, ext2, lim_v2, tam); // 2º montanha
	preencheMatriz(tam, terreno, vetor, vetor2);
	geraImg(tam, terreno, nomeArq);
	
	return 0;
}