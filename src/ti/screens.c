#include <tigcclib.h>
#include "ui.h"
#include "screens.h"
#include "../core/quantum.h"

void screen_constants(void)
{
    ui_clear();
    ui_title("CONSTANTES");

    ui_line(14, "h    = 6.62607015E-34");
    ui_line(24, "hbar = 1.054571817E-34");
    ui_line(34, "c    = 2.99792458E8");
    ui_line(44, "e    = 1.602176634E-19");
    ui_line(54, "me   = 9.1093837E-31");

    ui_footer("Tecla: volver");
    ui_wait();
}

void screen_photon_demo(void)
{
    char buffer[64];

    double lambda_nm = 632.8;
    double e_ev = q_photon_energy_ev_from_nm(lambda_nm);
    double freq_hz = q_photon_frequency_hz_from_nm(lambda_nm);

    ui_clear();
    ui_title("FOTON");

    ui_line(14, "lambda = 632.8 nm");

    sprintf(buffer, "E = %.4f eV", e_ev);
    ui_line(28, buffer);

    sprintf(buffer, "nu = %.3E Hz", freq_hz);
    ui_line(42, buffer);

    ui_line(60, "E = h*c/lambda");

    ui_footer("Tecla: volver");
    ui_wait();
}

void screen_box1d_demo(void)
{
    char buffer[64];

    int n = 1;
    double L_m = 1.0e-9;
    double e_ev = q_particle_box_energy_ev(n, Q_ME, L_m);

    ui_clear();
    ui_title("CAJA 1D");

    ui_line(14, "n = 1");
    ui_line(24, "L = 1.0 nm");
    ui_line(34, "m = electron");

    sprintf(buffer, "E1 = %.4f eV", e_ev);
    ui_line(50, buffer);

    ui_line(66, "E = n^2*h^2/(8mL^2)");

    ui_footer("Tecla: volver");
    ui_wait();
}

void screen_about(void)
{
    ui_clear();
    ui_title("ABOUT");

    ui_line(16, "Quantum89 v0.1");
    ui_line(28, "Mecanica Cuantica");
    ui_line(40, "TI-89 Titanium");
    ui_line(52, "C / GCC4TI");
    ui_line(68, "Eliseo H.");

    ui_footer("Tecla: volver");
    ui_wait();
}
