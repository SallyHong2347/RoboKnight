#pragma once

#ifdef _WIN32

#include <Windows.h>

class InputSimulation {
public:
  InputSimulation();
  ~InputSimulation();
  void simulateKeyPress(WORD key);
  void simulateKeyRelease(WORD key);
  void simulateKeyStroke(WORD key);
  void simulateMousePress(int x, int y);
  void simulateMouseRelease(int x, int y);
  void simulateMouseClickAt(int x, int y);

private:
  void sendInput(INPUT &input);
};

#endif // _WIN32