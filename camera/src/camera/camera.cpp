#include <iostream>
#include <string>
#include "camera.hpp"
#include "../state/istate.hpp"

#include "../state/notshoot/notshooting.hpp"
#include "../state/notshoot/idle.hpp"
#include "../state/shoot/shooting.hpp"

Camera::Camera()
{
  std::cout << "Construct Camera\n";
}

Camera::~Camera()
{
  std::cout << "Destruct Camera\n";
}

bool Camera::IsMemoryAvailable() const
{
  return true;
}

bool Camera::IsBatteryLow() const
{
  return false;
}

std::string Camera::GetCurrentState() const
{
  return std::string("CurrentState----> ") + state_cast< const IState & >().GetStateName();
}

void Camera::DisplayFocused(const EvInFocus &)
{
  std::cout << "[Transition Action]: Camera focused on objects\n";
}

void Camera::AllocateMemory(const EvShutterFull &)
{
  std::cout << "[Transition Action]: Camera goes into Power Saving Mode\n";
}

void Camera::PowerSavingMode(const EvConfig &)
{
  std::cout << "[Transition Action]: Camera goes nto Power Saving Mode\n";
}

int main()
{
  Camera myCamera;

  myCamera.initiate(); 
  std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvConfig());
  std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvConfig());
  std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvShutterHalf());
  std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvShutterFull());
  std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvInFocus());
  std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvShutterReleased());
   std::cout << myCamera.GetCurrentState() << "\n";

  myCamera.process_event(EvStored());
  std::cout << myCamera.GetCurrentState() << "\n";

  return 0;
}
