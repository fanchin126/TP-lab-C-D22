#define _USE_MATH_DEFINES // Asegura que M_PI este disponible en <math.h>
#include <stdio.h>
#include <math.h>
#include "simulador.h"

// Inicializa los datos de la nave
int inicializar_nave(NaveOrion *nave, double altitud_inicial) {
    if (nave == NULL) return 0;

    nave->altitud = altitud_inicial;
    nave->radio_orbital = R_TIERRA + altitud_inicial;

    nave->velocidad_orbital = 0.0;
    nave->periodo_segundos = 0.0;
    nave->periodo_minutos = 0.0;
    nave->aceleracion_centripeta = 0.0;
    nave->desvio_lateral = 0.0;

    nave->fuerza_gravitatoria = 0.0;
    nave->fuerza_centripeta = 0.0;
    
    return 1;
}

// Calcula velocidad, periodo y aceleracion centripeta
int calcular_dinamica_orbital(NaveOrion *nave) {
    if (nave == NULL || nave->radio_orbital <= 0.0) return 0;

    // Velocidad orbital
    nave->velocidad_orbital = sqrt((G_GRAV * M_TIERRA) / nave->radio_orbital);

    // Periodo orbital usando M_PI de <math.h>
    nave->periodo_segundos = (2.0 * M_PI * nave->radio_orbital) / nave->velocidad_orbital;
    nave->periodo_minutos = nave->periodo_segundos / 60.0;

    // Aceleracion centripeta
    nave->aceleracion_centripeta = (nave->velocidad_orbital * nave->velocidad_orbital) / nave->radio_orbital;
    
    return 1;
}

// Calcula la fuerza gravitatoria y la centripeta
int calcular_fuerzas(NaveOrion *nave) {
    if (nave == NULL || nave->radio_orbital <= 0.0) return 0;

    // Fuerza gravitatoria: Fg = G * MT * m / r^2
    nave->fuerza_gravitatoria = (G_GRAV * M_TIERRA * M_ORION) / (nave->radio_orbital * nave->radio_orbital);

    // Fuerza centripeta: Fc = m * ac
    nave->fuerza_centripeta = M_ORION * nave->aceleracion_centripeta;
    
    return 1;
}

// Calcula la desviacion producida por el pulso lateral
int aplicar_pulso_lateral(NaveOrion *nave, double aceleracion, double delta_t) {
    if (nave == NULL) return 0;

    // Delta x = 1/2 * a * delta_t^2
    nave->desvio_lateral += 0.5 * aceleracion * delta_t * delta_t;
    
    return 1;
}

// Imprime el reporte completo
int imprimir_reporte_telemetria(const NaveOrion *nave) {
    if (nave == NULL) return 0;

    printf("\n");
    printf("====================================================\n");
    printf("          SIMULADOR ARTEMIS - NAVE ORION\n");
    printf("====================================================\n");

    printf("\n--- DATOS ORBITALES ---\n");
    printf("Altitud: %.2f m (%.2f km)\n", nave->altitud, nave->altitud / 1000.0);
    printf("Radio orbital: %.2f m\n", nave->radio_orbital);
    printf("Velocidad orbital: %.2f m/s\n", nave->velocidad_orbital);
    printf("Periodo orbital: %.2f segundos\n", nave->periodo_segundos);
    printf("Periodo orbital: %.2f minutos\n", nave->periodo_minutos);
    printf("Aceleracion centripeta: %.4f m/s^2\n", nave->aceleracion_centripeta);

    printf("\n--- ANALISIS DE FUERZAS ---\n");
    // Se cambia de %.2f a %g para habilitar notacion cientifica si el numero es muy grande
    printf("Fuerza gravitatoria: %g N\n", nave->fuerza_gravitatoria);
    printf("Fuerza centripeta: %g N\n", nave->fuerza_centripeta);
    printf("Diferencia entre fuerzas: %g N\n", fabs(nave->fuerza_gravitatoria - nave->fuerza_centripeta));

    printf("\nDemostracion fisica:\n");
    printf("La fuerza gravitatoria actua como fuerza centripeta.\n");
    printf("Fg = Fc, por lo tanto la nave puede mantener\n");
    printf("una orbita circular bajo el modelo planteado.\n");

    printf("\n--- PULSO LATERAL ---\n");
    printf("Desviacion lateral: %.2f m\n", nave->desvio_lateral);
    printf("La trayectoria deja de ser circular ideal debido\n");
    printf("a la aceleracion lateral aplicada.\n");
    printf("La desviacion calculada corresponde al modelo\n");
    printf("de aceleracion lateral constante durante el pulso.\n");

    printf("\n====================================================\n");
    
    return 1;
}