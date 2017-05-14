#ifndef __CONFIGURING_HPP__
#define __CONFIGURING_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>

#include <string>

#include "../../event/events.hpp"
#include "../istate.hpp"

#include "notshooting.hpp"
#include "idle.hpp"

namespace sc = boost::statechart;

struct Configuring : sc::simple_state< Configuring, NotShooting >,
		     IState
{
  typedef sc::transition<
    EvConfig,
    Idle,
    Camera,
    &Camera::PowerSavingMode
  > reactions;

  Configuring();
  ~Configuring();

  std::string GetStateName() const;
};

#endif
