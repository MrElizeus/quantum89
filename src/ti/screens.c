#include <stdio.h>
#include <tigcclib.h>
#include "ui.h"
#include "screens.h"
#include "../core/quantum.h"

static void show_photon_result(double lambda_nm)
{
    char buffer[64];
    double e_j;
    double e_ev;
    double freq_hz;
    double momentum;
    double ratio_cc;

    e_j = q_photon_energy_j_from_nm(lambda_nm);
    e_ev = q_photon_energy_ev_from_nm(lambda_nm);
    freq_hz = q_photon_frequency_hz_from_nm(lambda_nm);
    momentum = q_photon_momentum_from_nm(lambda_nm);
    ratio_cc = q_photon_energy_ratio_from_nm(lambda_nm, Q_CC_BOND);

    ui_clear();
    ui_title("FOTON RESULT");

    sprintf(buffer, "lambda = %.1f nm", lambda_nm);
    ui_line(12, buffer);

    sprintf(buffer, "nu = %.3E Hz", freq_hz);
    ui_line(24, buffer);

    sprintf(buffer, "E = %.3E J", e_j);
    ui_line(36, buffer);

    sprintf(buffer, "E = %.4f eV", e_ev);
    ui_line(48, buffer);

    sprintf(buffer, "p = %.3E kgm/s", momentum);
    ui_line(60, buffer);

    sprintf(buffer, "E/Ecc = %.3f", ratio_cc);
    ui_line(72, buffer);

    ui_footer("Tecla: volver");
    ui_wait();
}

static void show_photon_formulas(void)
{
    ui_clear();
    ui_title("FOTON FORMULAS");

    ui_line(14, "nu = c/lambda");
    ui_line(26, "E  = h*nu");
    ui_line(38, "E  = h*c/lambda");
    ui_line(50, "p  = h/lambda");
    ui_line(62, "eV = J/e");
    ui_line(74, "Ecc=5.8E-19 J");

    ui_footer("Tecla: volver");
    ui_wait();
}

void screen_constants(void)
{
    short key;

    ui_clear();
    ui_title("CONSTANTES");

    ui_line(12, "h    = 6.62607015E-34");
    ui_line(22, "hbar = 1.054571817E-34");
    ui_line(32, "c    = 2.99792458E8");
    ui_line(42, "e    = 1.602176634E-19");
    ui_line(52, "me   = 9.1093837015E-31");
    ui_line(62, "mp   = 1.67262192369E-27");

    ui_footer("ENTER sigue | ESC vuelve");
    key = ui_wait_key();
    if (key == KEY_ESC)
    {
        return;
    }

    ui_clear();
    ui_title("CONSTANTES");
    ui_line(14, "u    = 1.66053906660E-27");
    ui_line(24, "kB   = 1.380649E-23");
    ui_line(34, "eps0 = 8.8541878128E-12");
    ui_line(44, "pi   = 3.14159265358979");
    ui_line(54, "CC   = 5.8E-19 J");
    ui_line(64, "G    = 6.67430E-11");
    ui_line(74, "hc   = 1240 eV*nm");
    ui_footer("Tecla: volver");
    ui_wait();
}

void screen_errors(void)
{
    short key;

    ui_clear();
    ui_title("ERRORES 1");
    ui_line(14, "eV -> J: * e");
    ui_line(26, "J -> eV: / e");
    ui_line(38, "nm -> m: *1E-9");
    ui_line(50, "pm -> m: *1E-12");
    ui_footer("ENTER sigue | ESC vuelve");
    key = ui_wait_key();
    if (key == KEY_ESC) return;

    ui_clear();
    ui_title("ERRORES 2");
    ui_line(14, "foton: E=h*nu");
    ui_line(26, "deBroglie: lambda=h/p");
    ui_line(38, "operadores usan hbar");
    ui_line(50, "px=-i*hbar*d/dx");
    ui_footer("ENTER sigue | ESC vuelve");
    key = ui_wait_key();
    if (key == KEY_ESC) return;

    ui_clear();
    ui_title("ERRORES 3");
    ui_line(14, "<A>=int psi* Apsi dx");
    ui_line(26, "A actua sobre psi");
    ui_line(38, "luego multiplicar");
    ui_line(50, "por psi* e integrar");
    ui_footer("ENTER sigue | ESC vuelve");
    key = ui_wait_key();
    if (key == KEY_ESC) return;

    ui_clear();
    ui_title("ERRORES 4");
    ui_line(14, "v: m/s");
    ui_line(24, "p: kg*m/s");
    ui_line(34, "lambda: m");
    ui_line(44, "P: adimensional");
    ui_line(54, "F: N = kg*m/s^2");
    ui_footer("ENTER sigue | ESC vuelve");
    key = ui_wait_key();
    if (key == KEY_ESC) return;

    ui_clear();
    ui_title("ERRORES 5");
    ui_line(14, "si v > c:");
    ui_line(26, "revisa eV -> J");
    ui_line(38, "revisa masa kg");
    ui_line(50, "o usa relatividad");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

void screen_photon_demo(void)
{
    short key;

    while (1)
    {
        ui_clear();
        ui_title("FOTON / PLANCK");

        ui_line(14, "1. HeNe 632.8 nm");
        ui_line(26, "2. UV 300 nm");
        ui_line(38, "3. Visible 600 nm");
        ui_line(50, "4. IR 1200 nm");
        ui_line(62, "5. Formulas");

        ui_footer("1-5 elegir | ESC volver");
        key = ngetchx();

        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                show_photon_result(632.8);
                break;

            case '2':
                show_photon_result(300.0);
                break;

            case '3':
                show_photon_result(600.0);
                break;

            case '4':
                show_photon_result(1200.0);
                break;

            case '5':
                show_photon_formulas();
                break;

            default:
                break;
        }
    }
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

    ui_line(16, "Quantum89 exam sprint");
    ui_line(28, "Tareas 1, 2 y 3");
    ui_line(40, "TI-89 Titanium");
    ui_line(52, "C / GCC4TI");
    ui_line(68, "Eliseo H.");

    ui_footer("Tecla: volver");
    ui_wait();
}
