//tipos de dados e bibliotecas

#ifndef __TIPOS_H_
#define __TIPOS_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Tipo da matriz
typedef struct {
	int r;
	int g;
	int b;
}PIXEL;

//Elementos do cenário
typedef enum {
	CEU,
	ESTRELA,
	MONTANHA,
	MONT_AUX,
}CENARIO;


#endif