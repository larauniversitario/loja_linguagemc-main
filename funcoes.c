//funçãoes implementadas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"

static int contador_produto = 0;
static int contador_carrinho = 0;
<<<<<<< HEAD
static itemCarrinho* carrinho = NULL;
static Produto produtos[50];

void infoProduto(Produto prod){
    printf("Nome: %s\nCodigo:%d\nPreco: R$ %.2f\n", prod.nome, prod.codigo, prod.preco );

}
  
void carregarProdutos() {
    FILE *arq = fopen("produtos.txt", "r");

    if (arq == NULL) return;

    while (fscanf(arq, "%s %d %f", produtos[contador_produto].nome,
                  &produtos[contador_produto].codigo,
                  &produtos[contador_produto].preco) == 3) {
        contador_produto++;
    }

    fclose(arq);
}

void salvarProduto(Produto p){
    FILE *arq;
    arq= fopen("produtos.txt", "a");//adiciona igual a um append
    
    if (arq== NULL)return;

    fprintf(arq, "%s %d %.2f\n", p.nome, p.codigo, p.preco);
=======
static itemCarrinho carrinho[50];
static Produto produtos[50];

void infoProduto(Produto prod){
    printf("Nome: %s\n Codigo:%d\n Preco: R$ %.2f", prod.nome, prod.codigo, prod.preco );

}
  
void carregarProdutos(){
FILE *arq;
arq= fopen("projeto.txt", "r");//leitura do arquivo

if (arq== NULL)return;
while(fscanf(arq,"%s %d %f",produtos[contador_produto].nome,//Lê dados formatados de um arquivo
    &produtos[contador_produto].codigo,
    &produtos[contador_produto].preco) == 3);

    contador_produto ++;
fclose(arq);
}
void salvarProduto(Produto p){
    FILE *arq;
    arq= fopen("projeto.txt", "a");//adiciona igual a um append
    
    if (arq== NULL)return;
    fprintf(arq,"%s %d %.2f",p.nome,p.codigo,p.preco);//É usado para escrever dados formatados em um arquivo
>>>>>>> b4ea79fb9a584015834296c028aa8b3dac86d310
    
   fclose(arq);
}

void listarProdutos() {
    if (contador_produto > 0) {
        printf("LISTAGEM DOS PRODUTOS:\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produtos[i]);
<<<<<<< HEAD
            Sleep(1000);
        }
    } else {
        printf("Nenhum produto cadastrado.\n");
        Sleep(2000);
    }
}

void cadastrarProdutos() {
    Produto novo;
    printf("CADASTRO DE PRODUTOS\n");
    printf("--------------------\n");
    printf("Digite o nome do produto: ");
    getchar(); // limpa buffer
    fgets(novo.nome, 30, stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';

    printf("Digite o valor do produto: ");
    scanf("%f", &novo.preco);

    novo.codigo = (contador_produto + 1);
    produtos[contador_produto++] = novo;
    salvarProduto(novo);
    printf("O produto foi cadastrado!\n");

    Sleep(2000);
}

void comprarProduto() {
    if (contador_produto > 0) {
        printf("Informe o codigo do produto que deseja adicionar ao carrinho.\n");
        printf("========== Produtos Disponiveis ==========\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produtos[i]);
            printf("--------------------------\n");
            Sleep(1000);
        }

        int codigo;
        scanf("%d", &codigo);

        int tem_mercado = 0;

        for (int i = 0; i < contador_produto; i++) {
            if (produtos[i].codigo == codigo) {
                tem_mercado = 1;
                Produto p = pegarProdutoPorCodigo(codigo);

                if (contador_carrinho == 0) {
                    carrinho = malloc(sizeof(itemCarrinho));
                } else {
                    carrinho = realloc(carrinho, (contador_carrinho + 1) * sizeof(itemCarrinho));
                }

                int *retorno = temNoCarrinho(codigo);
                if (retorno[0] == 1) {
                    // produto já no carrinho: só aumenta a quantidade do índice certo
                    carrinho[retorno[1]].quantidade++;
                    printf("Aumentei a quantidade do produto %s já existente no carrinho.\n", p.nome);
                } else {
                    // produto novo no carrinho
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi adicionado ao carrinho.\n", p.nome);
                }

                Sleep(2000);
                return;
            }
        }

        if (!tem_mercado) {
            printf("Nao foi encontrado o produto com codigo %d.\n", codigo);
            Sleep(2000);
        }
    } else {
        printf("Ainda nao existem produtos para vender.\n");
        Sleep(2000);
    }
}

=======
            Sleep(2);
        }
        Sleep(2);
        menu();
    } else {
        printf("Nenhum produto cadastrado.\n");
        Sleep(2);
        menu();
    }
}

void cadastrarProdutodos(){//teste
    Produto novo;
    printf("CADASTRO DE PRODUTOS");
    printf("--------------------");
    printf("Digite o nome do produto:");
    fgets(novo.nome,30,stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0';    // remove o '\n'
    printf("Digite o valor do produto:");
    scanf("%f",&novo.preco);

    printf("o produto foi cadastrado!");
    
    novo.codigo=(contador_produto + 1);
    produtos[contador_produto++] = novo;
    salvarProduto(novo);
    
}
void comprarProduto(){
    if(contador_produto > 0){
        printf("Informe o código do produto que deseja adicionar ao carrinho.\n");
        printf("========== Produtos Disponíveis ==========\n");
        for(int i = 0; i < contador_produto; i++){
           infoProduto(produtos[i]);
           printf("--------------------------\n");
           Sleep(1000);
        }
        int codigo;
        scanf("%d", &codigo);
        getchar();

        int tem_mercado = 0;

        for(int i = 0; i < contador_produto; i++){
            if(produtos[i].codigo == codigo){
                tem_mercado = 1;

                Produto p = pegarProdutoPorCodigo(codigo);
                char nome_limpo[100];
                strcpy(nome_limpo, p.nome);
                nome_limpo[strcspn(nome_limpo, "\n")] = '\0';

                if(contador_carrinho > 0){
                    int * retorno = temNoCarrinho(codigo);
                    if (retorno[0] == 1){
                        carrinho[retorno[1]].quantidade++;

                        char nome_existente[100];
                        strcpy(nome_existente, carrinho[retorno[1]].produto.nome);
                        nome_existente[strcspn(nome_existente, "\n")] = '\0';

                        printf("Aumentei a quantidade do produto %s já existente no carrinho.\n", nome_existente);
                        
                    
                    } else {//adiciona o produto pela primeira vez no carrinho se ele ainda nao estiver
                        carrinho[contador_carrinho].produto = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O produto %s foi adicionado ao carrinho.\n", nome_limpo);

                    }
                } else {//adiciona o primeiro produto do carrinho
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi adicionado ao carrinho.\n", nome_limpo);
                    
                }
                Sleep(2000);
                menu();
                return;
            }
        }
        if(!tem_mercado){ //produto nao existente(cadastrado) no mercado
            printf("Não foi encontrado o produto com código %d.\n", codigo);
            Sleep(2000);
            menu();
        }
    } else {
        printf("Ainda não existem produtos para vender.\n");
        Sleep(2000);
        menu();
    }
}
>>>>>>> b4ea79fb9a584015834296c028aa8b3dac86d310
void visualizarCarrinho(){
    if(contador_carrinho > 0){
        printf("Produtos do carrinho:\n");
        printf("---------------------\n");
        for(int i = 0; i < contador_carrinho; i++){
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("---------------------\n");
            Sleep(1000);
        }
<<<<<<< HEAD
        Sleep(2000);
    }else{
        printf("Ainda nao temos produto no carrinho.\n");
        Sleep(2000);
=======
        sleep(2000);
        menu();
    }else{
        printf("Ainda não temos produto no carrinho.\n");
        Sleep(2000);
        menu();
>>>>>>> b4ea79fb9a584015834296c028aa8b3dac86d310
    }

}
void fecharPedido(){
<<<<<<< HEAD
    if(contador_carrinho > 0){
        float valorTotal = 0.0;
        printf("Produtos do Carrinho\n");
        for(int i = 0; i < contador_carrinho; i ++){
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade: %d\n", quantidade);
            Sleep(1000);
        }
        printf("O valor total da sua compra e R$ %.2f\n", valorTotal);
        contador_carrinho = 0;
        printf("Obrigada por sua compra!\n");
        Sleep(5000);
    }else{
        printf("Nao ha nenhum produto no seu carrinho ainda.\n");
        Sleep(3000);
    }
}
Produto pegarProdutoPorCodigo(int codigo){
    Produto p = {"", 0, 0.0};// valor padrao caso o prod n seja encontrado;
    for (int i = 0; i < contador_produto; i++){
        if(produtos[i].codigo == codigo){
            return  produtos[i];
        }
    }
        return p;
}
int * temNoCarrinho(int codigo){
    static int retorno[] = {0, 0};
    for(int i = 0; i < contador_carrinho; i++){
        if(carrinho[i].produto.codigo == codigo){
            retorno[0] = 1;
            retorno[1] = i;
            return retorno; // RETORNO IMEDIATO AO ENCONTRAR
        }      
    }
    retorno[0] = 0; // Não encontrou
    retorno[1] = -1;
    return retorno;
}

void menu(){
    int opcao;
    do{
        printf("--------MENU-------\n");
        printf("1-Cadastrar produto\n");
        printf("2-Listar produto\n");
        printf("3-Comprar produto\n");
        printf("4-visualizar carrinho\n");
        printf("5-Fechar pedido\n");
        printf("6-Sair do sistema\n");
        printf("Digite um numero:");
        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                cadastrarProdutos();
                break;
            case 2:
                listarProdutos();
                break;
            case 3:
                comprarProduto();
                break;
            case 4:
                visualizarCarrinho();
                break;
            case 5:
                fecharPedido();
                break;
            case 6:
                printf("Volte sempre!\n");
            Sleep(2000);
            exit(0);
        break;
            default:
                printf("Numero invalido!");
                Sleep(2000);
                break;
        }
    } while(opcao != 6);
=======

}
Produto pegarProdutoPorCodigo(int codigo){

}
int * temNoCarrinho(int codigo){

}

void menu(){
    printf("--------MENU-------\n");
    printf("1-Cadastrar produto\n");
    printf("2-Listar produto\n");
    printf("3-Comprar produto\n");
    printf("4-visualizar carrinho\n");
    printf("5-Fechar pedido\n");
    printf("6-Sair do sistema\n");

    int opcao;
    printf("Digite um numero:");
    scanf("%d",&opcao);

    switch (opcao)
    {
    case 1:
        cadastrarProdutodos();
        break;
     case 2:
        listarProdutos();
        break;
    case 3:
        comprarProduto();
        break;
    case 4:
        visualizarCarrinho();
        break;
    case 5:
        fecharPedido();
        break;
    case 6:
        printf("Volte sempre!\n");
        Sleep(2);
        exit(0);
        break;
    default:
        printf("Numero invalido!");
        Sleep(2);
        menu();
        break;
    }
>>>>>>> b4ea79fb9a584015834296c028aa8b3dac86d310
}

