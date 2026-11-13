#ifndef SIMULADOR_H
#define SIMULADOR_H

// Constantes fisicas del problema LEO
#define G_GRAV 6.674e-11
#define M_TIERRA 5.972e24
#define R_TIERRA 6371000.0
#define M_ORION 33000.0
// La constante PI manual fue eliminada; se usara M_PI de <math.h>

// Estructura que representa el estado de la nave Orion
typedef struct {
    double altitud;
    double radio_orbital;
    double velocidad_orbital;
    double periodo_segundos;
    double periodo_minutos;
    double aceleracion_centripeta;
    double desvio_lateral;

    // Nuevos datos para demostrar la igualdad de fuerzas
    double fuerza_gravitatoria;
    double fuerza_centripeta;

} NaveOrion;

// Prototipos de las funciones (ahora retornan int para control de errores)
int inicializar_nave(NaveOrion *nave, double altitud_inicial);
int calcular_dinamica_orbital(NaveOrion *nave);
int calcular_fuerzas(NaveOrion *nave);
int aplicar_pulso_lateral(NaveOrion *nave, double aceleracion, double delta_t);
int imprimir_reporte_telemetria(const NaveOrion *nave);

#endif