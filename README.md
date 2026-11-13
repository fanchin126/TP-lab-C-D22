# Simulador de Misiones Artemis – Lenguaje C

## 1. Presentación del equipo

**Equipo:** C Squad

**Materia:** Algoritmos y Estructuras de Datos

**Integrantes:**
- Fanchin Tomás
- Selinger Joaquin
- Silva Matias

## 2. Descripción del proyecto

El presente trabajo práctico consiste en el desarrollo de un simulador de misiones Artemis utilizando el lenguaje de programación C.

Nuestro equipo trabaja sobre el **Escenario 2: Inserción y Estabilidad en Órbita Terrestre Baja (LEO)**, cuyo objetivo es modelar el comportamiento orbital de la nave Orión alrededor de la Tierra.

Mediante el programa se realizan cálculos de velocidad orbital, período orbital, aceleración centrípeta y fuerzas gravitatoria y centrípeta. Además, se simula la aplicación de un pulso de aceleración lateral y se calcula la desviación producida.

El proyecto busca aplicar los conocimientos de programación en C mediante el uso de funciones, estructuras, punteros, modularización y validaciones de datos.

---

## 3. Organización del proyecto

El programa está dividido en módulos para organizar las responsabilidades y facilitar su mantenimiento.

### Archivos del proyecto

| Archivo | Función |
|---|---|
| `main.c` | Contiene la función principal, muestra el menú, solicita los datos y coordina la ejecución. |
| `simulador.c` | Contiene las funciones que realizan los cálculos físicos y la simulación orbital. |
| `simulador.h` | Contiene las constantes físicas, la estructura `NaveOrion` y los prototipos de las funciones del simulador. |
| `validaciones.c` | Implementa la función encargada de leer y validar los datos ingresados por el usuario. |
| `validaciones.h` | Declara la función de validación para que pueda utilizarse desde otros módulos. |

### Funcionamiento de la modularización

- Los archivos `.h` contienen las declaraciones de las funciones, estructuras y constantes necesarias.
- Los archivos `.c` contienen las implementaciones de las funciones.
- `main.c` coordina la ejecución y utiliza las funciones de los demás módulos.

Se utiliza `void` en las funciones que no necesitan devolver un valor, mientras que otras funciones utilizan tipos como `double` cuando necesitan retornar un resultado.

---

## 4. Desarrollo físico del escenario

La nave Orión se encuentra en una órbita circular terrestre baja, a una altitud de 192 km.

### Datos del problema

| Magnitud | Valor |
|---|---:|
| Constante gravitatoria (G) | 6,674 × 10⁻¹¹ N·m²/kg² |
| Masa de la Tierra | 5,972 × 10²⁴ kg |
| Radio terrestre | 6.371.000 m |
| Masa de Orión | 33.000 kg |
| Altitud inicial | 192.000 m |
| Aceleración lateral | 0,50 m/s² |
| Duración del pulso | 10 s |


### 4.1. Demostración de la fuerza centrípeta y cálculo de la velocidad orbital

La fuerza de atracción gravitatoria que ejerce la Tierra sobre la nave está dada por la ley de gravitación universal de Newton:

$$
F_g=\frac{G\cdot M_T\cdot m}{r^2}
$$

Por otro lado, para que un cuerpo describa una trayectoria circular necesita una fuerza resultante dirigida hacia el centro, denominada fuerza centrípeta:

$$
F_c=\frac{m\cdot v^2}{r}
$$

En este escenario, la fuerza gravitatoria proporciona la fuerza centrípeta necesaria para mantener la órbita circular. Por lo tanto:

$$
F_g=F_c
$$

Reemplazando las expresiones:

$$
\frac{G\cdot M_T\cdot m}{r^2}
=
\frac{m\cdot v^2}{r}
$$

Simplificando la masa de la nave:

$$
\frac{G\cdot M_T}{r^2}
=
\frac{v^2}{r}
$$

Multiplicando ambos miembros por el radio orbital:

$$
\frac{G\cdot M_T}{r}=v^2
$$

Despejando la velocidad orbital:

$$
\boxed{v=\sqrt{\frac{G\cdot M_T}{r}}}
$$

Primero calculamos el radio orbital:

$$
r=R_T+h
$$

$$
r=6.371.000+192.000
$$

$$
r=6.563.000\ m
$$

Reemplazando los valores en la fórmula:

$$
v=\sqrt{\frac{6,674\times10^{-11}\cdot5,972\times10^{24}}{6.563.000}}
$$

Resultado:

$$
\boxed{v=7.792,95\ m/s}
$$

Se demuestra que, bajo el modelo de órbita circular ideal, la gravedad proporciona la fuerza centrípeta necesaria para mantener la trayectoria de Orión.

### 4.2. Cálculo del período orbital

El período orbital representa el tiempo que tarda la nave en completar una vuelta alrededor de la Tierra.

Se utiliza la fórmula:

$$
T=\frac{2\pi r}{v}
$$

Reemplazando:

$$
T=\frac{2\pi\cdot6.563.000}{7.792,95}
$$

Resultado:

$$
\boxed{T=5.291,52\ segundos}
$$

Pasando a minutos:

$$
T=\frac{5.291,52}{60}
$$

$$
\boxed{T=88,19\ minutos}
$$

### 4.3. Cálculo de la aceleración centrípeta

La aceleración centrípeta es la aceleración dirigida hacia el centro de la trayectoria circular.

Su fórmula es:

$$
a_c=\frac{v^2}{r}
$$

Reemplazando:

$$
a_c=\frac{7.792,95^2}{6.563.000}
$$

Resultado:

$$
\boxed{a_c=9,2534\ m/s^2}
$$

### 4.4. Aplicación del pulso lateral

El ejercicio plantea que la nave activa un propulsor auxiliar lateral que genera una aceleración constante de 0,50 m/s² durante 10 segundos, perpendicular a su velocidad orbital.

Para calcular el desplazamiento lateral se utiliza:

$$
\Delta x=\frac{1}{2}\cdot a\cdot(\Delta t)^2
$$

Reemplazando:

$$
\Delta x=\frac{1}{2}\cdot0,50\cdot10^2
$$

Resultado:

$$
\boxed{\Delta x=25\ m}
$$

El pulso lateral produce una desviación de 25 metros respecto de la dirección que habría seguido la nave sin ese impulso, según el modelo simplificado utilizado.


---

## 5. Resultados de la simulación

Para los datos iniciales establecidos en la consigna, el programa obtiene los siguientes resultados:

| Magnitud | Resultado |
|---|---:|
| Altitud | 192.000 m |
| Radio orbital | 6.563.000 m |
| Velocidad orbital | 7.792,95 m/s |
| Período orbital | 5.291,52 s |
| Período orbital | 88,19 min |
| Aceleración centrípeta | 9,2534 m/s² |
| Fuerza gravitatoria | 305.362,10 N |
| Fuerza centrípeta | 305.362,10 N |
| Desviación lateral | 25 m |

---

## 6. Validaciones de entrada

El programa cuenta con un módulo independiente de validaciones para controlar los datos ingresados por el usuario.

La función `leer_numero()` realiza los siguientes controles:

- Comprueba que se haya ingresado un dato.
- Verifica que el dato sea numérico.
- Rechaza caracteres adicionales no válidos.
- Detecta valores fuera del rango numérico permitido.
- Comprueba que el valor no sea inferior al mínimo establecido.

Cuando se detecta una entrada incorrecta, el programa muestra un mensaje de error y solicita nuevamente el dato.

También se permite ingresar cero cuando el mínimo establecido es cero.

---


## 7. Compilación y ejecución

Para iniciar el simulador Artemis, se debe ejecutar el archivo **`Iniciar Artemis.bat`**, ubicado en la carpeta principal del proyecto.

Al hacer doble clic sobre este archivo:

1. Se compilan automáticamente los archivos fuente utilizando GCC.
2. Se genera el ejecutable `artemis_sim.exe`.
3. Se inicia el simulador.
4. Se muestra el menú principal para comenzar la simulación o salir del programa.

