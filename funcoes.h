//funcoes.h

#ifndef __FUNCOES_H_
#define __FUNCOES_H_

#include "tipos.h"

void preencheMatriz(int tam, PIXEL img[tam][tam], int v[tam], int v2[tam]);
void geraImg (int tam, PIXEL img[tam][tam], char *nomeArq);
void contorno(int *v, int ext_1, int ext_2, int limite, int tam);
#endif