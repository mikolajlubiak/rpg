// header
#include "shop.hpp"

namespace rpg
{
    void Shop::loop()
    {
        char input = 0;
        while (input != 'q')
        {
            BodyPart body_part;
            std::uint64_t armor_strength;
            std::cout << "What body part armor do you want to buy? [b - Boots, c - Chest, h - Head, q - Quit]: ";
            std::cin >> input;
            switch (input)
            {
            case 'b':
                body_part = BodyPart::BOOTS;
                break;

            case 'c':
                body_part = BodyPart::CHEST;
                break;

            case 'h':
                body_part = BodyPart::HEAD;
                break;

            default:
                break;
            }

            if (input != 'q')
            {
                std::cout << "Choose armor strength [Unsigned integer]: ";
                std::cin >> armor_strength;

                if (armor_strength <= m_pPlayer->m_Money)
                {
                    m_pPlayer->m_Equipment[body_part] = Equipment(armor_strength);
                    m_pPlayer->m_Money -= armor_strength;
                    std::cout << "Ordered!\n";
                }
                else
                {
                    std::cout << "You don't have enough money!\n";
                }
            }
        }
    }

}