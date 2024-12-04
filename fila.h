#ifndef FILA_H
#define FILA_H

typedef struct NO{
    int idade;
    struct NO* prox;
}No;

typedef struct Fila{
    int tamanho;
    No* inicio;
    No* fim;
}FilaNo;

/* Funcao que inicializa a fila
 * Exemplo de uso:
 * FilaNo* fila = criar_fila();
 */
FilaNo* criar_fila();

/* Funcao que insere um novo cliente no final da fila
 * Exemplo de uso:
 * inserir_fila(fila, 25); //Por exemplo, insere um cliente de 25 anos na fila
 */
void inserir_fila(FilaNo* fila, int idade);

/* Funcao que ordena a fila de clientes pela idade(decrescente)
 * Exemplo de uso:
 * ordenar_fila(fila); //ordena a fila de clientes pela idade, do maior para o menor
 */
void ordenar_fila(FilaNo* fila);

/* Funcao que atende(remove) o primeiro cliente da fila
 * Exemplo de uso:
 * int idade_atendida = atender_fila(fila); //Remove e retorna a idade do cliente atendido
 */
int atender_fila(FilaNo* fila);

/* Funcao que libera toda a memoria alocada para a fila e seus elementos
 * Exemplo de uso:
 * destruir_fila(fila); //Libera a memoria da fila
 */
void destruir_fila(FilaNo* fila);

#endif