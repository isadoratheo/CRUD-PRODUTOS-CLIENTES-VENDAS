#define TAMANHO 20 //Constante que define tamanho max da lista
#define VERSAO 1.7 //Constante para versão atual do SCG
#include <string.h> //Bibliotecas necessarias para as funções
#include <stdlib.h> //Biblioteca padrao
#include "Structs.h" //Chamando arquivo de structs

struct Game jogos[TAMANHO]; //variavel global jogos
struct Cliente cliente[TAMANHO]; //variável global clientes
struct Venda venda[TAMANHO]; //variável global vendas

int contadorGames = 0; //variavel global contador
int contadorCliente = 0; //variavel global contador
int contadorVenda = 0; //variável global contador

//funcao utilizada para ler Strings com espaço em C
void leString(char stringLiga[], int max) {
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
        letra = fgetc(stdin);
        if ((letra == '\n') && (i == 0)) {
            i = i - 1;
            continue;
        }
        if (letra == '\n') break;
        stringLiga[i] = letra;
    }
    stringLiga[i] = '\0';
}

//Create C
//Essa funcao fica responsavel por dar uma carga inicial de dados no sistema
void anexarDados(){ //dados presentes no sistema assim q ele é iniciado
    printf("Anexando Dados Base Do SCG...\n"); //mensagem bonitinha para display
    printf("Danos Anexados com Sucesso!\n");
    
    strcpy(jogos[0].nome, "God of War I"); //jogos com nome, ano, preco e prateleira
    strcpy(jogos[0].ano, "2005");
    strcpy(jogos[0].preco, "80,00");
    jogos[0].prat = 001;
    jogos[0].ativo = 1; //se ativo = 1, ele aparece, se ativo = 0, ele não aparece
    
    strcpy(jogos[1].nome, "God of War II");
    strcpy(jogos[1].ano, "2007");
    strcpy(jogos[1].preco, "90,00");
    jogos[1].prat = 001;
    jogos[1].ativo = 1;
    
    strcpy(jogos[2].nome, "God of War III");
    strcpy(jogos[2].ano, "2010");
    strcpy(jogos[2].preco, "70,00");
    jogos[2].prat = 001;
    jogos[2].ativo = 1;
    
    strcpy(jogos[3].nome, "God of War Ascension");
    strcpy(jogos[3].ano, "2013");
    strcpy(jogos[3].preco, "40,00");
    jogos[3].prat = 001;
    jogos[3].ativo = 1;
    
    strcpy(jogos[4].nome, "God of War");
    strcpy(jogos[4].ano, "2018");
    strcpy(jogos[4].preco, "180,00");
    jogos[4].prat = 001;
    jogos[4].ativo = 1;
    
    strcpy(jogos[5].nome, "God of War Ragnarok");
    strcpy(jogos[5].ano, "2022");
    strcpy(jogos[5].preco, "57,90");
    jogos[5].prat = 001;
    jogos[5].ativo = 1;
    
    contadorGames = 6; //marcando quantos games temos inicialmente na lista de informações iniciais
  
    strcpy(cliente[0].nome, "Eduardo G.T"); //Clientes com nome, CPF e ID
    strcpy(cliente[0].CPF, "123.456.789-00");
    cliente[0].id = 001;
    cliente[0].ativo = 1;
    
    contadorCliente = 1; 
    
    strcpy(venda[0].produto, "God of War"); //Vendas com produtos, ID da venda, cliente e id do cliente
    strcpy(venda[0].idVenda, "202201");
    strcpy(venda[0].clientevenda, "Roger Cleiton JR");
    venda[0].id = 001;
    venda[0].ativo = 1;
    
    contadorVenda = 1;

}

//Create C
//Essa funcao fica responsavel pela interface aonde o usuario cadastra novos jogos
void cadastrarGames(){ //função para adicionar novos jogos no sistema
    
    printf("\nDigite o nome do game: \n");
    leString(jogos[contadorGames].nome, 50);
    
    printf("\nDigite o ano de lançamento do game: \n");
    leString(jogos[contadorGames].ano, 12);
    
    printf("\nDigite o preco do game (xx,xx): \n");
    leString(jogos[contadorGames].preco, 20);
    
    printf("\nDigite o número da prateleira aonde será guardado: \n");
    fflush(stdin);
    scanf("%d", &jogos[contadorGames].prat);
    
    printf("\nEnviando seu game para o banco de dados do SCG...\n");  //mensagem bonitinha para display
    printf("O SCG recebeu seu game com sucesso!\n");

    jogos[contadorGames].ativo = 1; //todo game registrado sera ativo = 1, para aparecer na lista
    contadorGames++; //contador aumenta a cada game cadastrado
}

//Create C
//Essa funcao fica responsavel pela interface aonde o usuario cadastra novos clientes
void cadastrarClientes(){ //função para adicionar novos clientes no sistema
    
    printf("\nDigite o nome do cliente: \n");
    leString(cliente[contadorCliente].nome, 50);
    
    printf("\nDigite o CPF do cliente (xxx.xxx.xxx-xx): \n");
    leString(cliente[contadorCliente].CPF, 20);
    
    printf("\nEnviando os dados do cliente para o banco de dados do SCG...\n");  //mensagem bonitinha para display
    printf("O SCG recebeu seus dados com sucesso!\n");

    cliente[contadorCliente].ativo = 1; //todo cliente registrado sera ativo = 1, para aparecer na lista
    contadorCliente++; //contador aumenta a cada cliente cadastrado
}

//Create C
//Essa funcao fica responsavel pela interface aonde o usuario cadastra novas vendas
void cadastrarVendas(){ //função para adicionar novas vendas no sistema
    
    printf("\nDigite o nome do produto: \n");
    leString(venda[contadorVenda].produto, 50);
    
    printf("\nDigite o Id da venda(xxxxxx): \n");
    leString(venda[contadorVenda].idVenda, 20);
    
    printf("\nDigite o nome do cliente: \n");
    leString(venda[contadorVenda].clientevenda, 50);
    
    printf("\nDefina o ID do cliente: \n");
    fflush(stdin);
    scanf("%d", &venda[contadorVenda].id);
    
    printf("\nEnviando os dados da venda para o banco de dados do SCG...\n");  //mensagem bonitinha para display
    printf("O SCG recebeu seus dados com sucesso!\n");

    venda[contadorVenda].ativo = 1; //toda venda registrada sera ativo = 1, para aparecer na lista
    contadorVenda++; //contador aumenta a cada venda cadastrada
}

//Retrieve R
//Essa funcao fica responsavel pela interface aonde o usuario visualiza a listagem de games
void listarGames(){ //função para listar todos os games no sistema
    if(contadorGames == 0){
        printf("\nNenhum Game Registrado Até Então \n"); //caso não tenhamos game
    } else {
        printf("\n-------------------------------------------------------------------------------");
        printf("\n                              GAMES NO SISTEMA:               "); //caso tenhamos pelo menos 1 game
        printf("\n-------------------------------------------------------------------------------");
        printf("\n Etiqueta \t Prateleira \t Ano \t Preco \t\t Nome"); 
        printf("\n-------------------------------------------------------------------------------"); //desenhos do display
        for(int i = 0; i < contadorGames; i++){ //laço para percorrer o vetor jogos
            if(jogos[i].ativo == 0) {
                printf("\n                     GAME INDISPONIVEL               "); //se ativo = 0, jogo indisponivel
            } else {
                printf("\n %d \t\t %d \t\t %s \t R$%s \t %s", i+1, jogos[i].prat, jogos[i].ano, jogos[i].preco, jogos[i].nome); //se ativo = 1, monta-se o display
            }
            printf("\n-------------------------------------------------------------------------------");
        }
        printf("\n                       TOTAL DE GAMES NO SISTEMA: %d               ", contadorGames); //exibe o valor do contador de games
        printf("\n-------------------------------------------------------------------------------\n");
    }
    
}

//Retrieve R
//Essa funcao fica responsavel pela interface aonde o usuario visualiza a listagem de clientes
void listarClientes(){ //função para listar todos os clientes no sistema
    if(contadorCliente == 0){
        printf("\nNenhum cliente Registrado Até Então \n"); //caso não tenhamos cliente
    } else {
         printf("\n--------------------------------------------------------------------");
        printf("\n                     CLIENTES NO SISTEMA:               "); //caso tenhamos pelo menos 1 cliente
        printf("\n--------------------------------------------------------------------");
        printf("\n \t Id \t\t CPF \t\t\t Nome"); 
        printf("\n--------------------------------------------------------------------"); //desenhos do display
        for(int i = 0; i < contadorCliente; i++){
            if(cliente[i].ativo == 0) {
                printf("\n                     CLIENTE INDISPONIVEL               "); //se ativo = 0, cliente indisponivel
            } else {
                printf("\n \t %d \t\t %s \t %s", i+1, cliente[i].CPF, cliente[i].nome); //se ativo = 1, monta-se o display
            }
            printf("\n--------------------------------------------------------------------");
        }
        printf("\n                TOTAL DE CLIENTES NO SISTEMA: %d               ", contadorCliente); //exibe o valor do contador de games
        printf("\n--------------------------------------------------------------------\n");
    }
    
}

//Retrieve R
//Essa funcao fica responsavel pela interface aonde o usuario visualiza a listagem de vendas
void listarVendas(){ //função para listar todos as vendas no sistema
    if(contadorVenda == 0){
        printf("\nNenhuma Venda Registrado Até Então \n"); //caso não tenhamos Vendas
    } else {
         printf("\n--------------------------------------------------------------------------------------");
        printf("\n                                VENDAS NO SISTEMA:               "); //caso tenhamos pelo menos 1 venda
        printf("\n--------------------------------------------------------------------------------------");
        printf("\n Produto \t Preco \t Id.Venda \t Nome.Cliente \t\t ID.Cliente"); 
        printf("\n--------------------------------------------------------------------------------------"); //desenhos do display
        for(int i = 0; i < contadorVenda; i++){
            if(venda[i].ativo == 0) {
                printf("\n                                     VENDA INDISPONIVEL               "); //se ativo = 0, venda indisponivel
            } else {
                printf("\n %s \t %s \t %s \t %s \t %d", venda[i].produto, jogos[i].preco, venda[i].idVenda, venda[i].clientevenda, venda[i].id); //se ativo = 1, monta-se o display
            }
            printf("\n--------------------------------------------------------------------------------------");
        }
        printf("\n                            TOTAL DE VENDAS NO SISTEMA: %d               ", contadorVenda); //exibe o valor do contador de games
        printf("\n--------------------------------------------------------------------------------------\n");
    }
    
}

//Utilize U
void pesquisarGames(){ //função para executar pesquisa de um nome exato no sistema
    
    char nome[100];
    int encontrado = 0;
    
    printf("Digite o nome do game que deseja pesquisar: "); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s':\n", nome);
    printf("\n--------------------------------------------------------"); //texto bonitinho com display mostrando os resultados
    printf("\n Etiqueta \t Prateleira \t Ano \t Nome");
    printf("\n--------------------------------------------------------");
    
    for(int i = 0; i < contadorGames; i++){                                 //strcasecmp serve para não levar em conta maisculas e minusculas
        if(jogos[i].ativo == 1 && strcasecmp(jogos[i].nome, nome) == 0) { // se ativo = 0, jogo indisponivel, se ativo = 1, monta-se o display
            printf("\n %d \t\t %d \t\t %s \t %s", i, jogos[i].prat, jogos[i].ano, jogos[i].nome);
            encontrado = 1; //marcador de jogos encontrados
        }
    }
    
    if(!encontrado){
        printf("\nNenhum jogo encontrado com o nome '%s'.\n", nome); //se não houver incremento em encontrado, a pesquisa não encontrou nada
    }
    printf("\n--------------------------------------------------------\n");


}

//Utilize U
void pesquisarClientes(){ //função para executar pesquisa de um nome exato no sistema
    
    char nome[100];
    int encontrado = 0;
    
    printf("Digite o nome do cliente que deseja pesquisar: "); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s':\n", nome);
    printf("\n----------------------------------------------------------------------"); //texto bonitinho com display mostrando os resultados
    printf("\n Ordem \t\t Id \t\t CPF \t\t\t Nome"); 
    printf("\n----------------------------------------------------------------------");
    
    for(int i = 0; i < contadorCliente; i++){                                 //strcasecmp serve para não levar em conta maisculas e minusculas
        if(cliente[i].ativo == 1 && strcasecmp(cliente[i].nome, nome) == 0) { // se ativo = 0, jogo indisponivel, se ativo = 1, monta-se o display
            printf("\n %d \t\t %d \t\t %s \t %s", i, cliente[i].id, cliente[i].CPF, cliente[i].nome);
            encontrado = 1; //marcador de clientes encontrados
        }
    }
    
    if(!encontrado){
        printf("\nNenhum cliente encontrado com o nome '%s'.\n", nome); //se não houver incremento em encontrado, a pesquisa não encontrou nada
    }
    printf("\n----------------------------------------------------------------------\n");


}

//Utilize U
int editarGames(){ //função para editar os valores individuais de cada game
    
    char nome[100];
    int encontrado = 0;
    
    printf("\nDigite a seguir o nome do jogo que deseja editar: \n"); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s':\n",nome);
    printf("\n--------------------------------------------------------");
    printf("\n Etiqueta \t Prateleira \t Ano \t Nome");
    printf("\n--------------------------------------------------------");
    
    for(int i = 0; i < contadorGames; i++){
        if(jogos[i].ativo == 1 && strcasecmp(jogos[i].nome, nome) == 0){ //exatamente o mesmo sistema de pesquisa
            printf("\n %d \t\t %d \t\t %s \t %s", i + 1 , jogos[i].prat, jogos[i].ano, jogos[i].nome);
            encontrado = 1;
            printf("\n--------------------------------------------------------\n");
            
            printf("\nDigite um novo nome para este jogo: ");//ao achar o game, o usuario pode alterar suas informações
            scanf(" %[^\n]%*c", jogos[i].nome);
            printf("\nDigite o novo ano para este jogo: ");
            scanf("%s", jogos[i].ano);
            printf("\nDigite a nova prateleira para este jogo: ");
            scanf("%d", &jogos[i].prat);
            printf("\nEnviando seu game para o banco de dados do SCG...\n");  //mensagem bonitinha para display
            printf("O SCG recebeu seu game com sucesso!\n");
            return 0 ;
        }
        
    }
    if(!encontrado){
            printf("\nNenhum jogo com este nome encontrado!!!");
        }
        printf("\n--------------------------------------------------------");

}

//Utilize U
int editarClientes(){ //função para editar os valores individuais de cada cliente
    
    char nome[100];
    int encontrado = 0;
    
    printf("\nDigite a seguir o nome do cliente que deseja editar: \n"); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s':\n",nome);
    printf("\n----------------------------------------------------------------------");
   printf("\n Ordem \t\t Id \t\t CPF \t\t\t Nome"); 
    printf("\n----------------------------------------------------------------------");
    
    for(int i = 0; i < contadorCliente; i++){
        if(cliente[i].ativo == 1 && strcasecmp(cliente[i].nome, nome) == 0){ //exatamente o mesmo sistema de pesquisa
            printf("\n %d \t\t %d \t\t %s \t %s", i + 1 , cliente[i].id, cliente[i].CPF, cliente[i].nome);
            encontrado = 1;
            printf("\n----------------------------------------------------------------------\n");
            
            printf("\nDigite um novo nome para este cliente: ");//ao achar o cliente, o usuario pode alterar suas informações
            scanf(" %[^\n]%*c", cliente[i].nome);
            printf("\nDigite o novo CPF para este cliente: ");
            scanf("%s", cliente[i].CPF);
            printf("\nDigite o nome id para este cliente: ");
            scanf("%d", &cliente[i].id);
            printf("\nEnviando suas alterações para o banco de dados do SCG...\n");  //mensagem bonitinha para display
            printf("O SCG recebeu seu cliente com sucesso!\n");
            return 0 ;
        }
        
    }
    if(!encontrado){
            printf("\nNenhum cliente com este nome encontrado!!!");
        }
        printf("\n--------------------------------------------------------");

}

//Delete D
void excluirGames(){ // função para excluir games do sistema
   
    char nome[100];
    int encontrado = 0;
    
    printf("\nDigite o nome do game que deseja excluir: "); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s': \n", nome);
    printf("\n--------------------------------------------------------");
    printf("\n Etiqueta \t Prateleira \t Ano \t Nome");
    printf("\n--------------------------------------------------------");
    
    for(int i = 0; i < contadorGames; i++){
        if(jogos[i].ativo == 1 && strcasecmp(jogos[i].nome, nome) == 0) { //exatamente o mesmo sistema de pesquisa, porém caso encontre o game, ele tera seu ativo = 0
            printf("\n--------------------Jogo excluido-----------------------");
            jogos[i].ativo = 0;
            encontrado = 1;
        }
    }
    if(!encontrado){
        printf("\nNenhum jogo foi encontrado com este nome");
    } 
    printf("\n--------------------------------------------------------\n");
}

//Delete D
void excluirClientes(){ // função para excluir clientes do sistema
   
    char nome[100];
    int encontrado = 0;
    
    printf("\nDigite o nome do cliente que deseja excluir: "); //aqui o usuario digite o nome que busca
    scanf(" %[^\n]%*c",nome); //A parte %[^\n]%*c serve para poder ler um linha inteira
    
    printf("\nResultado da pesquisa para '%s': \n", nome);
    printf("\n----------------------------------------------------------------------");
    printf("\n Ordem \t\t Id \t\t CPF \t\t\t Nome"); 
    printf("\n-----------------------------------------------------------------------");
    
    for(int i = 0; i < contadorCliente; i++){
        if(cliente[i].ativo == 1 && strcasecmp(cliente[i].nome, nome) == 0) { //exatamente o mesmo sistema de pesquisa, porém caso encontre o cliente, ele tera seu ativo = 0
            printf("\n--------------------Cliente excluido-----------------------");
            cliente[i].ativo = 0;
            encontrado = 1;
        }
    }
    if(!encontrado){
        printf("\nNenhum cliente foi encontrado com este nome");
    } 
    printf("\n----------------------------------------------------------------------\n");
}

int menu(){ //função com o display do menu, que aparece assim que executamos o código
    int opcao;
    
    printf("\nBem-vindo, o que deseja fazer?: \n");
    printf("1 - Cadastrar Games\n");
    printf("2 - Listar Games\n");
    printf("3 - Cadastrar Clientes\n"); 
    printf("4 - Listar Clientes\n"); 
    printf("5 - Cadastrar Vendas\n");
    printf("6 - Listar Vendas\n");
    printf("7 - Pesquisar Games\n");
    printf("8 - Editar Games\n");
    printf("9 - Excluir Games\n");
    printf("10- Pesquisar Clientes\n");
    printf("11- Editar Clientes\n");
    printf("12- Excluir Clientes\n");
    printf("0 - Sair do sistema\n");
    printf("Favor Insira um Número --> ");
    scanf("%d", &opcao);
    
    return opcao;
}
