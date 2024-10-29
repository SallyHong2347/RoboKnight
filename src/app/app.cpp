#include "../input_simulation/include/input_simulation.h"
#include "../input_simulation/include/player_action.h"
#include "../logger/include/logger.h"
#include <chrono>
#include <iostream>
#include <string>
#include <thread>


int main() {
    setupLogger();
  std::string userResponse;
  do {
    std::cout << "new hellow world" << std::endl;
    std::cin.get();

    InputSimulation inputSim = InputSimulation::InputSimulation();
    PlayerAction playerAction(inputSim);

    // assume the game start in pause mode
    // click in the game screen
    inputSim.simulateMouseClickAt(100, 100);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    inputSim.simulateKeyStroke(VK_SPACE);
    std::this_thread::sleep_for(std::chrono::milliseconds(400));

    // player actions
    playerAction.moveRight();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    playerAction.stopMoveRight();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.moveLeft();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    playerAction.stopMoveLeft();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.jump();
    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    playerAction.stopJump();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.moveRight();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    playerAction.stopMoveRight();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.moveLeft();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    playerAction.stopMoveLeft();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.jump();
    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    playerAction.attack();
    playerAction.stopJump();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    playerAction.attack();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    inputSim.simulateKeyStroke(VK_ESCAPE);

    std::cout << "actions complete" << std::endl;
    std::cout << "Do you want to repeat the actions? (yes/no): ";
    std::cin >> userResponse;
  } while (userResponse == "yes");

  return 0;
}