#pragma once

#include <wheels/core/core.hpp>

#include <wheels/string/string_view.hpp>

namespace wheels {

class SourceLocation {
 public:
  SourceLocation(const char* file, SizeType line, const char* function);

  [[nodiscard]]
  StringView File() const noexcept;

  [[nodiscard]]
  SizeType Line() const noexcept;

  [[nodiscard]]
  StringView Function() const noexcept;

 private:
  StringView file_;
  SizeType line_;
  StringView function_;
};

}  // namespace wheels

