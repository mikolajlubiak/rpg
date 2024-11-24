#pragma once

// local
#include "player.hpp"

// std
#include <cstdint>

namespace rpg
{

    class Game
    {
    public:
        Game()
        {
            setup();
        }

        void setup();
        void loop();

    private:
        std::shared_ptr<Player> m_pPlayer;
    };
}
