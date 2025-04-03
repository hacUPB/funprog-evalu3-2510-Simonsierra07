#include <stdio.h>

void calcularLeyOhm();
void calcularFactorDePotencia();
void calcularResistenciaConductor();
void calcularResistenciaLED();

int main() {
    int opcion;

    do {
        printf("\nBienvenido a la Calculadora de Ingeniería\n");
        printf("Por favor, selecciona una opción:\n");
        printf("1. Calcular Ley de Ohm\n");
        printf("2. Calcular Factor de Potencia\n");
        printf("3. Calcular Resistencia de un Conductor\n");
        printf("4. Calcular Valor de la Resistencia para un LED\n");
        printf("5. Salir\n");
        printf("Ingresa el número de la opción deseada: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                calcularLeyOhm();
                break;
            case 2:
                calcularFactorDePotencia();
                break;
            case 3:
                calcularResistenciaConductor();
                break;
            case 4:
                calcularResistenciaLED();
                break;
            case 5:
                printf("¡Gracias por usar la calculadora!\n");
                break;
            default:
                printf("Opción no válida, intenta de nuevo.\n");
        }
    } while(opcion != 5);

    return 0;
}
