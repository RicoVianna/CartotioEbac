#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteda de alocação de espaços na memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pelas strings


int registrar () //sequência para a função "resitrar" (case 1)
{
	setlocale (LC_ALL, "portuguese"); //definindo o idioma para alocar as regras gramaticais do "BLOCO REGISTRAR"
	
	char cpf [15]; //início de "definindo variáveis"
	char arquivo [15]; 
	char prim_nome [30]; 
	char ult_nome [30]; 
	char nacionalidade [30];
	char cargo [30]; //fim de "definindo variáveis"
	
	printf ("Digite o CPF que deseja registrar: "); //programa solicitando ao usuario informação para cadastro
	scanf ("%s", cpf); //salvando a resposta do usuário na variável "CPF"
	
	strcpy (arquivo, cpf); //copiando o valor da variável "cpf" para a variável "arquivo"	
	FILE *file; //"chamando" o arquivo do sistema
	
	file = fopen (arquivo, "w"); //criando o arquivo
	fprintf (file, "CPF: "); //incluindo "CPF" antes da informação a ser digitada. para melhor entendimento da exibição
	fprintf (file, cpf); //salvando o valor da variável "cpf" na variável "arquivo"
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, ";\nNOME "); //incluindo a "PONTO E VÍRGULA" e "NOME" para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite o primeiro nome do membro que deseja registrar: "); //programa solicitando ao usuário informação para cadastro
	scanf ("%s", prim_nome); //salvando a resposta do usuário na variável "PRIM_NOME"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, prim_nome); //salvando a variável "prim_nome" no arquivo
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, ";\nULTIMO NOME:  "); //incluindo "PONTO E VÍRGULA" e "ULT-NOME" antes da informação a ser digitada, para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite o último nome do membro que deseja registrar: "); //probrama solicitando ao usuário informações para cadastro
	scanf ("%s", ult_nome); //salvando a resposa do usuário na variável "ULT_NOME"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, ult_nome); //incluindo a variável "ult_nome" no arquivo
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, ";\nNACIONALIDADE: "); //incluindo "PONTO E VÍRGULA" e "NACIONALIDADE" antes da informação a ser digitada, para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite a nacionalidade do membro que deseja registrar: "); //programa solicitando ao usuário informações para cadastro
	scanf ("%s", nacionalidade); //salvando a resposta do usuário na variável "NACIONALIDADE"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, nacionalidade); //incluindo a variável "nacionalidade" no arquivo
	fclose (file); //fechando o arquivo
	
	file = fopen (arquivo, "a"); // abrindo o arquivo para atualização
	fprintf (file, ";\nCARGO "); //incluindo "PONTO E VÍRGULA" e "CARGO" antes da informação a ser digitada para melhor entendimento do texto
	fclose (file); //fechando o arquivo
	
	printf ("Digite o cargo do novo membro: "); //programa solicitando ao usuário informações para cadastro
	scanf ("%s", cargo); //salvando a resposta do usuário na variável "CARGO"
	
	file = fopen (arquivo, "a"); //abrindo o arquivo para atualização
	fprintf (file, cargo); //incluindo a variável "cargo" no arquivo
	fprintf (file, "."); //incluindo "ponto final" após a exibição do cargo
	fclose (file); //fechando o arquivo
	
	system ("pause"); //pausa a tela para a exibição das informações
	
}


int consultar() //sequència para a função "consultar" (case 2)
{
	setlocale (LC_ALL, "portuguese"); //definindo o idioma para alocar as regras gramaticais do "BLOCO CONSULTAR" 
	
	char cpf [15]; //definindo as variáveis
	char conteudo [200]; //definindo as variáveis
		
	printf ("Digite o CPF que deseja consultar: \n"); //programa solicitando ao usuário informações para cadastro
	scanf ("%s", cpf); //resposta do usuário para a solicitação acima
	
	FILE *file; //criando o arquivo
	file = fopen (cpf, "r"); //abrindo e lendo o arquivo "cpf"
	
	if (file==NULL) //criando resposta para caso de usuário não identificado
	{
		printf ("\n\n\t##########################################\n\n"); //criando um ambiente para a exibição da msg
		printf ("\t ARQUIVO NÃO LOCALIZADO, TENTE NOVAMENTE!"); //resposta para o caso acima	
	}
	
	if (file != NULL)
	{
		printf ("\n\n\t##########################################\n\n"); //criando um ambiente para a exibição da msg
		printf ("\t  SEGUE ABAIXO O CADASTRO SOLICITADO: \n\n"); //resposta para o caso acima
	}
	
	while (fgets(conteudo, 200, file) != NULL) //criando sequència para quando a informação (cpf) estiver correto
	{
		printf ("\t\t%s", conteudo); //exibindo o conteúdo do cadastro
	}
	
	printf ("\n\n\t##########################################\n\n\n"); //criando um ambiente para a exibição da msg
	system ("pause"); //pausando a tela para a exibição do cadastro

}


int deletar() //sequência para o função "deletar" (case 3)
{
	char cpf[15]; //declarando a variável "CPF" que será usada para localizar o arquivo que deve ser localizado
	
	printf ("CPF: "); //instrução para que o usuário digite o CPF que será deletado
	scanf ("%s", cpf); //salva a resposta do usuário na variável "CPF"
	
	FILE *file; //localiza o arquivo da biblioteca para criar o arquivo do programa
	file = fopen(cpf, "r"); //le o arquivo referente ao CPF digitado
	fclose (file); //fecha o arquivo
	
	if (file == NULL) //chamada para avisar que o usuário nunca esteve no sistema
	{
		printf ("\n\t#######################\n\n"); //criando ambiente para exibição das respostas do prograa
		printf ("\t CADASTRO INEXISTENTE! \n\n"); //resposta do programa para casos em que o usuário não está cadastrado
		printf ("\t#######################\n\n\n"); //criando ambiente para exibição das respostas do prograa
	}
	else //chamada para a avisar que o usuário foi devidamente deletado 
	{
		remove (cpf); //função que remove o CPF solicitado do arquivo
		printf ("\n\t#####################################\n\n"); //criando ambiente para exibição das respostas do prograa
		printf ("\t O USUÁRIO FOI DELETADO COM SUCESSO! \n\n"); //resposta do programa para avisar que o usuário foi removido
		printf ("\t#####################################\n\n\n"); //criando ambiente para exibição das respostas do prograa
	}
	system ("pause"); //pausa a tela para exibição das informações
	
}
	

int main () //função principal do programa
{
	int opcao=0; //definindo as variáveis
	int laco=1; //definindo as variáveis
	
	for (laco=1;laco=1;) //criando o loop infinito
	{
		setlocale(LC_ALL, "portuguese"); //definindo a linguagem por região
		system ("cls"); //fechando a tela anterior para uma visualização mais limpa
		
		printf ("#########################################\n"); //início de "ambiente" de cabeçalho
		printf ("############# CARTÓRIO EBAC #############\n");
		printf ("#########################################\n\n\n"); //final de "ambiente" de cabeçalho
		printf ("Escolha a opção desejada no menu: \n\n"); //chamada para o início do menu
		printf ("\t1 - Para REGISTRAR: \n"); //início do menu (escolhas do usuário)
		printf ("\t2 - Para CONSULTAR: \n");
		printf ("\t3 - Para DELETAR: \n"); 
		printf ("\t4 - Para SAIR: \n\n");
		printf ("Opção: "); //resposta da escolha do usuário
		
		scanf ("%d", &opcao); // salva a resposta do usuário na variável "opção"
		system ("cls"); //fechando a tela anterior para uma visualização mais limpa
		
		switch (opcao) //chamada sequênciia da opção escolhida
		{
			case 1: //caso escolha a opção 1 do menu
			registrar(); //chamada para a sequência do registro de nomes
			break; //fechando o "case 1"
			
			case 2: //caso escolha a opção 2 do menu
			consultar(); //chamada para a sequêcia da consulta de nomes
			break; //fechando o "case 2"
			
			case 3: //caso escolhaa opção 3 do menu
			deletar(); //chamada para a sequência da exclusão de nomes 
			break; //fechando o "caso 3"
			
			case 4:
			printf ("Você escolheu SAIR!\n");
			printf ("Obrigado por usar o sistema!\n\n");
			return 0;
			break;
			
			default: //caso o usuário digite algo diferente das opções sugeridas no menu
			printf ("OPÇÃO INVÁLIDA!\n\n"); //mensagem exibida pelo programa avisando o erro
			system ("pause"); //pausando o programa para visualização
			break; //fechando o "default"
		}
	}
}
