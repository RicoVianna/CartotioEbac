#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteda de aloca��o de espa�os na mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pelas strings


int registrar () //sequ�ncia para a fun��o "resitrar" (case 1)
{
	setlocale (LC_ALL, "portuguese"); //definindo o idioma para alocar as regras gramaticais do "BLOCO REGISTRAR"
	
	char cpf [15]; //in�cio de "definindo vari�veis"
	char arquivo [15]; 
	char prim_nome [30]; 
	char ult_nome [30]; 
	char nacionalidade [30];
	char cargo [30]; //fim de "definindo vari�veis"
	
	printf ("Digite o CPF que deseja registrar: "); //programa solicitando ao usuario informa��o para cadastro
	scanf ("%s", cpf); //salvando a resposta do usu�rio na vari�vel "CPF"
	
	strcpy (arquivo, cpf); //copiando o valor da vari�vel "cpf" para a vari�vel "arquivo"	
	FILE *file; //"chamando" o arquivo do sistema
	
	file = fopen (arquivo, "w"); //criando o arquivo
	fprintf (file, "CPF: "); //incluindo "CPF" antes da informa��o a ser digitada. para melhor entendimento da exibi��o
	fprintf (file, cpf); //salvando o valor da vari�vel "cpf" na vari�vel "arquivo"
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, ";\nNOME "); //incluindo a "PONTO E V�RGULA" e "NOME" para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite o primeiro nome do membro que deseja registrar: "); //programa solicitando ao usu�rio informa��o para cadastro
	scanf ("%s", prim_nome); //salvando a resposta do usu�rio na vari�vel "PRIM_NOME"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, prim_nome); //salvando a vari�vel "prim_nome" no arquivo
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, ";\nULTIMO NOME:  "); //incluindo "PONTO E V�RGULA" e "ULT-NOME" antes da informa��o a ser digitada, para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite o �ltimo nome do membro que deseja registrar: "); //probrama solicitando ao usu�rio informa��es para cadastro
	scanf ("%s", ult_nome); //salvando a resposa do usu�rio na vari�vel "ULT_NOME"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, ult_nome); //incluindo a vari�vel "ult_nome" no arquivo
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, ";\nNACIONALIDADE: "); //incluindo "PONTO E V�RGULA" e "NACIONALIDADE" antes da informa��o a ser digitada, para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite a nacionalidade do membro que deseja registrar: "); //programa solicitando ao usu�rio informa��es para cadastro
	scanf ("%s", nacionalidade); //salvando a resposta do usu�rio na vari�vel "NACIONALIDADE"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, nacionalidade); //incluindo a vari�vel "nacionalidade" no arquivo
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); // abrindo o arquivo para atualiza��o
	fprintf (file, ";\nCARGO "); //incluindo "PONTO E V�RGULA" e "CARGO" antes da informa��o a ser digitada para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite o cargo do novo membro: "); //programa solicitando ao usu�rio informa��es para cadastro
	scanf ("%s", cargo); //salvando a resposta do usu�rio na vari�vel "CARGO"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualiza��o
	fprintf (file, cargo); //incluindo a vari�vel "cargo" no arquivo
	fprintf (file, "."); //incluindo "ponto final" ap�s a exibi��o do cargo
	fclose (file); //fechando o arquivo
	
	system ("pause"); //pausa a tela para a exibi��o das informa��es
	
}


int consultar() //sequ�ncia para a fun��o "consultar" (case 2)
{
	setlocale (LC_ALL, "portuguese"); //definindo o idioma para alocar as regras gramaticais do "BLOCO CONSULTAR" 
	
	char cpf [15]; //definindo as vari�veis
	char conteudo [200]; //definindo as vari�veis
		
	printf ("Digite o CPF que deseja consultar: \n"); //programa solicitando ao usu�rio informa��es para cadastro
	scanf ("%s", cpf); //resposta do usu�rio para a solicita��o acima
	
	FILE *file; //criando o arquivo
	file = fopen (cpf, "r"); //abrindo e lendo o arquivo "cpf"
	
	if (file==NULL) //criando resposta para caso de usu�rio n�o identificado
	{
		printf ("\n\n\t##########################################\n\n"); //criando um ambiente para a exibi��o da msg
		printf ("\t ARQUIVO N�O LOCALIZADO, TENTE NOVAMENTE!"); //resposta para o caso acima	
	}
	
	if (file != NULL)
	{
		printf ("\n\n\t##########################################\n\n"); //criando um ambiente para a exibi��o da msg
		printf ("\t  SEGUE ABAIXO O CADASTRO SOLICITADO: \n\n"); //resposta para o caso acima
	}
	
	while (fgets(conteudo, 200, file) != NULL) //criando sequ�ncia para quando a informa��o (cpf) estiver correto
	{
		printf ("\t\t%s", conteudo); //exibindo o conte�do do cadastro
	}
	
	printf ("\n\n\t##########################################\n\n\n"); //criando um ambiente para a exibi��o da msg
	system ("pause"); //pausando a tela para a exibi��o do cadastro

}


int deletar() //sequ�ncia para o fun��o "deletar" (case 3)
{
	char cpf[15]; //declarando a vari�vel "CPF" que ser� usada para localizar o arquivo que deve ser localizado
	
	printf ("CPF: "); //instru��o para que o usu�rio digite o CPF que ser� deletado
	scanf ("%s", cpf); //salva a resposta do usu�rio na vari�vel "CPF"
	
	FILE *file; //localiza o arquivo da biblioteca para criar o arquivo do programa
	file = fopen(cpf, "r"); //le o arquivo referente ao CPF digitado
	fclose (file); //fecha o arquivo
	
	if (file == NULL) //chamada para avisar que o usu�rio nunca esteve no sistema
	{
		printf ("\n\t#######################\n\n"); //criando ambiente para exibi��o das respostas do prograa
		printf ("\t CADASTRO INEXISTENTE! \n\n"); //resposta do programa para casos em que o usu�rio n�o est� cadastrado
		printf ("\t#######################\n\n\n"); //criando ambiente para exibi��o das respostas do prograa
	}
	else //chamada para a avisar que o usu�rio foi devidamente deletado 
	{
		remove (cpf); //fun��o que remove o CPF solicitado do arquivo
		printf ("\n\t#####################################\n\n"); //criando ambiente para exibi��o das respostas do prograa
		printf ("\t O USU�RIO FOI DELETADO COM SUCESSO! \n\n"); //resposta do programa para avisar que o usu�rio foi removido
		printf ("\t#####################################\n\n\n"); //criando ambiente para exibi��o das respostas do prograa
	}
	system ("pause"); //pausa a tela para exibi��o das informa��es
	
}
	

int main () //fun��o principal do programa
{
	int opcao=0; //definindo as vari�veis
	int laco=1; //definindo as vari�veis
	
	for (laco=1;laco=1;) //criando o loop infinito
	{
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem por regi�o
		system ("cls"); //fechando a tela anterior para uma visualiza��o mais limpa
		
		printf ("#########################################\n"); //in�cio de "ambiente" de cabe�alho
		printf ("############# CART�RIO EBAC #############\n");
		printf ("#########################################\n\n\n"); //final de "ambiente" de cabe�alho
		printf ("Escolha a op��o desejada no menu: \n\n"); //chamada para o in�cio do menu
		printf ("\t1 - Para REGISTRAR: \n"); //in�cio do menu (escolhas do usu�rio)
		printf ("\t2 - Para CONSULTAR: \n");
		printf ("\t3 - Para DELETAR: \n"); 
		printf ("\t4 - Para SAIR: \n\n");
		printf ("Op��o: "); //resposta da escolha do usu�rio
		
		scanf ("%d", &opcao); // salva a resposta do usu�rio na vari�vel "op��o"
		system ("cls"); //fechando a tela anterior para uma visualiza��o mais limpa
		
		switch (opcao) //chamada sequ�nciia da op��o escolhida
		{
			case 1: //caso escolha a op��o 1 do menu
			registrar(); //chamada para a sequ�ncia do registro de nomes
			break; //fechando o "case 1"
			
			case 2: //caso escolha a op��o 2 do menu
			consultar(); //chamada para a sequ�cia da consulta de nomes
			break; //fechando o "case 2"
			
			case 3: //caso escolhaa op��o 3 do menu
			deletar(); //chamada para a sequ�ncia da exclus�o de nomes 
			break; //fechando o "caso 3"
			
			case 4:
			printf ("Voc� escolheu SAIR!\n");
			printf ("Obrigado por usar o sistema!\n\n");
			return 0;
			break;
			
			default: //caso o usu�rio digite algo diferente das op��es sugeridas no menu
			printf ("OP��O INV�LIDA!\n\n"); //mensagem exibida pelo programa avisando o erro
			system ("pause"); //pausando o programa para visualiza��o
			break; //fechando o "default"
		}
	}
}
