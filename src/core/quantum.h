#ifndef QUANTUM_H
#define QUANTUM_H

#define Q_H        6.62607015e-34
#define Q_HBAR     1.054571817e-34
#define Q_C        2.99792458e8
#define Q_E        1.602176634e-19
#define Q_ME       9.1093837015e-31
#define Q_MP       1.67262192369e-27
#define Q_KB       1.380649e-23
#define Q_G        6.67430e-11
#define Q_EPS0     8.8541878128e-12
#define Q_U        1.66053906660e-27
#define Q_PI       3.14159265358979323846
#define Q_CC_BOND  5.8e-19

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

#endif
