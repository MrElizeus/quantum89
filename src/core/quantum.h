#ifndef QUANTUM_H
#define QUANTUM_H

#define Q_H          6.62607015e-34
#define Q_HBAR       1.054571817e-34
#define Q_C          2.99792458e8
#define Q_E          1.602176634e-19
#define Q_ME         9.1093837015e-31
#define Q_MP         1.67262192369e-27
#define Q_KB         1.380649e-23
#define Q_EPS0       8.8541878128e-12
#define Q_G          6.67430e-11
#define Q_U          1.66053906660e-27
#define Q_PI         3.14159265358979323846
#define Q_CC_BOND    5.8e-19
#define Q_CC_BOND_J  Q_CC_BOND
#define Q_CC_BOND_EV (Q_CC_BOND / Q_E)

double q_ev_to_j(double ev);
double q_j_to_ev(double j);

double q_photon_energy_j_from_nm(double lambda_nm);
double q_photon_energy_ev_from_nm(double lambda_nm);
double q_photon_frequency_hz_from_nm(double lambda_nm);
double q_photon_momentum_from_nm(double lambda_nm);
double q_photon_energy_ratio_from_nm(double lambda_nm, double reference_j);
int q_photon_has_enough_energy(double lambda_nm, double reference_j);

double q_particle_box_energy_j(int n, double mass_kg, double length_m);
double q_particle_box_energy_ev(int n, double mass_kg, double length_m);

double q_mass_from_u(double atomic_mass_u);
double q_classical_momentum(double mass_kg, double velocity_m_s);
double q_nonrel_momentum_from_ke_j(double mass_kg, double kinetic_j);
double q_nonrel_velocity_from_ke_j(double mass_kg, double kinetic_j);
double q_debroglie_wavelength_m(double momentum_kg_m_s);
double q_ratio(double numerator, double denominator);

double q_work_function_j_from_threshold_nm(double lambda0_nm);
double q_work_function_ev_from_threshold_nm(double lambda0_nm);
double q_photoelectron_ke_j(double lambda_nm, double lambda0_nm);
double q_photoelectron_ke_ev(double lambda_nm, double lambda0_nm);

double q_coulomb_force_ep(double r_m);
double q_gravity_force_ep(double r_m);
double q_force_ratio(double small_force, double large_force);

double q_planck_dimensionless_x(double frequency_hz, double temperature_k);
int q_planck_low_frequency_limit_valid(double frequency_hz, double temperature_k);

double q_box_probability_fraction(int n, double x1_over_a, double x2_over_a);
double q_box_px2_expected(int n, double length_m);
double q_box_x_expected(double length_m);
double q_box_x2_expected(int n, double length_m);
double q_box_sigma_x(int n, double length_m);
double q_box_sigma_x_over_a(int n);
double q_box_trial_energy_poly_j(double mass_kg, double length_m);
double q_box_trial_energy_poly_ev(double mass_kg, double length_m);

double q_osc_omega(double k, double mass_kg);
double q_osc_total_energy_from_k(double k, double amplitude_m);
double q_osc_total_energy_from_omega(double mass_kg, double omega, double amplitude_m);
double q_osc_avg_kinetic_energy(double mass_kg, double omega, double amplitude_m);
double q_osc_avg_kinetic_fraction(void);

#endif
