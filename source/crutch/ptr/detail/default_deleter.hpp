#pragma once

#include <crutch/concept/derived_from.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>
#include <crutch/memory/placement.hpp>

namespace crutch {

namespace detail {

template <typename Type>
struct DefaultDeleter {
 public:
  DefaultDeleter() = default;

  template <DerivedFrom<Type> DerivedType>
  explicit DefaultDeleter(DefaultDeleter<DerivedType>&& other) noexcept;

  void operator()(Type* pointer) noexcept;
};

}  // namespace detail

}  // namespace crutch

#define DEFAULT_DELETER_IMPL
#include <crutch/ptr/detail/default_deleter.ipp>
#undef DEFAULT_DELETER_IMPL