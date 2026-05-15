#include <math.h>
#include <stdio.h>
#include "../src/core/quantum.h"

static int almost_equal_rel(double actual, double expected, double rel_tol)
{
    double diff;
    double scale;

    diff = fabs(actual - expected);
    scale = fabs(expected);

    if (scale < 1.0)
    {
        scale = 1.0;
    }

    return diff / scale <= rel_tol;
}

static int check_value(const char *name, double actual, double expected, double rel_tol)
{
    if (!almost_equal_rel(actual, expected, rel_tol))
    {
        printf("FAIL %s\n", name);
        printf("  actual   = %.12e\n", actual);
        printf("  expected = %.12e\n", expected);
        return 1;
    }

    printf("OK   %s = %.12e\n", name, actual);
    return 0;
}

int main(void)
{
    int failures;
    double lambda_nm;
    double e_photon_ev;
    double e_photon_j;
    double freq_hz;
    double momentum;
    double e_box_ev;

    failures = 0;
    lambda_nm = 632.8;

    e_photon_j = q_photon_energy_j_from_nm(lambda_nm);
    e_photon_ev = q_photon_energy_ev_from_nm(lambda_nm);
    freq_hz = q_photon_frequency_hz_from_nm(lambda_nm);
    momentum = q_photon_momentum_from_nm(lambda_nm);

    e_box_ev = q_particle_box_energy_ev(1, Q_ME, 1.0e-9);

    printf("Quantum89 core test\n");
    printf("-------------------\n");

    failures += check_value("photon 632.8 nm E J", e_photon_j, 3.139136942397e-19, 1.0e-9);
    failures += check_value("photon 632.8 nm E eV", e_photon_ev, 1.959295171195, 1.0e-9);
    failures += check_value("photon 632.8 nm nu Hz", freq_hz, 4.737554646018e14, 1.0e-9);
    failures += check_value("photon 632.8 nm p", momentum, 1.047103373894e-27, 1.0e-9);

    failures += check_value("photon 300 nm E eV", q_photon_energy_ev_from_nm(300.0), 4.132806614440, 1.0e-9);
    failures += check_value("photon 600 nm E eV", q_photon_energy_ev_from_nm(600.0), 2.066403307220, 1.0e-9);
    failures += check_value("photon 1200 nm E eV", q_photon_energy_ev_from_nm(1200.0), 1.033201653610, 1.0e-9);

    failures += check_value("photon 300 nm E/Ecc", q_photon_energy_ratio_from_nm(300.0, Q_CC_BOND), 1.141635550086, 1.0e-9);

    if (!q_photon_has_enough_energy(300.0, Q_CC_BOND))
    {
        printf("FAIL photon 300 nm C-C threshold\n");
        failures++;
    }

    if (q_photon_has_enough_energy(600.0, Q_CC_BOND))
    {
        printf("FAIL photon 600 nm C-C threshold\n");
        failures++;
    }

    failures += check_value("box 1D E1 eV", e_box_ev, 0.376030162617, 1.0e-9);

    if (failures)
    {
        printf("%d test(s) failed\n", failures);
        return 1;
    }

    printf("All tests passed\n");
    return 0;
}
