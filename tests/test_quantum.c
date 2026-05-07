#include <stdio.h>
#include "../src/core/quantum.h"

int main(void)
{
    double lambda_nm = 632.8;
    double e_photon_ev;
    double e_photon_j;
    double freq_hz;
    double e_box_ev;

    e_photon_j = q_photon_energy_j_from_nm(lambda_nm);
    e_photon_ev = q_photon_energy_ev_from_nm(lambda_nm);
    freq_hz = q_photon_frequency_hz_from_nm(lambda_nm);

    e_box_ev = q_particle_box_energy_ev(1, Q_ME, 1.0e-9);

    printf("Quantum89 core test\n");
    printf("-------------------\n");
    printf("Photon lambda = %.1f nm\n", lambda_nm);
    printf("Photon E = %.6e J\n", e_photon_j);
    printf("Photon E = %.6f eV\n", e_photon_ev);
    printf("Photon nu = %.6e Hz\n", freq_hz);
    printf("Box 1D: n=1, L=1 nm, m=me\n");
    printf("E1 = %.6f eV\n", e_box_ev);

    return 0;
}
