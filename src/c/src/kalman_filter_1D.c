#include "../include/kalman_filter_1D.h"

double calculate_kalman_gain(double const error_in_estimate, double const error_in_measurement)
{
    return error_in_estimate / (error_in_estimate + error_in_measurement);
}

double calculate_current_estimate(double const previous_estimate, double const kalman_gain, double const current_measurement)
{
    return previous_estimate + kalman_gain * (current_measurement - previous_estimate);
}

double calculate_error_in_estimate(double const kalman_gain, double const previous_error_in_estimate)
{
    return (1 - kalman_gain) * previous_error_in_estimate;
}
