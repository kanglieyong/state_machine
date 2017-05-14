#include <iostream>
#include <string>

#include "notshooting.hpp"
#include "../shoot/shooting.hpp"
#include "../shoot/focusing.hpp"

NotShooting::NotShooting()
{
  std::cout << "Enter NotShooting\n";
}

NotShooting::~NotShooting()
{
  std::cout << "Exit NotShooting\n";
}

std::string NotShooting::GetStateName() const
{
  return std::string("NotShooting");
}

sc::result NotShooting::react(const EvShutterHalf &)
{
  std::cout << "NotShooting::react(const EvShutterHalf &), ";
  if ( context< Camera >().IsBatteryLow() ) {
    std::cout << "Guard: IsBatteryLow() is true\n";
    return forward_event();
  } else {
    std::cout << "Guard: IsBatteryLow() is false\n";
    return transit< Shooting >();
  }
}
