# Compilador COBOL-85 a Python

## Descripción
Implementación de un compilador que traduce un subconjunto de COBOL-85 a Python, desarrollado con Flex y Bison.

## Características
- Traducción de divisiones básicas (`IDENTIFICATION`, `DATA`, `PROCEDURE`)
- Soporte para verbos esenciales:
  - `PERFORM VARYING` → bucles `while`
  - `IF-THEN-ELSE` → `if-elif-else`
  - `COMPUTE` → expresiones Python
- Generación de funciones anidadas para párrafos COBOL
- Manejo de variables compartidas con `nonlocal`

## Estructura del código
├── lexer.l # Reglas léxicas (Flex)

├── parser.y # Gramática (Bison)

├── Makefile # Automatización de compilación

├── test.cbl # Programa COBOL de prueba

└── output.py # Salida Python generada
