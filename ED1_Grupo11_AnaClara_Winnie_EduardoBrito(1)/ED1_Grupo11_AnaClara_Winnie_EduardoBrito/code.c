/* Grupo 11: 
Componentes: Ana Clara Sesana Moreira
Eduardo Gil Gigante Brito 
Winnie Barros de Souza 
*/

/* #include < caminho_para_tad > */
#include "code.h"

/*Funcão para limpar terminal */
void limparTerminal() {
    printf("\033c");  /* Se o terminal for para Windows, devemos utilizar o comando
                              system("clear");*/
}
//Função para o usuário pressionar enter para continuar.
void pressioneEnterParaContinuar() {
    printf(RED"Pressione Enter para continuar...\n");
    while (getchar() != '\n'); // Aguarda até que o usuário pressione Enter
}
//Função para imprimir o menu principal, com a arte ASCII ART.
void menu(){
    printf(RED"-----------------------Livraria Books----------------------\n");
        printf(RED"|                     ______ ______                       |\n");
        printf(RED"|                   _/      Y      \\_                     |\n");
        printf(RED"|                  // ~~ ~~ | ~~ ~  \\\\                    |\n");
        printf(RED"|                 // ~ ~ ~~ | ~~~ ~~ \\\\                   |\n");
        printf(RED"|                //________.|.________\\\\  Created by @ana,|\n");
        printf(RED"|               `----------`-'----------' @edu and @winnie|\n");
        printf(RED"|--------------------------Menu---------------------------|\n");
        printf(RED"| [1]: Listar dados de todas as filiais                   |\n");
        printf(RED"| [2]: Listar os dados de uma filial                      |\n");
        printf(RED"| [3]: Criar uma nova filial                              |\n");
        printf(RED"| [4]: Encerrar atividades de uma filial                  |\n");
        printf(RED"| [5]: Realizar operações de estoque de uma filial        |\n");
        printf(RED"| [6]: Sair                                               |\n");
        printf(RED"|---------------------------------------------------------|\n");
        printf(YELLOW"Digite uma opção: ");
}
//Função para imprimir o segundo menu, ou submenu.
void submenu(){
    printf(YELLOW"|----------------------Livraria Books----------------------------|\n");
    printf(YELLOW"|[1]: Imprimir a lista dos livros em ordem crescente de isbn:    |\n");
    printf(YELLOW"|[2]: Inserir um novo livro:                                     |\n");
    printf(YELLOW"|[3]: Buscar um livro no sistema:                                |\n");
    printf(YELLOW"|[4]: Imprimir a arvore binaria de busca:                        |\n");
    printf(YELLOW"|[5]: Excluir um livro:                                          |\n");
    printf(YELLOW"|[6]: Retornar ao menu principal:                                |\n");
    printf(YELLOW"|----------------------------------------------------------------|\n");
    printf(YELLOW"Digite uma opção: \n");
}
//Função para imprimir o último menu, com a ASCII ART.
void menuFinal(){
    printf(RED"           __    ___ __   __ __     __  __  __  \n");
    printf(RED"     \\  / /  \\ |  | |_   (_ |_ |\\/||__)|__)|_   |          \n");
    printf(RED"      \\/  \\__/ |__| |__  __)|__|  ||   | \\ |__  .           \n"); 
    printf("\n\n");                  
    exit(1);
}
/* Função para limpar o buffer de entrada, essa função serve 
porque ao utilizar os códigos de escape ANSI para formatação de cores,
estava conflitando com os outros scanf e dando buffer overflow, portanto era necessário
fazer essa função para limpar o buffer após os prints.
*/
void clearInputBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

//Função para criar o nó da filial, de forma ordenada.
Filial *CriaNo(int id, char *endereco, char *gerente ){
    Filial *novo = (Filial*)malloc(sizeof(Filial));
    if (novo == NULL)
    {
        printf("Erro na Alocacao de Memoria");
        exit(1);
    }
    novo->id = id;
    strcpy(novo->gerente, gerente);
    strcpy(novo->endereco, endereco);
    novo->prox = NULL;
    novo->estoque = NULL;
    return novo;
}
//Função para busca a lista.
Filial *buscaListaOrd(Filial *L, int valor, Filial **pred){
    Filial *aux = L;
    (*pred) = NULL;
    if (L == NULL) return NULL;
    else{
        while (aux != NULL){
            if (valor == aux->id) break;
            {
                (*pred) = aux;
                aux = aux->prox;
            } 
        }
        return aux; 
    }
}
//Função para inserir uma filial de forma ordenada.
Filial *InsereOrde(Filial *L, int id, char *endereco, char *gerente){
    Filial *novo = CriaNo(id, endereco, gerente);
    Filial *pred = NULL;
    Filial *aux = buscaListaOrd(L, id, &pred);
    if (pred == NULL){
        novo->prox = aux;
        L = novo;
    }else{
        novo->prox = aux;
        pred->prox = novo;
    }
    return L;

}
//Função para excluir a lista de filial.
Filial *excluirListaOrd(Filial *L, int id){
    Filial *pred = NULL;
    Filial *aux = buscaListaOrd(L, id, &pred);
    if (aux != NULL && aux->id == id){
        if (pred == NULL) L = aux->prox;
        else pred->prox = aux->prox;
        free(aux);
    }
    return L;
    
}
//Função para imprimir somente uma filial.
void unicaFilial(Filial *L){
    Filial *aux = L;
    printf(RED"Id da Filial: %d\n", aux->id);
    printf(RED"Endereco da Filial: %s\n", aux->endereco);
    printf(RED"Gerente da Filial: %s\n", aux->gerente);
    printf(RED"\n---------------------------\n");
    printf("\n");
    

}
//Função para imprimir todas as listas de filiais.
void imprimeLista(Filial *L){
    Filial *aux = L;
    int i = 1;
    while (aux != NULL)
    {
        printf(RED"Id da %dª Filial cadastrada: %d\n", i, aux->id);
        printf(RED"Endereco da %dª Filial cadastrada: %s\n", i, aux->endereco);
        printf(RED"Gerente da %dª Filial cadastrada: %s\n", i, aux->gerente);
        printf(RED"\n---------------------------\n");
        aux = aux->prox;
        i++;
        printf("\n");

    }
    printf("\n");
    
}



