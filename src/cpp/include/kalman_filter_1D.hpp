#pragma once

#include <utility>

namespace etkin
{

    struct KalmanFilterState
    {
        double kalman_gain;
        double previous_estimate;
        double current_estimate;
        double error_in_estimate;
        double previous_error_in_estimate;
        double current_measurement;
        double error_in_measurement;
    };

    class KalmanFilter
    {
    private:
        KalmanFilterState state;
        void calculate_kalman_gain() noexcept;
        void calculate_current_estimate() noexcept;
        void calculate_error_in_estimate() noexcept;
    public:
        KalmanFilter(KalmanFilterState const &) noexcept;
        KalmanFilter(KalmanFilterState &&) noexcept;
        double update(double const) noexcept;
        KalmanFilterState get_current_state() const noexcept;
    };

}
