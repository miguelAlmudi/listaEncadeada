#include <stdio.h>
#include <stdlib.h>
#include "list_encadeada.h"

int main (){
    /*
    int v;
    Lista *lista1 = cria();
    srand(time(NULL));

    do{
        v = rand() % 14;
        lista1 = inserir(lista1, v);

    }while (v != 7);

    printf("Lista 1 antes separacao\n");
    imprimeLista(lista1);

    printf("digite o elemento de separacao\n");
    scanf("%d", &v);

    Lista *lista2 = separa(lista1, v);

    printf("Lista 1 depois da separacao:\n");
    imprimeLista(lista1);
    printf("\n");

    printf("Lista 2 depois da separacao:\n");
    imprimeLista(lista2);

    Lista* lista3 = cria_circular(lista1);

    imprimeLista(lista3);

    destroiLista(lista1);
    destroiLista(lista2);
    destroiLista(lista3);

    */

    Lista* lista1 = cria();
    lista1 = inserir(lista1, 1);
    lista1 = inserir(lista1, 2);

    printf("%d\n", conta_nos_rec(lista1));

    imprime_descrescente_recursivo(lista1);
return 0;
}
