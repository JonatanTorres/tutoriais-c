#include <stdio.h>
int main() {
    int variavelInt = 50;
    printf("variavelInt:\n");
    printf("endereço: %d\n",&variavelInt);
    printf("valor: %d\n",variavelInt);
    printf("-----------\n\n");

    int* ponteiroVariavel = &variavelInt;
    printf("ponteiroVariavel:\n");
    printf("endereço: %d\n",&ponteiroVariavel);
    printf("valor: %d\n",ponteiroVariavel);
    printf("valor*: %d\n",*ponteiroVariavel);
    printf("-----------\n\n");

    int** ponteiroDePointeiro = &ponteiroVariavel;
    printf("ponteiroVariavel:\n");
    printf("endereço: %d\n",&ponteiroDePointeiro);
    printf("valor: %d\n",ponteiroDePointeiro);
    printf("valor*: %d\n",*ponteiroDePointeiro);
    
    return 0;
}