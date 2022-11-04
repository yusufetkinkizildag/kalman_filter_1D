#include "../include/kalman_filter_1D.hpp"

namespace etkin
{

    KalmanFilter::KalmanFilter(KalmanFilterState const &state) noexcept : state{state} {}
    
    KalmanFilter::KalmanFilter(KalmanFilterState &&state) noexcept : state{std::move(state)} {}

    double KalmanFilter::update(double const current_measurement) noexcept
    {
        auto &s{this->state};
        s.current_measurement = current_measurement;
        s.kalman_gain = s.error_in_estimate / (s.error_in_estimate + s.error_in_measurement);
        s.current_estimate = s.previous_estimate + s.kalman_gain * (s.current_measurement - s.previous_estimate);
        s.error_in_estimate = (1 - s.kalman_gain) * s.previous_error_in_estimate;
        return s.current_estimate;
    }

    KalmanFilterState KalmanFilter::get_state() const noexcept
    {
        return this->state;
    }

    void KalmanFilter::reset(KalmanFilterState const &new_state) noexcept
    {
        this->state = new_state;
    }

    void KalmanFilter::reset(KalmanFilterState &&new_state) noexcept
    {
        this->state = std::move(new_state);
    }

} // namespace etkin

