#ifndef __STATE_HPP__
#define __STATE_HPP__

#include <string>

struct IState
{
  virtual std::string GetStateName() const = 0;
};

#endif
