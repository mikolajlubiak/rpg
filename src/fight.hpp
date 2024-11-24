#pragma once

// local
#include "player.hpp"
#include "player_classes/player_classes.hpp"
#include "equipment.hpp"

// std
#include <cstdint>
#include <random>
#include <iostream>

namespace rpg
{

    class Fight
    {
    public:
        Fight(std::shared_ptr<Player> player);

        void loop();

        void hit(std::shared_ptr<Player> who, std::shared_ptr<Player> whom, std::uint64_t attack_damage, BodyPart body_part);

    private:
        std::shared_ptr<Player> m_pEnemy;
        std::shared_ptr<Player> m_pPlayer;

        std::uint64_t m_Reward;
    };
}
