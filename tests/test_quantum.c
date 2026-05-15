#include <math.h>
#include <stdio.h>
#include "../src/core/quantum.h"

static int check_close(const char *name, double actual, double expected, double rel_tol)
{
    double diff;
    double limit;

    diff = fabs(actual - expected);
    if (expected == 0.0)
    {
        limit = rel_tol;
    }
    else
    {
        limit = rel_tol * fabs(expected);
    }

    if (diff > limit)
    {
        printf("FAIL %s: got %.15e expected %.15e (limit %.15e)\n", name, actual, expected, limit);
        return 0;
    }

    return 1;
}

static int check_int_equal(const char *name, int actual, int expected)
{
    if (actual != expected)
    {
        printf("FAIL %s: got %d expected %d\n", name, actual, expected);
        return 0;
    }

    return 1;
}

int main(void)
{
    int failures;
    int checks;
    double lambda_nm;
    double value_j;
    double value_ev;
    double value_hz;
    double photon_p;
    double kinetic_j;
    double momentum;
    double velocity;
    double wavelength_m;
    double mass_kg;
    double force_e;
    double force_g;
    double x;
    double energy_j;
    double omega;
    double atom_p;
    double photons_to_stop;

    failures = 0;
    checks = 0;

    printf("Quantum89 core test\n");
    printf("-------------------\n");

    checks++;
    failures += check_close("1 eV -> J", q_ev_to_j(1.0), Q_E, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("1 eV -> J -> eV", q_j_to_ev(Q_E), 1.0, 1.0e-12) ? 0 : 1;

    lambda_nm = 632.8;
    value_j = q_photon_energy_j_from_nm(lambda_nm);
    value_ev = q_photon_energy_ev_from_nm(lambda_nm);
    value_hz = q_photon_frequency_hz_from_nm(lambda_nm);
    photon_p = q_photon_momentum_from_nm(lambda_nm);

    checks++;
    failures += check_close("Photon 632.8 nm energy J", value_j, 3.139136942397169e-19, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photon 632.8 nm energy eV", value_ev, 1.9592951711946944, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photon 632.8 nm frequency", value_hz, 4.7375546460176994e14, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photon 632.8 nm momentum", photon_p, 1.0471033738938052e-27, 1.0e-12) ? 0 : 1;

    checks++;
    failures += check_close("Photon 300 nm energy eV", q_photon_energy_ev_from_nm(300.0), 4.132806614440009, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photon 600 nm energy eV", q_photon_energy_ev_from_nm(600.0), 2.0664033072200043, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photon 1200 nm energy eV", q_photon_energy_ev_from_nm(1200.0), 1.0332016536100022, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photon 300 nm E/Ecc", q_photon_energy_ratio_from_nm(300.0, Q_CC_BOND), 1.141635550086, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_int_equal("300 nm > CC bond eV", q_photon_energy_ev_from_nm(300.0) > Q_CC_BOND_EV, 1) ? 0 : 1;
    checks++;
    failures += check_int_equal("600 nm < CC bond eV", q_photon_energy_ev_from_nm(600.0) < Q_CC_BOND_EV, 1) ? 0 : 1;
    checks++;
    failures += check_int_equal("300 nm threshold helper", q_photon_has_enough_energy(300.0, Q_CC_BOND), 1) ? 0 : 1;
    checks++;
    failures += check_int_equal("600 nm threshold helper", q_photon_has_enough_energy(600.0, Q_CC_BOND), 0) ? 0 : 1;

    checks++;
    failures += check_close("Box 1D E1 eV", q_particle_box_energy_ev(1, Q_ME, 1.0e-9), 0.376030162617, 1.0e-12) ? 0 : 1;

    kinetic_j = q_ev_to_j(1.0);
    momentum = q_nonrel_momentum_from_ke_j(Q_ME, kinetic_j);
    velocity = q_nonrel_velocity_from_ke_j(Q_ME, kinetic_j);
    wavelength_m = q_debroglie_wavelength_m(momentum);

    checks++;
    failures += check_close("electron 1 eV momentum", momentum, 5.402747766957797e-25, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("electron 1 eV v/c", q_ratio(velocity, Q_C), 1.9783585031909016e-3, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("electron 1 eV lambda", wavelength_m, 1.2264259661581492e-9, 1.0e-12) ? 0 : 1;

    kinetic_j = q_ev_to_j(10.0);
    momentum = q_nonrel_momentum_from_ke_j(Q_ME, kinetic_j);
    velocity = q_nonrel_velocity_from_ke_j(Q_ME, kinetic_j);
    wavelength_m = q_debroglie_wavelength_m(momentum);

    checks++;
    failures += check_close("electron 10 eV momentum", momentum, 1.708498856697524e-24, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("electron 10 eV v/c", q_ratio(velocity, Q_C), 6.256118898444743e-3, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("electron 10 eV lambda", wavelength_m, 3.8782994346323357e-10, 1.0e-12) ? 0 : 1;

    kinetic_j = q_ev_to_j(100.0);
    momentum = q_nonrel_momentum_from_ke_j(Q_ME, kinetic_j);
    velocity = q_nonrel_velocity_from_ke_j(Q_ME, kinetic_j);
    wavelength_m = q_debroglie_wavelength_m(momentum);

    checks++;
    failures += check_close("electron 100 eV momentum", momentum, 5.402747766957797e-24, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("electron 100 eV v/c", q_ratio(velocity, Q_C), 1.9783585031909020e-2, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("electron 100 eV lambda", wavelength_m, 1.2264259661581493e-10, 1.0e-12) ? 0 : 1;

    mass_kg = q_mass_from_u(28.0);
    momentum = q_classical_momentum(mass_kg, 500.0);
    checks++;
    failures += check_close("N2 mass", mass_kg, 4.64950938648e-26, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("N2 momentum", momentum, 2.32475469324e-23, 1.0e-12) ? 0 : 1;

    mass_kg = q_mass_from_u(22.99);
    atom_p = q_classical_momentum(mass_kg, 900.0);
    photon_p = q_photon_momentum_from_nm(590.0);
    photons_to_stop = q_ratio(atom_p, 2.0 * photon_p);
    checks++;
    failures += check_close("Na mass", mass_kg, 3.8175793141134e-26, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Na momentum", atom_p, 3.4358213827020597e-23, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("590 nm photon momentum", photon_p, 1.1230627372881356e-27, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Na photons to stop", photons_to_stop, 15296.65827484648, 1.0e-12) ? 0 : 1;

    checks++;
    failures += check_close("Work function J", q_work_function_j_from_threshold_nm(564.0), 3.522067122604483e-19, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Work function eV", q_work_function_ev_from_threshold_nm(564.0), 2.198301390659579, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photoelectron 410 nm J", q_photoelectron_ke_j(410.0, 564.0), 1.3229227728807088e-19, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photoelectron 410 nm eV", q_photoelectron_ke_ev(410.0, 564.0), 0.825703449174574, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Photoelectron 600 nm clamps", q_photoelectron_ke_ev(600.0, 564.0), 0.0, 1.0e-12) ? 0 : 1;

    force_e = q_coulomb_force_ep(300.0e-12);
    force_g = q_gravity_force_ep(300.0e-12);
    checks++;
    failures += check_close("Coulomb force", force_e, 2.5634195026019285e-9, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Gravity force", force_g, 1.129925981169097e-48, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Gravity/Coulomb ratio", q_force_ratio(force_g, force_e), 4.407885560760526e-40, 1.0e-12) ? 0 : 1;

    x = q_planck_dimensionless_x(1.0e12, 300.0);
    checks++;
    failures += check_close("Planck x", x, 0.15997476911220737, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_int_equal("Planck low-freq false", q_planck_low_frequency_limit_valid(1.0e12, 300.0), 0) ? 0 : 1;
    checks++;
    failures += check_int_equal("Planck low-freq true", q_planck_low_frequency_limit_valid(1.0e11, 300.0), 1) ? 0 : 1;

    checks++;
    failures += check_close("Box P n1 0->1/4", q_box_probability_fraction(1, 0.0, 0.25), 0.09084505690810465, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box P n1 1/4->1/2", q_box_probability_fraction(1, 0.25, 0.5), 0.4091549430918953, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box P n2 0->1/4", q_box_probability_fraction(2, 0.0, 0.25), 0.25, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box P n2 1/4->1/2", q_box_probability_fraction(2, 0.25, 0.5), 0.25, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box P n3 0->1/4", q_box_probability_fraction(3, 0.0, 0.25), 0.3030516476972984, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box P n3 1/4->1/2", q_box_probability_fraction(3, 0.25, 0.5), 0.19694835230270152, 1.0e-12) ? 0 : 1;

    checks++;
    failures += check_close("Box px^2 n1 L=1nm", q_box_px2_expected(1, 1.0e-9), 1.0976201394729598e-49, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box <x> L=2nm", q_box_x_expected(2.0e-9), 1.0e-9, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box <x^2> n1 L=1nm", q_box_x2_expected(1, 1.0e-9), 2.826727415121644e-19, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box sigma n1 L=1nm", q_box_sigma_x(1, 1.0e-9), 1.8075602759566398e-10, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box sigma/a n1", q_box_sigma_x_over_a(1), 0.18075602759566398, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box sigma/a n2", q_box_sigma_x_over_a(2), 0.26583488367413544, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box sigma/a n3", q_box_sigma_x_over_a(3), 0.2787550514099014, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box trial J", q_box_trial_energy_poly_j(Q_ME, 1.0e-9), 7.325117177976947e-20, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Box trial eV", q_box_trial_energy_poly_ev(Q_ME, 1.0e-9), 0.4571978533783153, 1.0e-12) ? 0 : 1;

    omega = q_osc_omega(100.0, 2.0);
    energy_j = q_osc_total_energy_from_k(100.0, 1.0);
    checks++;
    failures += check_close("Oscillator omega", omega, 7.0710678118654755, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Oscillator total energy from k", energy_j, 50.0, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Oscillator total energy from omega", q_osc_total_energy_from_omega(2.0, omega, 1.0), 50.0, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Oscillator <T>", q_osc_avg_kinetic_energy(2.0, omega, 1.0), 25.0, 1.0e-12) ? 0 : 1;
    checks++;
    failures += check_close("Oscillator <T>/E", q_osc_avg_kinetic_fraction(), 0.5, 1.0e-12) ? 0 : 1;

    if (failures == 0)
    {
        printf("All %d checks passed.\n", checks);
        return 0;
    }

    printf("%d of %d checks failed.\n", failures, checks);
    return 1;
}
