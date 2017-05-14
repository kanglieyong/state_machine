#ifndef __FOCUSED_HPP__
#define __FOCUSED_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>

#include "../../event/events.hpp"
#include "../istate.hpp"

#include "shooting.hpp"

namespace sc = boost::statechart;

struct Focused : sc::simple_state< Focused, Shooting >,
		 IState
{
  typedef sc::custom_reaction< EvShutterFull > reactions;

  Focused();
  ~Focused();

  std::string GetStateName() const;
  sc::result react(const EvShutterFull &);
};

#endif
