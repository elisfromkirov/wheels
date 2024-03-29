#include <wheels/test/assertion_failure.hpp>

namespace wheels {

AssertionFailure::AssertionFailure(const char* expression, SourceLocation location)
    : expression_{expression},
      location_{location} {
}

StringView AssertionFailure::Expression() const noexcept {
  return expression_;
}

const SourceLocation& AssertionFailure::Location() const noexcept {
  return location_;
}

}  // namespace wheels