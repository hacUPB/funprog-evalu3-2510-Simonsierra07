#include <stdio.h>
#include <string.h>
#include <math.h>

void calcularLeyOhm() {
    int opcion;
    float V, I, R;

    printf("\nHas seleccionado calcular la Ley de Ohm.\n");
    printf("¿Qué parámetro deseas calcular?\n");
    printf("1. Calcular Tensión (V)\n");
    printf("2. Calcular Corriente (I)\n");
    printf("3. Calcular Resistencia (R)\n");
    printf("4. Volver al menú principal\n");
    printf("Ingresa la opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Ingresa la corriente (I en amperios): ");
        scanf("%f", &I);
        printf("Ingresa la resistencia (R en ohmios): ");
        scanf("%f", &R);
        V = I * R;
        printf("La Tensión es: %.2f V\n", V);
    } else if (opcion == 2) {
        printf("Ingresa la tensión (V en voltios): ");
        scanf("%f", &V);
        printf("Ingresa la resistencia (R en ohmios): ");
        scanf("%f", &R);
        I = V / R;
        printf("La Corriente es: %.2f A\n", I);
    } else if (opcion == 3) {
        printf("Ingresa la tensión (V en voltios): ");
        scanf("%f", &V);
        printf("Ingresa la corriente (I en amperios): ");
        scanf("%f", &I);
        R = V / I;
        printf("La Resistencia es: %.2f ohmios\n", R);
    } else {
        printf("Volviendo al menú...\n");
    }
}

void calcularFactorDePotencia() {
    int opcion;
    float P, S, V, I;

    printf("\nHas seleccionado calcular el Factor de Potencia.\n");
    printf("¿Qué deseas calcular?\n");
    printf("1. Potencia Activa (P)\n");
    printf("2. Potencia Aparente (S)\n");
    printf("3. Factor de Potencia (FP)\n");
    printf("Opción: ");
    scanf("%d", &opcion);

    if (opcion == 1) {
        printf("Tensión (V): ");
        scanf("%f", &V);
        printf("Corriente (I): ");
        scanf("%f", &I);
        P = V * I;
        printf("Potencia Activa: %.2f W\n", P);
    } else if (opcion == 2) {
        printf("Tensión (V): ");
        scanf("%f", &V);
        printf("Corriente (I): ");
        scanf("%f", &I);
        S = V * I;
        printf("Potencia Aparente: %.2f VA\n", S);
    } else if (opcion == 3) {
        printf("Potencia activa (P en W): ");
        scanf("%f", &P);
        printf("Tensión (V): ");
        scanf("%f", &V);
        printf("Corriente (I): ");
        scanf("%f", &I);
        S = V * I;
        if (S != 0)
            printf("Factor de Potencia: %.2f\n", P / S);
        else
            printf("La potencia aparente no puede ser cero.\n");
    } else {
        printf("Opción no válida.\n");
    }
}

void calcularResistenciaConductor() {
    char material[20];
    double resistividad, coef_temp, longitud, area, temperatura;
    double R20, R;

    printf("\n--- RESISTENCIA DE UN CONDUCTOR ---\n");
    printf("Material (oro, cobre, aluminio, otros): ");
    scanf("%s", material);

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
        printf("Resistividad del material (Ohm·m): ");
        scanf("%lf", &resistividad);
        printf("Coeficiente de temperatura (1/°C): ");
        scanf("%lf", &coef_temp);
    }

    printf("Longitud del conductor (m): ");
    scanf("%lf", &longitud);
    printf("Área de la sección transversal (m²): ");
    scanf("%lf", &area);
    printf("Temperatura (°C): ");
    scanf("%lf", &temperatura);

    R20 = resistividad * (longitud / area);
    R = R20 * (1 + coef_temp * (temperatura - 20));
    printf("Resistencia a %.1f°C: %.6f ohmios\n", temperatura, R);
}

void calcularResistenciaLED() {
    double V_fuente, V_f, I_f, V_R, R, P_R, P_total, I_total;
    int num_leds;
    char tipo_conexion[10];

    printf("\n--- RESISTENCIA PARA UN LED ---\n");
    printf("Tensión de la fuente (V): ");
    scanf("%lf", &V_fuente);
    printf("Número de LEDs: ");
    scanf("%d", &num_leds);
    printf("Tipo de conexión (serie/paralelo): ");
    scanf("%s", tipo_conexion);
    printf("Tensión nominal del LED (V): ");
    scanf("%lf", &V_f);
    printf("Corriente nominal del LED (A): ");
    scanf("%lf", &I_f);

    if (strcmp(tipo_conexion, "serie") == 0) {
        V_R = V_fuente - (V_f * num_leds);
        I_total = I_f;
    } else if (strcmp(tipo_conexion, "paralelo") == 0) {
        V_R = V_fuente - V_f;
        I_total = I_f * num_leds;
    } else {
        printf("Conexión no válida.\n");
        return;
    }

    if (V_R <= 0) {
        printf("Error: tensión insuficiente.\n");
        return;
    }

    R = V_R / I_total;
    P_R = R * I_total * I_total;
    P_total = V_fuente * I_total;

    printf("\n--- RESULTADOS ---\n");
    printf("Resistencia: %.2f ohmios\n", R);
    printf("Potencia en la resistencia: %.2f W\n", P_R);
    printf("Potencia total del circuito: %.2f W\n", P_total);
    printf("Corriente total: %.2f A\n", I_total);
}

//  MAIN 

int main() {
    int opcion;

    do {
        printf("\n=== CALCULADORA DE INGENIERÍA ===\n");
        printf("1. Calcular Ley de Ohm\n");
        printf("2. Calcular Factor de Potencia\n");
        printf("3. Calcular Resistencia de un Conductor\n");
        printf("4. Calcular Resistencia para un LED\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: calcularLeyOhm(); break;
            case 2: calcularFactorDePotencia(); break;
            case 3: calcularResistenciaConductor(); break;
            case 4: calcularResistenciaLED(); break;
            case 5: printf("¡Gracias por usar la calculadora!\n"); break;
            default: printf("Opción inválida.\n");
        }
    } while(opcion != 5);

    return 0;
}
