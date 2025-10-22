#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Definição da struct Item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Vetor de itens com capacidade para 10 elementos
#define MAX_ITENS 10
Item mochila[MAX_ITENS];
int totalItens = 0;

// Protótipos de funções
void inserirItem();
void removerItem();
void listarItens();
void buscarItem();

// Função para inserir um novo item na mochila
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf(" Mochila cheia! Não é possível adicionar mais itens.\n");
        return;
    }

    Item novoItem;
    printf("Digite o nome do item: ");
    scanf(" %[^\n]", novoItem.nome);  // Captura string com espaços
    printf("Digite o tipo do item (arma, munição, cura, ferramenta): ");
    scanf(" %[^\n]", novoItem.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);

    mochila[totalItens] = novoItem;
    totalItens++;

    printf(" Item adicionado com sucesso!\n");
    listarItens();
}

// Função para remover um item pelo nome
void removerItem() {
    char nomeRemover[30];
    printf("Digite o nome do item a ser removido: ");
    scanf(" %[^\n]", nomeRemover);

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = 1;
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            printf("🗑️ Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf(" Item não encontrado na mochila.\n");
    }

    listarItens();
}

// Função para listar todos os itens da mochila
void listarItens() {
    printf("\n Itens na mochila:\n");
    if (totalItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    for (int i = 0; i < totalItens; i++) {
        printf("%d. Nome: %s | Tipo: %s | Quantidade: %d\n",
               i + 1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("\n");
}

// Função para buscar um item pelo nome
void buscarItem() {
    char nomeBusca[30];
    printf("Digite o nome do item para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
            printf("🔍 Item encontrado:\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf(" Item não encontrado.\n");
    }
}

// Função principal com menu interativo
int main() {
    int opcao;

    do {
        printf("=== Sistema de Inventário ===\n");
        printf("1. Inserir item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirItem();
                break;
            case 2:
                removerItem();
                break;
            case 3:
                listarItens();
                break;
            case 4:
                buscarItem();
                break;
            case 0:
                printf(" Saindo do sistema. Boa sorte no jogo!\n");
                break;
            default:
                printf(" Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
