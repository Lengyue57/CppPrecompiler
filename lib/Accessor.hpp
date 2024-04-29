#ifndef _ACCESSOR_ACCESSOR_HPP
#define _ACCESSOR_ACCESSOR_HPP

#include <initializer_list>
#include <utility>

// template<class _Ty>
// concept

template<class _inClass, class _type>
class Accessor {
  friend _inClass;
  using value_type = _type;

  value_type obj;

  template<class... _Tys>
  constexpr Accessor(_Tys&&... _args): obj(std::forward<_Tys>(_args)...) {}
  template<class _Ty>
  constexpr Accessor(std::initializer_list<_Ty>&& _init):
    obj(std::forward<std::initializer_list<_Ty>>(_init))
  {}

  template<class _Ty>
  Accessor& operator=(_Ty&& _src) {
    obj = std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator+=(_Ty&& _src) {
    obj += std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator-=(_Ty&& _src) {
    obj -= std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator*=(_Ty&& _src) {
    obj *= std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator/=(_Ty&& _src) {
    obj /= std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator%=(_Ty&& _src) {
    obj %= std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator^=(_Ty&& _src) {
    obj ^= std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator&=(_Ty&& _src) {
    obj &= std::forward<_Ty>(_src);
    return *this;
  }
  template<class _Ty>
  Accessor& operator|=(_Ty&& _src) {
    obj |= std::forward<_Ty>(_src);
    return *this;
  }
 public:

};

#endif // !_ACCESSOR_ACCESSOR_HPP