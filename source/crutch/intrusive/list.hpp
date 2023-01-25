#pragma once

#include <crutch/intrusive/node.hpp>

namespace crutch {

template <typename Type>
class IntrusiveList {
 public:
  [[nodiscard]]
  IntrusiveNode<Type>* Head() noexcept;

  [[nodiscard]]
  IntrusiveNode<Type>* Tail() noexcept;

  [[nodiscard]]
  bool IsEmpty() const noexcept;

  void Insert(IntrusiveNode<Type>* node) noexcept;

 private:
  IntrusiveNode<Type> node_;
};

}  // namespace crutch

#define LIST_IMPL
#include <crutch/intrusive/list.ipp>
#undef LIST_IMPL