#pragma once

// local
#include "../player.hpp"

// std
#include <cstdint>

namespace rpg
{

    class Fighter : public Player
    {
    public:
        Fighter()
        {
            m_Strength = 10;
            m_Defense = 1;
            m_Exp = 1;
            m_Health = 100;
        }

        Fighter(std::uint64_t strength)
        {
            m_Strength = 10 * strength;
            m_Defense = 10 * strength;
            m_Exp = strength;
            m_Health = 100 * strength;
        }
    };

}
