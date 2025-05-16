//funçãoes implementadas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include "funcoes.h"

static int contador_produto = 0;
static int contador_carrinho = 0;
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
    
   fclose(arq);
}

void listarProdutos() {
    if (contador_produto > 0) {
        printf("LISTAGEM DOS PRODUTOS:\n");
        for (int i = 0; i < contador_produto; i++) {
            infoProduto(produtos[i]);
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
        printf("Informe o código do produto que deseja adicionar ao carrinho.\n");
        printf("========== Produtos Disponíveis ==========\n");
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

                int * retorno = temNoCarrinho(codigo);
                if (retorno[0] == 1) {
                    carrinho[retorno[1]].quantidade++;
                    printf("Aumentei a quantidade do produto %s já existente no carrinho.\n", p.nome);
                } else {
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
            printf("Não foi encontrado o produto com código %d.\n", codigo);
            Sleep(2000);
        }
    } else {
        printf("Ainda não existem produtos para vender.\n");
        Sleep(2000);
    }
}
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
        Sleep(2000);
    }else{
        printf("Ainda não temos produto no carrinho.\n");
        Sleep(2000);
    }

}
void fecharPedido(){
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
        }      
    }
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
}

