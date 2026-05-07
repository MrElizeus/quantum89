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

## Roadmap
**v0.2**
- Entrada manual para lambda
- Entrada manual para n y L
- Mejor formato numérico

**v0.3**
- Oscilador armónico
- Niveles de energía
- Unidades eV/J

**v0.4**
- Números complejos
- Matrices 2x2
- Matrices de Pauli
- Spin 1/2

**v0.5**
- Normalización numérica
- Valores esperados
- Integración por trapecios

**v1.0**
- Pozo finito
- Barrera rectangular
- Túnel cuántico
- Schrödinger 1D básico
