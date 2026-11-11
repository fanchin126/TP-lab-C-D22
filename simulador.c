#include <stdio.h>
#include <math.h>
#include "simulador.h"

// Inicializa la nave con la altitud ingresada y radio r = R_T + h
void inicializar_nave(NaveOrion *nave, double altitud_inicial) {
    if (nave == NULL) return;

    nave->altitud = altitud_inicial;
    nave->radio_orbital = R_TIERRA + altitud_inicial;
    nave->velocidad_orbital = 0.0;
    nave->periodo_segundos = 0.0;
    nave->periodo_minutos = 0.0;
    nave->aceleracion_centripeta = 0.0;
    nave->desvio_lateral = 0.0;
}

// Resuelve incisos 1, 2 y 3 del problema físico
void calcular_dinamica_orbital(NaveOrion *nave) {
    if (nave == NULL) return;

    // 1. Velocidad Orbital: v = sqrt((G * M_T) / r)
    nave->velocidad_orbital = sqrt((G_GRAV * M_TIERRA) / nave->radio_orbital);

    // 2. Período Orbital: T = (2 * PI * r) / v
    nave->periodo_segundos = (2.0 * PI * nave->radio_orbital) / nave->velocidad_orbital;
    nave->periodo_minutos = nave->periodo_segundos / 60.0;

    // 3. Aceleración Centrípeta: ac = (v^2) / r
    nave->aceleracion_centripeta = pow(nave->velocidad_orbital, 2) / nave->radio_orbital;
}

// Resuelve inciso 4: Movimiento rectilíneo lateral Delta_x = 0.5 * a * (dt^2)
void aplicar_pulso_lateral(NaveOrion *nave, double aceleracion, double delta_t) {
    if (nave == NULL) return;

    nave->desvio_lateral += 0.5 * aceleracion * pow(delta_t, 2);
}

// Muestra los resultados en consola
void imprimir_reporte_telemetria(const NaveOrion *nave) {
    if (nave == NULL) return;

    printf("\n================ TELEMETRIA ORBITAL LEO ================\n");
    printf("Altitud (h):                 %.2f m (%.2f km)\n", nave->altitud, nave->altitud / 1000.0);
    printf("Radio Orbital Total (r):     %.2f m\n", nave->radio_orbital);
    printf("Velocidad Orbital (v):       %.2f m/s\n", nave->velocidad_orbital);
    printf("Periodo Orbital (T):         %.2f s (%.2f min)\n", nave->periodo_segundos, nave->periodo_minutos);
    printf("Aceleracion Centripeta (ac): %.2f m/s^2\n", nave->aceleracion_centripeta);
    printf("Desviacion Lateral (Delta x): %.2f m\n", nave->desvio_lateral);
    printf("========================================================\n\n");
}