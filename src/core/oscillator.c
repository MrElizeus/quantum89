#include <math.h>
#include "quantum.h"

double q_osc_omega(double k, double mass_kg)
{
    if (k < 0.0 || mass_kg <= 0.0)
    {
        return 0.0;
    }

    return sqrt(k / mass_kg);
}

double q_osc_total_energy_from_k(double k, double amplitude_m)
{
    if (k < 0.0)
    {
        return 0.0;
    }

    return 0.5 * k * amplitude_m * amplitude_m;
}

double q_osc_total_energy_from_omega(double mass_kg, double omega, double amplitude_m)
{
    if (mass_kg <= 0.0 || omega < 0.0)
    {
        return 0.0;
    }

    return 0.5 * mass_kg * omega * omega * amplitude_m * amplitude_m;
}

double q_osc_avg_kinetic_energy(double mass_kg, double omega, double amplitude_m)
{
    if (mass_kg <= 0.0 || omega < 0.0)
    {
        return 0.0;
    }

    return 0.25 * mass_kg * omega * omega * amplitude_m * amplitude_m;
}

double q_osc_avg_kinetic_fraction(void)
{
    return 0.5;
}
