

El programa tendrá un **menú principal** que te permitirá elegir entre varias opciones. Dependiendo de la opción que elijas, el programa realizará diferentes cálculos relacionados con la ingeniería eléctrica, como la Ley de Ohm, el factor de potencia, la resistencia de un conductor y la resistencia para un LED.


#### 1. Menú Principal

En el menú principal, el usuario elige qué cálculo desea hacer. El programa se repetirá hasta que el usuario elija salir.

```c
#include <stdio.h>
#include <math.h>

// Declaración de funciones para cada opción
void calcularLeyOhm();
void calcularFactorDePotencia();
void calcularResistenciaConductor();
void calcularResistenciaLED();

int main() {
    int opcion;

    // Bucle principal que muestra el menú hasta que el usuario quiera salir
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

        // Llamamos a la función correspondiente según la opción seleccionada
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
    } while(opcion != 5);  // El bucle se repite hasta que el usuario seleccione '5'

    return 0;
}
```

#### 2. Función para la Ley de Ohm

La Ley de Ohm nos dice que:

- V = I * R (Tensión)
- I = V/R (Corriente)
- R = V/I (Resistencia)


Aquí pedimos al usuario que ingrese los valores necesarios según lo que quiera calcular.

```c
void calcularLeyOhm() {
    int opcion;
    float V, I, R;

    // Submenú para elegir qué calcular
    printf("\nHas seleccionado calcular la Ley de Ohm.\n");
    printf("¿Qué parámetro deseas calcular?\n");
    printf("1. Calcular Tensión (Voltaje)\n");
    printf("2. Calcular Corriente\n");
    printf("3. Calcular Resistencia\n");
    printf("4. Volver al menú principal\n");
    printf("Ingresa el número de la opción deseada: ");
    scanf("%d", &opcion);

    // Realizamos el cálculo dependiendo de la opción seleccionada
    if (opcion == 1) {
        // Calcular Tensión (V)
        printf("Ingresa el valor de la corriente (I) en amperios: ");
        scanf("%f", &I);
        printf("Ingresa el valor de la resistencia (R) en ohmios: ");
        scanf("%f", &R);
        V = I * R;
        printf("La Tensión es: %.2f V\n", V);
    } 
    else if (opcion == 2) {
        // Calcular Corriente (I)
        printf("Ingresa el valor de la tensión (V) en voltios: ");
        scanf("%f", &V);
        printf("Ingresa el valor de la resistencia (R) en ohmios: ");
        scanf("%f", &R);
        I = V / R;
        printf("La Corriente es: %.2f A\n", I);
    } 
    else if (opcion == 3) {
        // Calcular Resistencia (R)
        printf("Ingresa el valor de la tensión (V) en voltios: ");
        scanf("%f", &V);
        printf("Ingresa el valor de la corriente (I) en amperios: ");
        scanf("%f", &I);
        R = V / I;
        printf("La Resistencia es: %.2f ohmios\n", R);
    } 
    else if (opcion == 4) {
        return;  // Volver al menú principal
    } 
    else {
        printf("Opción no válida.\n");
    }
}
```


La fórmula para el **factor de potencia** (FP) es:


FP= P/S


Donde:
- P es la potencia activa en **watts (W)**.
- S es la potencia aparente en **volt-amperios (VA)**, que se calcula como:


S = V * I

Simplemente pedimos al usuario que ingrese la **potencia activa (P)**, **tensión (V)** y **corriente (I)**, y luego calculamos la **potencia aparente (S)**. Finalmente, calculamos el **factor de potencia** utilizando la fórmula anterior.

### Código para el Cálculo Simplificado del Factor de Potencia

```c
void calcularFactorDePotencia() {
    int opcion;
    float P, S, V, I;

    printf("\nHas seleccionado calcular el Factor de Potencia.\n");
    printf("¿Qué parámetro deseas calcular?\n");
    printf("1. Calcular Potencia Activa (P)\n");
    printf("2. Calcular Potencia Aparente (S)\n");
    printf("3. Calcular Factor de Potencia (FP)\n");
    printf("Ingresa el número de la opción deseada: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        // Calcular Potencia Activa (P)
        printf("Ingresa el valor de la tensión (V) en voltios: ");
        scanf("%f", &V);
        printf("Ingresa el valor de la corriente (I) en amperios: ");
        scanf("%f", &I);
        // Potencia activa es simplemente P = V * I
        P = V * I;
        printf("La Potencia Activa es: %.2f W\n", P);
    } 
    else if (opcion == 2) {
        // Calcular Potencia Aparente (S)
        printf("Ingresa el valor de la tensión (V) en voltios: ");
        scanf("%f", &V);
        printf("Ingresa el valor de la corriente (I) en amperios: ");
        scanf("%f", &I);
        // Potencia aparente es S = V * I
        S = V * I;
        printf("La Potencia Aparente es: %.2f VA\n", S);
    } 
    else if (opcion == 3) {
        // Calcular Factor de Potencia (FP)
        printf("Ingresa el valor de la potencia activa (P) en watts: ");
        scanf("%f", &P);
        printf("Ingresa el valor de la tensión (V) en voltios: ");
        scanf("%f", &V);
        printf("Ingresa el valor de la corriente (I) en amperios: ");
        scanf("%f", &I);
        
        // Calculamos la potencia aparente: S = V * I
        S = V * I;
        
        // Ahora calculamos el factor de potencia FP = P / S
        if (S != 0) {  // Para evitar la división por cero
            float FP = P / S;
            printf("El Factor de Potencia es: %.2f\n", FP);
        } else {
            printf("La potencia aparente no puede ser cero. Verifica los valores ingresados.\n");
        }
    } 
    else {
        printf("Opción no válida.\n");
    }
}
```

### Explicación del Código

1. **Potencia Activa (P)**: Es simplemente el producto de la tensión V y la corriente I:
   
   P = V * I
   
   El usuario ingresa V y I, y el programa calcula P.

2. **Potencia Aparente (S)**: También es el producto de la tensión V y la corriente I:
   
   S = V * I
   
   El usuario ingresa V y I, y el programa calcula S.

3. **Factor de Potencia (FP)**: Es la relación entre la potencia activa P y la potencia aparente S:

   FP = P/S
   
   El programa calcula S a partir de V y I, y luego calcula el **factor de potencia** dividiendo P entre S.

