#include "quantum.h"

double q_ev_to_j(double ev)
{
    return ev * Q_E;
}

double q_j_to_ev(double j)
{
    return j / Q_E;
}

double q_particle_box_energy_j(int n, double mass_kg, double length_m)
{
    double nd;

    if (n <= 0 || mass_kg <= 0.0 || length_m <= 0.0)
    {
        return 0.0;
    }

    nd = (double)n;
    return (nd * nd * Q_H * Q_H) / (8.0 * mass_kg * length_m * length_m);
}

double q_particle_box_energy_ev(int n, double mass_kg, double length_m)
{
    return q_j_to_ev(q_particle_box_energy_j(n, mass_kg, length_m));
}
