#include <stdio.h>
#include "fila.h"

int main() {
    struct fila minhafila; // nome do registrador para facilitar

    int capacidade, op = 0, verificador, elemento, valor;


    printf ("Informe a capacidade da fila: ");
    scanf ("%d", &capacidade);

    criarfila (&minhafila, capacidade); // criação da fila

    while (op != 8) { // menu de opções
        printf("Informe a opção desejada:\n");
        printf("1. Incluir elemento.\n");
        printf("2. Retirar elemento.\n");
        printf("3. Verificar se a fila está vazia.\n");
        printf("4. Imprimir os valores que estão na fila.\n");
        printf("5. Mostrar o último elemento da fila.\n");
        printf("6. Mostrar o primeiro elemento da fila.\n");
        printf("7. Encerrar o programa.\n");

        scanf("%d", &op);

        switch (op) {

            case 1: { // incluir elemento
                verificador = full (&minhafila);

                if (verificador == -1) {
                    printf ("Não será possível incluir mais elementos, a fila está cheia!\n");
                }
                else {
                    printf ("A fila contém %d espaços vazios.\n", verificador);

                    printf ("Informe um valor para ser inserido na fila: \n");
                    scanf ("%d", &elemento);

                    insertion(&minhafila, elemento);
                }
                break;
            }

            case 2: { // retira o primeiro elemento incluido na fila (FIFO)
                verificador = empty(&minhafila);

                if (verificador == -1) {
                    printf ("A fila está vazia! Não será possível retirar nenhum elemento.\n");
                }
                else {
                    valor = remover(&minhafila);
                    printf ("O valor retirado foi: %d.\n", valor);
                }
                break;
            }

            case 3: { // verificar se a fila está vazia
                verificador = empty (&minhafila);

                if (verificador == -1) {
                    printf("A fila está vazia!\n");
                }
                else {
                    printf ("A fila contém %d elementos.\n", verificador);
                }
                break;
            }

            case 4: { // imprime os valores na tela
                verificador = empty (&minhafila);

                if (verificador == -1) {
                    printf ("A fila está vazia, não há valores para serem imprimidos.\n");
                }
                else {
                    imprime(&minhafila);
                }
                break;
            }

            case 5: { // mostra  o último elemento da fila
                verificador = empty(&minhafila);

                if (verificador == -1){
                    printf("A fila está vazia!\n");
                }
                else {
                    valor = ultimo(&minhafila);

                    printf("O último valor presente na fila é: %d.\n", valor);
                }
                break;
            }

            case 6: { // mostra o primeiro elemento da fila
                verificador = empty(&minhafila);

                if (verificador == -1){
                    printf("A fila está vazia!\n");
                }
                else {
                    valor = primeiro(&minhafila);

                    printf("O primeiro valor presente na fila é: %d.\n", valor);
                }
                break;
            }

            case 7: {
                op = 8;
                break;
            }
        }


    }



    return 0;
}
