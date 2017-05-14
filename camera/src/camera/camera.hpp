#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <boost/statechart/state_machine.hpp>
#include <string>
#include "../event/events.hpp"

namespace sc = boost::statechart;

struct NotShooting;
struct Camera : sc::state_machine< Camera, NotShooting >
{
  Camera();
  ~Camera();

  bool IsMemoryAvailable() const;
  bool IsBatteryLow() const;

  std::string GetCurrentState() const;

  // transition actions
  void DisplayFocused(const EvInFocus &);
  void AllocateMemory(const EvShutterFull &);
  void PowerSavingMode(const EvConfig &);
};

#endif
