#include "quantum.h"

double q_planck_dimensionless_x(double frequency_hz, double temperature_k)
{
    if (temperature_k <= 0.0)
    {
        return 0.0;
    }

    return (Q_H * frequency_hz) / (Q_KB * temperature_k);
}

int q_planck_low_frequency_limit_valid(double frequency_hz, double temperature_k)
{
    return q_planck_dimensionless_x(frequency_hz, temperature_k) < 0.1;
}
