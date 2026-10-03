#pragma once

#include <cstddef>

namespace floyd {
namespace detail {
inline constexpr std::size_t Hare_Step{2};
inline constexpr std::size_t Turtle_Step{1};

template<typename T>
const T* get_nth_nbor(const T* node, std::size_t n) {
  const T* ptr = node;
  for (std::size_t i{0}; i < n; ++i) {
    if (ptr == nullptr) return nullptr;
    ptr = ptr->nbor;
  }

  return ptr;
}
} /* detail */

template<typename T>
[[nodiscard]] bool is_sequence_looping(const T* head) {
  auto hare = head;
  auto turtle = head;

  while (hare != nullptr) {
    hare = detail::get_nth_nbor(hare, detail::Hare_Step);
    turtle = detail::get_nth_nbor(turtle, detail::Turtle_Step);
    if (hare == nullptr) return false;

    if (hare == turtle) return true;
  }
  return false;
}
} /* floyd */
