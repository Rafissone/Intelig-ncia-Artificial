/*
    Nome: Rafissone Manuel Macilaho
    Curso: Engenharia Informática - Labora, Nível 3
    Cadeira: Inteligência Artificial (INAR)
    
    Resolućão da Primeira Tarefa
*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Estrutura de Informacao
typedef struct  info
{
    int value;
}Info;


//Estrutura de uma árvore binária
typedef struct tree
{
    Info info;
    struct tree *left;
    struct tree *right;
}Tree;

//Funcao que inicializa uma árvore binária
Tree *treeInitialize(){
    return NULL;
}

//Funcao que cria um nó de informacao e retorna o nó criado
Info infoCreate(){
    int cod;
    printf("\n Informe o valor: ");
    scanf("%d", &cod);
    Info item;
    item.value = cod;
    return item;
}

//Funcao que adiciona um nó na árvore e retorna o nó adicionado
Tree *treeInsert(Tree *root, Info info){
    //Caso a árvore esteja nula, vai-se alocar um espaćo e atribuir a informaćão
    if(root == NULL){
        Tree *auxiliary = (Tree *)malloc(sizeof(Tree));
        auxiliary->info = info;
        auxiliary->left = NULL;
        auxiliary->right = NULL;
        return auxiliary;
    }

    //Caso a árvore não esteja vazia 
    else{

        /*Se o  novo valor informado seja maior que o valor anterior da árvore, 
        este será  armazenado na sub-árvore a direita*/

        if(info.value > root->info.value){
            root->right = treeInsert(root->right, info);
        }
        
         /*Se o  novo valor informado seja menor que o valor anterior da árvore, 
        este será  armazenado na sub-árvore a esquerda*/

        else if(info.value < root->info.value){
            root->left = treeInsert(root->left, info);
        }

         /*Se o  novo valor informado seja igua ao valor anterior da árvore, 
        este será  ignorado*/

        else{
            printf("\nEste valor é igaual ao valor anterior da árvore\n");
            printf("Valor Ignorado\n");
        }
    }
    return root;
}


//Funcao que faz a busca por profundidade da árvore em ordem
void treePrintInOrder(Tree *root){
    if(root != NULL){
        
        treePrintInOrder(root->left);
        printf("Informacao: %d\n", root->info.value);
        treePrintInOrder(root->right);
    } 
}

//Funcao que faz a busca por profundidade da árvore em pré - ordem
void treePrintPreOrder(Tree *root){
    if(root != NULL){
        printf("Informacao: %d\n", root->info.value);
        treePrintPreOrder(root->left);
        treePrintPreOrder(root->right);
    } 
}

//Funcao que faz a busca por profundidade da árvore em pos - ordem
void treePrintPostOrder(Tree *root){
    if(root != NULL){
        treePrintPostOrder(root->left);
        treePrintPostOrder(root->right);
        printf("Informacao: %d\n", root->info.value);
    } 
}


//Funcao que liberta os nos da arvore
void treeFree(Tree *root){
    if(root != NULL){
        treeFree(root->left);
        treeFree(root->right);
        free(root);
    }
    
}
