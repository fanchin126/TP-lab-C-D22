#include <stdio.h>
#include "simulador.h"

int main(void) {
    // Instanciamos la variable estática
    NaveOrion orion;

    // Pasamos la dirección de memoria (&orion) -> Paso por referencia
    inicializar_nave(&orion, 192000.0); // 192 km
    calcular_dinamica_orbital(&orion);
    aplicar_pulso_lateral(&orion, 0.50, 10.0); // a = 0.50 m/s^2, dt = 10 s

    // Mostramos resultados
    imprimir_reporte_telemetria(&orion);

    return 0;
}