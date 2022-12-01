#include <stdio.h>

typedef struct exemplo
    {
        double id;
        int valor;
    } Exemplo;

typedef struct exemplo2
    {
        int id;
        Exemplo* exemplo;
    } Exemplo2;

int main() {


    int* vetorInt;

    Exemplo* vetorExemplo;

    vetorExemplo = malloc(sizeof(Exemplo) * 5);

    vetorExemplo[3].valor = 50;

    printf("%d\n\n", vetorExemplo[3].valor);

    int vetorIntNormal[5];

    vetorInt = malloc((int) sizeof(int) * 5);

    printf("%d\n",sizeof(vetorInt));
    printf("%d\n\n",sizeof(vetorIntNormal));

    vetorInt[0] = 5;
    vetorInt[1] = 10;
    vetorInt[2] = 15;

    printf("%d\n", vetorInt[0]);
    printf("%d\n", vetorInt[1]);
    printf("%d\n", vetorInt[2]);

    return 0;
}