#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    FILE* arquivo = fopen("clientes.txt", "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //Cria uma fila  
    FilaNo* fila = criar_fila();
    int idade;

    //Leitura das idades e inserção na fila
    while (fscanf(arquivo, "%d", &idade) != EOF) {
        printf("Lendo idade do Cliente: %d\n", idade);
        inserir_fila(fila, idade);
    }
    fclose(arquivo);

    //Faz a ordenação da fila
    printf("\nOrdenando Fila...\n");
    ordenar_fila(fila);

    //Atende e remove os clientes
    printf("\nAtendendo clientes:\n");
    while (fila->tamanho > 0) {
        int atendido = atender_fila(fila);
        printf("Cliente atendido(a): %d\n", atendido);
    }

    //Libera a memória alocada
    destruir_fila(fila);

    return 0;
}