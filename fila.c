#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

//funcao que cria e inicializa a fila
FilaNo* criar_fila() {
    //aloca memoria para a estrutura da fila
    FilaNo* fila = (FilaNo*)malloc(sizeof(FilaNo));
    if (!fila) {
        printf("Erro ao alocar memoria para a fila\n");
        exit(EXIT_FAILURE);  //Caso falhe, termina o programa
    }
    fila->inicio = fila->fim = NULL;  //fila vazia no início
    fila->tamanho = 0;  //tamanho inicial eh 0
    return fila;
}

//funcao que insere um novo cliente no final da fila
void inserir_fila(FilaNo* fila, int idade) {
    //aloca memoria para um novo NO
    No* novoNo = (No*)malloc(sizeof(No));
    if (!novoNo) {
        printf("Erro ao alocar memoria para um novo no\n");
        exit(EXIT_FAILURE);  //caso falhe, termina o programa
    }
    novoNo->idade = idade;  //atribui a idade ao novo NO
    novoNo->prox = NULL;  //o novo NO não aponta para nada ainda

    //se a fila ja tiver elementos, o novo NO vai para o fim
    if (fila->fim != NULL) {
        fila->fim->prox = novoNo;
    } else {
        fila->inicio = novoNo;  //se a fila estava vazia, o novo NO eh o inicio
    }

    fila->fim = novoNo;  //atualiza o ponteiro do fim da fila
    fila->tamanho++;  //aumenta o tamanho da fila
}

//funcao que ordena a fila de forma decrescente pela idade
void ordenar_fila(FilaNo* fila) {
    //se a fila estiver vazia ou tiver apenas um elemento, nao eh necesssrio ordenar
    if (fila->inicio == NULL || fila->tamanho < 2) {
        return;
    }

    int trocado;
    do {
        trocado = 0;
        No* atual = fila->inicio;
        //percorre todos os NOS da fila
        while (atual->prox) {
            //se a idade do NO atual for menor que a do próximo, troca as idades
            if (atual->idade < atual->prox->idade) {
                int temp = atual->idade;
                atual->idade = atual->prox->idade;
                atual->prox->idade = temp;
                trocado = 1;  //indica que houve troca
            }
            atual = atual->prox;  //vai para o proximo NO
        }
    } while (trocado);  //continua ate nao haver mais trocas
}

//funcao que atende (remove) o primeiro cliente da fila
int atender_fila(FilaNo* fila) {
    //se a fila estiver vazia, retorna -1
    if (!fila->inicio) return -1;

    //remove o primeiro no da fila
    No* removido = fila->inicio;
    int idade = removido->idade;  //guarda a idade do cliente removido

    fila->inicio = removido->prox;  //o proximo NO se torna o inicio da fila
    if (fila->inicio == NULL) {
        fila->fim = NULL;  //se a fila ficou vazia, atualiza o fim para NULL
    }

    free(removido);  //libera a memoria do no removido
    fila->tamanho--;  //decrementa o tamanho da fila

    return idade;  //retorna a idade do cliente atendido
}

//funcao que destroi a fila e libera toda a memoria alocada
void destruir_fila(FilaNo* fila) {
    //enquanto houver clientes na fila ele vai atendendo e removendo
    while (fila->inicio) {
        atender_fila(fila);
    }
    free(fila);  //libera a memoria da estrutura da fila
}