#include <iostream>
#include <string>

#include "configuring.hpp"

Configuring::Configuring()
{
  std::cout << "Enter Configuring\n";
}

Configuring::~Configuring()
{
  std::cout << "Exit Configuring\n";
}

std::string Configuring::GetStateName() const
{
  return std::string("Configuring");
}
