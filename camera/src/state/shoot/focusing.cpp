#include <iostream>
#include <string>

#include "focusing.hpp"
#include "focused.hpp"
#include "../../camera/camera.hpp"

Focusing::Focusing()
{
  std::cout << "Enter Focusing\n";
}

Focusing::~Focusing()
{
  std::cout << "Exit Focusing\n";
}

std::string Focusing::GetStateName() const
{
  return std::string("Focusing");
}

sc::result Focusing::react(const EvInFocus & evInFocus)
{
  std::cout << "Focusing::react(const EvInFocus &)\n";
  return transit< Focused >(&Camera::DisplayFocused, evInFocus);
};
