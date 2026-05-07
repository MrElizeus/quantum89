#include "quantum.h"

double q_ev_to_j(double ev)
{
    return ev * Q_E;
}

double q_j_to_ev(double j)
{
    return j / Q_E;
}

double q_photon_energy_j_from_nm(double lambda_nm)
{
    double lambda_m = lambda_nm * 1.0e-9;
    return (Q_H * Q_C) / lambda_m;
}

double q_photon_energy_ev_from_nm(double lambda_nm)
{
    return q_j_to_ev(q_photon_energy_j_from_nm(lambda_nm));
}

double q_photon_frequency_hz_from_nm(double lambda_nm)
{
    double lambda_m = lambda_nm * 1.0e-9;
    return Q_C / lambda_m;
}

double q_particle_box_energy_j(int n, double mass_kg, double length_m)
{
    double nd = (double)n;
    return (nd * nd * Q_H * Q_H) / (8.0 * mass_kg * length_m * length_m);
}

double q_particle_box_energy_ev(int n, double mass_kg, double length_m)
{
    return q_j_to_ev(q_particle_box_energy_j(n, mass_kg, length_m));
}
