#ifndef LISTA_2ENCADEADA_H_INCLUDED
#define LISTA_2ENCADEADA_H_INCLUDED

typedef struct node{

    int info;
    struct node *prev;
    struct node *next;

}Lista;

Lista* insertFront(Lista* L, int elem);

#endif // LISTA_2ENCADEADA_H_INCLUDED
