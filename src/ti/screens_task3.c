#include <stdio.h>
#include <tigcclib.h>
#include "ui.h"
#include "screens.h"
#include "../core/quantum.h"

static int task3_page_pause(void)
{
    return ui_wait_key() != KEY_ESC;
}

static void task3_box_probability(void)
{
    char buffer[64];
    double p11;
    double p12;
    double p13;
    double p21;
    double p22;
    double p23;

    p11 = q_box_probability_fraction(1, 0.0, 0.25);
    p12 = q_box_probability_fraction(2, 0.0, 0.25);
    p13 = q_box_probability_fraction(3, 0.0, 0.25);
    p21 = q_box_probability_fraction(1, 0.25, 0.5);
    p22 = q_box_probability_fraction(2, 0.25, 0.5);
    p23 = q_box_probability_fraction(3, 0.25, 0.5);

    ui_clear();
    ui_title("CAJA PROB");
    ui_line(14, "psi_n=sqrt(2/a)");
    ui_line(26, "*sin(n*pi*x/a)");
    ui_line(38, "P=int |psi|^2 dx");
    ui_line(50, "entre x1 y x2");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CAJA PROB");
    ui_line(14, "sin^2 antider:");
    ui_line(26, "x/2 - sin(2kx)/(4k)");
    ui_line(38, "k=n*pi/a");
    ui_line(50, "evalua limites");
    ui_line(62, "error: a/4 no 1/4");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CAJA PROB");
    ui_line(14, "P(0,a/4)");
    sprintf(buffer, "n1 = %.4f", p11);
    ui_line(24, buffer);
    sprintf(buffer, "n2 = %.4f", p12);
    ui_line(34, buffer);
    sprintf(buffer, "n3 = %.4f", p13);
    ui_line(44, buffer);
    ui_line(58, "a = ancho de caja");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("CAJA PROB");
    ui_line(14, "P(a/4,a/2)");
    sprintf(buffer, "n1 = %.4f", p21);
    ui_line(24, buffer);
    sprintf(buffer, "n2 = %.4f", p22);
    ui_line(34, buffer);
    sprintf(buffer, "n3 = %.4f", p23);
    ui_line(44, buffer);
    ui_line(58, "patron oscilante");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_px(void)
{
    ui_clear();
    ui_title("<px>");
    ui_line(14, "px=-i*hbar*d/dx");
    ui_line(26, "<px>=int psi* px psi dx");
    ui_line(38, "operador actua");
    ui_line(50, "sobre psi primero");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("<px>");
    ui_line(14, "psi real en caja");
    ui_line(26, "onda estacionaria");
    ui_line(38, "<px> = 0");
    ui_line(50, "izq y der cancelan");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_px2(void)
{
    ui_clear();
    ui_title("<px2>");
    ui_line(14, "px2=-hbar^2*d2/dx2");
    ui_line(26, "d2psi =");
    ui_line(38, "-(n*pi/a)^2 psi");
    ui_line(50, "entonces es auto");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("<px2>");
    ui_line(14, "<px2> =");
    ui_line(26, "(n*pi*hbar/a)^2");
    ui_line(38, "siempre positivo");
    ui_line(50, "mide energia cin");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_sigma_x(void)
{
    char buffer[64];
    double sigma1;
    double sigma2;
    double sigma3;

    sigma1 = q_box_sigma_x_over_a(1);
    sigma2 = q_box_sigma_x_over_a(2);
    sigma3 = q_box_sigma_x_over_a(3);

    ui_clear();
    ui_title("SIGMA X");
    ui_line(14, "<x> = a/2");
    ui_line(26, "<x2> = a^2(1/3");
    ui_line(38, "-1/(2n^2*pi^2))");
    ui_line(50, "sigma=sqrt(<x2>-<x>^2)");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("SIGMA X");
    sprintf(buffer, "sigma/a n1=%.4f", sigma1);
    ui_line(14, buffer);
    sprintf(buffer, "sigma/a n2=%.4f", sigma2);
    ui_line(26, buffer);
    sprintf(buffer, "sigma/a n3=%.4f", sigma3);
    ui_line(38, buffer);
    ui_line(52, "sube hacia a/sqrt(12)");
    ui_line(64, "mas extendida");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_expected_value(void)
{
    ui_clear();
    ui_title("VALOR ESP");
    ui_line(14, "<A>=int psi* Apsi dx");
    ui_line(26, "si psi compleja:");
    ui_line(38, "usa conjugada psi*");
    ui_line(50, "A actua sobre psi");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("VALOR ESP");
    ui_line(14, "1 aplica A a psi");
    ui_line(26, "2 multiplica psi*");
    ui_line(38, "3 integra dominio");
    ui_line(50, "4 revisa unidades");
    ui_line(62, "fisica: promedio");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_values_menu(void)
{
    short key;

    while (1)
    {
        ui_clear();
        ui_title("VALORES");
        ui_line(16, "1. <px>");
        ui_line(28, "2. <px2>");
        ui_line(40, "3. Sigma x");
        ui_line(52, "4. Valor esp");
        ui_footer("1-4 elegir | ESC volver");
        key = ui_wait_key();
        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1': task3_px(); break;
            case '2': task3_px2(); break;
            case '3': task3_sigma_x(); break;
            case '4': task3_expected_value(); break;
            default: break;
        }
    }
}

static void task3_trial_energy(void)
{
    char buffer[64];
    double energy_ev;

    energy_ev = q_box_trial_energy_poly_ev(Q_ME, 1.0e-9);

    ui_clear();
    ui_title("ENERGIA TRIAL");
    ui_line(14, "Psi = sqrt(630/a^9)");
    ui_line(24, "* x^2*(a-x)^2");
    ui_line(36, "H = -hbar^2/(2m)");
    ui_line(46, "d2/dx2");
    ui_line(58, "<E> = 6*hbar^2/(m*a^2)");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("ENERGIA TRIAL");
    ui_line(14, "deriva dos veces");
    ui_line(26, "integra Psi* H Psi");
    ui_line(38, "normalizacion incluida");
    ui_line(50, "error: olvidar dx");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("ENERGIA TRIAL");
    ui_line(14, "electron, a = 1 nm");
    sprintf(buffer, "E = %.4f eV", energy_ev);
    ui_line(26, buffer);
    ui_line(40, "no CAS, solo formula");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_oscillator(void)
{
    char buffer[64];
    double omega;
    double energy_j;
    double avg_t_j;

    omega = q_osc_omega(100.0, 2.0);
    energy_j = q_osc_total_energy_from_k(100.0, 1.0);
    avg_t_j = q_osc_avg_kinetic_energy(2.0, omega, 1.0);

    ui_clear();
    ui_title("OSCILADOR");
    ui_line(14, "d2x/dt2 + (k/m)x = 0");
    ui_line(26, "x = C*sin(wt+phi)");
    ui_line(38, "w = sqrt(k/m)");
    ui_line(52, "solucion armonica");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("OSCILADOR");
    ui_line(14, "verifica:");
    ui_line(26, "x''=-w^2 x");
    ui_line(38, "si w^2=k/m");
    ui_line(50, "cumple ecuacion");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("OSCILADOR");
    ui_line(14, "E = 1/2*k*C^2");
    ui_line(26, "= 1/2*m*w^2*C^2");
    ui_line(38, "<T>/E = 1/2");
    ui_line(50, "<T> = E/2");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("OSCILADOR");
    sprintf(buffer, "k=100 m=2 C=1");
    ui_line(14, buffer);
    sprintf(buffer, "w = %.3f", omega);
    ui_line(26, buffer);
    sprintf(buffer, "E = %.2f J", energy_j);
    ui_line(38, buffer);
    sprintf(buffer, "<T> = %.2f J", avg_t_j);
    ui_line(50, buffer);
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_formulas(void)
{
    ui_clear();
    ui_title("FORMULAS T3");
    ui_line(14, "psi_n = sqrt(2/a)");
    ui_line(24, "* sin(n*pi*x/a)");
    ui_line(34, "P=int |psi|^2 dx");
    ui_line(44, "<px2>=(n*pi*hbar/a)^2");
    ui_line(54, "<x> = a/2");
    ui_line(64, "<x2> = a^2*(1/3");
    ui_line(74, " -1/(2n^2*pi^2))");
    ui_footer("ENTER sigue | ESC vuelve");
    if (!task3_page_pause())
    {
        return;
    }

    ui_clear();
    ui_title("FORMULAS T3");
    ui_line(14, "sigma = sqrt(<x2>-<x>^2)");
    ui_line(26, "<E> = 6*hbar^2/(m*a^2)");
    ui_line(38, "w = sqrt(k/m)");
    ui_line(50, "E = 1/2*k*C^2");
    ui_line(62, "<T>/E = 1/2");
    ui_footer("ENTER sigue | ESC vuelve");
    ui_wait_key();
}

static void task3_menu_draw(void)
{
    ui_clear();
    ui_title("TAREA 3");
    ui_line(16, "1. Caja prob");
    ui_line(28, "2. Valores");
    ui_line(40, "3. Energia trial");
    ui_line(52, "4. Oscilador");
    ui_line(64, "5. Formulas");
    ui_footer("1-5 elegir | ESC volver");
}

void screen_task3_menu(void)
{
    short key;

    while (1)
    {
        task3_menu_draw();
        key = ui_wait_key();
        if (key == KEY_ESC)
        {
            break;
        }

        switch (key)
        {
            case '1':
                task3_box_probability();
                break;

            case '2':
                task3_values_menu();
                break;

            case '3':
                task3_trial_energy();
                break;

            case '4':
                task3_oscillator();
                break;

            case '5':
                task3_formulas();
                break;

            default:
                break;
        }
    }
}
