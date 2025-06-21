typedef struct Game { //A struct jogos contem, nome, ano, preco e prateleira
    int prat; //Prateleira
    char nome[50];
    char ano[12];
    char preco[10];
    int ativo;
} d1;

typedef struct Cliente { //A struct cliente contem, nome, CPF e id
    int id;
    char nome[50];
    char CPF[20];
    int ativo;
} p1;

typedef struct Venda { //A struct venda contem id, produto e id do cliente
int id;
char produto[50];
char idVenda[20];
char clientevenda[50];
int ativo;
} r1;