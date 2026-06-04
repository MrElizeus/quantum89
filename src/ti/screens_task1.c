#include <stdio.h>
#include <tigcclib.h>
#include "ui.h"
#include "screens.h"
#include "../core/quantum.h"

static int task1_page_pause(void)
{
    return ui_wait_key() != KEY_ESC;
}

static void task1_photon_resolution(void)
{
    char buffer[64];
    double lambda_nm;
    double lambda_m;
    double freq_hz;
    double energy_j;
    double energy_ev;

    lambda_nm = 632.8;
    lambda_m = lambda_nm * 1.0e-9;
    freq_hz = q_photon_frequency_hz_from_nm(lambda_nm);
    energy_j = q_photon_energy_j_from_nm(lambda_nm);
    energy_ev = q_photon_energy_ev_from_nm(lambda_nm);

    ui_clear();
    ui_title("RESOLUCION");
    ui_line(14, "DATO:");
    sprintf(buffer, "lambda = %.1f nm", lambda_nm);
    ui_line(24, buffer);
    sprintf(buffer, "lambda = %.3E m", lambda_m);
    ui_line(34, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("RESOLUCION");
    ui_line(14, "FRECUENCIA:");
    ui_line(24, "nu = c/lambda");
    sprintf(buffer, "nu = %.3E Hz", freq_hz);
    ui_line(34, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("RESOLUCION");
    ui_line(14, "ENERGIA:");
    ui_line(24, "E = h*nu");
    ui_line(34, "E = h*c/lambda");
    sprintf(buffer, "E = %.3E J", energy_j);
    ui_line(44, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("RESOLUCION");
    ui_line(14, "eV:");
    ui_line(24, "E(eV)=E(J)/e");
    sprintf(buffer, "E = %.4f eV", energy_ev);
    ui_line(34, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("RESOLUCION");
    ui_line(14, "FISICA:");
    ui_line(24, "menor lambda");
    ui_line(34, "mayor E y nu");
    ui_line(46, "lambda <-> nu");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photon_presets(void)
{
    char buffer[64];
    double e300;
    double e600;
    double e1200;

    e300 = q_photon_energy_ev_from_nm(300.0);
    e600 = q_photon_energy_ev_from_nm(600.0);
    e1200 = q_photon_energy_ev_from_nm(1200.0);

    ui_clear();
    ui_title("FOTON PRESETS");
    sprintf(buffer, "300 nm = %.3f eV  > CC", e300);
    ui_line(14, buffer);
    sprintf(buffer, "600 nm = %.3f eV  < CC", e600);
    ui_line(26, buffer);
    sprintf(buffer, "1200 nm = %.3f eV < CC", e1200);
    ui_line(38, buffer);
    ui_line(54, "CC = C-C bond");
    ui_line(66, "300 nm rompe, 600 no");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photon_formula(void)
{
    ui_clear();
    ui_title("FOTON FORMULA");
    ui_line(14, "E = h*nu");
    ui_line(24, "nu = c/lambda");
    ui_line(34, "E = h*c/lambda");
    ui_line(46, "p = h/lambda");
    ui_line(58, "1/lambda -> E sube");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("ATAJO 1240");
    ui_line(14, "E(eV)=1240/lambda");
    ui_line(26, "lambda en nm");
    ui_line(38, "NO usar metros");
    ui_line(50, "si usas m: hc/lambda");
    ui_line(62, "y divide por e");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photon_threshold(void)
{
    char buffer[64];
    double e300;
    double e600;

    e300 = q_photon_energy_ev_from_nm(300.0);
    e600 = q_photon_energy_ev_from_nm(600.0);

    ui_clear();
    ui_title("UMBRAL CC");
    sprintf(buffer, "CC = %.2f eV", Q_CC_BOND_EV);
    ui_line(14, buffer);
    sprintf(buffer, "300 nm = %.3f eV", e300);
    ui_line(26, buffer);
    sprintf(buffer, "600 nm = %.3f eV", e600);
    ui_line(38, buffer);
    ui_line(54, "300 nm >= umbral");
    ui_line(66, "600 nm < umbral");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photon_planck(void)
{
    ui_clear();
    ui_title("PLANCK");
    ui_line(14, "E = h*nu");
    ui_line(24, "nu = c/lambda");
    ui_line(34, "E = h*c/lambda");
    ui_line(46, "cada foton vale E");
    ui_line(58, "mayor nu -> mayor E");
    ui_line(70, "compara con enlace");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photon_menu(void)
{
    short key;

    while (1)
    {
        ui_clear();
        ui_title("FOTON / PLANCK");
        ui_line(16, "1. Demo 632.8");
        ui_line(28, "2. Presets 300/600/1200");
        ui_line(40, "3. Formula");
        ui_line(52, "4. Umbral CC");
        ui_line(64, "5. Planck");
        ui_line(76, "6. Resolucion");
        ui_footer("1-6 elegir | ESC volver");

        key = ui_wait_key();
        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                screen_photon_demo();
                break;

            case '2':
                task1_photon_presets();
                break;

            case '3':
                task1_photon_formula();
                break;

            case '4':
                task1_photon_threshold();
                break;

            case '5':
                task1_photon_planck();
                break;

            case '6':
                task1_photon_resolution();
                break;

            default:
                break;
        }
    }
}

static void task1_debroglie_electron_case(const char *title, double kinetic_ev)
{
    char buffer[64];
    double kinetic_j;
    double momentum;
    double velocity;
    double wavelength_m;

    kinetic_j = q_ev_to_j(kinetic_ev);
    momentum = q_nonrel_momentum_from_ke_j(Q_ME, kinetic_j);
    velocity = q_nonrel_velocity_from_ke_j(Q_ME, kinetic_j);
    wavelength_m = q_debroglie_wavelength_m(momentum);

    ui_clear();
    ui_title(title);
    sprintf(buffer, "K = %.1f eV", kinetic_ev);
    ui_line(14, buffer);
    sprintf(buffer, "K = %.3E J", kinetic_j);
    ui_line(24, buffer);
    ui_line(36, "MOMENTO:");
    ui_line(46, "p = sqrt(2*m*K)");
    sprintf(buffer, "p = %.3E", momentum);
    ui_line(56, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title(title);
    ui_line(14, "VELOCIDAD:");
    ui_line(24, "v = sqrt(2*K/m)");
    sprintf(buffer, "v = %.3E m/s", velocity);
    ui_line(34, buffer);
    sprintf(buffer, "v/c = %.3E", q_ratio(velocity, Q_C));
    ui_line(46, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title(title);
    ui_line(14, "ONDA:");
    ui_line(24, "lambda = h/p");
    sprintf(buffer, "lambda = %.3E m", wavelength_m);
    ui_line(34, buffer);
    sprintf(buffer, "lambda = %.3f pm", wavelength_m * 1.0e12);
    ui_line(46, buffer);
    ui_line(58, "dH = 128 pm");
    sprintf(buffer, "N = %.3E", q_ratio(128.0e-12, wavelength_m));
    ui_line(68, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title(title);
    ui_line(14, "FISICA:");
    ui_line(24, "lambda tipo pm");
    ui_line(34, "resuelve atomos");
    ui_line(46, "si v > c:");
    ui_line(56, "error eV->J o masa");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_debroglie_n2(void)
{
    char buffer[64];
    double mass_kg;
    double momentum;
    double wavelength_m;

    mass_kg = q_mass_from_u(28.0);
    momentum = q_classical_momentum(mass_kg, 500.0);
    wavelength_m = q_debroglie_wavelength_m(momentum);

    ui_clear();
    ui_title("N2");
    ui_line(14, "m = 28u");
    ui_line(24, "v = 500 m/s");
    sprintf(buffer, "m = %.3E kg", mass_kg);
    ui_line(34, buffer);
    sprintf(buffer, "p = %.3E", momentum);
    ui_line(46, buffer);
    sprintf(buffer, "lambda = %.3E m", wavelength_m);
    ui_line(58, buffer);
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_debroglie_na(void)
{
    char buffer[64];
    double mass_kg;
    double atom_p;
    double photon_p;
    double photons_to_stop;

    mass_kg = q_mass_from_u(22.99);
    atom_p = q_classical_momentum(mass_kg, 900.0);
    photon_p = q_photon_energy_j_from_nm(590.0) / Q_C;
    photons_to_stop = q_ratio(atom_p, 2.0 * photon_p);

    ui_clear();
    ui_title("NA 590 nm");
    ui_line(14, "m = 22.99u");
    ui_line(24, "v = 900 m/s");
    sprintf(buffer, "p = %.3E", atom_p);
    ui_line(34, buffer);
    sprintf(buffer, "m = %.3E kg", mass_kg);
    ui_line(46, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("NA 590 nm");
    ui_line(14, "PHOTON:");
    sprintf(buffer, "p_ph = %.3E", photon_p);
    ui_line(24, buffer);
    ui_line(36, "N = p / (2*p_ph)");
    sprintf(buffer, "N = %.3E", photons_to_stop);
    ui_line(46, buffer);
    ui_line(58, "2*p_ph = reflejo");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_debroglie_formula(void)
{
    ui_clear();
    ui_title("DE BROGLIE");
    ui_line(14, "K = p^2 / 2m");
    ui_line(24, "p = sqrt(2*m*K)");
    ui_line(34, "v = sqrt(2*K/m)");
    ui_line(46, "lambda = h/p");
    ui_line(58, "m = A*u");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("DE BROGLIE");
    ui_line(14, "electron: K eV -> J");
    ui_line(26, "luego p y lambda");
    ui_line(38, "H enlace ~128 pm");
    ui_line(50, "compara escalas");
    ui_line(62, "usa h, no hbar");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_debroglie_menu(void)
{
    short key;

    while (1)
    {
        ui_clear();
        ui_title("DE BROGLIE");
        ui_line(16, "1. electron 1 eV");
        ui_line(28, "2. electron 10 eV");
        ui_line(40, "3. electron 100 eV");
        ui_line(52, "4. N2 28u / 500");
        ui_line(64, "5. Na 22.99u / 900");
        ui_line(76, "6. formulas");
        ui_footer("1-6 elegir | ESC volver");

        key = ui_wait_key();
        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                task1_debroglie_electron_case("ELECTRON 1 eV", 1.0);
                break;

            case '2':
                task1_debroglie_electron_case("ELECTRON 10 eV", 10.0);
                break;

            case '3':
                task1_debroglie_electron_case("ELECTRON 100 eV", 100.0);
                break;

            case '4':
                task1_debroglie_n2();
                break;

            case '5':
                task1_debroglie_na();
                break;

            case '6':
                task1_debroglie_formula();
                break;

            default:
                break;
        }
    }
}

static void task1_photoelectric_case(void)
{
    char buffer[64];
    double lambda0_nm;
    double lambda_nm;
    double phi_ev;
    double energy_ev;
    double kinetic_ev;

    lambda0_nm = 564.0;
    lambda_nm = 410.0;
    phi_ev = q_work_function_ev_from_threshold_nm(lambda0_nm);
    energy_ev = q_photon_energy_ev_from_nm(lambda_nm);
    kinetic_ev = q_photoelectron_ke_ev(lambda_nm, lambda0_nm);

    ui_clear();
    ui_title("FOTOELECTRICO");
    ui_line(14, "POTASIO:");
    sprintf(buffer, "lambda0 = %.0f nm", lambda0_nm);
    ui_line(24, buffer);
    sprintf(buffer, "lambda = %.0f nm", lambda_nm);
    ui_line(34, buffer);
    ui_line(48, "phi = hc/lambda0");
    ui_line(60, "Kmax = E - phi");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("FOTOELECTRICO");
    sprintf(buffer, "phi = %.3f eV", phi_ev);
    ui_line(14, buffer);
    sprintf(buffer, "E = %.3f eV", energy_ev);
    ui_line(26, buffer);
    sprintf(buffer, "Kmax = %.3f eV", kinetic_ev);
    ui_line(38, buffer);
    ui_line(54, "lambda < lambda0");
    ui_line(66, "si hay emision");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photoelectric_formula(void)
{
    ui_clear();
    ui_title("FOTOELECTRICO");
    ui_line(14, "phi = h*c/lambda0");
    ui_line(24, "E = h*c/lambda");
    ui_line(34, "Kmax = E - phi");
    ui_line(46, "Kmax = hc(1/l -");
    ui_line(56, "1/l0)");
    ui_line(68, "con lambda en m");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("FOTO ATAJO");
    ui_line(14, "E(eV)=1240/lambda");
    ui_line(26, "phi=1240/lambda0");
    ui_line(38, "K=1240*(1/l-1/l0)");
    ui_line(50, "si lambda < lambda0");
    ui_line(62, "sale electron");
    ui_line(74, "si no, K=0");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_photoelectric_menu(void)
{
    short key;

    while (1)
    {
        ui_clear();
        ui_title("FOTOELECTRICO");
        ui_line(16, "1. Potasio 564/410");
        ui_line(28, "2. Formula");
        ui_footer("1-2 elegir | ESC volver");

        key = ui_wait_key();
        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                task1_photoelectric_case();
                break;

            case '2':
                task1_photoelectric_formula();
                break;

            default:
                break;
        }
    }
}

static void task1_forces_case(void)
{
    char buffer[64];
    double r_m;
    double potential_j;
    double potential_ev;
    double coulomb_n;
    double gravity_n;
    double ratio;

    r_m = 300.0e-12;
    potential_j = -(Q_E * Q_E) / (4.0 * Q_PI * Q_EPS0 * r_m);
    potential_ev = q_j_to_ev(potential_j);
    coulomb_n = q_coulomb_force_ep(r_m);
    gravity_n = q_gravity_force_ep(r_m);
    ratio = q_force_ratio(gravity_n, coulomb_n);

    ui_clear();
    ui_title("FUERZAS");
    ui_line(14, "r = 300 pm");
    ui_line(24, "V = -e^2/(4*pi*eps0*r)");
    ui_line(34, "F = -dV/dr");
    sprintf(buffer, "V = %.3E J", potential_j);
    ui_line(46, buffer);
    sprintf(buffer, "V = %.3f eV", potential_ev);
    ui_line(58, buffer);
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("FUERZAS PASOS");
    ui_line(14, "r=300 pm=3E-10 m");
    ui_line(26, "d(1/r)/dr=-1/r^2");
    ui_line(38, "Fe=e^2/(4*pi*eps0*r^2)");
    ui_line(50, "Fg=G*me*mp/r^2");
    ui_line(62, "error: usar 300 m");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("FUERZAS");
    sprintf(buffer, "Fe = %.3E N", coulomb_n);
    ui_line(14, buffer);
    sprintf(buffer, "Fg = %.3E N", gravity_n);
    ui_line(26, buffer);
    sprintf(buffer, "Fg/Fe = %.3E", ratio);
    ui_line(38, buffer);
    ui_line(54, "gravedad despreciable");
    ui_line(66, "ratio << 1");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_blackbody_case(void)
{
    char buffer[64];
    double x_high;
    double x_low;

    x_high = q_planck_dimensionless_x(1.0e12, 300.0);
    x_low = q_planck_dimensionless_x(1.0e11, 300.0);

    ui_clear();
    ui_title("CUERPO NEGRO");
    ui_line(14, "PLANCK:");
    ui_line(24, "drho = (8*pi*h/c^3)");
    ui_line(34, "* nu^3 /(exp(x)-1)");
    ui_line(46, "x = h*nu/(k*T)");
    ui_line(58, "x << 1 => clasico");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CUERPO NEGRO");
    ui_line(14, "BAJA FREC:");
    ui_line(24, "exp(x) ~ 1 + x");
    ui_line(34, "denom ~ h*nu/kT");
    ui_line(46, "RJ: (8*pi*k*T/c^3)");
    ui_line(58, "* nu^2 dnu");
    ui_line(70, "h*nu cancela");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CUERPO NEGRO");
    sprintf(buffer, "x(1E12,300)=%.3E", x_high);
    ui_line(14, buffer);
    sprintf(buffer, "x(1E11,300)=%.3E", x_low);
    ui_line(26, buffer);
    ui_line(38, "x < 0.1 => clasico");
    ui_line(50, "1E12 Hz: no");
    ui_line(60, "1E11 Hz: si");
    if (!task1_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CUERPO NEGRO");
    ui_line(14, "Planck corta alta nu");
    ui_line(26, "RJ crece como nu^2");
    ui_line(38, "alta nu explota");
    ui_line(50, "catastrofe UV");
    ui_line(62, "fisica: cuantos");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task1_menu_draw(void)
{
    ui_clear();
    ui_title("TAREA 1");
    ui_line(16, "1. Foton/Planck");
    ui_line(28, "2. de Broglie");
    ui_line(40, "3. Fotoelectrico");
    ui_line(52, "4. Fuerzas");
    ui_line(64, "5. Cuerpo negro");
    ui_footer("1-5 elegir | ESC volver");
}

void screen_task1_menu(void)
{
    short key;

    while (1)
    {
        task1_menu_draw();
        key = ui_wait_key();
        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                task1_photon_menu();
                break;

            case '2':
                task1_debroglie_menu();
                break;

            case '3':
                task1_photoelectric_menu();
                break;

            case '4':
                task1_forces_case();
                break;

            case '5':
                task1_blackbody_case();
                break;

            default:
                break;
        }
    }
}
