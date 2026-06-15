#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"
#include "validacao.h"


void cadastrarLivro(Livro **livros){
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    if (novoLivro == NULL)
    {
        printf("\nErro ao alocar memória para o novo livro.\n");
        return;
    }
    printf("\n------Cadastro de Livro------\n");
    do{
    novoLivro->codlivro = lerInteiro("Digite o código do livro: ");

    if (!validarCodigo(novoLivro->codlivro))
    {
        printf("O código deve ser maior que zero.\n");
        continue;
    }

    if (codigoJaExiste(*livros, novoLivro->codlivro)){
        printf("Já existe um livro com esse código.\n");
    }

    } while (!validarCodigo(novoLivro->codlivro) || codigoJaExiste(*livros, novoLivro->codlivro));
    
    do{
        lerString("Digite o título do livro: ", novoLivro->titulo, sizeof(novoLivro->titulo));

        if (tituloJaExiste(*livros, novoLivro->titulo)){
            printf("Já existe um livro com esse título.\n");
        }

    } while (tituloJaExiste(*livros, novoLivro->titulo));

   do{
        lerString("Digite o autor do livro: ", novoLivro->autor, sizeof(novoLivro->autor));

        if (!validarNome(novoLivro->autor)){
            printf("Autor inválido.\n");
        }

    } while (!validarNome(novoLivro->autor));

    do{
        novoLivro->anopublicacao = lerInteiro("Digite o ano de publicação: ");
        if (!validarAnoPublicacao(novoLivro->anopublicacao)){
            printf("Ano de publicação inválido.\n");
        }
    
    } while (!validarAnoPublicacao(novoLivro->anopublicacao));

    do{
        novoLivro->quantidade = lerInteiro("Digite a quantidade disponível: ");
        if (!validarQuantidade(novoLivro->quantidade)){
            printf("Quantidade inválida.\n");
        }

    } while (!validarQuantidade(novoLivro->quantidade));

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
    Livro *atual = livros; //ponteiro aux atual recebe o primeiro nó da lista 
    printf("\n-----Lista de Livros------\n");
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

void editarLivro(Livro **livros, Emprestimo *emprestimos) {
    if (*livros == NULL) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    char titulo[50];
    lerString("Digite o título do livro que deseja editar: ", titulo, sizeof(titulo));

    Livro *atual = *livros;
    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {

            int opcao;
            do {
                printf("\n------Editar Livro------\n");
                printf("1. Código     (atual: %d)\n", atual->codlivro);
                printf("2. Título     (atual: %s)\n", atual->titulo);
                printf("3. Autor      (atual: %s)\n", atual->autor);
                printf("4. Ano        (atual: %d)\n", atual->anopublicacao);
                printf("5. Quantidade (atual: %d)\n", atual->quantidade);
                printf("0. Confirmar edições\n");
                printf("------------------------\n");

                opcao = lerInteiro("Escolha o campo: ");

                switch (opcao) {
                    case 1: {
                        int novoCodigo;
                        do {
                            novoCodigo = lerInteiro("Novo código: ");
                            if (!validarCodigo(novoCodigo))
                                printf("Código inválido.\n");
                            else if (novoCodigo != atual->codlivro && codigoJaExiste(*livros, novoCodigo))
                                printf("Já existe um livro com esse código.\n");
                        } while (!validarCodigo(novoCodigo) || (novoCodigo != atual->codlivro && codigoJaExiste(*livros, novoCodigo)));
                        atual->codlivro = novoCodigo;
                        printf("Código atualizado.\n");
                        break;
                    }

                    case 2: {
                        char novoTitulo[50];
                        do {
                            lerString("Novo título: ", novoTitulo, sizeof(novoTitulo));
                            if (strcmp(novoTitulo, atual->titulo) != 0 && tituloJaExiste(*livros, novoTitulo))
                                printf("Já existe um livro com esse título.\n");
                        } while (strcmp(novoTitulo, atual->titulo) != 0 && tituloJaExiste(*livros, novoTitulo));

                        // Atualiza empréstimos com o título antigo
                        Emprestimo *emp = emprestimos;
                        while (emp != NULL) {
                            if (strcmp(emp->titulolivro, atual->titulo) == 0)
                                strcpy(emp->titulolivro, novoTitulo);
                            emp = emp->prox;
                        }
                        strcpy(atual->titulo, novoTitulo);
                        printf("Título atualizado.\n");
                        break;
                    }

                    case 3: {
                        char novoAutor[50];
                        do {
                            lerString("Novo autor: ", novoAutor, sizeof(novoAutor));
                            if (!validarNome(novoAutor))
                                printf("Autor inválido.\n");
                        } while (!validarNome(novoAutor));
                        strcpy(atual->autor, novoAutor);
                        printf("Autor atualizado.\n");
                        break;
                    }

                    case 4: {
                        int novoAno;
                        do {
                            novoAno = lerInteiro("Novo ano de publicação: ");
                            if (!validarAnoPublicacao(novoAno))
                                printf("Ano inválido.\n");
                        } while (!validarAnoPublicacao(novoAno));
                        atual->anopublicacao = novoAno;
                        printf("Ano atualizado.\n");
                        break;
                    }

                    case 5: {
                        int novaQuantidade;
                        do {
                            novaQuantidade = lerInteiro("Nova quantidade: ");
                            if (!validarQuantidade(novaQuantidade))
                                printf("Quantidade inválida.\n");
                        } while (!validarQuantidade(novaQuantidade));
                        atual->quantidade = novaQuantidade;
                        printf("Quantidade atualizada.\n");
                        break;
                    }

                    case 0:
                        break;

                    default:
                        printf("Opção inválida.\n");
                }

            } while (opcao != 0);

            salvarlivros(*livros);
            salvaremprestimos(emprestimos);
            printf("\nLivro salvo com sucesso.\n");
            return;
        }

        atual = atual->prox;
    }

    printf("\nLivro não encontrado.\n");
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
            printf("\n-----Livro encontrado-----\n");
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

void excluirLivro(Livro **livros, Emprestimo *emprestimos, char *titulo) {
    if (*livros == NULL) {
        printf("\nNenhum livro cadastrado.\n");
        return;
    }

    Livro *atual = *livros;
    Livro *anterior = NULL;

    if (livroPossuiEmprestimos(emprestimos, titulo)) {
        printf("\nNão é possível excluir este livro.\nExistem empréstimos ativos.\n");
        return;
    }

    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            if (anterior == NULL) {
                *livros = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            salvarlivros(*livros);
            printf("\nLivro excluído com sucesso.\n");
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("\nLivro não encontrado.\n");
}

void salvarlivros(Livro *livros) {
    FILE *arquivo = fopen("livros.txt", "w");
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo para salvar os livros.\n");
        return;
    }

    Livro *atual = livros;
    while (atual != NULL) {
        fprintf(arquivo, "[LIVRO]\n");
        fprintf(arquivo, "Codigo: %d\n",     atual->codlivro);
        fprintf(arquivo, "Titulo: %s\n",     atual->titulo);
        fprintf(arquivo, "Autor: %s\n",      atual->autor);
        fprintf(arquivo, "Ano: %d\n",        atual->anopublicacao);
        fprintf(arquivo, "Quantidade: %d\n", atual->quantidade);
        fprintf(arquivo, "\n"); // linha em branco separando os registros
        atual = atual->prox;
    }

    fclose(arquivo);
}

void carregarLivros(Livro **livros) {
    FILE *arquivo = fopen("livros.txt", "r");
    if (arquivo == NULL) {
        *livros = NULL;
        return;
    }

    *livros = NULL;

    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {

        // Detecta o início de um novo registro
        if (strncmp(linha, "[LIVRO]", 7) != 0)
            continue;

        Livro *novoLivro = malloc(sizeof(Livro));
        if (novoLivro == NULL) {
            printf("Erro ao alocar memoria.\n");
            fclose(arquivo);
            return;
        }

        int camposLidos = 0;

        // Lê as próximas 5 linhas esperadas do registro
        while (camposLidos < 5 && fgets(linha, sizeof(linha), arquivo) != NULL) {
            if      (sscanf(linha, "Codigo: %d",      &novoLivro->codlivro)      == 1) camposLidos++;
            else if (sscanf(linha, "Titulo: %49[^\n]", novoLivro->titulo)         == 1) camposLidos++;
            else if (sscanf(linha, "Autor: %49[^\n]",  novoLivro->autor)          == 1) camposLidos++;
            else if (sscanf(linha, "Ano: %d",          &novoLivro->anopublicacao) == 1) camposLidos++;
            else if (sscanf(linha, "Quantidade: %d",   &novoLivro->quantidade)    == 1) camposLidos++;
        }

        // Descarta o nó se algum campo falhou
        if (camposLidos != 5) {
            free(novoLivro);
            continue;
        }

        // Insere no início da lista
        novoLivro->prox = *livros;
        *livros = novoLivro;
    }

    fclose(arquivo);
}
