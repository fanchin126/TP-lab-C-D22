
@echo off
title Simulador Artemis - C Squad

cd /d "%~dp0"

echo ========================================
echo       SIMULADOR ARTEMIS - C SQUAD
echo ========================================
echo.

"C:\msys64\ucrt64\bin\gcc.exe" -Wall -Wextra main.c simulador.c validaciones.c -o artemis_sim.exe -lm

if errorlevel 1 (
    echo.
    echo ERROR AL COMPILAR EL PROGRAMA.
    pause
    exit /b 1
)

echo Compilacion correcta.
echo Iniciando Artemis...
echo.

artemis_sim.exe

echo.
echo Simulador finalizado.
pause
