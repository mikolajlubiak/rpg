// header
#include "fight.hpp"

namespace rpg {
Fight::Fight(std::shared_ptr<Player> player) : m_pPlayer(player) {
  std::uint64_t enemy_strength;
  std::cout << "Choose enemy strength [Unsigned integer]: ";
  std::cin >> enemy_strength;
  m_Reward = enemy_strength;

  char input;
  std::cout << "Choose yur enemy type [f - Fighter, m - Magician]: ";
  std::cin >> input;
  switch (input) {
  case 'f':
    m_pEnemy = std::make_shared<Fighter>(enemy_strength);
    break;

  case 'm':
    m_pEnemy = std::make_shared<Magician>(enemy_strength);
    break;

  default:
    m_pEnemy = std::make_shared<Fighter>(enemy_strength);
    break;
  }
}

void Fight::hit(std::shared_ptr<Player> who, std::shared_ptr<Player> whom,
                std::uint64_t attack_damage, BodyPart body_part) {
  who->attack(whom, attack_damage, body_part);
}

void Fight::loop() {
  std::random_device rd;
  std::uniform_int_distribution<std::uint64_t> distribution(1, 100);
  std::mt19937 engine(rd());

  bool players_turn = true;

  uint64_t spell_damage = 0;
  uint64_t spell_heal = 0;

  uint64_t turn_count = 0;

  while (m_pEnemy->m_Health > 0 && m_pPlayer->m_Health > 0) {
    if (turn_count >= 5) {
      spell_damage = 0;
      spell_heal = 0;
    }

    std::cout << "Player, health:" << m_pPlayer->m_Health << '\n';
    std::cout << "Enemy, health:" << m_pEnemy->m_Health << '\n';

    if (players_turn) {
      BodyPart body_part;
      std::uint64_t chance;
      std::uint64_t attack_damage;

      char input;
      std::cout << "What do you want to do? [a - Attack, h - Heal yourself "
                   "(50%), d - Additional damage (50%)]: ";
      std::cin >> input;

      if (input == 'a') {
        std::cout << "Where do you want to hit your enemy? [b - Boots (50%), c "
                     "- Chest (90%), h - Head (20%)]: ";
        std::cin >> input;
        switch (input) {
        case 'b':
          body_part = BodyPart::BOOTS;
          chance = 50;
          attack_damage = 4;
          break;

        case 'c':
          body_part = BodyPart::CHEST;
          chance = 90;
          attack_damage = 2;
          break;

        case 'h':
          body_part = BodyPart::HEAD;
          chance = 20;
          attack_damage = 5;
          break;

        default:
          body_part = BodyPart::BOOTS;
          chance = 0;
          attack_damage = 0;
          break;
        }

        if (distribution(engine) < chance) {
          hit(m_pPlayer, m_pEnemy, attack_damage, body_part);
        }
      } else if (input == 'h') {
        if (1 <= m_pPlayer->m_Exp) {
          if (distribution(engine) < 50) {
            spell_heal = 10;

            std::cout << "Spell casted!\n";
          } else {
            std::cout << "You don't have enough luck!\n";
          }

          m_pPlayer->m_Exp -= 1;
        } else {
          std::cout << "You don't have enough exp!\n\n\n";
          continue;
        }
      } else if (input == 'd') {
        if (2 <= m_pPlayer->m_Exp) {

          if (distribution(engine) < 50) {
            spell_damage = 10;

            std::cout << "Spell casted!\n";
          } else {
            std::cout << "You don't have enough luck!\n";
          }

          m_pPlayer->m_Exp -= 2;
        } else {
          std::cout << "You don't have enough exp!\n\n\n";
          continue;
        }
      }

      m_pPlayer->m_Health += spell_heal;
      m_pEnemy->m_Health -= spell_damage;

      players_turn = false;
    } else {
      std::cout << "Enemy attacks!\n";

      if (distribution(engine) < 50) {
        std::uint64_t random = distribution(engine);

        if (random <= 33) {

          hit(m_pEnemy, m_pPlayer, 1, BodyPart::BOOTS);
        } else if (random > 33 && random <= 66) {

          hit(m_pEnemy, m_pPlayer, 1, BodyPart::CHEST);
        } else if (random > 66) {

          hit(m_pEnemy, m_pPlayer, 1, BodyPart::HEAD);
        }

        std::cout << "Enemy hit you!\n";
      } else {
        std::cout << "Enemy missed!\n";
      }

      players_turn = true;
    }

    std::cout << "\n\n";
  }

  if (m_pEnemy->m_Health <= 0) {
    std::cout << "Enemy died, you won\n";
    m_pPlayer->m_Money += m_Reward;
    m_pPlayer->m_Exp += m_Reward;
  } else {
    std::cout << "You died, enemy won\n";
  }
}
} // namespace rpg
