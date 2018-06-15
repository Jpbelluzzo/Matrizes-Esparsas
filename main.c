#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main()
{
    int opcao;
    int verifica=0;
    int atribuiu=0;
    int linhas, colunas;
    struct elemento *A;
    A=NULL;
    struct elemento *B;
    B=A;
    printf(" Matriz Esparsa - Introducao a Ciencia da Computacao I - SSC0600");

    while(1){

        menu();
        scanf("%d",&opcao);

        if(opcao==1){

            if(verifica){
                printf("Matriz ja criada.");
            }else{
            printf("Digite o tamanho da matriz:");

            printf("\n Linhas:");
            scanf("%d",&linhas);
            while(linhas<=0){
                printf("Digite um numero valido.\n Linhas:");            //Verifica se a linha é válida
                scanf("%d",&linhas);
            }

            printf(" Colunas:");
            scanf("%d",&colunas);

            while(colunas<=0){
                printf("Digite um numero valido.\n Colunas:");          //Verifica se a linha é válida
                scanf("%d",&colunas);
            }

            printf("\n\nMatriz criada com sucesso!\n");
            verifica=1;
            }
        }
        if(opcao==2){
            if(verifica){
                free(A);
                free(B);
                A=NULL;
                B=A;
                verifica=0;                             //zera os 'flags'
                atribuiu=0;
                printf("\nMatriz excluida com sucesso.");
            }else{printf("Nenhuma matriz criada.");}
        }
        if(opcao==3){
            if(verifica){
                int linhaconsulta;
                int colunaconsulta;
                int encontrou=0;
                float numero;
                struct elemento *procura;
                procura=A;

                printf("Digite a posicao que sera consultada:");

                printf("\n Linha:");
                linhaconsulta=verificalinha(linhaconsulta,linhas);

                printf(" Coluna:");
                colunaconsulta=verificacoluna(colunaconsulta,colunas);

                while((procura)!=NULL){
                    if(linhaconsulta==(procura->linha) && colunaconsulta==(procura->coluna) ){
                        encontrou=1;
                        numero=(procura->valor);                    //busca entre os elementos atribuídos
                        break;
                    }
                    procura=(procura->prox);
                }
                if(encontrou){                                      //se encontrou, printa o valor
                    printf("O valor da posicao e: %.2f",numero);
                }else{printf("O valor da posicao e: 0");}           //se não encontrou, printa 0


            }else{printf("Nenhuma matriz criada.");}
        }
        if(opcao==4){
            if(verifica){
                int linhaconsulta;
                float somalinha=0;
                struct elemento *percorre;
                percorre=A;

                printf("Digite a linha cuja soma sera consultada:");
                linhaconsulta=verificalinha(linhaconsulta,linhas);

                while((percorre)!=NULL){
                    if(percorre->linha==linhaconsulta){             //quando a linha for igual soma em 'somalinha'
                        somalinha+=percorre->valor;
                    }
                    percorre=percorre->prox;
                }
                printf("\n\nA soma dos elementos da linha %d e: %.2f",linhaconsulta,somalinha);

            }else{printf("Nenhuma matriz criada.");}
        }
        if(opcao==5){
            if(verifica){
                int colunaconsulta;
                float somacoluna=0;
                struct elemento *percorre;
                percorre=A;

                printf("Digite a coluna cuja soma sera consultada:");
                colunaconsulta=verificacoluna(colunaconsulta,colunas);

                while((percorre)!=NULL){
                    if(percorre->coluna==colunaconsulta){           //quando a coluna for igual, soma em 'somacoluna'
                        somacoluna+=percorre->valor;
                    }
                    percorre=percorre->prox;
                }
                printf("\n\nA soma dos elementos da coluna %d e: %.2f",colunaconsulta,somacoluna);
            }else{printf("Nenhuma matriz criada.");}
        }
        if(opcao==6){

            if(verifica){

                int atriblinha;
                int atribcoluna;
                float num;
                int encontrou=0;
                struct elemento *percorre;

                printf("Digite a posicao em que sera atribuido o valor:");

                printf("\n Linha:");
                atriblinha=verificalinha(atriblinha,linhas);

                printf(" Coluna:");
                atribcoluna=verificacoluna(atribcoluna,colunas);

                printf(" Digite um valor:");
                scanf("%f", &num);

                if(atribuiu){       //Verifica se é a primeira atribuição à matriz

                    percorre=A;
                    while(percorre!=NULL){
                        if(atriblinha==percorre->linha && atribcoluna==percorre->coluna){
                            encontrou++;                                                    //Verifica se já houve atribuição
                            break;                                                          //de valor naquela posição
                        }
                        percorre=percorre->prox;
                    }

                    if(encontrou){                                         //se já há algum elemento diferente de 0 na posição...
                        percorre->valor=num;
                    }else{                                                                  //se a posição está com o elemento 0
                        (B->prox)=(struct elemento*)calloc(1,sizeof(struct elemento));
                        B->ant=B;
                        B=B->prox;
                        B->prox=NULL;
                        B->linha=atriblinha;
                        B->coluna=atribcoluna;
                        B->valor=num;
                        }

                }else{                                           //...se já foi atribuído pelo usuário algum elemento na matriz

                    A=(struct elemento*)calloc(1,sizeof(struct elemento));
                    A->ant=NULL;
                    A->prox=NULL;
                    A->linha=atriblinha;
                    A->coluna=atribcoluna;
                    A->valor=num;
                    B=A;
                }

                atribuiu=1;
                printf("\nValor atribuido!");

            }else{printf("Nenhuma matriz criada.");}
        }
        if(opcao==7){
                return 0;
        }


        if(fim()){return 0;}
    }
}
