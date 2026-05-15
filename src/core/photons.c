#include "quantum.h"

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

double q_photon_momentum_from_nm(double lambda_nm)
{
    double lambda_m = lambda_nm * 1.0e-9;
    return Q_H / lambda_m;
}

double q_photon_energy_ratio_from_nm(double lambda_nm, double reference_j)
{
    return q_photon_energy_j_from_nm(lambda_nm) / reference_j;
}

int q_photon_has_enough_energy(double lambda_nm, double reference_j)
{
    return q_photon_energy_j_from_nm(lambda_nm) >= reference_j;
}
