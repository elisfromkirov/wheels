#pragma once

#include <wheels/core/core.hpp>

#include <wheels/iterator/const_ptr.hpp>
#include <wheels/iterator/ptr.hpp>

namespace wheels {

template <typename Type, SizeType size>
class Array {
 public:
  using Iterator = Ptr<Type>;

  using ConstIterator = ConstPtr<Type>;

 public:
  Iterator Begin() noexcept;

  Iterator End() noexcept;

  ConstIterator ConstBegin() const noexcept;

  ConstIterator ConstEnd() const noexcept;

  Type& operator[](SizeType index) noexcept;

  const Type& operator[](SizeType index) const noexcept;

  Type& At(SizeType index) noexcept;

  const Type& At(SizeType index) const noexcept;

  Type* Data() noexcept;

  const Type* Data() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

 private:
  alignas(alignof(Type)) Byte data_[size * sizeof(Type)];
};

}  // namespace wheels

#define ARRAY_IMPL
#include <wheels/array/array.ipp>
#undef ARRAY_IMPL