#include "../include/kalman_filter_1D.hpp"

namespace etkin
{

    KalmanFilter::KalmanFilter(KalmanFilterState const &state) noexcept
        : state{state}
        {

        }
    
    KalmanFilter::KalmanFilter(KalmanFilterState &&state) noexcept
        : state{std::move(state)}
        {

        }

    double KalmanFilter::update(double const current_measurement) noexcept
    {
        this->state.current_measurement = current_measurement;
        calculate_kalman_gain();
        calculate_current_estimate();
        calculate_error_in_estimate();
        return this->state.current_estimate;
    }

    KalmanFilterState KalmanFilter::get_current_state() const noexcept
    {
        return this->state;
    }

    void KalmanFilter::calculate_kalman_gain() noexcept
    {
        this->state.kalman_gain = this->state.error_in_estimate / (this->state.error_in_estimate + this->state.error_in_measurement);
    }

    void KalmanFilter::calculate_current_estimate() noexcept
    {
        this->state.current_estimate = this->state.previous_estimate + this->state.kalman_gain * (this->state.current_measurement - this->state.previous_estimate);
    }

    void KalmanFilter::calculate_error_in_estimate() noexcept
    {
        this->state.error_in_estimate = (1 - this->state.kalman_gain) * this->state.previous_error_in_estimate;
    }

} // namespace etkin

