#pragma once

#include <crutch/concept/trivial_pointer_for.hpp>

#include <crutch/core/core.hpp>

namespace crutch {

template <typename Pointer, typename Type>
concept PointerFor = TrivialPointerFor<Pointer, Type> ||
    requires(Pointer pointer) {
      { pointer.operator*() } noexcept -> ::std::convertible_to<Type&>;
      { pointer.operator->() } noexcept -> ::std::convertible_to<Type*>;
    };

}  // namespace crutch