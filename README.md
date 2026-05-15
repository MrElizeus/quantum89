# Quantum89

Quantum89 es una app para TI-89 Titanium escrita en C con GCC4TI. La versión actual combina el módulo de fotones en `src/core/photons.c` con el sprint de examen para Tareas 1, 2 y 3.

## Alcance del sprint

- Tarea 1: fotones, Planck, de Broglie, fotoeléctrico, fuerzas Coulomb/gravedad y cuerpo negro.
- Tarea 2: operadores, autofunciones y conmutadores.
- Tarea 3: pozo 1D, probabilidades, valores esperados, energía trial y oscilador.

La interfaz muestra fórmulas y pasos en notación ASCII de calculadora, no en LaTeX.

## Menús

- `Tarea 1 Luz`
- `Tarea 2 Oper`
- `Tarea 3 Caja/Osc`
- `Constantes`
- `About`

## Módulos

- `src/core/`: fórmulas numéricas y constantes físicas.
- `src/ti/`: pantallas de la TI-89.
- `tests/`: regresión numérica en PC.

## Build

```bash
make
```

## Test

```bash
make test
```

## Send

```bash
make send
```

## Nota

El objetivo es un repaso rápido y verificable para el examen. No incluye CAS simbólico, renderizado LaTeX ni entrada manual de fórmulas.
