# MicroCommon

Utility library for Arduino Micro Libraries

Git URL : https://github.com/thomasfredericks/MicroCommon

Namespace: Micro

## Functions

### `Micro::modulo(value, modulus)`

Computes the modulo of a value, ensuring a non-negative result.

- Parameters:
  - `value`:  Input value (`int32_t`)
  - `modulus`:  Modulus value (`int32_t`)
- Returns:
  - Value wrapped in the range `[0, modulus-1]` (`int32_t`)

### `Micro::wrap(value, min, max)`

Wraps `value` to the inclusive range `[min, max]`.

- Parameters:
  - `value`:  Input value (`int32_t`)
  - `min`:  Minimum value of range (`int32_t`)
  - `max`:  Maximum value of range (`int32_t`)
- Returns:
  - Wrapped value in `[min, max]` (`int32_t`)

### `Micro::clamp<T>(value, min, max)`

Clamps a value to the inclusive range `[min, max]`.

- Parameters:
  - `value`:  Input value (`T`)
  - `min`:  Minimum allowed value (`T`)
  - `max`:  Maximum allowed value (`T`)
- Returns:
  - Clamped value (`T`)

### `Micro::map<T>(value, in_min, in_max, out_min, out_max)`

Maps a value from the input range `[in_min, in_max]` to the output range `[out_min, out_max]`.

- Parameters:
  - `value`:  Input value (`T`)
  - `in_min`:  Minimum of input range (`T`)
  - `in_max`:  Maximum of input range (`T`)
  - `out_min`:  Minimum of output range (`T`)
  - `out_max`:  Maximum of output range (`T`)
- Returns:
  - Mapped value in output range (`T`)

### `Micro::randomHash32(x)`

Generates a deterministic 32-bit hash from the input integer.

- Parameters:
  - `x`:  Input seed (`uint32_t`)
- Returns:
  - Deterministic hashed value (`uint32_t`)

### `Micro::rand01(x)`

Generates a deterministic pseudo-random float in the range `[0.0, 1.0]`.

- Parameters:
  - `x`:  Input seed (`uint32_t`)
- Returns:
  - Pseudo-random float (`float`)

### `Micro::interpolatedRandom01(x)`

Generates a deterministic pseudo-random float in `[0.0, 1.0]` with linear interpolation between integer steps.

- Parameters:
  - `x`:  Input value (`float`)
- Returns:
  - Interpolated pseudo-random float (`float`)

