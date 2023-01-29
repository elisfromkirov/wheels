#pragma once

#include <crutch/allocator/core/allocator.hpp>
#include <crutch/allocator/core/default.hpp>

#include <crutch/core/concept/constructible.hpp>
#include <crutch/core/concept/copy_constructible.hpp>
#include <crutch/core/concept/move_constructible.hpp>

#include <crutch/core/macro/assert.hpp>
#include <crutch/core/type/size.hpp>

#include <crutch/container/vector/detail/vector_base.hpp>

namespace crutch {

template <typename Type>
class Vector : private detail::VectorBase<Type> {
 public:
  static constexpr SizeType default_capacity{8};

  static constexpr SizeType default_growth_factor{2};

 public:
  using Iterator = Type*;

  using ConstIterator = const Type*;

 public:
  explicit Vector(IAllocator* allocator = GetDefaultAllocator());

  Iterator Begin() noexcept;

  Iterator End() noexcept;

  ConstIterator ConstBegin() const noexcept;

  ConstIterator ConstEnd() const noexcept;

  Type& operator[](SizeType index) noexcept;

  const Type& operator[](SizeType index) const noexcept;

  Type& At(SizeType index) noexcept;

  const Type& At(SizeType index) const noexcept;

  Type& Back() noexcept;

  const Type& Back() const noexcept;

  Type* Data() noexcept;

  const Type* Data() const noexcept;

  [[nodiscard]]
  bool IsEmpty() const noexcept;

  [[nodiscard]]
  SizeType Size() const noexcept;

  [[nodiscard]]
  SizeType Capacity() const noexcept;

  void Reserve(SizeType capacity) requires CopyConstructible<Type> && (!MoveConstructible<Type>);

  void Reserve(SizeType capacity) requires MoveConstructible<Type>;

  void PushBack(const Type& value) requires CopyConstructible<Type>;

  void PushBack(Type&& value) requires MoveConstructible<Type>;

  template <typename... ArgTypes>
  requires Constructible<Type, ArgTypes...>
  void EmplaceBack(ArgTypes&&... args);

  void PopBack() noexcept;
};

}  // namespace crutch

#define VECTOR_IMPL
#include <crutch/container/vector/vector.ipp>
#undef VECTOR_IMPL