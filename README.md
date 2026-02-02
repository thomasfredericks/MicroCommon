# MicroCommon

Utility library for Arduino Micro Libraries

Git URL : https://github.com/thomasfredericks/MicroCommon

## Functions

### `microModulo(value, modulus)`

Returns the modulus of `value` wrapped to always be non-negative.

- Parameters:
  - `value`: Value to wrap (`int32_t`)
  - `modulus`: Modulus (`int32_t`)
- Returns:
  - The wrapped value (`int32_t`)

### `microWrap(value, min, max)`

Wraps `value` to the inclusive range `[min, max]`.

- Parameters:
  - `value`: Value to wrap (`int32_t`)
  - `min`: Minimum value (`int32_t`)
  - `max`: Maximum value (`int32_t`)
- Returns:
  - The wrapped value (`int32_t`)

### `microClamp<T>(value, min, max)`

Clamps `value` to the inclusive range `[min, max]`.

- Template Parameter: T – Type of value, min, and max
- Parameters:
  - `value`: Value to clamp (`T`)
  - `min`: Minimum value (`T`)
  - `max`: Maximum value (`T`)
- Returns:
  - The clamped value (`T`)

### `microMap<T>(value, in_min, in_max, out_min, out_max)`

Maps `value` from the range `[in_min, in_max]` to `[out_min, out_max]`.

- Template Parameter: T – Type of input and output values
- Parameters:
  - `value`: Value to map (`T`)
  - `in_min`: Input range minimum (`T`)
  - `in_max`: Input range maximum (`T`)
  - `out_min`: Output range minimum (`T`)
  - `out_max`: Output range maximum (`T`)
- Returns:
  - The mapped value (`T`)

### `microRandomHash32(x)`

Generates a deterministic 32-bit random hash from `x`.

- Parameters:
  - `x`: Input seed (`uint32_t`)
- Returns:
  - Randomized hash (`uint32_t`)

### `microRand01(x)`

Generates a deterministic random float in the range `[0.0, 1.0]` based on `x`.

- Parameters:
  - `x`: Input seed (`uint32_t`)
- Returns:
  - Ran


