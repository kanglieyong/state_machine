#ifndef __IDLE_HPP__
#define __IDLE_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>

#include "../istate.hpp"
#include "../../event/events.hpp"
#include "notshooting.hpp"

namespace sc = boost::statechart;

struct Idle : sc::simple_state< Idle, NotShooting >, IState
{
  typedef sc::custom_reaction< EvConfig > reactions;

  Idle();
  ~Idle();

  std::string GetStateName() const;
  sc::result react(const EvConfig &);
};

#endif
