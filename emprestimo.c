#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "validacao.h"
#include "emprestimo.h"

void emprestarLivro(Livro *livros, Emprestimo **emprestimos)
{
    if (livros == NULL)
    {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    char titulo[50];

    lerString("Digite o título do livro que deseja emprestar: ", titulo, sizeof(titulo));

    if (!validarDisponibilidade(livros, titulo))
    {
        printf("\nLivro não encontrado ou sem exemplares disponíveis.\n");
        return;
    }

    Livro *atual = livros;

    while (atual != NULL)
    {
        if (strcmp(atual->titulo, titulo) == 0)
        {
            Emprestimo *novoEmprestimo =
                (Emprestimo *)malloc(sizeof(Emprestimo));

            if (novoEmprestimo == NULL)
            {
                printf("\nErro ao alocar memória para o empréstimo.\n");
                return;
            }

            do
            {
                lerString(
                    "Digite o nome do aluno: ",
                    novoEmprestimo->nomealuno,
                    sizeof(novoEmprestimo->nomealuno));

                if (!validarNome(novoEmprestimo->nomealuno))
                {
                    printf("Nome inválido.\n");
                }

            } while (!validarNome(novoEmprestimo->nomealuno));
            do
            {
                novoEmprestimo->matricula =
                    lerInteiro("Digite a matrícula do aluno: ");

                if (!validarMatricula(novoEmprestimo->matricula))
                {
                    printf("Matrícula inválida.\n");
                }

            } while (!validarMatricula(novoEmprestimo->matricula));

            // Validação nova — vem logo após o bloco da matrícula
            if (!matriculaCompativel(*emprestimos, novoEmprestimo->matricula, novoEmprestimo->nomealuno))
            {
                printf("\nEsta matrícula já está cadastrada para outro aluno.\n");
                free(novoEmprestimo);
                return;
            }

            strcpy(novoEmprestimo->titulolivro,atual->titulo);

            if (emprestimoJaExiste(*emprestimos,novoEmprestimo->matricula,novoEmprestimo->titulolivro))
            {
                printf(
                    "\nEste aluno já possui este livro emprestado.\n");

                free(novoEmprestimo);
                return;
            }

            do
            {
                lerString(
                    "Digite a data de empréstimo (dd/mm/aaaa): ",
                    novoEmprestimo->dataemprestimo,
                    sizeof(novoEmprestimo->dataemprestimo));

                if (!validarDataEmprestimo(
                        novoEmprestimo->dataemprestimo))
                {
                    printf(
                        "Data de empréstimo inválida.\n");
                }

            } while (!validarDataEmprestimo(
                novoEmprestimo->dataemprestimo));

            do
            {
                lerString(
                    "Digite a data de entrega (dd/mm/aaaa): ",
                    novoEmprestimo->dataentrega,
                    sizeof(novoEmprestimo->dataentrega));

                if (!validarDataEntrega(
                        novoEmprestimo->dataemprestimo,
                        novoEmprestimo->dataentrega))
                {
                    printf(
                        "A data de entrega não pode ser anterior à data de empréstimo.\n");
                }

            } while (!validarDataEntrega(
                novoEmprestimo->dataemprestimo,
                novoEmprestimo->dataentrega));

            atual->quantidade--;

            novoEmprestimo->prox = *emprestimos;
            *emprestimos = novoEmprestimo;

            salvarlivros(livros);
            salvaremprestimos(*emprestimos);

            printf("\nLivro emprestado com sucesso.\n");
            return;
        }

        atual = atual->prox;
    }

    printf("\nLivro não encontrado.\n");
}

void devolverLivro(Livro *livros, Emprestimo **emprestimos)
{
    if (*emprestimos == NULL)
    {
        printf("\nNenhum empréstimo registrado.\n");
        return;
    }

    char titulo[50];
    int matricula;

    lerString(
        "Digite o título do livro: ",
        titulo,
        sizeof(titulo));

    do
    {
        matricula = lerInteiro(
            "Digite a matrícula do aluno: ");

        if (!validarMatricula(matricula))
        {
            printf("Matrícula inválida.\n");
        }

    } while (!validarMatricula(matricula));

    Emprestimo *atual = *emprestimos;
    Emprestimo *anterior = NULL;

    while (atual != NULL)
    {
        if (strcmp(atual->titulolivro, titulo) == 0 &&
            atual->matricula == matricula)
        {
            if (anterior == NULL)
            {
                *emprestimos = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            Livro *livroAtual = livros;

            while (livroAtual != NULL)
            {
                if (strcmp(livroAtual->titulo, titulo) == 0)
                {
                    livroAtual->quantidade++;
                    break;
                }

                livroAtual = livroAtual->prox;
            }

            free(atual);

            salvarlivros(livros);
            salvaremprestimos(*emprestimos);

            printf("\nLivro devolvido com sucesso.\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("\nNenhum empréstimo encontrado para essa matrícula e livro.\n");
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

int livroPossuiEmprestimos(Emprestimo *emprestimos, const char *titulo)
{
    Emprestimo *atual = emprestimos;

    while (atual != NULL)
    {
        if (strcmp(atual->titulolivro, titulo) == 0)
        {
            return 1;
        }

        atual = atual->prox;
    }

    return 0;
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
        fprintf(arquivo, "[EMPRESTIMO]\n");
        fprintf(arquivo, "Aluno: %s\n", atual->nomealuno);
        fprintf(arquivo, "Matricula: %d\n", atual->matricula);
        fprintf(arquivo, "Livro: %s\n", atual->titulolivro);
        fprintf(arquivo, "DataEmprestimo: %s\n", atual->dataemprestimo);
        fprintf(arquivo, "DataEntrega: %s\n", atual->dataentrega);
        fprintf(arquivo, "\n");
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarEmprestimos(Emprestimo **emprestimos)
{
    FILE *arquivo = fopen("emprestimos.txt", "r");
    if (arquivo == NULL)
    {
        *emprestimos = NULL;
        return;
    }

    *emprestimos = NULL;

    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        // Detecta o início de um novo registro
        if (strncmp(linha, "[EMPRESTIMO]", 12) != 0)
            continue;

        Emprestimo *novoEmprestimo = malloc(sizeof(Emprestimo));
        if (novoEmprestimo == NULL)
        {
            printf("Erro ao alocar memoria.\n");
            fclose(arquivo);
            return;
        }

        int camposLidos = 0;

        // Lê as próximas linhas do registro
        while (camposLidos < 5 && fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            if (sscanf(linha, "Aluno: %49[^\n]", novoEmprestimo->nomealuno) == 1)
                camposLidos++;
            else if (sscanf(linha, "Matricula: %d", &novoEmprestimo->matricula) == 1)
                camposLidos++;
            else if (sscanf(linha, "Livro: %49[^\n]", novoEmprestimo->titulolivro) == 1)
                camposLidos++;
            else if (sscanf(linha, "DataEmprestimo: %10[^\n]", novoEmprestimo->dataemprestimo) == 1)
                camposLidos++;
            else if (sscanf(linha, "DataEntrega: %10[^\n]", novoEmprestimo->dataentrega) == 1)
                camposLidos++;
        }

        // Descarta o nó se algum campo falhou
        if (camposLidos != 5)
        {
            free(novoEmprestimo);
            continue;
        }

        // Insere no início da lista
        novoEmprestimo->prox = *emprestimos;
        *emprestimos = novoEmprestimo;
    }

    fclose(arquivo);
}