#include <crutch/core/utility/source_location.hpp>

namespace crutch {

SourceLocation::SourceLocation(const char* file, SizeType line, const char* function)
    : file_{file},
      line_{line},
      function_{function} {
}

const char* SourceLocation::File() const noexcept {
  return file_;
}

SizeType SourceLocation::Line() const noexcept {
  return line_;
}

const char* SourceLocation::Function() const noexcept {
  return function_;
}

}  // namespace crutch