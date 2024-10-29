#pragma once

#include "input_simulation.h"

class PlayerAction {
public:
  PlayerAction(InputSimulation &inputSim);

  void mousePress(int x, int y);
  void mouseRelease(int x, int y);
  void mouseClick(int x, int y);
  void moveRight();
  void stopMoveRight();
  void moveLeft();
  void stopMoveLeft();
  void jump();
  void stopJump();
  void attack();

private:
  InputSimulation &inputSim;
};