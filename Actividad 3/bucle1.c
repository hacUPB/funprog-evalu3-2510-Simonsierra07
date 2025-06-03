#include <stdio.h>

int main() {
    int numero, i, j;

  
    printf("Ingresa un numero: ");
    scanf("%d", &numero);

    
    for(i = 1; i <= numero; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d ", j); 
        }
        printf("\n");
    }
    for(i = numero - 1; i >= numero; i--) {
        for(i = 1; j <= i; j++) {
            printf("%d ", i); 
        }
        printf("\n");
    }
    return 0;
}