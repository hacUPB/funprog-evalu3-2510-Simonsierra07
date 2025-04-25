

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
        return; 
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




**Calcular la Resistencia de un Conductor**


La resistencia eléctrica de un cable depende del material, su longitud, su grosor (área de sección transversal) y la temperatura. Cuando sube la temperatura, la resistencia también suele subir.

### Fórmulas:

1. **Resistencia a 20 °C** (temperatura estándar):
\[
R_{20} = \rho \cdot \frac{L}{A}
\]
- \( \rho \): resistividad del material (en ohm·metro, Ω·m)
- \( L \): longitud del conductor (en metros)
- \( A \): área de la sección transversal (en metros cuadrados)

2. **Resistencia corregida por temperatura**:
\[
R = R_{20} \cdot (1 + \alpha \cdot (T - 20))
\]
- \( \alpha \): coeficiente de temperatura del material
- \( T \): temperatura real de operación (en °C)

```c
#include <stdio.h>
#include <string.h>

int main() {
    char opcion[10];

    printf("\n¿Desea calcular resistencia de un conductor o de un LED? (conductor/led): ");
    scanf("%s", opcion);

    if (strcmp(opcion, "conductor") == 0) {
        char material[20];
        double resistividad, coef_temp;
        double longitud, area, temperatura;
        double R20, R;

        printf("\n--- CALCULAR RESISTENCIA DE UN CONDUCTOR ---\n");
        printf("Material (oro, cobre, aluminio, otros): ");
        scanf("%s", material);

        // Definimos valores de resistividad y coef_temp según el material
        if (strcmp(material, "oro") == 0) {
            resistividad = 2.44e-8;
            coef_temp = 0.0034;
        } else if (strcmp(material, "cobre") == 0) {
            resistividad = 1.68e-8;
            coef_temp = 0.00393;
        } else if (strcmp(material, "aluminio") == 0) {
            resistividad = 2.82e-8;
            coef_temp = 0.0039;
        } else {
            printf("Ingrese la resistividad del material (Ohm·metro): ");
            scanf("%lf", &resistividad);
            printf("Ingrese el coeficiente de temperatura (1/°C): ");
            scanf("%lf", &coef_temp);
        }

        // Pedimos datos físicos del conductor
        printf("Ingrese la longitud del conductor (metros): ");
        scanf("%lf", &longitud);
        printf("Ingrese el área de la sección transversal (m^2): ");
        scanf("%lf", &area);
        printf("Ingrese la temperatura de operación (°C): ");
        scanf("%lf", &temperatura);

        // Cálculo de resistencia a 20 °C
        R20 = resistividad * (longitud / area);

        // Cálculo considerando la temperatura real
        R = R20 * (1 + coef_temp * (temperatura - 20));

        printf("Resistencia del conductor a %.1f°C: %.6f ohmios\n", temperatura, R);
```


**Calcular Resistencia para un LED**

Un LED necesita una corriente muy específica. Si conectamos un LED directamente a una fuente de voltaje más alta que la tensión del LED, se quemará. Por eso usamos una resistencia limitadora, que absorbe el exceso de voltaje.

### Fórmulas:

1. **Voltaje sobre la resistencia**:
\[
V_R = V_{fuente} - V_{LED\_total}
\]
- Si están **en serie**: \( V_{LED\_total} = V_f \cdot n \)
- Si están **en paralelo**: \( V_{LED\_total} = V_f \)

2. **Resistencia necesaria**:
\[
R = \frac{V_R}{I_{total}}
\]

3. **Potencia disipada por la resistencia**:
\[
P_R = R \cdot I_{total}^2
\]

4. **Potencia total del circuito**:
\[
P_{total} = V_{fuente} \cdot I_{total}
\]


```c
    } else if (strcmp(opcion, "led") == 0) {
        double V_fuente, V_f, I_f, V_R, R, P_R, P_total, I_total;
        int num_leds;
        char tipo_conexion[10];

        printf("\n--- CALCULAR RESISTENCIA PARA UN LED ---\n");
        printf("Ingrese la tensión de la fuente (V): ");
        scanf("%lf", &V_fuente);
        printf("Ingrese el número de LEDs: ");
        scanf("%d", &num_leds);
        printf("Tipo de conexión (serie/paralelo): ");
        scanf("%s", tipo_conexion);
        printf("Ingrese la tensión nominal del LED (V): ");
        scanf("%lf", &V_f);
        printf("Ingrese la corriente nominal del LED (A): ");
        scanf("%lf", &I_f);

        // Calcular tensión que debe caer en la resistencia
        if (strcmp(tipo_conexion, "serie") == 0) {
            V_R = V_fuente - (V_f * num_leds);
            I_total = I_f;
        } else if (strcmp(tipo_conexion, "paralelo") == 0) {
            V_R = V_fuente - V_f;
            I_total = I_f * num_leds;
        } else {
            printf("Conexión no válida. Debe ser 'serie' o 'paralelo'.\n");
            return 1;
        }

        if (V_R <= 0) {
            printf("Error: la tensión de la fuente es insuficiente.\n");
            return 1;
        }

        R = V_R / I_total;
        P_R = R * I_total * I_total;
        P_total = V_fuente * I_total;

        printf("\n--- RESULTADOS ---\n");
        printf("Resistencia necesaria: %.2f ohmios\n", R);
        printf("Potencia disipada por la resistencia: %.2f W\n", P_R);
        printf("Potencia total del circuito: %.2f W\n", P_total);
        printf("Corriente total: %.2f A\n", I_total);
    } else {
        printf("Opción no reconocida.\n");
    }

    return 0;
}
```
