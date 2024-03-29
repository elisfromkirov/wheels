#pragma once

namespace wheels {

namespace detail {

template <typename ReturnValue, typename... Arguments>
class IInvokable;

template <typename ReturnValue, typename... Arguments>
class IInvokable<ReturnValue (Arguments...)> {
 public:
  virtual ~IInvokable() noexcept = default;

  virtual ReturnValue Invoke(Arguments... arguments) = 0;
};

}  // namespace detail

}  // namespace wheels