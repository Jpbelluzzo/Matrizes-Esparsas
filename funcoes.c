#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void menu(){
    printf("\n\n1.Criar matriz");
    printf("\n2.Excluir matriz");
    printf("\n3.Consultar valor da matriz");
    printf("\n4.Consultar soma dos valores de uma linha da matriz");
    printf("\n5.Consultar soma dos valores de uma coluna da matriz");
    printf("\n6.Atribuir um valor a uma posicao da matriz");
    printf("\n7.Sair");
    printf("\n\nSelecione uma opcao:");
}

int fim(){
    int saida=0;
    printf("\n\n1.Voltar ao menu principal");
    printf("\n2.Sair");
    scanf("%d",&saida);
    if(saida==2){
        return 1;
    }
    system("cls");
    return 0;
}

int verificalinha(int linhadada, int linhastotal){
    scanf("%d",&linhadada);
    while(linhadada<0 || linhadada>(linhastotal-1)){
        printf("\nDigite uma linha valida.\n\n Linha:");        //Verifica se a linha é válida
        scanf("%d",&linhadada);
        }

    return linhadada;
}

int verificacoluna(int colunadada, int colunastotal){
     scanf("%d",&colunadada);
     while(colunadada<0 || colunadada>(colunastotal-1)){
        printf("\nDigite uma coluna valida.\n\n Coluna:");          //Verifica se a coluna é válida
        scanf("%d",&colunadada);
    }
    return colunadada;
}
