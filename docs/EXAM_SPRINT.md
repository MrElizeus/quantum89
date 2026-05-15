# Exam Sprint

## 1. Covered Topics

- Tarea 1: photon energy, Planck relation, de Broglie wavelength, photoelectric effect, Coulomb vs gravity, blackbody low-frequency limit.
- Tarea 2: linear operators, eigenfunctions/eigenvalues, commutators.
- Tarea 3: particle in a 1D box, probabilities, expected values, uncertainty, trial-state energy, harmonic oscillator.

## 2. Formula Map By Task

- Tarea 1:
  - `E = h*nu`
  - `nu = c/lambda`
  - `lambda = h/p`
  - `p = sqrt(2*m*K)`
  - `phi = hc/lambda0`
  - `Kmax = E - phi`
  - `Fe = e^2/(4*pi*eps0*r^2)`
  - `Fg = G*me*mp/r^2`
  - `x = h*nu/(kB*T)`
  - `x < 0.1` means the classical limit is reasonable
- Tarea 2:
  - `A f = g`
  - `A f = lambda f`
  - `[A,B] = AB - BA`
- Tarea 3:
  - `psi_n = sqrt(2/a)*sin(n*pi*x/a)`
  - `P = int[x1,x2] |psi|^2 dx`
  - `<px^2> = (n*pi*hbar/a)^2`
  - `<x> = a/2`
  - `<x2> = a^2(1/3 - 1/(2n^2*pi^2))`
  - `sigma = sqrt(<x2>-<x>^2)`
  - `<E> = 6*hbar^2/(m*a^2)`
  - `w = sqrt(k/m)`
  - `E = 1/2*k*C^2`

## 3. Calculator Menu Map

- Main menu
  - `Tarea 1 Luz`
  - `Tarea 2 Oper`
  - `Tarea 3 Caja/Osc`
  - `Constantes`
  - `About`
- Tarea 1
  - Photon/Planck
  - de Broglie
  - Fotoelectrico
  - Fuerzas
  - Cuerpo negro
- Tarea 2
  - Operadores
  - Autofunciones
  - Conmutadores
  - Reglas clave
- Tarea 3
  - Caja prob
  - Caja valores
  - Energia trial
  - Oscilador
  - Formulas

## 4. What Quantum89 Calculates

- Photon energy, frequency and momentum derived from wavelength.
- de Broglie wavelength, momentum and non-relativistic velocity from kinetic energy.
- Photoelectric work function and maximum kinetic energy for preset wavelengths.
- Coulomb and gravitational force magnitudes for electron-proton pairs.
- Planck low-frequency parameter `x` and a study helper for the classical limit.
- Box probabilities, expected values, uncertainty, and trial-state energy.
- Harmonic oscillator frequency, total energy, and average kinetic energy.

## 5. What Quantum89 Only Explains

- Operator application patterns.
- Eigenfunction resolution steps.
- Commutator expansion and cancellation.
- Blackbody derivation pages and the Rayleigh-Jeans approximation.

## 6. Known Limitations

- No LaTeX renderer.
- No symbolic CAS.
- No arbitrary numeric input.
- No generic parser for user-entered formulas.
- No graphing or persistence.
- Only the fixed exam presets are implemented in the UI.
