#include "list_encadeada.h"
#include <stdio.h>
#include <stdlib.h>
Lista *cria(){

return NULL;
}

Lista *inserir(Lista* l, int elem){ //passa a lista em que sera inserida, e insere o elemento

    No *novo = (No*) malloc(sizeof(No)); //cria uma nova lista

    novo->info = elem;
    novo->next = l;

    return novo;
}

void destroiLista(Lista *l){

    Lista *aux;

    while(l != NULL){

        aux = l->next;
        free(l);
        l = aux;
    }

}

void imprimeLista(Lista *l){

    Lista *aux;

    for(aux = l; aux != NULL; aux = aux->next){

        printf("%d\n", aux->info);

    }

}

Lista* remover(Lista *l, int elem){

    Lista* prev = NULL; //cria um previo para salvar o endereço do anterior
    Lista* aux = l;

    while(aux != NULL &&(aux->info != elem)){//enquanto nao estiver no final da lista, e o elemento lido nao for o desejado
        prev = aux;
        aux = aux->next;

    }

    if(aux == NULL){ //caso nao tenha encontrado o elemento, aux estara valendo null

        return l; //retorna a lista
    }
    else if(prev == NULL){//caso quiser remover o inicio da lista

        l = l->next;

    }
    else{ //caso queira remover algum elmento do meio ou final da fila

        prev->next = aux->next;
    }
    free(aux); //destroi o auxiliar
    return l;

}

int conta_nos (Lista* lista){

    int i = 0;
    Lista *aux = lista;

    while(aux != NULL){

        i++;
        aux = aux->next;

    }

return i;
}

Lista* procurar (Lista* lista, int elem){

    Lista *aux = lista;

    while(aux != NULL &&(aux->info != elem)){

        aux = aux->next;
    }

    return aux;
}

Lista* separa (Lista* lista, int n){

    Lista *fim = procurar(lista, n);//definindo o fim da lista
    Lista *lista2;
    lista2 = fim->next; //vai procurar o elemento "n" na lista e retornar o endereço dele
    fim->next = NULL;

    return lista2;
}

Lista* cria_circular (Lista *lista){

    Lista *inicio = lista;
    Lista *aux = lista;

    if(lista == NULL)
        return 0;

    while(aux->next != NULL){

        aux = aux->next;
    }

    aux->next = lista;

return lista;
}

int conta_nos_rec(Lista* lista){


    if(lista == NULL){

        return 0;
    }

    else
        return(1 + conta_nos_rec(lista->next));
}

Lista* remover_ex(Lista *lista, int elem){

    Lista *prv = NULL;
    Lista *v = lista;

        while ((v != NULL) && (v->info != elem)){

            prv = v;
            v = v->next;

        }

        if (v == NULL){

            return lista;
        }

        if (prv == NULL){
             lista = v->next;
        }

        else{

             prv->next = v->next;
        }

        free(v);

        return lista;
}

void imprime_descrescente_recursivo(Lista *l){

    if(l != NULL){

        imprime_descrescente_recursivo(l->next);
        printf("%d\n", l->info);
    }

}
