/* © copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>*/

//funções 
#include "tipos.h"
#include <string.h>

/**
	* Aqui gera um contorno aleatório para montanhas
	* Pega uma média entre extremos e aplica um deslocamento
	* Essa é uma função recursiva, as variáveis limite, ext_1 e ext_2 
	são alteradas a cada chamada
	* @param v      Referencia do vetor a ser utilizado
	* @param ext_1  Extremo inicial do vetor
	* @param ext_2  Extremo final do vetor
	* @param limite Valor máximo que pode ser atribuído ao deslocamento
*/

void contorno(int *v, int ext_1, int ext_2, int limite, int tamanho){
	
	int delta;
	// TODO gera um deslocamento aleatório
	if (limite>=2){
		delta = (-limite)+2*(rand()%limite);
	}else {
		delta = 0;
	}
	
	// TODO atribui a expressão a uma variável	
	int metade = (ext_2-ext_1)/2; //apenas para evitar repetição

	// TODO condição de parada da recurssão
	if (metade > 0){

		int aux = ((v[ext_1]+v[ext_2])/2 + delta);
		v[ext_1+metade] = aux;

		//verificação de segmentation fault
		if (aux > tamanho-1){
			v[ext_1+metade] = tamanho-1;
		}else if (aux < 0){
			v[ext_1+metade] = 0;
		}
		
		// TODO chamadas da recurssão
		//divide direita
		contorno(v,ext_1,ext_1+metade, limite/2, tamanho);
		//divide esquerda
		contorno(v,ext_1+metade,ext_2, limite/2, tamanho);
	}
}

/**
	* Aqui recebe os vetores com os contornos de cada montanha, a matriz 
	da imagem que será gerada e o tamanho da imagem.
	* @param tam Tamanho da imagem (a imagem é quadrada)
	* @param img Matriz que contém os dados da imagem
	* @param v   Vetor com os dados do contorno da montanha principal
	* @param v2  Vetor com os dados do contorno da montanha auxiliar
*/

void preencheMatriz(int tam, PIXEL img[tam][tam], int v[tam], int v2[tam]){
	
	int i, j;
	int aux = 0;

	//Cores padrões usadas
	int cores[4][3]={
		{4,8,27}, //céu
		{255,255,255}, //estrela
		{40,20,13}, //montanha principal
		{56,28,12}, //montanha secundária
	};

	// TODO Colore uma base para o céu (evita que o gradiente fique estranho)
	// TODO Utiliza cores com base no enum e na matriz cores
	for(i=0;i<50;i++){
		for(j=0;j<tam;j++){
			img[i][j].r = cores[CEU][0];
			img[i][j].g = cores[CEU][1];
			img[i][j].b = cores[CEU][2];
		}
	}

	// TODO Colore e aplica gradiente no céu 
	for (i=50;i<tam;i++){
		/*faz com que o auxiliar aumente a cada 8 linhas
		  Controla a intensidade do gradiente*/
		if((i%8)==0 && i!=0)
			aux++;
		for (j=0;j<tam;j++){

			img[i][j].r = cores[CEU][0]+aux;
			img[i][j].g = cores[CEU][1]+aux;
			img[i][j].b = cores[CEU][2]+aux;

		}
	}

	// TODO aplica estrelas no céu
	/*
		@param quant_star quantidade aleatória de estrelas para
		serem geradas
		@param l_star linha da matriz em que uma estrela será colocada
		@param c_star coluna da matriz em que uma estrela será colocada
	*/
	int quant_star = 10+(rand()%35);
	int l_star, c_star;
	for (i=0;i<quant_star;i++){

		// TODO gera uma linha e uma coluna aleatória para posicionar uma estrela
		l_star = 5+(rand()%v[rand()%tam]);
		c_star = 5+(rand()%tam);

		img[l_star][c_star].r = cores[ESTRELA][0];
		img[l_star][c_star].g = cores[ESTRELA][1];
		img[l_star][c_star].b = cores[ESTRELA][2];

	}	

	// TODO Aplica cor na montanha principal
	// @param aux linha do contorno da montanha
	for (i=0; i<tam; i++){
		aux = v[i];
		for (j=aux; j< tam; j++){
			
			img[j][i].r = cores[MONTANHA][0];
			img[j][i].g = cores[MONTANHA][1];
			img[j][i].b = cores[MONTANHA][2];
			
		}
	}
	// TODO Aplica cor na montanha secundária
	// @param aux linha do contorno da montanha
	for (i=0; i<tam; i++){
		aux = v2[i];
		for (j=aux; j< tam; j++){
			
			img[j][i].r = cores[MONT_AUX][0];
			img[j][i].g = cores[MONT_AUX][1];
			img[j][i].b = cores[MONT_AUX][2];
		}		
	}	
}



