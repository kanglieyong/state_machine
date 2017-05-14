#ifndef __SHOOTING_HPP__
#define __SHOOTING_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/transition.hpp>

#include <string>

#include "../istate.hpp"
#include "../../event/events.hpp"
#include "../../camera/camera.hpp"

namespace sc = boost::statechart;

struct Focusing;
struct Shooting : sc::simple_state< Shooting, Camera, Focusing >,
		  IState
{
  typedef sc::custom_reaction< EvShutterReleased > reactions;

  Shooting();
  ~Shooting();

  std::string GetStateName() const;

  sc::result react(const EvShutterReleased &);
};

#endif
