#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"

void printClock(clock_t tempo){

    tempo = clock() - tempo;
        printf("Tempo exec: %f ms = %f s\n", ((double)tempo)/((CLOCKS_PER_SEC/1000)), ((double)tempo)/((CLOCKS_PER_SEC)));

}

int main()
{
    Lista* lista = criaLista();

    system("title Trabalho 1 Estrutura de dados 1 - Miguel Almudi");
    int var = 1, RG, posN, aux;
    clock_t t;
    char nome[20];
    char* rgString;


    while(var){
        system("pause");
        printf("\tSelecionar uma Opcao:\n");
        printf("\t1) Inserir no Inicio\n");
        printf("\t2) Inserir no Fim\n");
        printf("\t3) Inserir na Posicao N\n");
        printf("\t4) Retirar no Inicio\n");
        printf("\t5) Retirar no Fim\n");
        printf("\t6) Retirar na Posicao N\n");
        printf("\t7) Imprimir Lista\n");
        printf("\t8) Salvar Lista\n");
        printf("\t9) Carregar Lista\n");
        printf("\t10) Sair do Sistema\n");
        printf("\t11) Limpar buffer\n");
        printf("\t12) Procurar um elemento\n");
        scanf("%d", &var);


        if(var == 1){

        //lista encadeada
            printf("\tDigite:\n");
            printf("\tNome\n");
            scanf("%s", nome);
            //fflush(stdin);
            //gets(nome);

            printf("\tRG\n");

            scanf("%d", &RG);
            //printf("passou");

            t = clock();
            lista = inserirElementoInicial(lista, RG, nome);

        }

        else if(var == 2){

            printf("\tDigite no seguite formato:\n");
            printf("\tNome RG\n");
            scanf("%s %d", nome, &RG);
            t = clock();
            lista = inserirElementoFinal(lista, RG, nome);

        }

        else if(var == 3){

            printf("\tDigite no seguite formato:\n");
            printf("\tNome RG PosicaoNaLista\n");
            scanf("%s %d %d", nome, &RG, &posN);
            t = clock();
            lista = inserirElementoPosN(lista, RG, nome, posN);
        }

        else if(var == 4){

            t = clock();
            lista = retirarElementoInicial(lista);
            printf("\tRemovido o elemento inicial\n");

        }

        else if(var == 5){

            t = clock();
            lista = retirarElementoFinal(lista);
            printf("\tRemovido o elemento final\n");

        }

        else if(var == 6){
            printf("\tDigite um elemento para ser retirado\n");
            scanf("%d", &aux);
            t = clock();
            lista = retirarElementoPosN(lista, aux);
            printf("\tRemovido o elemento da posicao %d\n", aux);

        }

        else if(var == 7){
            t = clock();
            printf("\t ----- Lista Encadeada ----- \n");
            imprimirLista(lista);

        }

        else if(var == 8){

            t = clock();
            salvaLista(lista, "listaSalva.txt");
            printf("\tlista salva\n");
        }

        else if(var == 9){
            t = clock();
            lista = carregaLista(lista, "NomeRG10K.txt");

            if(lista == NULL)
                printf("\tErro ao carregar lista!\n");
        }

        else if(var == 10){
            destroiLista(lista);
            var = 0;
            return 0;
        }

        else if(var == 11){

            system("cls");

        }

        else if(var == 12){

            printf("\t%d elementos cadastrados\n", contaElementos(lista));
            printf("\tDigite um rg:\n");
            scanf("%d", &RG);
            t = clock();
            procuraElemento(lista, RG);
        }

        else{
            printf("\tCOMANDO INVALIDO!\n");
        }

        printClock(t);
        //t = clock() - t;
        //printf("Tempo exec: %.4f ms = %.4f s\n", ((double)t)/((CLOCKS_PER_SEC/1000)), ((double)t)/((CLOCKS_PER_SEC)));
    }
/**/

    return 0;
}
