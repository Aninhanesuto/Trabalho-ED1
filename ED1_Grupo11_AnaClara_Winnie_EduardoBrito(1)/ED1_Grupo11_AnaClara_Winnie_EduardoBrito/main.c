/* Grupo 11: 
Componentes: Ana Clara Sesana Moreira
Eduardo Gil Gigante Brito 
Winnie Barros de Souza 
*/

/* Inclusão das bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include "code.h"
/* #include < caminho_para_tad > */

int main() {
    Filial *root;
    Filial *pred = NULL;
    Filial *busca = NULL;
    Filial *busca2 = NULL;
    Livro *buscaIsbn = NULL;
    Livro *paiaux = NULL;
    char enter;
    int escolha1;
    int escolha2;
    int qtde_filiais;
    int id;
    int idprocurado;
    int qtde_livros;
    char endereco[100];
    char gerente[50];
    char isbn[50];
    char titulo[100];
    char autor[50];
    int qtde_estoque = 0;
    

    /* Do-While para que seja aberto o menu ao menos uma vez
     * Para encerrá-lo o usuário tem de digitar "6"
     * Qualquer valor fora dos listados, será reaberto o menu
     */
    do {
        limparTerminal(); // Função para limpar o terminal.
        menu(); //Função para chamar o menu principal.
        
        if (scanf("%d", &escolha1) != 1){
            /* Tratamento de erro para caso o usuário do programa insira um valor que não seja 
            inteiro.
            */
            printf(RED"Você digitou um valor que não é inteiro, digite novamente!\n");
            pressioneEnterParaContinuar();
            clearInputBuffer();
            continue;
        }
        switch(escolha1) {
            case 1:
            if (root == NULL){
                /*Tratamento de erro para caso o usuário imprima a lista de filiais,
                mas ainda não tenha cadastrado nenhuma.
                */
                printf(YELLOW"A Livraria Books não possui filiais, por favor cadastre uma primeiro!\n");
                pressioneEnterParaContinuar();
                
                
            }
            else{     
                //Se passar pelo tratamento de erro, ele limpar o terminal e imprime a lista de filiais corretamente.
                limparTerminal();
                imprimeLista(root);
                pressioneEnterParaContinuar();
            }
            
                break;

            case 2:
                if (root == NULL){
                /*Tratamento de erro para caso o usuário queira pesquisar  a lista de filiais,
                mas ainda não tenha cadastrado nenhuma.
                */
                printf(YELLOW"A Livraria Books não possui nenhuma filial, por favor cadastre uma primeiro!\n");
                pressioneEnterParaContinuar();
                
                
            }
            else{
                //Se passar pelo tratamento de erro, ele irá pesquisar a filial e retornar pro usuário.
                printf(YELLOW"Digite o id da filial que você está procurando: \n");
                scanf("%d", &idprocurado);
                busca = buscaListaOrd(root, idprocurado, &pred);
                if (busca != NULL) {
                    unicaFilial(busca); //Imprime uma única filial.
                    pressioneEnterParaContinuar();
                } else{
                    //Tratamento para caso o usuário digite uma filial que não exista.
                    printf(RED"Filial não encontrada.\n");
                    pressioneEnterParaContinuar();
                }    
             }
            break;
            case 3:
                printf(RED"Você quer cadastrar quantas filiais? \n");
                scanf("%d", &qtde_filiais);
                for (int i = 0; i < qtde_filiais; i++){
                    if (root == NULL){
                        
                        printf(RED"Digite o id da filial: \n");
                        clearInputBuffer();//Serve para limpar o buffer do código ANSI que eu coloquei na impressão do terminal.
                        scanf("%d", &id);
                    }
                    else{
                        printf(RED"Digite o id da filial: \n");
                        clearInputBuffer();
                        scanf("%d", &id);
                        busca2 = buscaListaOrd(root, id, &pred);
                        if (busca2 != NULL){
                            //Serve para verificar caso o usuário já tenha colocado um id que já exista na lista de filiais.
                            while (busca2->id == id){
                            printf(RED"Este id já está cadastrada, insira novamente um id: \n");
                            clearInputBuffer();
                            scanf("%d", &id); 
                            /*Ele pedirá até que você digite um id que não exista, mas caso o usuário tente colocar duas vezes
                            um id que já exista, estava indo o segundo id como se não existisse, portanto tive que colocar a busca
                            de novo no final.
                            */
                            busca2 = buscaListaOrd(root, id, &pred);
                            if (busca2 == NULL){
                                //Se agora o usuário, coloque um id que não exista, isso evita que dê segmentation fault ao acessar busca2->id.
                                break;
                            }   
                        }
                        }
                    }
                        //Caso não exista o id,o código prossegue e cria a filial corretamente.
                        printf(RED"Digite o endereço da filial: \n");
                        scanf("%c", &enter);
                        scanf("%[^\n]", endereco);
                        printf(RED"Digite o nome do gerente da filial: \n");
                        scanf("%c", &enter);
                        scanf("%[^\n]", gerente);
                        root = InsereOrde(root, id, endereco, gerente);
                    }
                break;

            case 4:
                printf("Digite o id da filial que voce quer excluir: \n");
                scanf("%d", &id);
                printf("Digite o id da filial que voce quer enviar: \n");
                scanf("%d", &idprocurado);
                
                busca = buscaListaOrd(root, id, &pred);
                busca2 = buscaListaOrd(root, idprocurado, &pred);
                if (busca  == NULL || busca2 == NULL){
                    //Tratamento de erro, para caso ele coloque uma filial que não exista.
                    printf("Você digitou um id de filial inexistente, tente novamente!\n");
                    pressioneEnterParaContinuar();
                    break;
                }
                else if (busca2->estoque == NULL)
                {
                    /*Coloquei essa verificação para caso o estoque da segunda filial ainda não exista, 
                    ou seja não tenha nenhum livro ainda cadastrado para ele criar o estoque da segunda e 
                    inserir todos os livros da primeira filial nela.
                    */ 
                    busca2->estoque = insereArvore(busca2->estoque, busca->estoque->isbn, busca->estoque->titulo, busca->estoque->autor, busca->estoque->qtde_estoque);
                    busca->estoque = excluirArvore(busca->estoque, isbn);
                    root = excluirListaOrd(root, id);
                    unicaFilial(busca2);
                    imprimeArvore(busca2->estoque, 0);
                    pressioneEnterParaContinuar();
                }
                
                else if(busca2->estoque != NULL){
                /*Tive que colocar mais um else if, para caso exista esta filial ele só transfira e tinha que ser um else if 
                para caso a segunda filial não existir, ele não tentar acessar e dar segmentation fault.
                */ 
                transfereLivros(busca->estoque, busca2->estoque);
                busca->estoque = excluirArvore(busca->estoque, isbn);
                root = excluirListaOrd(root, id);
                unicaFilial(busca2);
                imprimeArvore(busca2->estoque, 0);
                pressioneEnterParaContinuar();
                }
                break;

            case 5:
                printf(RED"Digite o id da filial que voce quer procurar: \n");
                scanf("%d", &id);
                Filial *predescolhida = NULL;
                Filial *escolhida = NULL;
                escolhida = buscaListaOrd(root, id, &predescolhida);
                limparTerminal();
                do{
                
                if (escolhida == NULL){
                    //Tratamento de erro para caso ele queira inserir um id de filial que não existe.
                    printf(YELLOW"Esta filial não existe.\n");
                    clearInputBuffer();
                    pressioneEnterParaContinuar();
                    
                    break;
                }
                else{
                limparTerminal();
                submenu(); //Função para imprimir o segunda menu, ou submenu.
                scanf("%d", &escolha2);
                limparTerminal();
                switch (escolha2){
                case 1:
                if (escolhida->estoque == NULL){
                //Tratamento de erro para caso ele queira imprimir um livro e não tenha nenhum livro cadastrado.
                printf(YELLOW"A filial que você está procurando não possui nenhum livro, cadastre um livro primeiro!\n");
                pressioneEnterParaContinuar();
                
                }

                else{ 
                // Se estiver correto, ele irá imprimir a lista dos livros em ordem crescente de ISBN.    
                limparTerminal();
                imprimirArvoreEmOrdem(escolhida->estoque);
                pressioneEnterParaContinuar();
                }
                break;
                case 2:
                    printf("Voce quer cadastrar quantos livros na filial: \n");
                    scanf("%d", &qtde_livros);
                    for (int i = 0; i < qtde_livros; i++){
                        printf(RED"Digite o isbn do livro que voce quer cadastrar: \n");
                        scanf("%c", &enter);
                        scanf("%[^\n]", isbn);
                        buscaIsbn = buscaArvore(escolhida->estoque, &paiaux,isbn);
                        if (buscaIsbn != NULL){
                            printf(YELLOW"Este livro já existe na filial\n\n");
                            printf("Digite a quantidade de estoque do livro inserido: \n");
                            scanf("%d", &qtde_estoque);
                            escolhida->estoque = insereArvore(buscaIsbn, isbn, titulo, autor, qtde_estoque);
                            imprimirUnicoLivro(buscaIsbn);
                            pressioneEnterParaContinuar();
                            
                        }
                        else{
                        printf("Digite o titulo do livro: \n");
                        scanf("%c", &enter);
                        scanf("%[^\n]", titulo);
                        printf("Digite o autor do livro: \n");
                        scanf("%c", &enter);
                        scanf("%[^\n]", autor);
                        printf("Digite a quantidade de estoque do livro inserido: \n");
                        scanf("%d", &qtde_estoque);
                        escolhida->estoque = insereArvore(escolhida->estoque, isbn, titulo, autor, qtde_estoque);
                        }
                    }
                    break;
                case 3:
                    if (root->estoque != NULL)
                    {
                        
                        printf(RED"Digite o isbn do livro que  voce quer procurar: \n");
                        scanf("%c", &enter);
                        scanf("%[^\n]", isbn);
                        buscaIsbn = buscaArvore(escolhida->estoque, &paiaux,isbn);
                        if (buscaIsbn == NULL){
                            //Tratamento de erro para caso o usuário digite um isbn errado.
                            printf("Esse isbn procurado não existe \n");
                            clearInputBuffer();
                            pressioneEnterParaContinuar();
                            break;
                        }
                        
                        else if(strcmp(isbn,buscaIsbn->isbn) == 0){
                            imprimirUnicoLivro(buscaIsbn);
                            pressioneEnterParaContinuar();
                            break;
                        }
                        
                        
                    }
                    else{
                        //Tratamento de erro para caso o usuário queira pesquisar, mas não tenha nenhum livro cadastrado.
                        printf(YELLOW"Não existe nenhum livro cadastrado, cadastre um livro na filial\n");
                        pressioneEnterParaContinuar();
                        break;
                    }
                    break;
                case 4:    
                    if (escolhida->estoque == NULL){
                        //Tratamento para caso ele queira imprimir, mas não tenha nenhum livro cadastrado.
                        printf(YELLOW"A filial que você está procurando não possui nenhum livro, cadastre um livro primeiro!\n");
                        pressioneEnterParaContinuar();
                    }
                    else{
                    imprimeArvore(escolhida->estoque, 0);
                    pressioneEnterParaContinuar();
                    }
                    break;
                case 5:   
                    printf(RED"Digite o isbn do livro que voce quer excluir: \n");
                    clearInputBuffer();
                    scanf("%c", &enter);
                    scanf("%[^\n]", isbn);
                    buscaIsbn = buscaArvore(escolhida->estoque, &paiaux,isbn);
                    if (buscaIsbn != NULL)
                    {
                       escolhida->estoque = excluirArvore(buscaIsbn, isbn);
                       printf(RED"O livro foi removido com sucesso \n");
                       clearInputBuffer();
                       pressioneEnterParaContinuar();
                    }
                    else{
                        //Tratamento de erro para caso o usuário digite um isbn errado.
                        printf(YELLOW"Esse isbn não foi encontrado.\n");
                        clearInputBuffer();
                    }
                    
                    break;
                case 6:
                    printf(YELLOW"Pressione Enter para continuar...");
                    break;
                default:
                    //Tratamento de erro para caso o usuário digite um valor que não esteja entre as opções do submenu.
                    printf(YELLOW"Por favor insira um valor valido!\n");
                    clearInputBuffer();
                    break;
                }
            }
            //Serve para a cada iteração limpar o buffer dos códigos ANSI.
            clearInputBuffer();
                }while(escolha2 != 6);
                break;
                

            case 6:
                limparTerminal();
                //Imprimir o menu final do código pro usuário.
                menuFinal();
                break;
            default:
                //Tratamento de erro para caso o usuário digite um valor que não esteja entre as opções do submenu.
                printf(YELLOW"Por favor insira um valor valido!\n");
                clearInputBuffer();
                break;
        }
    //Serve para a cada iteração limpar o buffer dos códigos ANSI
    clearInputBuffer();
    } while(escolha1 != 6);

    return 0;
}