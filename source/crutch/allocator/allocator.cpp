#include <crutch/allocator/allocator.hpp>

namespace crutch {

Byte* Allocator::AllocateImpl(SizeType bytes, SizeType alignment) {
  ASSERT(bytes != 0, "number of bytes to allocate must be greater than zero");
  ASSERT(alignment != 0, "alignment must be greater than zero");

  Byte* pointer = static_cast<Byte*>(
      ::operator new(bytes, ::std::align_val_t(alignment), ::std::nothrow));
  ASSERT(pointer != nullptr, "operator new error");

  return pointer;
}

void Allocator::DeallocateImpl(Byte* pointer, SizeType bytes, SizeType alignment) noexcept {
  ASSERT(pointer != nullptr, "pointer must be a valid pointer");
  ASSERT(bytes != 0, "number of bytes to deallocate must be greater than zero");
  ASSERT(alignment != 0, "alignment must be greater than zero");

  ::operator delete(pointer, std::align_val_t(alignment));
}

bool Allocator::IsEqualImpl(const IAllocator* other) const noexcept {
  return this == other;
}

}  // namespace crutch