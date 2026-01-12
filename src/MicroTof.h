

#ifndef __MICRO_TOF_H__
#define __MICRO_TOF_H__

#include <Arduino.h>
#include <cmath> // for fmodf

#include <type_traits>
#include <assert.h>
#include <cassert>
#include <cstring>


/* #ifndef MICRO_TOF_COUNT_OF_ARRAY
#define MICRO_TOF_COUNT_OF_ARRAY(X) (sizeof(X) / sizeof(X[0]))
#endif */

namespace MicroTof
{

  int modulo(int value, int modulus)
  {
    return (value % modulus + modulus) % modulus;
  }

  // Wrap 'value' to the range [min, max] (max inclusive)
  int wrap(int value, int min, int max)
  {
    int range = max - min + 1; // +1 for max-inclusive
    if (range <= 1)
      return min;

    return MicroTof::modulo(value - min, range) + min;
  }

  // Clamps 'value' to the range [min, max] (max inclusive)
  template <typename T>
  T clamp(T value, T min, T max)
  {
    if (value <= min)
      return min;
    if (value >= max)
      return max;
    return value;
  }

  // Maps 'value' from [in_min, in_max] to [out_min, out_max]
  template <typename T>
  T map(T value, T in_min, T in_max, T out_min, T out_max)
  {
    const T run = in_max - in_min;
    if (run == 0)
    {
      return 0;
    }
    const T rise = out_max - out_min;
    const T delta = value - in_min;
    return (delta * rise) / run + out_min;
  }

  // Deterministic random (fast hash)
  uint32_t randomHash32(uint32_t x)
  {
    x ^= x >> 17;
    x *= 0xed5ad4bbU;
    x ^= x >> 11;
    x *= 0xac4c1b51U;
    x ^= x >> 15;
    x *= 0x31848babU;
    x ^= x >> 14;
    return x;
  }

  float rand01(uint32_t x)
  {
    return randomHash32(x) / 4294967295.0f;
  }

  // Smooth random between integer steps (interpolated hash)
  // The integer part of x is the actual random value
  // The float part is the interpolation factor (% between two random values)
  float interpolatedRandom01(float x, uint32_t seed)
  {
    int xi = floor(x);
    float xf = x - xi;
    float a = rand01(seed + xi);
    float b = rand01(seed + xi + 1);
    return a * (1 - xf) + b * xf;
  }

  // ==============================================


/* 
  template <typename T, size_t Initial = 4, size_t GrowBy = 4>
  class PointerList
  {
    static_assert(std::is_pointer<T>::value,
                  "PointerList<T>: T must be a pointer type");

    T *data_ = nullptr; // array of pointers (T is already a pointer)
    size_t count_ = 0;
    size_t capacity_;

  public:
    PointerList() : capacity_(Initial)
    {
      data_ = (T *)malloc(sizeof(T) * capacity_);
      if (!data_)
        capacity_ = 0;
    }

    ~PointerList()
    {
      free(data_);
    }

    size_t getCount() const { return count_; }

    // get stored pointer
    T get(size_t index) const
    {
      assert(index < count_);
      return data_[index];
    }

    // add pointer
    bool add(T item)
    {
      if (item == nullptr)
        return false;

      if (count_ >= capacity_)
      {
        size_t newCapacity = capacity_ + GrowBy;
        T *newData = (T *)malloc(sizeof(T) * newCapacity);
        if (!newData)
          return false;

        memcpy(newData, data_, sizeof(T) * count_);
        free(data_);
        data_ = newData;
        capacity_ = newCapacity;
      }

      data_[count_++] = item;
      return true;
    }
  };

  // ==============================================

  // Key + pointer pair
  template <typename T>
  struct KeyPointerPair
  {
    static_assert(std::is_pointer<T>::value,
                  "KeyPointerPair<T>: T must be a pointer type");

    const char *key_;
    T pointer_; // store pointer internally

    // Constructor takes a pointer and stores the address
    KeyPointerPair(const char *key, T pointer) : key_(key), pointer_(pointer) {}
  };

  // ==============================================

  // Binder
  template <typename T, size_t Initial = 4, size_t GrowBy = 4>
  class Binder
  {
    static_assert(std::is_pointer<T>::value, "KeyPointerBinder<T>: T must be a pointer type");

    PointerList<KeyPointerPair<T> *, Initial, GrowBy> pairs_;

  public:
    Binder() {}

    ~Binder()
    {
      for (size_t i = 0; i < pairs_.getCount(); ++i)
        delete pairs_.get(i);
    }

    // bind by pointer
    bool add(const char *key, T pointer)
    {
      return pairs_.add(new KeyPointerPair<T>{key, pointer});
    }

    // get pointer to the stored value by key
    T get(const char *key)
    {
      for (size_t i = 0; i < pairs_.getCount(); ++i)
      {
        if (strcmp(pairs_.get(i)->key_, key) == 0)
          return pairs_.get(i)->pointer_;
      }
      return nullptr;
    }

    // get pointer by index
    T get(size_t index)
    {
      if (index >= pairs_.getCount())
        return nullptr;
      return pairs_.get(index)->pointer_;
    }

    size_t getCount() const { return pairs_.getCount(); }
  }; */



// ==============================================
// Simple fixed-size pointer list
/* template <typename T, size_t Capacity = 8>
class PointerList
{
    static_assert(std::is_pointer<T>::value, "PointerList<T>: T must be a pointer type");

    T data_[Capacity]; // array of pointers (T is already a pointer)
    size_t count_ = 0;

public:
    PointerList() = default;

    size_t getCount() const { return count_; }

    // get stored pointer
    T get(size_t index) const
    {
        assert(index < count_);
        return data_[index];
    }

    // add pointer
    bool add(T item)
    {
        if (item == nullptr)
            return false;

        if (count_ >= Capacity)
            return false; // reached max capacity

        data_[count_++] = item;
        return true;
    }
}; */

// ==============================================
// Key + pointer pair
template <typename T>
struct KeyPointerPair
{
    static_assert(std::is_pointer<T>::value, "KeyPointerPair<T>: T must be a pointer type");

    const char *key_ = nullptr;
    T pointer_ = nullptr; 

    KeyPointerPair(const char *key, T pointer) : key_(key), pointer_(pointer) {};

    KeyPointerPair() {};
};

// ==============================================
// Binder
template <typename T, size_t Capacity = 8>
class Binder
{
    static_assert(std::is_pointer<T>::value, "Binder<T>: T must be a pointer type");
    size_t count_ = 0;
    KeyPointerPair<T> pairs_[Capacity];

public:
    Binder() = default;

    ~Binder()
    {

    }

    // bind by pointer
    bool add(const char *key, T pointer)
    {
        if (count_ >= Capacity)
            return false; // reached max capacity

        pairs_[count_].key_ = key;
        pairs_[count_].pointer_ = pointer;
        count_++;
        return true;
    }

    // get pointer to the stored value by key
    T get(const char *key)
    {
        for (size_t i = 0; i < count_; ++i)
        {
            if (strcmp(pairs_[i].key_, key) == 0)
                return pairs_[i].pointer_;
        }
        return nullptr;
    }

    // get pointer by index
    T get(size_t index)
    {
        if (index >= count_)
            return nullptr;
        return pairs_[index].pointer_;
    }

    size_t getCount() const { return count_; }
};

} // namespace MicroTof
#endif
