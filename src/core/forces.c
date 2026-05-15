#include "quantum.h"

double q_coulomb_force_ep(double r_m)
{
    if (r_m <= 0.0)
    {
        return 0.0;
    }

    return (Q_E * Q_E) / (4.0 * Q_PI * Q_EPS0 * r_m * r_m);
}

double q_gravity_force_ep(double r_m)
{
    if (r_m <= 0.0)
    {
        return 0.0;
    }

    return (Q_G * Q_ME * Q_MP) / (r_m * r_m);
}

double q_force_ratio(double small_force, double large_force)
{
    if (large_force == 0.0)
    {
        return 0.0;
    }

    return small_force / large_force;
}
