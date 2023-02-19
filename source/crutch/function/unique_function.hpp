#pragma once

#include <crutch/concept/copyable.hpp>
#include <crutch/concept/moveable.hpp>

#include <crutch/core/core.hpp>

#include <crutch/function/detail/unique_function_base.hpp>

#include <crutch/memory/allocator.hpp>
#include <crutch/memory/default.hpp>

namespace crutch {

template <typename ReturnValue, typename... Arguments>
class UniqueFunction;

template <typename ReturnValue, typename... Arguments>
class UniqueFunction<ReturnValue(Arguments...)> final : private detail::UniqueFunctionBase<ReturnValue(Arguments...)> {
 public:
  template <typename Routine,
      typename ::std::enable_if_t<
          !::std::is_same_v<Routine, UniqueFunction<ReturnValue(Arguments...)>>, int> = 0>
  requires Copyable<Routine> || Moveable<Routine>
  explicit UniqueFunction(Routine&& closure, IAllocator* allocator = GetDefaultAllocator());

  ReturnValue operator()(Arguments... arguments);
};

}  // namespace crutch

#define UNIQUE_FUNCTION_IMPL
#include <crutch/function/unique_function.ipp>
#undef UNIQUE_FUNCTION_IMPL