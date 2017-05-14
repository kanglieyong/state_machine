#include <iostream>
#include "events.hpp"

EvConfig::EvConfig()
{
  std::cout << "Construct EvConfig!\n";
}

EvConfig::~EvConfig()
{
  std::cout << "Destruct EvConfig!\n";
}

EvShutterHalf::EvShutterHalf()
{
  std::cout << "Construct EvShutterHalf!\n";
}

EvShutterHalf::~EvShutterHalf()
{
  std::cout << "Destruct EvShutterHalf!\n";
}

EvShutterFull::EvShutterFull()
{
  std::cout << "Construct EvShutterFull!\n";
}

EvShutterFull::EvShutterFull(const EvShutterFull & other)
{
  std::cout << "Copy Construct EvShutterFull!\n";
}

EvShutterFull::~EvShutterFull()
{
  std::cout << "Destruct EvShutterFull!\n";
}

EvShutterReleased::EvShutterReleased()
{
  std::cout << "Construct EvShutterReleased!\n";
}

EvShutterReleased::~EvShutterReleased()
{
  std::cout << "Destruct EvShutterReleased!\n";
}

EvInFocus::EvInFocus()
{
  std::cout << "Construct EvInFocus!\n";
}

EvInFocus::~EvInFocus()
{
  std::cout << "Destruct EvInFocus!\n";
}

EvStored::EvStored()
{
  std::cout << "Construct EvStored!\n";
}

EvStored::~EvStored()
{
  std::cout << "Destruct EvStored!\n";
}

