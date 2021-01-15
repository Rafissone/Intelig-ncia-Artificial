/*
    Nome: Rafissone Manuel Macilaho
    Curso: Engenharia Informática - Labora, Nível 3
    Cadeira: Inteligência Artificial (INAR)
    
    Resolućão da Primeira Tarefa
*/

#include "crud.h"

/*Prótotipo das funćões*/
int menu();
void menuPrincipal();


int main(){

    menuPrincipal();

    return 0;
}

/*Desenvolvimento das funćões*/

/*Funćão que exibe o menu principal para o usuário*/
int menu(){
    int escolha;
    printf("\n===================================");
    printf("\n| 1. Adicionar na Árvore          |");
    printf("\n| 2. Busca na Árvore em Ordem     |");
    printf("\n| 3. Busca na Árvore em Pré-Ordem |");
    printf("\n| 4. Busca na Árvore em Pós-Ordem |");
    printf("\n| 0. Sair do Programa             |");
    printf("\n====================================");
    printf("\nEscolha: ");
    scanf("%d", &escolha);
    return escolha;
}

/*Funćão que executa as operaćões escolhidas pelo usuário*/
void menuPrincipal(){
    Tree *root = treeInitialize();
    for(;;){
        int escolha = menu();

        switch(escolha){
            case 1: {
                root = treeInsert(root, infoCreate());
            }break;

            case 2: treePrintInOrder(root); break;

            case 3: treePrintPreOrder(root); break;

            case 4: treePrintPostOrder(root); break;

            case 0: {
                treeFree(root);
                exit(0);
            } break;

            default: printf("\nEscolha Inválida"); break;
        }
    }
}