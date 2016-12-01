/* © copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>*/

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

void preencheMatriz(int tam, PIXEL img[tam][tam], int v[tam], int v2[tam]){
	int i, j;
	int aux = 0;

	//pintar base
	for(i=0;i<50;i++){
		for(j=0;j<tam;j++){
			img[i][j].r = 4;
			img[i][j].g = 8;
			img[i][j].b = 27;
		}
	}
	//pintar céu 
	for (i=50;i<tam;i++){
		//faz com que o auxiliar aumente a cada três linhas
		if((i%8)==0 && i!=0)
			aux++;
		for (j=0;j<tam;j++){

			img[i][j].r = 4+aux;
			img[i][j].g = 8+aux;
			img[i][j].b = 27+aux;

		}
	}

	// pintar estrelas
	int quant_star = 10+(rand()%35);
	int l_star, c_star;
	for (i=0;i<quant_star;i++){
		l_star = 5+(rand()%v[rand()%tam]);
		c_star = 5+(rand()%tam);

		img[l_star][c_star].r = 255;
		img[l_star][c_star].g = 255;
		img[l_star][c_star].b = 255;

	}	

	//pintar 1º montanha
	for (i=0; i<tam; i++){
		aux = v[i];
		for (j=aux; j< tam; j++){
			
			img[j][i].r = 40;
			img[j][i].g = 20;
			img[j][i].b = 13;
			
		}
	}
	//pintar 2º montanha
	for (i=0; i<tam; i++){
		aux = v2[i];
		for (j=aux; j< tam; j++){
			
			img[j][i].r = 20;
			img[j][i].g = 20;
			img[j][i].b = 20;
			/*if (aux < v[i]){
				for(j=aux; j<10; j++){
					img[j][i].r = 35;
					img[j][i].g = 35;
					img[j][i].b = 35;
				}

			}*/

		}
	}
}



