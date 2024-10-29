// RoboKnight/src/input_simulation/input_simulation.cpp

#ifdef _WIN32

#include "include/input_simulation.h"
#include <spdlog/spdlog.h>
#include <Windows.h>

InputSimulation::InputSimulation() {
  spdlog::info("[input] InputSimulation initialized");
}

InputSimulation::~InputSimulation() {
  spdlog::info("[input] InputSimulation destroyed");
}

void InputSimulation::simulateKeyPress(WORD key) {
  spdlog::info("[input] {} key pressed", key);
  INPUT input = {0};
  input.type = INPUT_KEYBOARD;
  input.ki.wVk = key;
  sendInput(input);
}

void InputSimulation::simulateKeyRelease(WORD key) {
  spdlog::info("[input] {} key released", key);
  INPUT input = {0};
  input.type = INPUT_KEYBOARD;
  input.ki.wVk = key;
  input.ki.dwFlags = KEYEVENTF_KEYUP;
  sendInput(input);
}

void InputSimulation::simulateKeyStroke(WORD key) {
  simulateKeyPress(key);
  simulateKeyRelease(key);
}

void InputSimulation::simulateMousePress(int x, int y) {
  INPUT input = {0};
  input.type = INPUT_MOUSE;
  input.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN));
  input.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN));
  input.mi.dwFlags =
      MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN;

  HDC hdc = GetDC(NULL);
  if (hdc) {
    spdlog::warn("found hdc for mouse click");
    HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
    HGDIOBJ hOldPen = SelectObject(hdc, hPen);
    HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
    HGDIOBJ hOldBrush = SelectObject(hdc, hBrush);

    Ellipse(hdc, x - 10, y - 10, x + 10, y + 10);

    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
    DeleteObject(hBrush);
    ReleaseDC(NULL, hdc);
  }

  sendInput(input);
}

void InputSimulation::simulateMouseRelease(int x, int y) {
  INPUT input = {0};
  input.type = INPUT_MOUSE;
  input.mi.dx = x * (65536 / GetSystemMetrics(SM_CXSCREEN));
  input.mi.dy = y * (65536 / GetSystemMetrics(SM_CYSCREEN));
  input.mi.dwFlags =
      MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP;
  sendInput(input);
}

void InputSimulation::simulateMouseClickAt(int x, int y) {
  simulateMousePress(x, y);
  std::this_thread::sleep_for(
      std::chrono::milliseconds(200));
  simulateMouseRelease(x, y);
}

void InputSimulation::sendInput(INPUT &input) {
  SendInput(1, &input, sizeof(INPUT));
}

#endif // _WIN32