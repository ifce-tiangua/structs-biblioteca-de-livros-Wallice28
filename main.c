#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nome[100];
    char isbn[20];
    float preco;
    int score;
    char editora[100];
} Livro;


typedef Livro* pLivro;


pLivro livro_aloc(int qtde) {
    return (pLivro)malloc(qtde * sizeof(Livro));
}

void livro_ler(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", livros[i].nome);  // Lê a string com espaços
        printf("ISBN: ");
        scanf(" %[^\n]", livros[i].isbn);
        printf("Preço: ");
        scanf("%f", &livros[i].preco);
        printf("Score (0-10): ");
        scanf("%d", &livros[i].score);
        printf("Editora: ");
        scanf(" %[^\n]", livros[i].editora);
        printf("\n");
    }
}


void livro_exibe(pLivro livros, int qtde) {
    for (int i = 0; i < qtde; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Nome: %s\n", livros[i].nome);
        printf("ISBN: %s\n", livros[i].isbn);
        printf("Preço: R$ %.2f\n", livros[i].preco);
        printf("Score: %d\n", livros[i].score);
        printf("Editora: %s\n", livros[i].editora);
        printf("\n");
    }
}


void livro_desaloca(pLivro livros) {
    free(livros);
}

int main() {
    int qtde;
    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &qtde);

    
    pLivro livros = livro_aloc(qtde);

    if (!livros) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

   
    livro_ler(livros, qtde);

    
    printf("\nInformações dos Livros Cadastrados:\n");
    livro_exibe(livros, qtde);

    
    livro_desaloca(livros);

    return 0;
    
}
