#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emprestimo.h"
#include "livro.h"


void emprestarLivro(Livro *livros, Emprestimo **emprestimos)
{
    if (livros == NULL)
    {
        printf("\nNenhum livro cadastrado. \n");
        return;
    } // Verifica se a lista de livros está vazia e exibe uma mensagem caso esteja
    char titulo[50];
    printf("\nDigite o título do livro que deseja emprestar: ");
    scanf(" %[^\n]", titulo);
    Livro *atual = livros;
    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        { // Compara o título do livro atual com o título buscado usando strcmp. Se forem iguais, strcmp retorna 0.
            if (atual->quantidade > 0)
            {
                atual->quantidade--; // Decrementa a quantidade disponível do livro
                Emprestimo *novoEmprestimo = (Emprestimo *)malloc(sizeof(Emprestimo));
                if (novoEmprestimo == NULL)
                {
                    printf("\nErro ao alocar memória para o novo empréstimo.\n");
                    return;
                }
                printf("\nDigite o nome do aluno: ");
                scanf(" %[^\n]", novoEmprestimo->nomealuno);
                printf("Digite a matrícula do aluno: ");
                scanf("%d", &novoEmprestimo->matricula);
                strcpy(novoEmprestimo->titulolivro, atual->titulo); // Copia o título do livro para o empréstimo
                printf("Digite a data de empréstimo (dd/mm/aaaa): ");
                scanf(" %[^\n]", novoEmprestimo->dataemprestimo);
                printf("Digite a data de entrega (dd/mm/aaaa): ");
                scanf(" %[^\n]", novoEmprestimo->dataentrega);
                novoEmprestimo->prox = *emprestimos; // O novo empréstimo aponta para o início da lista de empréstimos
                *emprestimos = novoEmprestimo;       // O início da lista de empréstimos agora é o novo empréstimo
                salvarlivros(livros);                // Salva os livros no arquivo após o empréstimo
                salvaremprestimos(*emprestimos);     // Salva os empréstimos no arquivo após o cadastro do novo empréstimo
                printf("\nLivro emprestado com sucesso.\n");
            }
            else
            {
                printf("\nDesculpe, não há exemplares disponíveis deste livro.\n");
            }
            return; // Encerra a função após encontrar o livro
        }
        atual = atual->prox; // Move para o próximo livro na lista
    }
    printf("\nLivro não encontrado.\n"); // Se o loop terminar sem encontrar o livro, exibe uma mensagem indicando que o livro não foi encontrado
}

void devolverLivro(Livro *livros, Emprestimo **emprestimos)
{
    if (*emprestimos == NULL)
    {
        printf("\nNenhum empréstimo registrado. \n");
        return;
    } // Verifica se a lista de empréstimos está vazia e exibe uma mensagem caso esteja
    char titulo[50];
    printf("\nDigite o título do livro que deseja devolver: ");
    scanf(" %[^\n]", titulo);
    Emprestimo *atual = *emprestimos;
    Emprestimo *anterior = NULL;
    while (atual != NULL)
    {
        if (strcmp(atual->titulolivro, titulo) == 0)
        { // Compara o título do livro emprestado com o título do livro a ser devolvido usando strcmp. Se forem iguais, strcmp retorna 0.
            if (anterior == NULL)
            {
                *emprestimos = atual->prox; // Se o empréstimo a ser removido for o primeiro da lista, atualiza o início da lista para o próximo empréstimo
            }
            else
            {
                anterior->prox = atual->prox; // Caso contrário, ajusta o ponteiro do empréstimo anterior para pular o empréstimo a ser removido
            }
            free(atual); // Libera a memória alocada para o empréstimo removido
            Livro *livroAtual = livros;
            while (livroAtual != NULL)
            {
                if (strcmp(livroAtual->titulo, titulo) == 0)
                {                             // Compara o título do livro atual com o título do livro a ser devolvido usando strcmp. Se forem iguais, strcmp retorna 0.
                    livroAtual->quantidade++; // Incrementa a quantidade disponível do livro
                    break;                    // Encerra o loop após encontrar o livro
                }
                livroAtual = livroAtual->prox; // Move para o próximo livro na lista
            }
            salvarlivros(livros);            // Salva os livros no arquivo após a devolução
            salvaremprestimos(*emprestimos); // Salva os empréstimos no arquivo após a remoção do empréstimo
            printf("\nLivro devolvido com sucesso.\n");
            return; // Encerra a função após processar a devolução
        }
        anterior = atual;    // Atualiza o ponteiro do empréstimo anterior para o empréstimo atual
        atual = atual->prox; // Move para o próximo empréstimo na lista
    }
    printf("\nEmpréstimo não encontrado para o livro especificado.\n"); // Se o loop terminar sem encontrar o empréstimo, exibe uma mensagem indicando que o empréstimo não foi encontrado
}

void listarEmprestimos(Emprestimo *emprestimos)
{
    if (emprestimos == NULL)
    {
        printf("\nNenhum empréstimo registrado. \n");
        return;
    } // Verifica se a lista de empréstimos está vazia e exibe uma mensagem caso esteja
    Emprestimo *atual = emprestimos;
    printf("\nLista de Empréstimos:\n");
    while (atual != NULL)
    {
        printf("Nome do Aluno: %s\n", atual->nomealuno);
        printf("Matrícula: %d\n", atual->matricula);
        printf("Título do Livro: %s\n", atual->titulolivro);
        printf("Data de Empréstimo: %s\n", atual->dataemprestimo);
        printf("Data de Entrega: %s\n", atual->dataentrega);
        printf("-------------------------\n");
        atual = atual->prox;
    } // Percorre a lista de empréstimos e exibe as informações de cada empréstimo até o final da lista (quando atual for NULL)
}

void salvaremprestimos(Emprestimo *emprestimos)
{
    FILE *arquivo = fopen("emprestimos.txt", "w");
    if (arquivo == NULL)
    {
        printf("\nErro ao abrir o arquivo para salvar os empréstimos.\n");
        return;
    }
    Emprestimo *atual = emprestimos;
    while (atual != NULL)
    {
        fprintf(arquivo, "%s;%d;%s;%s;%s\n", atual->nomealuno, atual->matricula, atual->titulolivro, atual->dataemprestimo, atual->dataentrega);
        atual = atual->prox;
    }
    fclose(arquivo);
}

void carregarEmprestimos(Emprestimo **emprestimos)
{
    // Abre o arquivo para leitura
    FILE *arquivo = fopen("emprestimos.txt", "r");

    // Se o arquivo não existir, inicia com lista vazia
    if (arquivo == NULL)
    {
        *emprestimos = NULL;
        return;
    }

    // Garante que a lista comece vazia
    *emprestimos = NULL;

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
            novoEmprestimo->dataentrega);

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
    }

    // Fecha o arquivo
    fclose(arquivo);
}