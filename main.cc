#include <print>
#include <vector>
#include <cstddef>
#include "floyd.hpp"

struct Node {
  std::size_t id{};
  Node* nbor{};
};

[[nodiscard]] std::vector<Node> spawn_looping_sequence(std::size_t size) {
  std::vector<Node> nodes(size);
  for (std::size_t i{0}; i < size; ++i) {
    nodes[i].id = i;
    nodes[i].nbor = &nodes[(i + 1) % size];
  }
  return nodes;
}

auto main() -> int {
  std::println("INFO: testing floyd's cycle detection algorithm on a sequence that is");
  auto nodes = spawn_looping_sequence(69'696'000);
  std::println("      looping:     {}", floyd::is_sequence_looping(nodes.data()));

  nodes.back().nbor = nullptr;
  std::println("      non looping: {}", floyd::is_sequence_looping(nodes.data()));

  return 0;
}
