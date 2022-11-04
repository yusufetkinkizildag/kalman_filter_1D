#include "cpp/include/kalman_filter_1D.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

namespace utility
{

    constexpr static auto print_state{[](auto const &state) noexcept
    {
        std::cout << "kalman_gain                  :" << state.kalman_gain << '\n';
        std::cout << "previous_estimate            :" << state.previous_estimate << '\n';
        std::cout << "current_estimate             :" << state.current_estimate << '\n';
        std::cout << "error_in_estimate            :" << state.error_in_estimate << '\n';
        std::cout << "previous_error_in_estimate   :" << state.previous_error_in_estimate << '\n';
        std::cout << "current_measurement          :" << state.current_measurement << '\n';
        std::cout << "error_in_measurement         :" << state.error_in_measurement << '\n';
    }};

} // namespace utility


int main(int argc, char const *argv[])
{
    // // Call the constructor with the constant lvalue reference to state object
    // etkin::KalmanFilterState initial_state{.kalman_gain{0.1},
    //    .previous_estimate{68.0},
    //    .current_estimate{0.0},
    //    .error_in_estimate{2.0},
    //    .previous_error_in_estimate{2.0},
    //    .current_measurement{75.0},
    //    .error_in_measurement{4.0}};
    // etkin::KalmanFilter filter{initial_state};

    // // Call the constructor with the rvalue reference to state object
    etkin::KalmanFilter filter{etkin::KalmanFilterState{.kalman_gain{0.1},
                                                        .previous_estimate{68.0},
                                                        .current_estimate{0.0},
                                                        .error_in_estimate{2.0},
                                                        .previous_error_in_estimate{2.0},
                                                        .current_measurement{75.0},
                                                        .error_in_measurement{4.0}}};

    std::vector<double> const measurements{75.0, 71.0, 70.0, 74.0, 72.0, 72.0, 72.0, 72.0, 72.0, 72.0, 72.0, 72.0, 72.0};

    std::for_each(std::cbegin(measurements), std::cend(measurements), [&filter](auto const current_measurement) noexcept
    {
        auto const current_estimate{filter.update(current_measurement)};
        std::cout << "current_measurement: " << current_measurement << '\n';
        std::cout << "current estimate: " << current_estimate << '\n';
        utility::print_state(filter.get_state());
    });

    filter.reset(etkin::KalmanFilterState{.kalman_gain{0.9},
                                          .previous_estimate{68.0},
                                          .current_estimate{0.0},
                                          .error_in_estimate{2.0},
                                          .previous_error_in_estimate{2.0},
                                          .current_measurement{75.0},
                                          .error_in_measurement{4.0}});

    utility::print_state(filter.get_state());

    return 0;
}
