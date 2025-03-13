#include <stdio.h>

int main() {
    int num1, num2;
    int opcion;

    printf("Ingrese el primer número: ");
    scanf("%f", &num1);
    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    printf("Seleccione la operación a realizar:\n");
    printf("1. Suma\n2. Resta\n3. Multiplicación\n4. División\n");
   
    printf("Opción: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            suma(num1, num2);
            break;
        case 2:
            resta(num1, num2);
            break;
        case 3:
            multiplicacion(num1, num2);
            break;
        case 4:
            division(num1, num2);
            break;
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}