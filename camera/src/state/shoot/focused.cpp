#include <iostream>
#include <string>

#include "focused.hpp"
#include "storing.hpp"

#include "../../camera/camera.hpp"

Focused::Focused()
{
  std::cout << "Enter Focused\n";
}

Focused::~Focused()
{
  std::cout << "Exit Focused\n";
}

std::string Focused::GetStateName() const
{
  return std::string("Focused");
}

sc::result Focused::react(const EvShutterFull & evShutterFull)
{
  std::cout << "Focused::react(const EvShutterFull &evShutterFull), ";
  if (context< Camera >().IsMemoryAvailable()) {
    std::cout << "Guard: IsMemoryAvailable() is true\n";
    return transit< Storing >(&Camera::AllocateMemory, evShutterFull);
  } else {
    std::cout << "Guard: IsMemoryAvailable() is false\n";
    return discard_event();
  }
  
}
