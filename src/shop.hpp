#pragma once

// local
#include "equipment.hpp"
#include "player.hpp"

// std
#include <cstdint>
#include <vector>
#include <iostream>
#include <memory>

namespace rpg
{
    typedef std::uint64_t cost;

    class Shop
    {
    public:
        Shop(std::shared_ptr<Player> player) : m_pPlayer(player) {}

        void loop();

    private:
        std::shared_ptr<Player> m_pPlayer;
    };

}
