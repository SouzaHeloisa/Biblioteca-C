#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"


void cadastrarLivro(Livro **livros){
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    if (novoLivro == NULL)
    {
        printf("\nErro ao alocar memória para o novo livro.\n");
        return;
    }
    printf("\nCadastro de Livro:\n");
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

    salvarlivros(*livros); // Salva os livros no arquivo após o cadastro
}

void listarLivros(Livro *livros){
    if (livros == NULL)
    {
        printf("\nNenhum livro cadastrado. \n");
        return;
    } // Verifica se a lista de livros está vazia e exibe uma mensagem caso esteja
    Livro *atual = livros;
    printf("\nLista de Livros:\n");
    while (atual != NULL)
    {
        printf("Código: %d\n", atual->codlivro);
        printf("Título: %s\n", atual->titulo);
        printf("Autor: %s\n", atual->autor);
        printf("Ano de Publicação: %d\n", atual->anopublicacao);
        printf("Quantidade Disponível: %d\n", atual->quantidade);
        printf("-------------------------\n");
        atual = atual->prox;
    } // Percorre a lista de livros e exibe as informações de cada livro até o final da lista (quando atual for NULL)
}

void buscarLivro(Livro *livros, char *titulo){
    if (livros == NULL)
    {
        printf("\nNenhum livro cadastrado. \n");
        return;
    } // Verifica se a lista de livros está vazia e exibe uma mensagem caso esteja
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        { // Compara o título do livro atual com o título buscado usando strcmp. Se forem iguais, strcmp retorna 0.
            printf("\nLivro encontrado:\n");
            printf("Código: %d\n", atual->codlivro);
            printf("Título: %s\n", atual->titulo);
            printf("Autor: %s\n", atual->autor);
            printf("Ano de Publicação: %d\n", atual->anopublicacao);
            printf("Quantidade Disponível: %d\n", atual->quantidade);
            return; // Encerra a função após encontrar o livro
        }
        atual = atual->prox; // Move para o próximo livro na lista
    }
    printf("\nLivro não encontrado.\n"); // Se o loop terminar sem encontrar o livro, exibe uma mensagem indicando que o livro não foi encontrado
}

void excluirLivro(Livro **livros, char *titulo){
    if (*livros == NULL)
    {
        printf("\nNenhum livro cadastrado. \n");
        return;
    } // Verifica se a lista de livros está vazia e exibe uma mensagem caso esteja
    Livro *atual = *livros;
    Livro *anterior = NULL;
    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        { // Compara o título do livro atual com o título a ser excluído usando strcmp. Se forem iguais, strcmp retorna 0.
            if (anterior == NULL)
            {
                *livros = atual->prox; // Se o livro a ser excluído for o primeiro da lista, atualiza o início da lista para o próximo livro
            }
            else
            {
                anterior->prox = atual->prox; // Caso contrário, ajusta o ponteiro do livro anterior para pular o livro a ser excluído
            }
            free(atual);           // Libera a memória alocada para o livro excluído
            salvarlivros(*livros); // Salva os livros no arquivo após a exclusão
            printf("\nLivro excluído com sucesso.\n");
            return; // Encerra a função após excluir o livro
        }
        anterior = atual;    // Atualiza o ponteiro do livro anterior para o livro atual
        atual = atual->prox; // Move para o próximo livro na lista
    }
    printf("\nLivro não encontrado.\n"); // Se o loop terminar sem encontrar o livro, exibe uma mensagem indicando que o livro não foi encontrado
}

void salvarlivros(Livro *livros){
    FILE *arquivo = fopen("livros.txt", "w"); // Abre o arquivo "livros.txt" para escrita. Se o arquivo não existir, ele será criado. Se já existir, seu conteúdo será sobrescrito.
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo para salvar os livros.\n");
        return;
    }
    Livro *atual = livros;
    while (atual != NULL)
    {
        fprintf(arquivo, "%d;%s;%s;%d;%d\n", atual->codlivro, atual->titulo, atual->autor, atual->anopublicacao, atual->quantidade);
        atual = atual->prox;
    } // Percorre a lista de livros e escreve as informações de cada livro no arquivo, separando os campos por ponto e vírgula (;). O formato é: código; título; autor; ano de publicação; quantidade disponível.
    fclose(arquivo);
}

void carregarLivros(Livro **livros)
{
    // Abre o arquivo para leitura
    FILE *arquivo = fopen("livros.txt", "r"); // Abre o arquivo "livros.txt" para leitura. Se o arquivo não existir, a função fopen retornará NULL.

    // Se o arquivo não existir, inicia com lista vazia
    if (arquivo == NULL)
    {
        *livros = NULL;
        return;
    } // Se o arquivo não puder ser aberto, a função exibe uma mensagem de erro, inicializa a lista de livros como vazia e retorna.

    // Garante que a lista comece vazia
    *livros = NULL;

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
        int camposLidos = sscanf(linha, "%d;%49[^;];%49[^;];%d;%d", &novoLivro->codlivro, novoLivro->titulo, novoLivro->autor, &novoLivro->anopublicacao, &novoLivro->quantidade);

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
    }

    // Fecha o arquivo
    fclose(arquivo);
}
