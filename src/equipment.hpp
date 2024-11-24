#pragma once

// std
#include <cstdint>

namespace rpg {

enum BodyPart : std::uint64_t {
  BOOTS,
  CHEST,
  HEAD,
};

class Equipment {
public:
  Equipment() = default;
  Equipment(std::uint64_t protection) : m_Protection(protection) {}
  std::uint64_t m_Protection = 1;
};

} // namespace rpg
