#include "lista_2encadeada.h"

Lista* insertFront(Lista* L, int elem){

    Lista* novo = (Lista*) malloc (sizeof(Lista));
    novo->info = elem;
    novo->prev = NULL;
    novo->next = L;

    if(L != NULL){//caso nao for o primeiro da lista

        L->prev = novo;
    }
    return novo;
}
