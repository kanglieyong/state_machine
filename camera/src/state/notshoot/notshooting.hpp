#ifndef __NOTSHOOTING_HPP__
#define __NOTSHOOTING_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>

#include "../istate.hpp"
#include "../../event/events.hpp"
#include "../../camera/camera.hpp"

namespace sc = boost::statechart;

struct Idle;
struct NotShooting : sc::simple_state< NotShooting, Camera, Idle >,
		     IState
{
  typedef sc::custom_reaction< EvShutterHalf > reactions;

  NotShooting();
  ~NotShooting();

  std::string GetStateName() const;

  sc::result react(const EvShutterHalf &);
};

#endif
