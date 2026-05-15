# Quantum89

Suite de Mecánica Cuántica para TI-89 Titanium escrita en C con GCC4TI.

## Objetivo

Crear una app científica compacta para cálculos de Mecánica Cuántica en TI-89 Titanium.

## Stack

- Fedora Linux
- VS Code
- GCC4TI / TIGCC
- TiLP2
- TI-89 Titanium

## Build

```bash
make
```

Test local en Fedora
```bash
make test
```

Enviar a calculadora
```bash
make send
```

## MVP v0.1
- Menú principal
- Constantes físicas
- Fotón: energía y frecuencia para 632.8 nm
- Partícula en caja 1D
- About

## v0.2-dev: Módulo Fotón / Planck

Este branch avanza el primer módulo académico priorizado desde la Tarea 1.

### Funciones agregadas

- Refactor del cálculo de fotones hacia `src/core/photons.c`.
- Energía del fotón desde longitud de onda en nm:
  - J
  - eV
- Frecuencia del fotón desde longitud de onda en nm.
- Momento del fotón:

```text
p = h / lambda
```

- Comparación energética contra un enlace C-C típico:

```text
Ecc = 5.8E-19 J
```

- Constantes físicas adicionales:
  - `Q_KB`
  - `Q_G`
  - `Q_EPS0`
  - `Q_U`
  - `Q_MP`
  - `Q_CC_BOND`

### Casos académicos incluidos en la pantalla de fotón

- He-Ne: `632.8 nm`
- UV: `300 nm`
- Visible: `600 nm`
- IR: `1200 nm`
- Formulario de ecuaciones:
  - `nu = c/lambda`
  - `E = h*nu`
  - `E = h*c/lambda`
  - `p = h/lambda`
  - `eV = J/e`

### Tests agregados

`make test` ahora verifica valores de regresión para:

- Fotón de `632.8 nm`:
  - energía en J
  - energía en eV
  - frecuencia en Hz
  - momento
- Fotones de `300 nm`, `600 nm` y `1200 nm`.
- Relación `E/Ecc` para `300 nm`.
- Comparación de umbral contra enlace C-C.
- Regresión de energía de caja 1D ya existente.

## Roadmap

**v0.2**
- Entrada manual para lambda
- Entrada manual para n y L
- Mejor formato numérico

**v0.3**
- de Broglie
- Momento de electrón acelerado
- Longitud de onda de electrón
- Comparación con escala atómica

**v0.4**
- Efecto fotoeléctrico
- Momento de fotón y átomo de sodio
- Fuerza eléctrica vs fuerza gravitacional

**v0.5**
- Cuerpo negro
- Límite Rayleigh-Jeans
- Guía de demostraciones

**v0.6**
- Partícula en caja 1D avanzada
- Probabilidades por intervalo
- Valores esperados
- Incertidumbre

**v0.7**
- Oscilador armónico
- Energía total
- Energía cinética promedio

**v0.8**
- Operadores
- Autofunciones
- Autovalores
- Conmutadores

**v1.0**
- Suite académica estable para Tareas 1, 2 y 3
