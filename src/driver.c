#include "c/include/kalman_filter_1D.h"
#include <stdio.h>
#define SIZE 4

void print_kalman_filter(kalman_filter_t const * const filter)
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
    double measurements[SIZE] = {75, 71, 70, 74};
    kalman_filter_t filter1 = {0.5, 68.0, 0, 2.0, 2.0, measurements[0], 4.0};
    printf("Initial condition...\n");
    print_kalman_filter(&filter1);
    int i;
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
