#include "configuring.hpp"
#include "idle.hpp"

#include <iostream>
#include <string>

Idle::Idle()
{
  std::cout << "Enter Idle\n";
}

Idle::~Idle()
{
  std::cout << "Exit Idle\n";
}

std::string Idle::GetStateName() const
{
  return std::string("Idle");
}

sc::result Idle::react(const EvConfig &)
{
  std::cout << "Idle::react(const EvConfig &)\n";

  return transit< Configuring>();
}
