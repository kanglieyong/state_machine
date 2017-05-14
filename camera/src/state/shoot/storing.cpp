#include <iostream>
#include <string>

#include "storing.hpp"
#include "../notshoot/notshooting.hpp"
#include "../notshoot/idle.hpp"

Storing::Storing()
{
  std::cout << "Enter Storing\n";
}

Storing::~Storing()
{
  std::cout << "Exit Storing\n";
}

std::string Storing::GetStateName() const
{
  return std::string("Storing");
}

sc::result Storing::react(const EvStored &evStored)
{
  std::cout << "Storing::react(const EvStored &evStored)\n";
  return transit< NotShooting >();
}

sc::result Storing::react(const EvShutterReleased &evShutterReleased)
{
  std::cout << "Storing::react(const EvShutterReleased &evShutterReleased)\n";
  std::cout << "Discard EvShutterReleased\n";

  return discard_event();
}
