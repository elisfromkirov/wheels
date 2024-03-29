#pragma once

#include <wheels/core/core.hpp>

namespace wheels {

template <typename Type>
class Ptr {
 public:
  explicit Ptr(Type* ptr = nullptr) noexcept;

  Ptr& operator+=(SizeType offset) noexcept;
  Ptr& operator-=(SizeType offset) noexcept;

  Ptr& operator++() noexcept;
  const Ptr operator++(int) noexcept;

  Ptr& operator--() noexcept;
  const Ptr operator--(int) noexcept;

  Type& operator*() noexcept;

  Type* operator->() noexcept;

  Type* Base() noexcept;

 private:
  [[nodiscard]]
  bool IsValid() const noexcept;

 private:
  Type* ptr_;
};

template <typename Type>
bool operator==(Ptr<Type> lhs, Ptr<Type> rhs) noexcept;

template <typename Type>
bool operator!=(Ptr<Type> lhs, Ptr<Type> rhs) noexcept;

template <typename Type>
const Ptr<Type> operator+(Ptr<Type> ptr, SizeType offset) noexcept;

template <typename Type>
const Ptr<Type> operator-(Ptr<Type> ptr, SizeType offset) noexcept;

}  // namespace wheels

#define PTR_IMPL
#include <wheels/iterator/ptr.ipp>
#undef PTR_IMPL