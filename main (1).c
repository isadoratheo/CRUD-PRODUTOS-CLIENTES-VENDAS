/******************************************************************************
Sistema de cadastro de clientes
SCG possibilita cadastro, listagem, pesquisa, edição e exclusão.
Código separado em 3 arquivos,  main, funções e structs.
CRUD completo.
Create em cadastro e dados iniciais.
Retrieve em listagem.
Update em pesquisa e edição.
Delete em deletar.
Desenvolvido pela aluna Isadora Theobaldo Moreira
*******************************************************************************/
#include <stdio.h>   //Bibiolteca Padrao
#include "Funcoes.h" //Chamando arquivo de funcoes

void main() {

	anexarDados(); //chamo a funcao que traz dados iniciais para o CRUD
	int opcao; //Variavel para armazenar a opcao inserida pelo usuario
	printf("\nSistema de Cadastro de Games - SCG %.1f\n", VERSAO);

	do { //Laço de repetição DO - WHILE
		opcao = menu(); 
		if(!opcao >=0 && !opcao <=11 ){ //Decisor IF, 
		}
		switch(opcao) { //switch para verificar o numero escolhido pelo usuario
		case 1:
			cadastrarGames(); //Cada caso chama uma funcao diferente
			break;
		case 2:
			listarGames();
			break;
		case 3:
			cadastrarClientes(); 
			break;
		case 4:
			listarClientes();
			break;
		case 5:
			cadastrarVendas();
			break;
		case 6:
		    listarVendas();
		    break;
		case 7:
		    pesquisarGames();
		    break;
		case 8:
		    editarGames();
		    break;
		case 9:
		    excluirGames();
		    break;
		case 10:
		    pesquisarClientes();
		    break;
		case 11:
		    editarClientes();
		    break;
		case 12:
		    excluirClientes();
		    break;
		case 0:
			printf("\nAgradecemos o Acesso ao SCG! \n\n");
			break;
		default:
			printf("\nOpcao indisponivel! \n");
		}
	} while(opcao != 0);//quando 0 for escolhido, programa encerra e imprime mensagem da linha 57
}
