#ifndef LIST_ENCADEADA_H_INCLUDED
#define LIST_ENCADEADA_H_INCLUDED

typedef struct no{

    int info;
    struct No *next;

}No, Lista;

Lista *cria();
Lista *inserir(Lista* l, int elem);
void destroiLista(Lista *l);
void imprimeLista(Lista *l);
Lista* remover(Lista *l, int elem);
int conta_nos (Lista* lista);
Lista* procurar (Lista* lista, int elem);
Lista* separa (Lista* lista, int n);
Lista* cria_circular (Lista *lista);
int conta_nos_rec(Lista* lista);
Lista* remover_ex(Lista *lista, int elem);
void imprime_descrescente_recursivo(Lista *l);

#endif // LIST_ENCADEADA_H_INCLUDED
