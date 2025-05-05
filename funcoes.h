// declaração das funções
#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    char nome[30];
    int codigo;
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} itemCarrinho;

void infoProduto(Produto prod);
void menu();
void listarProdutos();
void cadastrarProdutos();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int* temNoCarrinho(int codigo);
void fecharPedido();
void carregarProdutos();     
void salvarProduto(Produto); 

#endif
