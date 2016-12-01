© copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>

*Produzido para a disciplina de PTP-2016.2 do IMD*
*Autor: Gabriel Araújo de Souza*
*Matrícula: 2016042088*
*Email: gabriel_feg@hotmail.com*


____________________________________________________________

* criar um enum
* separar melhor a função preencher imagem
* criar um parametro para receber o repositório 
____________________________________________________________

1 - O QUE FOI FEITO



2 - O QUE NÃO FOI FEITO




3 - BIBLIOTECAS USADAS

	* stdio.h
	* string.h
	* stdlib.h
	* time.h

4 - ARQUIVOS CRIADOS

	4.1 - main.c

		* Esse é o arquivo principal do projeto
		* Responsável por receber os parâmetros digitados pelo usuário
		* Declara o tamanho da imagem
		* Chama as funções de criar, pintar e gerar a imagem

	4.2 - funcoes.c
		
		* Possui a função de criar o contorno das montanhas
		* Possui a função que aplica o gradiente, estrelas, e cores na imagem
		
	4.3 - funcoes.h
		
		* Arquivo ".h" de funcoes.c

	4.4 - gerar_Img.c

		* Contém a função que cria um arquivo ".ppm" e gera a imagem
		* Utiliza a biblioteca string.h

	4.5 - gerar_Img.h

		* Arquivo ".h" de gerar_Img.c

	4.6 - tipos.h

		* Criado para definir novos tipos de variáveis

5 - COMPILANDO O PROJETO

	gcc main.c funcoes.c gerar_Img.c -o <nome_do_arquivo.exe>

