#ifndef BITOPS_H
#define BITOPS_H

namespace bitops {

/// Flips the bit at position n
template<typename _IntT, typename _SmallIntT>
inline void flip(_IntT& i, _SmallIntT n) {
    i ^= 1 << (n - 1);
}

/// Sets the bit at position n
template<typename _IntT, typename _SmallIntT>
inline void set(_IntT& i, _SmallIntT n) {
    i |= 1 << (n - 1);
}

/// Sets all bits in the mask in i
template<typename _IntT>
inline void set_mask(_IntT& i, _IntT mask) {
    i |= mask;
}

/// Unsets all bits in the mask in i
template<typename _IntT>
inline void unset_mask(_IntT& i, _IntT mask) {
    i &= ~mask;
}

/// Unsets the bit at position n
template<typename _IntT, typename _SmallIntT>
inline void unset(_IntT& i, _SmallIntT n) {
    i &= ~(1 << (n - 1));
}

/// Checks whether the bit at position n is set
template<typename _IntT, typename _SmallIntT>
inline constexpr bool is_set(_IntT i, _SmallIntT n) {
    return i & (1 << (n - 1));
}

/// Checks whether the bit at position n is NOT set
template<typename _IntT, typename _SmallIntT>
inline constexpr bool is_not_set(_IntT i, _SmallIntT n) {
    return !is_set(i, n);
}

/// Checks whether all bits in the mask are set in i
template<typename _IntT>
inline constexpr bool is_mask_set(_IntT i, _IntT mask) {
    return (i & mask) == mask;
}

}

#endif // BITOPS_H
