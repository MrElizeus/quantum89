#include "quantum.h"

double q_work_function_j_from_threshold_nm(double lambda0_nm)
{
    return q_photon_energy_j_from_nm(lambda0_nm);
}

double q_work_function_ev_from_threshold_nm(double lambda0_nm)
{
    return q_j_to_ev(q_work_function_j_from_threshold_nm(lambda0_nm));
}

double q_photoelectron_ke_j(double lambda_nm, double lambda0_nm)
{
    double kinetic_j;

    kinetic_j = q_photon_energy_j_from_nm(lambda_nm) - q_work_function_j_from_threshold_nm(lambda0_nm);
    if (kinetic_j < 0.0)
    {
        return 0.0;
    }

    return kinetic_j;
}

double q_photoelectron_ke_ev(double lambda_nm, double lambda0_nm)
{
    return q_j_to_ev(q_photoelectron_ke_j(lambda_nm, lambda0_nm));
}
