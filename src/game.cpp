// header
#include "game.hpp"

// local
#include "fight.hpp"
#include "player_classes/player_classes.hpp"
#include "shop.hpp"

// std
#include <iostream>

namespace rpg {
void Game::setup() {
  char input;
  std::cout << "Choose yoour fighter [f - Fighter, m - Magician]: ";
  std::cin >> input;
  switch (input) {
  case 'f':
    m_pPlayer = std::make_shared<Fighter>();
    break;

  case 'm':
    m_pPlayer = std::make_shared<Magician>();
    break;

  default:
    m_pPlayer = std::make_shared<Fighter>();
    break;
  }
}

void Game::loop() {
  while (m_pPlayer->m_Health > 0) {
    char input;
    std::cout << "What do you want to do? [f - Fight, s - Shop]: ";
    std::cin >> input;
    if (input == 'f') {
      Fight fight(m_pPlayer);
      fight.loop();
    } else if (input == 's') {
      Shop shop(m_pPlayer);
      shop.loop();
    }
  }
}
} // namespace rpg
