#ifndef FILA_FILA_H
#define FILA_FILA_H

#include <stdlib.h>

struct fila {
    int pos_ini; // posição de um primeiro elemento
    int pos_fim; // posição do último elemento
    int qtditens; // qtd de itens no vetor
    int cap; // capacidade da fila
    int *fila; // vetor fila que será manipulado
};

void criarfila (struct fila *f, int capacidade) {
    f->pos_ini = 0; // posição inicial
    f->pos_fim = -1; // posição final vazio
    f->qtditens = 0; // quantidade de itens
    f->cap = capacidade; // capacidade
    f->fila = (int *) malloc(capacidade * sizeof(int)); //alocação dinâmica da memória - cria o vetor fila com n capacidades

    if (f->fila == NULL) { // verificar se a alocação foi bem-sucedida
        printf("Erro ao alocar memória para a fila.\n");
        exit(EXIT_FAILURE);
    }
}

void imprime (struct fila *f) { // imprime os valores na tela
    printf ("Os valores que estão na fila são:\n");

    for (int i = f->pos_ini, j=0; j < (f->qtditens); i++, j++) {
        printf("Posição %d: %d.\n", j+1, f->fila[i]);
    }
}

int full (struct fila *f) { // tratamento overflow
    if ((f->qtditens) == (f->cap)) { // fila está cheia
        return -1;
    }
    else {
        return (f->cap - f->qtditens); // retorna a qtd de espaços vazios na fila
    }
}

int empty (struct fila *f) { // tratamento underflow
    if (f->qtditens == 0) { // fila está vazia
        return -1;
    }
    else {
        return (f->qtditens); // fila contém elementos, retorna a qtd de elementos
    }
}

int ultimo (struct fila *f) { // mostra o último elemento da fila
    int aux = f->fila[f->pos_fim];
    return aux;
}

int primeiro (struct fila *f) { // mostra o primeiro elemento da fila
   int aux = f->fila[f->pos_ini];
   return aux;
}

void insertion (struct fila *f, int numeroincluido) { // inclui elementos novos na fila
    if (f->pos_fim == f->cap - 1) {
        f->pos_fim = -1;
    }

    f->pos_fim++;
    f->fila[f->pos_fim] = numeroincluido;
    f->qtditens++;
}

int remover (struct fila *f) { // remove os elementos na fila (FIFO)
        int aux = f->fila[f->pos_ini]; // variavel aux recebe o valor retirado

        f->pos_ini++; // incrementa a posição inicial

        if (f->pos_ini == f->cap) { // verifica se a posição inicial é igual a capacidade
            f->pos_ini = 0; // se for, a pos_ini inicializa com 0 novamente (implementação circular)
        }
        f->qtditens--; // decrementa a quantidade de itens no vetor
        return aux; // retorna o valor retirado
}








#endif // FILA_FILA_H