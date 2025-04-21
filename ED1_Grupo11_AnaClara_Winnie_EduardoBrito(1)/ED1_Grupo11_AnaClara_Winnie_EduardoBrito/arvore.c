/* Grupo 11: 
Componentes: Ana Clara Sesana Moreira
Eduardo Gil Gigante Brito 
Winnie Barros de Souza 
*/

/* #include < caminho_para_tad > */
#include "code.h"

//Função para criar a árvore binária de busca para os livros.
Livro *CriaArvore(char *isbn, char *titulo, char *autor, int qtde_estoque){
    Livro *novo = (Livro*)malloc(sizeof(Livro));
    if (novo == NULL)
    {
        printf("Erro de Alocacao de Memoria");
        exit(1);

    }
    strcpy(novo->isbn, isbn);
    strcpy(novo->titulo, titulo);
    strcpy(novo->autor, autor);
    novo->qtde_estoque = qtde_estoque;
    novo->esq = novo->dir = NULL;
    return novo;
}
//Função para buscar na árvore.
Livro *buscaArvore(Livro *root, Livro **paiaux, char *isbn){
    Livro *aux = root;
    (*paiaux) = NULL;
    while (aux != NULL)
    {
        if(strcmp(aux->isbn, isbn) == 0) break;
        if(strcmp(aux->isbn, isbn) == 1) {
            *paiaux = aux; 
            aux=aux->dir;
        }
        else {
            *paiaux = aux; 
            aux = aux->esq;
        }
    }
    return aux;   
}
//Função que serve para inserir na árvore binária de busca, de acordo com o valor do isbn.
Livro *insereArvore(Livro *root,char *isbn, char *titulo, char *autor, int qtde_estoque){
    Livro *novo = CriaArvore(isbn, titulo, autor, qtde_estoque);
    Livro *paiaux = NULL;
    Livro *aux = root;
    
    if(root == NULL)return novo;
    while (aux != NULL){
        paiaux = aux;
        if (strcmp(aux->isbn, isbn) < 0){
            aux = aux->esq;
        }
        else if(strcmp(aux->isbn, isbn) > 0){
            aux = aux->dir;
            }
        else {
            aux->qtde_estoque += qtde_estoque;
            //free(novo);
            return root;
        }
    }
if (strcmp(paiaux->isbn, isbn) < 0){
        paiaux->esq = novo;

    }
else{
        paiaux->dir = novo;
    }
    return root;
}
//Função para auxiliar na exclusão de uma árvore.
Livro *sucessor(Livro *x, Livro **paisuc){
    Livro *aux = x->dir;
    *paisuc = x;
    if(aux == NULL) return NULL;
    while(aux->esq != NULL){
        *paisuc = aux;
        aux=aux->esq;
    }
    return aux;
}
 //Função para transferir os livros de uma filial para outra.
void transfereLivros(Livro *source, Livro *destiny){
    if (!source)return;
    
    destiny = insereArvore(destiny, source->isbn, source->titulo, source->autor, source->qtde_estoque);
    transfereLivros(source->esq, destiny);
    transfereLivros(source->dir, destiny);
    

}
//Função para excluir uma árvore binária de busca.
Livro *excluirArvore(Livro *root, char *isbn){
    Livro *paiaux = NULL;
    Livro *aux = buscaArvore(root,&paiaux,isbn);
    if(!aux)return root;
    if(aux->dir == NULL && aux->esq == NULL){
        if(paiaux == NULL){
            free(aux);
            return NULL;
        }else{
            if(paiaux->esq == aux){
                paiaux->esq = NULL;
            }else{
                paiaux->dir = NULL;
            }
            free(aux);
            return root;
        }    
    }else{
        Livro *paisuc = NULL;
        Livro *suc = sucessor(aux, &paisuc);
        if(suc == NULL){
            if(paiaux == NULL){
                root = aux->esq;
                free(aux);
                return root;
            }else{
                if(paiaux->esq == aux){
                    paiaux->esq = aux->esq;
                }else{
                    paiaux->dir = aux->esq;
                }
                free(aux);
                return root;
            }
        }else{
            strcpy(aux->isbn, suc->isbn);
            strcpy(aux->titulo, suc->titulo);
            strcpy(aux->autor, suc->autor);
            aux->qtde_estoque = suc->qtde_estoque;
            if(paisuc->esq == suc){
                paisuc->esq = suc->dir;
            }else{
                paisuc->dir = suc->dir;
            }
            free(aux);
            return root;
        }
    }
}
//Função para imprimir a lista de livros em ordem crescente de isbn
void imprimirArvoreEmOrdem(Livro *root) {
    if (root != NULL) {
        imprimirArvoreEmOrdem(root->dir);
        printf(RED"ISBN: %s\n", root->isbn);
        printf(RED"Título: %s\n", root->titulo);
        printf(RED"Autor: %s\n", root->autor);
        printf(RED"Quantidade em Estoque: %d\n\n", root->qtde_estoque);
        printf(RED"---------------------------\n");
        imprimirArvoreEmOrdem(root->esq);
        
        
       
    }
}
//Função que serve para imprimir somente uma lista de livro.
void imprimirUnicoLivro(Livro *root) {

        printf(RED"ISBN: %s\n", root->isbn);
        printf(RED"Título: %s\n", root->titulo);
        printf(RED"Autor: %s\n", root->autor);
        printf(RED"Quantidade em Estoque: %d\n\n", root->qtde_estoque);
        printf("---------------------------\n");
        clearInputBuffer();
        
    
}
//Função que imprime a estrutura de árvore binária de busca.
void imprimeArvore(Livro *root, int nivel){
    if(root != NULL){
        imprimeArvore(root->esq,nivel+1);
        for(int i = 0; i < nivel; i++){
            printf("\t");
        }
        printf("%s\n", root->isbn);
        imprimeArvore(root->dir, nivel+1);
    }
}
