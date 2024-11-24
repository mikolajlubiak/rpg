#pragma once

// local
#include "../player.hpp"

// std
#include <cstdint>

namespace rpg
{

    class Magician : public Player
    {
    public:
        Magician()
        {
            m_Strength = 5;
            m_Defense = 3;
            m_Exp = 5;
            m_Health = 100;
        }

        Magician(std::uint64_t strength)
        {
            m_Strength = 5 * strength;
            m_Defense = 5 * strength;
            m_Exp = strength;
            m_Health = 100 * strength;
        }
    };

}
