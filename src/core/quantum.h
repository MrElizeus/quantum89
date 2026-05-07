#ifndef QUANTUM_H
#define QUANTUM_H

#define Q_H      6.62607015e-34
#define Q_HBAR   1.054571817e-34
#define Q_C      2.99792458e8
#define Q_E      1.602176634e-19
#define Q_ME     9.1093837015e-31
#define Q_PI     3.14159265358979323846

double q_ev_to_j(double ev);
double q_j_to_ev(double j);

double q_photon_energy_j_from_nm(double lambda_nm);
double q_photon_energy_ev_from_nm(double lambda_nm);
double q_photon_frequency_hz_from_nm(double lambda_nm);

double q_particle_box_energy_j(int n, double mass_kg, double length_m);
double q_particle_box_energy_ev(int n, double mass_kg, double length_m);

#endif
