#include <math.h>
#include "quantum.h"

double q_mass_from_u(double atomic_mass_u)
{
    if (atomic_mass_u <= 0.0)
    {
        return 0.0;
    }

    return atomic_mass_u * Q_U;
}

double q_classical_momentum(double mass_kg, double velocity_m_s)
{
    return mass_kg * velocity_m_s;
}

double q_nonrel_momentum_from_ke_j(double mass_kg, double kinetic_j)
{
    if (mass_kg <= 0.0 || kinetic_j < 0.0)
    {
        return 0.0;
    }

    return sqrt(2.0 * mass_kg * kinetic_j);
}

double q_nonrel_velocity_from_ke_j(double mass_kg, double kinetic_j)
{
    if (mass_kg <= 0.0 || kinetic_j < 0.0)
    {
        return 0.0;
    }

    return sqrt((2.0 * kinetic_j) / mass_kg);
}

double q_debroglie_wavelength_m(double momentum_kg_m_s)
{
    if (momentum_kg_m_s < 0.0)
    {
        momentum_kg_m_s = -momentum_kg_m_s;
    }

    if (momentum_kg_m_s == 0.0)
    {
        return 0.0;
    }

    return Q_H / momentum_kg_m_s;
}

double q_ratio(double numerator, double denominator)
{
    if (denominator == 0.0)
    {
        return 0.0;
    }

    return numerator / denominator;
}
