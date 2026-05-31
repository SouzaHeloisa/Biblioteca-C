#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

typedef struct livro{
    int codlivro;
    char titulo[50];
    char autor[50];
    int anopublicacao;
    int quantidade;
    struct livro *prox;
} Livro;

typedef struct emprestimo{
    char nomealuno[50];
    int matricula;
    char titulolivro[50];
    char dataemprestimo[11];
    char dataentrega[11];
    struct emprestimo *prox;
}Emprestimo;

void cadastrarLivro(Livro **livros, int *numLivros){
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    if (novoLivro == NULL) {
        printf("Erro ao alocar memória para o novo livro.\n");
        return;
    }
    printf("Digite o código do livro: ");
    scanf("%d", &novoLivro->codlivro); 
    printf("Digite o título do livro: ");
    scanf(" %[^\n]", novoLivro->titulo);
    printf("Digite o autor do livro: ");
    scanf(" %[^\n]", novoLivro->autor);
    printf("Digite o ano de publicação do livro: ");
    scanf("%d", &novoLivro->anopublicacao);
    printf("Digite a quantidade de exemplares disponíveis: ");
    scanf("%d", &novoLivro->quantidade);
    novoLivro->prox = *livros; 
    /*O novo livro aponta para o início da lista, 
    escolhemos o início da lista para facilitar a inserção e ter o melhor desempenho O(1), 
    já que não precisamos percorrer a lista para encontrar o final*/
    *livros = novoLivro; // O início da lista agora é o novo livro
    (*numLivros)++; // Incrementa o número de livros cadastrados

    salvarlivros(*livros); // Salva os livros no arquivo após o cadastro
}

void emprestarLivro(Livro *livros,Emprestimo **emprestimos,int *numEmprestimos){

}

void devolverLivro(Livro *livros,Emprestimo **emprestimos,int *numEmprestimos){

}

void listarLivros(Livro *livros){

}

void buscarLivro(Livro *livros, char *titulo){

}

void listarEmprestimos(Emprestimo *emprestimos){

}

void excluirLivro(Livro **livros, int *numLivros, char *titulo){

}

void salvarlivros(Livro *livros){
    FILE *arquivo = fopen("livros.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os livros.\n");
        return;
    }
    Livro *atual = livros;
    while (atual != NULL) {
        fprintf(arquivo, "%d;%s;%s;%d;%d\n", atual->codlivro, atual->titulo, atual->autor, atual->anopublicacao, atual->quantidade);
        atual = atual->prox;
    }
    fclose(arquivo);
}


void salvaremprestimos(Emprestimo *emprestimos){
    FILE *arquivo = fopen("emprestimos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os empréstimos.\n");
        return;
    }
    Emprestimo *atual = emprestimos;
    while (atual != NULL) {
        fprintf(arquivo, "%s;%d;%s;%s;%s\n", atual->nomealuno, atual->matricula, atual->titulolivro, atual->dataemprestimo, atual->dataentrega);
        atual = atual->prox;
    }
    fclose(arquivo);
}

void carregarLivros(Livro **livros, int *numLivros)
{
    // Abre o arquivo para leitura
    FILE *arquivo = fopen("livros.txt", "r");

    // Se o arquivo não existir, inicia com lista vazia
    if (arquivo == NULL){
        *livros = NULL;
        *numLivros = 0;
        return;
    }

    // Garante que a lista comece vazia
    *livros = NULL;
    *numLivros = 0;

    // Buffer para armazenar cada linha lida do arquivo
    char linha[200];

    // Lê uma linha por vez até o final do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        // Aloca memória para um novo nó da lista
        Livro *novoLivro = malloc(sizeof(Livro));

        // Verifica se a alocação foi bem-sucedida
        if (novoLivro == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            fclose(arquivo);
            return;
        }

        // Tenta extrair os 5 campos da linha
        int camposLidos = sscanf(linha,"%d;%49[^;];%49[^;];%d;%d",&novoLivro->codlivro,novoLivro->titulo,novoLivro->autor,&novoLivro->anopublicacao,&novoLivro->quantidade);

        // Se não conseguiu ler todos os campos, descarta o nó
        if (camposLidos != 5)
        {
            free(novoLivro);
            continue;
        }

        // O novo nó será inserido no início da lista
        novoLivro->prox = *livros;

        // Atualiza o início da lista
        *livros = novoLivro;

        // Incrementa a quantidade de livros carregados
        (*numLivros)++;
    }

    // Fecha o arquivo
    fclose(arquivo);
}

void carregarEmprestimos(Emprestimo **emprestimos, int *numEmprestimos)
{
    // Abre o arquivo para leitura
    FILE *arquivo = fopen("emprestimos.txt", "r");

    // Se o arquivo não existir, inicia com lista vazia
    if (arquivo == NULL){
        *emprestimos = NULL;
        *numEmprestimos = 0;
        return;
    }

    // Garante que a lista comece vazia
    *emprestimos = NULL;
    *numEmprestimos = 0;

    // Buffer para armazenar cada linha lida do arquivo
    char linha[200];

    // Lê uma linha por vez até o final do arquivo
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {
        // Aloca memória para um novo nó da lista
        Emprestimo *novoEmprestimo = malloc(sizeof(Emprestimo));

        // Verifica se a alocação foi bem-sucedida
        if (novoEmprestimo == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            fclose(arquivo);
            return;
        }

        // Tenta extrair os 5 campos da linha
        int camposLidos = sscanf(
            linha,
            "%49[^;];%d;%49[^;];%10[^;];%10s",
            novoEmprestimo->nomealuno,
            &novoEmprestimo->matricula,
            novoEmprestimo->titulolivro,
            novoEmprestimo->dataemprestimo,
            novoEmprestimo->dataentrega
        );

        // Se não conseguiu ler todos os campos, descarta o nó
        if (camposLidos != 5)
        {
            free(novoEmprestimo);
            continue;
        }

        // O novo nó será inserido no início da lista
        novoEmprestimo->prox = *emprestimos;

        // Atualiza o início da lista
        *emprestimos = novoEmprestimo;

        // Incrementa a quantidade de empréstimos carregados
        (*numEmprestimos)++;
    }

    // Fecha o arquivo
    fclose(arquivo);
}