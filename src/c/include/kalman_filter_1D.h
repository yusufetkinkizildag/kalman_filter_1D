#ifndef __KALMAN_FILTER_1D_H__
#define __KALMAN_FILTER_1D_H__

struct KalmanFilter
{
    double kalman_gain;
    double previous_estimate;
    double current_estimate;
    double error_in_estimate;
    double previous_error_in_estimate;
    double current_measurement;
    double error_in_measurement;
};

typedef struct KalmanFilter kalman_filter_t;

double calculate_kalman_gain(double const, double const);
double calculate_current_estimate(double const, double const, double const);
double calculate_error_in_estimate(double const, double const);

#endif
