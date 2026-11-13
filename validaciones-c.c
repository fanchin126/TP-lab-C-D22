
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include "validaciones.h"

double leer_numero(const char *mensaje, double minimo) {

    char entrada[100];
    char *fin;
    double valor;

    while (1) {

        printf("%s", mensaje);

        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("Error al leer la entrada.\n");
            continue;
        }

        errno = 0;
        valor = strtod(entrada, &fin);

        if (fin == entrada) {
            printf("Error: debe ingresar un numero.\n");
            continue;
        }

        while (isspace((unsigned char)*fin)) {
            fin++;
        }

        if (*fin != '\0') {
            printf("Error: ingreso caracteres no validos.\n");
            continue;
        }

        if (errno == ERANGE || !isfinite(valor)) {
            printf("Error: numero fuera del rango permitido.\n");
            continue;
        }

        if (valor < minimo) {
            printf("Error: el valor minimo permitido es %.2f.\n",
                   minimo);
            continue;
        }

        return valor;
    }
}
