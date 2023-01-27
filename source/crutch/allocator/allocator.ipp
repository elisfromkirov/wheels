#ifndef ALLOCATOR_IMPL
#error Do not include this file directly
#endif

namespace crutch {

template <typename Type>
typename Allocator<Type>::Pointer Allocator<Type>::Allocate(SizeType amount) noexcept {
  ASSERT(amount != 0, "amount must be greater than zero");

  auto* data = new (::std::nothrow) Uint8[sizeof(Type) * amount];
  ASSERT(data != nullptr, "new operator's error");

  return reinterpret_cast<Type*>(data);
}

template <typename Type>
void Allocator<Type>::Deallocate(Pointer pointer, SizeType amount) noexcept {
  ASSERT(pointer != nullptr, "pointer must be a valid pointer");
  ASSERT(amount != 0, "amount must be greater than zero");

  delete[] reinterpret_cast<Uint8*>(pointer);
}

template <typename Type>
template <typename... ArgTypes>
requires Constructible<Type, ArgTypes...>
void Allocator<Type>::ConstructAt(Pointer pointer, ArgTypes&&... args) {
  new (pointer) Type(::std::forward<ArgTypes>(args)...);
}

template <typename Type>
void Allocator<Type>::DestroyAt(Pointer pointer) noexcept {
  pointer->~Type();
}

}  // namespace crutch