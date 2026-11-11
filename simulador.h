#ifndef SIMULADOR_H
#define SIMULADOR_H

// Constantes físicas del problema LEO
#define G_GRAV 6.674e-11        // N*m^2/kg^2 (Constante de gravitación)
#define M_TIERRA 5.972e24       // kg (Masa de la Tierra)
#define R_TIERRA 6371000.0      // m (Radio terrestre medio)
#define M_ORION 33000.0         // kg (Masa nave Orion)
#define PI 3.14159265358979323846

// Tipo de dato estructurado para almacenar el estado orbital
typedef struct {
    double altitud;              // h en metros
    double radio_orbital;        // r = R_TIERRA + h en metros
    double velocidad_orbital;    // v en m/s
    double periodo_segundos;     // T en segundos
    double periodo_minutos;      // T en minutos
    double aceleracion_centripeta; // ac en m/s^2
    double desvio_lateral;       // Delta x en metros
} NaveOrion;

// Prototipos que operan mediante paso por referencia (punteros)
void inicializar_nave(NaveOrion *nave, double altitud_inicial);
void calcular_dinamica_orbital(NaveOrion *nave);
void aplicar_pulso_lateral(NaveOrion *nave, double aceleracion, double delta_t);
void imprimir_reporte_telemetria(const NaveOrion *nave);

#endif // SIMULADOR_H