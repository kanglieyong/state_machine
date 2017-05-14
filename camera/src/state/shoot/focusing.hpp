#ifndef __FOCUSING_HPP__
#define __FOCUSING_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/mpl/list.hpp>
#include <boost/statechart/deferral.hpp>

#include <string>

#include "../../event/events.hpp"
#include "../istate.hpp"

#include "shooting.hpp"

namespace sc = boost::statechart;

struct Focusing : sc::simple_state< Focusing, Shooting >,
		  IState
{
  typedef boost::mpl::list<
    sc::custom_reaction< EvInFocus >,
    sc::deferral< EvShutterFull >
  > reactions;

  Focusing();
  ~Focusing();

  std::string GetStateName() const;
  sc::result react(const EvInFocus &);
};

#endif
