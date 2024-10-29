#include "include/player_action.h"
#include "spdlog/spdlog.h"

PlayerAction::PlayerAction(InputSimulation &inputSim) : inputSim(inputSim) {}

void PlayerAction::mousePress(int x, int y) {
  spdlog::info("[action] mouse press at ({}, {})", x, y);
  inputSim.simulateMousePress(x, y);
}

void PlayerAction::mouseRelease(int x, int y) {
  spdlog::info("[action] mouse release at ({}, {})", x, y);
  inputSim.simulateMouseRelease(x, y);
}

void PlayerAction::mouseClick(int x, int y) {
  spdlog::info("[action] mouse click at ({}, {})", x, y);
  inputSim.simulateMouseClickAt(x, y);
}

void PlayerAction::moveRight() {
  spdlog::info("[action] move right");
  inputSim.simulateKeyPress('D');
}

void PlayerAction::stopMoveRight() {
  spdlog::info("[action] stop move right");
  inputSim.simulateKeyRelease('D');
}

void PlayerAction::moveLeft() {
  spdlog::info("[action] move left");
  inputSim.simulateKeyPress('A');
}

void PlayerAction::stopMoveLeft() {
  spdlog::info("[action] stop move left");
  inputSim.simulateKeyRelease('A');
}

void PlayerAction::jump() {
  spdlog::info("[action] jump");
  inputSim.simulateKeyPress(VK_SPACE);
}

void PlayerAction::stopJump() {
  spdlog::info("[action] stop jump");
  inputSim.simulateKeyRelease(VK_SPACE);
}

void PlayerAction::attack() {
  spdlog::info("[action] attack");
  inputSim.simulateKeyStroke('J');
}