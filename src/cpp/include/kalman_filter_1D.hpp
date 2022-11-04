#pragma once

#include <utility>
#include <vector>
#include <algorithm>

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
    public:
        KalmanFilter(KalmanFilterState const &) noexcept;
        KalmanFilter(KalmanFilterState &&) noexcept;
        void reset(KalmanFilterState const &) noexcept;
        void reset(KalmanFilterState &&) noexcept;
        double update(double const) noexcept;
        std::vector<double> update(std::vector<double> const &) noexcept;
        KalmanFilterState get_state() const noexcept;
    };

}
