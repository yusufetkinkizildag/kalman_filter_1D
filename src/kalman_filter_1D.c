#include <stdio.h>
#define SIZE 4

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

double calculate_kalman_gain(double error_in_estimate, double error_in_measurement)
{
    double kalman_gain = error_in_estimate / (error_in_estimate + error_in_measurement);
    return kalman_gain;
}

double calculate_current_estimate(double previous_estimate, double kalman_gain, double current_measurement)
{
    double current_estimate = previous_estimate + kalman_gain * (current_measurement - previous_estimate);
    return current_estimate;
}

double calculate_error_in_estimate(double kalman_gain, double previous_error_in_estimate)
{
    double error_in_estimate = (1 - kalman_gain) * previous_error_in_estimate;
    return error_in_estimate;
}

void print_kalman_filter(kalman_filter_t *filter)
{
    if (filter != NULL)
    {
        printf("kalman_gain                  : %lf\n", filter->kalman_gain);
        printf("previous_estimate            : %lf\n", filter->previous_estimate);
        printf("current_estimate             : %lf\n", filter->current_estimate);
        printf("error_in_estimate            : %lf\n", filter->error_in_estimate);
        printf("previous_error_in_estimate   : %lf\n", filter->previous_error_in_estimate);
        printf("current_measurement          : %lf\n", filter->current_measurement);
        printf("error_in_measurement         : %lf\n", filter->error_in_measurement);
        printf("\n\n");
    }
    else
    {
        printf("filter pointer is NULL...\n");
    }
}

int main(int argc, char const *argv[])
{
    int i;
    double measurements[SIZE] = {75, 71, 70, 74};
    kalman_filter_t filter1 = {0.5, 68.0, 0, 2.0, 2.0, measurements[0], 4.0};
    printf("Initial condition...\n");
    print_kalman_filter(&filter1);
    for (i = 0; i < SIZE; i++)
    {
        printf("%d. measurement...\n", i);
        filter1.current_measurement = measurements[i];
        filter1.kalman_gain = calculate_kalman_gain(filter1.error_in_estimate, filter1.error_in_measurement);
        printf("kalman_gain calculated...\n");
        print_kalman_filter(&filter1);
        filter1.current_estimate = calculate_current_estimate(filter1.previous_estimate, filter1.kalman_gain, filter1.current_measurement);
        printf("current_estimate calculated...\n");
        print_kalman_filter(&filter1);
        filter1.error_in_estimate = calculate_error_in_estimate(filter1.kalman_gain, filter1.previous_error_in_estimate);
        printf("error_in_estimate calculated...\n");
        print_kalman_filter(&filter1);
        filter1.previous_error_in_estimate = filter1.error_in_estimate;
        filter1.previous_estimate = filter1.current_estimate;
    }

    return 0;
}
