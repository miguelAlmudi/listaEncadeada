#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{

    int posicaoN;
    int rg;
    char nome[25];
    struct no* proximo;

}Lista;

Lista* criaLista();

int contaElementos(Lista* lista);

Lista* inserirElementoFinal(Lista* lista, int rg, char* nomeUsuario);

Lista* inserirElementoInicial(Lista* lista, int rg, char* nomeUsuario);

Lista* inserirElementoPosN(Lista* lista, int rg, char* nomeUsuario, int posN);

Lista* retirarElementoInicial(Lista* lista);

Lista* retirarElementoFinal(Lista* lista);

Lista* retirarElementoPosN(Lista* lista, int posN);

void imprimirLista(Lista* lista);

Lista* carregaLista(Lista* lista, char* nomeArquivo);

void salvaLista(Lista* lista, char* nomeArquivo);

void procuraElemento(Lista* lista, int rg);

void destroiLista(Lista* lista);

#endif // LISTA_H_INCLUDED
