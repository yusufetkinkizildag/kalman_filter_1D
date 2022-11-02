# kalman_filter_1D
$K$ stands for `kalman_gain`

$E_{est}$ stands for `error_in_estimate`

$E_{mea}$ stands for `error_in_measurement`

$$K = \frac{E_{est}}{E_{est} + E_{mea}}$$

So

$$ 0 \leq K \leq 1 $$

$X_{t-1}$ stands for `previous_estimate`

$X_t$ stands for `current_estimate`

$M$ stands for `current_measurement`

$$X_t = X_{t-1} + K(M - X_{t-1})$$

$E_{est_{t-1}}$ stands for `previous_error_in_estimate`

$$E_{est} = (1 - K) E_{est_{t-1}}$$
