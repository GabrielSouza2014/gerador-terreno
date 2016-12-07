© copyright  2016 - Gabriel Araújo de Souza
 - Todos os direitos reservados - <gabriel_feg@hotmail.com>

*Produzido para a disciplina de PTP-2016.2 do IMD*
*Autor: Gabriel Araújo de Souza*
*Matrícula: 2016042088*
*Email: gabriel_feg@hotmail.com*


____________________________________________________________

1 - O QUE FOI FEITO

	*Gerador de Contorno aleatório da montanha
	*Recebimento de parâmetros pelo usuário (tamanho da imagem,
	 fator deslocamento e nome do arquivo gerado), além da criação
	 de um Default caso não seja digitado nada.
	*Gerador de efeitos graficos 
		-> Gerador de estrelas aleatório;
		-> Aplicador de Gradiente;
		-> Colorir Céu, e montanhas;
		-> Gerador de Montanha Extra (para efeito de cadeias rochosas);
	*Criação de um novo tipo de dado para a matriz imagem
	*criação de um enum para os modulos do cenário
	*Gerador de Imagem *.ppm utilizando arquivos
	*Modularização do projeto


2 - O QUE NÃO FOI FEITO

	*Verificar se o tamanho que o usuário digitou é uma potência de 2 + 1

3 - O QUE FARIA DIFERENTE

	* A partir dos aprendizados obtidos o que se faria diferente seria 
	uma melhor uso de cores para os elementos do cenário e a criação de 
	um efito mais realístico para as montanhas (pedras, arvores, etc). 
	A criação de um gerador de terrenos com altitudes se tornou mais claro
	com este projeto,e portanto,tentaria fazer esse novo modelo. O uso do
	Enum, a criação de novos tipos de dados e a manipulação de arquivos
	ficaram amis claras, e portanto usaria de forma mais eficiente em 
	novos projetos.
	

4 - BIBLIOTECAS USADAS

	* stdio.h
	* string.h
	* stdlib.h
	* time.h

5 - COMPILANDO O PROJETO

	gcc main.c funcoes.c gerar_Img.c -o <nome_do_arquivo.exe>

6 - EXECUTANDO O PROJETO

	./<nome_do_arquivo>
	-s -> tamanho da imagem quadrada
	-d -> deslocamento inicial
	-o -> nome do arquivo imagem que será gerado