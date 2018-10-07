// André de Souza Ferreira //
// Código do Desafio 07 //

# include <stdio.h>
# include <stdlib.h>

struct treap {
    char letter;
    int number;
};

void treap(struct treap vector[], int N);

int main() {

    // Definição do número de casos:
    int cases, i, N;
    scanf("%d", &cases);

    while (cases--) {

        // Definição do tamanho do vetor de pares rótulo / prioridade:
        scanf("%d", &N);
        struct treap heap[N];

        // Colocando os inputs:

        for (i = 0; i < N; i++) {
            scanf("%c%*%d", &heap[i].letter, &heap[i].number);      
        }

        // Colocando os parênteses:

        printf("(\n");

        treap(heap, N);

        printf(")\n");

    
    }

    return 0;
}

void treap(struct treap vector[], int N) {
    
    int k;

    for (k = 0; k <= N; k++) {

        if (vector[k].number == 1) {

            printf("\n%c/%d\n)\n", vector[k].letter, vector[k].number);

        } else if (vector[k].number > vector[k+1].number && vector[k].number != 1) {

            printf("%c/%d\n(\n", vector[k].letter, vector[k].number);
            treap(vector + 1, N - 1);
            printf(")\n");
            break;

        } else if (vector[k].number < vector[k+1].number) {

            printf("(\n%c/%d\n", vector[k].letter, vector[k].number);
            treap(vector + 1, N - 1);
            printf(")\n");
            break;

        }

        
    }

}