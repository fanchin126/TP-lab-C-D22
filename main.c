#include <stdio.h>
#include "simulador.h"
#include "validaciones.h"

// Muestra el menu principal
void mostrar_menu(void) {
    printf("\n");
    printf("========================================\n");
    printf("       SIMULADOR ARTEMIS - ORION\n");
    printf("========================================\n");
    printf("1. Iniciar simulacion orbital\n");
    printf("2. Salir\n");
    printf("========================================\n");
}

// Ejecuta una simulacion completa
void ejecutar_simulacion(void) {
    NaveOrion orion;

    double altitud;
    double aceleracion;
    double tiempo;

    printf("\n--- CONFIGURACION DE LA MISION ---\n");

    altitud = leer_numero("Ingrese la altitud orbital en metros: ", 0.0);
    aceleracion = leer_numero("Ingrese la aceleracion lateral en m/s^2: ", 0.0);
    tiempo = leer_numero("Ingrese la duracion del pulso en segundos: ", 0.0);

    // Inicializacion y cálculos con validación de estado (manejo de errores)
    if (!inicializar_nave(&orion, altitud)) {
        printf("Error: No se pudo inicializar la nave.\n");
        return;
    }
    
    if (!calcular_dinamica_orbital(&orion)) {
        printf("Error: Fallo en el calculo de dinamica orbital.\n");
        return;
    }
    
    if (!calcular_fuerzas(&orion)) {
        printf("Error: Fallo al calcular las fuerzas.\n");
        return;
    }
    
    if (!aplicar_pulso_lateral(&orion, aceleracion, tiempo)) {
        printf("Error: Fallo al aplicar el pulso lateral.\n");
        return;
    }

    // Reporte final
    imprimir_reporte_telemetria(&orion);
}

int main(void) {
    int opcion; // Se corrige el tipo de dato a int para el menu

    do {
        mostrar_menu();

        // Se castea el double de leer_numero a int
        opcion = (int)leer_numero("Seleccione una opcion (1-2): ", 1.0);

        if (opcion == 1) {
            ejecutar_simulacion();
        } else if (opcion == 2) {
            printf("\nFinalizando simulador Artemis...\n");
        } else {
            printf("\nOpcion incorrecta. Seleccione 1 o 2.\n");
        }

    } while (opcion != 2);

    return 0;
}
