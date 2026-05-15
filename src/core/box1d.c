#include <math.h>
#include "quantum.h"

double q_box_probability_fraction(int n, double x1_over_a, double x2_over_a)
{
    double f1;
    double f2;
    double twonpi;
    double result;
    double tmp;

    if (n <= 0)
    {
        return 0.0;
    }

    f1 = x1_over_a;
    f2 = x2_over_a;
    if (f2 < f1)
    {
        tmp = f1;
        f1 = f2;
        f2 = tmp;
    }

    twonpi = 2.0 * (double)n * Q_PI;
    result = (f2 - f1) - (sin(twonpi * f2) - sin(twonpi * f1)) / twonpi;
    return result;
}

double q_box_px2_expected(int n, double length_m)
{
    double nd;

    if (n <= 0 || length_m <= 0.0)
    {
        return 0.0;
    }

    nd = (double)n * Q_PI * Q_HBAR / length_m;
    return nd * nd;
}

double q_box_x_expected(double length_m)
{
    if (length_m <= 0.0)
    {
        return 0.0;
    }

    return 0.5 * length_m;
}

double q_box_x2_expected(int n, double length_m)
{
    double nd;

    if (n <= 0 || length_m <= 0.0)
    {
        return 0.0;
    }

    nd = (double)n;
    return length_m * length_m * (1.0 / 3.0 - 1.0 / (2.0 * nd * nd * Q_PI * Q_PI));
}

double q_box_sigma_x(int n, double length_m)
{
    double x_expected;
    double x2_expected;
    double variance;

    if (n <= 0 || length_m <= 0.0)
    {
        return 0.0;
    }

    x_expected = q_box_x_expected(length_m);
    x2_expected = q_box_x2_expected(n, length_m);
    variance = x2_expected - (x_expected * x_expected);
    if (variance < 0.0)
    {
        variance = 0.0;
    }

    return sqrt(variance);
}

double q_box_sigma_x_over_a(int n)
{
    double variance_over_a2;

    if (n <= 0)
    {
        return 0.0;
    }

    variance_over_a2 = 1.0 / 12.0 - 1.0 / (2.0 * (double)n * (double)n * Q_PI * Q_PI);
    if (variance_over_a2 < 0.0)
    {
        variance_over_a2 = 0.0;
    }

    return sqrt(variance_over_a2);
}

double q_box_trial_energy_poly_j(double mass_kg, double length_m)
{
    if (mass_kg <= 0.0 || length_m <= 0.0)
    {
        return 0.0;
    }

    return (6.0 * Q_HBAR * Q_HBAR) / (mass_kg * length_m * length_m);
}

double q_box_trial_energy_poly_ev(double mass_kg, double length_m)
{
    return q_j_to_ev(q_box_trial_energy_poly_j(mass_kg, length_m));
}
