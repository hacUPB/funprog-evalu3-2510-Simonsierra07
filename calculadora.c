#include <stdio.h>

int suma(int num1, int num2) {
    return num1 + num2;
}

int resta(int num1, int num2) {
    return num1 - num2;
}

int multiplicacion(int num1, int num2) {
    return num1 * num2;
}

float division(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: División por cero.\n");
        return 0;  // Retornar 0 en caso de error
    }
    return (float)num1 / num2;
}

int main() {
    int num1, num2;
    int opcion;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);  
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);  

    printf("Seleccione la operación a realizar:\n");
    printf("1. Suma\n2. Resta\n3. Multiplicación\n4. División\n");
   
    printf("Opción: ");
    scanf("%d", &opcion);

    switch(opcion) {
        case 1:
            printf("Resultado: %d\n", suma(num1, num2));
            break;
        case 2:
            printf("Resultado: %d\n", resta(num1, num2));
            break;
        case 3:
            printf("Resultado: %d\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("Resultado: %.2f\n", division(num1, num2));
            break;
        default:
            printf("Opción no válida.\n");
    }

    return 0;
}
