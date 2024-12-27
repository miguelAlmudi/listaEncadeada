#include "lista.h"


Lista* criaLista(){
    return NULL;
}

int contaElementos(Lista* lista){

    int elementos = 0;

    if(lista == NULL)
        return 0;

    while(lista != NULL){

        elementos++;
        lista = lista->proximo;
    }
return elementos;
}

Lista* inserirElementoFinal(Lista* lista, int rg, char* nomeUsuario){

    Lista* novo = (Lista*) malloc(sizeof(Lista));
    Lista* aux = lista;
    novo->rg = rg;
    //novo->nome = nomeUsuario;
    strcpy(novo->nome, nomeUsuario);


    //caso for o primeiro elemento

    if(lista == NULL){

        novo->proximo = lista;
        novo->posicaoN = 1;
        //-----------------------
        printf("\tC = 1 - M = 1\n");
        
        return novo;
    }

    //caso qualquer
    int i = 2;
    while(aux->proximo != NULL){

        aux = aux->proximo;
        i++;//marcando posicao do elemento
    }

    //aux proximo vira o penultimo, e novo vira o ultimo
    novo->proximo = aux->proximo;
    novo->posicaoN = i;
    aux->proximo = novo;
    //-----------------------
    printf("\tC = %d - ", i+1);
    printf("M = %d\n", i+1);

    return lista;
}

Lista* inserirElementoInicial(Lista* lista, int rg, char* nomeUsuario){

    Lista* novo = (Lista*) malloc (sizeof(Lista));
    Lista* aux = lista;
    int comp = 0, mov = 0;
    novo->rg = rg;
    //novo->nome = nomeUsuario;
    strcpy(novo->nome, nomeUsuario);
    novo->posicaoN = 1;

    //caso for o elemento inicial

    if(lista == NULL){

        novo->proximo = lista;
        //-----------------------
        printf("\tC = 1 - M = 1\n");
        
        return novo;
    }
    comp++;

    //caso qualquer
    //remarcando as posicoes
    while(aux != NULL){

        aux->posicaoN++;
        aux = aux->proximo;
        comp++;
        mov++;

    }

    novo->proximo = lista;
    mov++;
    printf("\tC = %d - M = %d\n", comp, mov);

    return novo;

}

Lista* inserirElementoPosN(Lista* lista, int rg, char* nomeUsuario, int posN){

    Lista* novo = (Lista*) malloc (sizeof(Lista));
    Lista* aux = lista;
    int comp = 0, mov = 0;

    novo->rg = rg;
    strcpy(novo->nome, nomeUsuario);
    novo->posicaoN = posN;

    //caso for o elemento inicial

    if(lista == NULL || (posN == 1)){

        novo->proximo = lista;
        comp++;
        mov++;

        //atualizando posicoes
        while(aux != NULL){

            aux->posicaoN++;
            aux = aux->proximo;
            comp++;
            mov++;
        }

        printf("\tC = %d - M = %d\n", comp, mov);

        return novo;
    }

    //caso for um elemento intermediario
    if(contaElementos(lista) >= posN){
        Lista* anterior = aux;

        while((aux->posicaoN != posN)&& aux != NULL){

            anterior = aux;
            aux = aux->proximo;
            comp++;
            mov++;

        }
        //o elemento na posN ja existe
        if(aux->posicaoN == posN && aux != NULL){

            anterior->proximo = novo;
            novo->proximo = aux;


            //atualizando posicoes
            while(aux != NULL){

                aux->posicaoN++;
                aux = aux->proximo;
                comp++;
                mov++;
            }

        }
    }


    //caso for o elemento final (elemento nao existe na posN)
    if(contaElementos(lista) < posN){
        comp++;        
        lista = inserirElementoFinal(lista, rg, nomeUsuario);

    }

printf("\tC = %d - M = %d\n", comp, mov);
return lista;
}

Lista* retirarElementoInicial(Lista* lista){

    int comp = 0, mov = 0;

    if(lista == NULL)
        return NULL;

    Lista* aux = lista->proximo;
    free(lista);
    lista = aux;
    mov++;

    while(aux != NULL){

        aux->posicaoN--;
        aux = aux->proximo;
        comp++;
        mov++;
    }
printf("\tC = %d - M = %d\n", comp, mov);
return lista;
}

Lista* retirarElementoFinal(Lista* lista){

    int comp = 0, mov = 0;
    if(lista == NULL || lista->proximo == NULL)
        return NULL;

    Lista* aux = lista;
    Lista* anterior = lista;

    while(aux->proximo != NULL){

        anterior = aux;
        aux = aux->proximo;
        comp++;
        mov++;

    }

    anterior->proximo = aux->proximo;
    
    printf("\tC = %d - M = %d\n", comp, mov);
    free(aux);

return lista;
}

Lista* retirarElementoPosN(Lista* lista, int posN){

    int comp = 0, mov = 0;
    //caso lista estiver vazia
    if(lista == NULL)
        return NULL;

    //caso for o primeiro da lista

    if(posN == 1){

        return (retirarElementoInicial(lista));

    }

    Lista* aux = lista;
    Lista* auxAnterior;

    while((posN != aux->posicaoN) && (aux->proximo != NULL)){

        auxAnterior = aux;
        aux = aux->proximo;
        comp++;
        mov++;

    }


    if(posN == aux->posicaoN){

        auxAnterior->proximo = aux->proximo;
        free(aux);
        aux = auxAnterior->proximo;
        comp++;
        mov++;

        while(aux != NULL){

            aux->posicaoN--;
            aux = aux->proximo;
            comp++;
            mov++;
        }
        printf("\tC = %d - M = %d\n", comp, mov);
        return lista;
    }

    if(aux->proximo == NULL){

        return (retirarElementoFinal(lista));
    }


}

void imprimirLista(Lista* lista){

if(lista == NULL){

    printf("lista vazia\n");
}

else{

    while(lista != NULL){

        printf("Pos: %d ", lista->posicaoN);
        printf("RG: %d ", lista->rg);
        printf("Nome: %s \n", lista->nome);
        lista = lista->proximo;

    }
    printf("\n");

}
}

void salvaLista(Lista* lista, char* nomeArquivo){

    FILE* listaSalva = fopen(nomeArquivo, "w+");
    Lista* aux = lista;

    while(aux != NULL){

        fprintf(listaSalva, "%s,%d\n", aux->nome, aux->rg);
        aux = aux->proximo;
    }
    fclose(listaSalva);
}

void procuraElemento(Lista* lista, int rg){

    int comp = 0, mov = 0;
    if(lista == NULL)
        printf("\tLista vazia\n");

    while(lista->rg != rg && lista->proximo != NULL){

        lista = lista->proximo;
        mov++;
        comp++;
    }
    if(lista->proximo == NULL && lista->rg != rg)
        printf("\tElemento nao consta\n");
        
    if(lista->rg == rg)
        printf("\tEncontrado: %s - Rg: %d - Posicao: %d\n", lista->nome, lista->rg, lista->posicaoN);

printf("\tC = %d - M = %d\n", comp, mov);
}

Lista* carregaLista(Lista* lista, char* nomeArquivo){

    FILE* listaNomes = fopen(nomeArquivo, "r");
    char nome[25];
    int rg = 0, i = 0, j = 0, k = 0, flag = 0;
    char rgStr[10] = {0};
    char buffer[40] = {0};


    if(listaNomes == NULL)
        return NULL;

    while(fscanf(listaNomes, "%[^\n]\n", buffer) != EOF){

        i = 0;
        j = 0;
        k = 0;

        char nome[25] = {0};
        char rgStr[10] = {0};
        //for(int l = 0; l < 25; l++){
            //nome[l] = '0';
        //}

        //flag = 0;

        while(buffer[i] != '\0')
        {

            if(((buffer[i] >= 'a') && (buffer[i] <= 'z')) || ((buffer[i] >= 'A') && (buffer[i] <= 'Z'))){
                nome[j] = buffer[i];
                j++;
            }

            if((buffer[i] >= '0') && (buffer[i] <= '9')){

                rgStr[k] = buffer[i];
                k++;

            }

            i++;
        }
        rg = atoi(rgStr);
        //printf("\t %s %d \n", nome, rg);
        lista = inserirElementoFinal(lista, rg, nome);

    }
    fclose(listaNomes);
    return lista;
}

void destroiLista(Lista* lista){

    Lista* aux = lista;

    while(lista != NULL){

        aux = lista;
        lista = lista->proximo;
        free(aux);

    }
    free(lista);
}
