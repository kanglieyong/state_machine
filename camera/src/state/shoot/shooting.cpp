#include <iostream>
#include <string>

#include "shooting.hpp"

#include "../notshoot/notshooting.hpp"
#include "../notshoot/idle.hpp"

Shooting::Shooting()
{
  std::cout << "Enter Shooting\n";
}

Shooting::~Shooting()
{
  std::cout << "Exit Shooting\n";
}

std::string Shooting::GetStateName() const
{
  return std::string("Shooting");
}

sc::result Shooting::react(const EvShutterReleased &)
{
  std::cout << "Shooting::react(const EvShutterReleased)\n";
  return transit< NotShooting >();
}
