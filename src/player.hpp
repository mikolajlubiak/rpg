#pragma once

// local
#include "equipment.hpp"

// std
#include <cstdint>
#include <unordered_map>
#include <memory>

namespace rpg
{

    class Player
    {
    public:
        virtual ~Player() = default;

        virtual void attack(std::shared_ptr<Player> enemy, std::uint64_t attack_damage, BodyPart body_part)
        {
            enemy->m_Health -= this->m_Strength * attack_damage - enemy->m_Equipment[body_part].m_Protection * enemy->m_Defense;
        }

        std::uint64_t m_Strength;
        std::uint64_t m_Defense;
        std::uint64_t m_Exp;
        std::int64_t m_Health;
        std::uint64_t m_Money;
        std::unordered_map<BodyPart, Equipment> m_Equipment{};
    };

}
