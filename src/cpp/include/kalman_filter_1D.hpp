#pragma once

namespace etkin
{
  
  struct KalmanFilter
  {
    double previous_estimate;
    double current_estimate;
    double previous_error_in_estimate;
  };

}
