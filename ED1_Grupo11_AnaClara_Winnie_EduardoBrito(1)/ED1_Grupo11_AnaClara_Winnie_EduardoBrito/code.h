/* Grupo 11: 
Componentes: Ana Clara Sesana Moreira
            Eduardo Gil Gigante Brito 
            Winnie Barros de Souza 
*/

#ifndef CODE_H
#define CODE_SH

// Inclusão das bibliotecas necessárias.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Definindo códigos de escape ANSI para formatação de texto e cores
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"

//Estrutura para os livros.
typedef struct livro {
    char isbn[50];      // Assuming a maximum of 50 characters for the ISBN
    char titulo[100];   // Assuming a maximum of 100 characters for the title
    char autor[50];     // Assuming a maximum of 50 characters for the author's name
    int qtde_estoque;
    struct livro *dir;
    struct livro *esq;
}Livro;

// Estrutura para as filiais.
typedef struct filial{
    int id;
    char endereco[100]; // Assuming a maximum of 100 characters for the address
    char gerente[50];  
    Livro *estoque;
    struct filial *prox;
}Filial;

//Definindo as funções do código.
void clearInputBuffer();
void limparTerminal();
void pressioneEnterParaContinuar();
void menu();
void submenu();
void menuFinal();

//Definindo as funções de árvore binária de busca para os livros.
Livro *CriaArvore(char *isbn, char *titulo, char *autor, int qtde_estoque);
Livro *buscaArvore(Livro *root, Livro **paiaux, char *isbn);
Livro *insereArvore(Livro *root,char *isbn, char *titulo, char *autor, int qtde_estoque);
Livro *sucessor(Livro *x, Livro **paisuc);
Livro *excluirArvore(Livro *root, char *isbn);
void imprimirUnicoLivro(Livro *root);
void imprimirArvoreEmOrdem(Livro *root);
void imprimeArvore(Livro *root, int nivel);
void transfereLivros(Livro *source, Livro *destiny);

//Definindo as funções de lista de encadeada para as filiais.
Filial *CriaNo(int id, char *endereco, char *gerente );
Filial *buscaListaOrd(Filial *L, int valor, Filial **pred);
Filial *InsereOrde(Filial *L, int id, char *endereco, char *gerente);
Filial *excluirListaOrd(Filial *L, int id);
void unicaFilial(Filial *L);
void imprimeLista(Filial *L);


#endif // CODE_H
