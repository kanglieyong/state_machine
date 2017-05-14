#ifndef __STORING_HPP__
#define __STORING_HPP__

#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/custom_reaction.hpp>
#include <boost/statechart/deferral.hpp>
#include <boost/mpl/list.hpp>

#include <string>

#include "../../event/events.hpp"
#include "../istate.hpp"
#include "shooting.hpp"

namespace sc = boost::statechart;

struct Storing : sc::simple_state< Storing, Shooting >,
		 IState
{
  typedef boost::mpl::list<
    sc::custom_reaction< EvStored >,
    sc::custom_reaction< EvShutterReleased >
  > reactions;

  Storing();
  ~Storing();

  std::string GetStateName() const;
  sc::result react(const EvStored &);
  sc::result react(const EvShutterReleased &);
};

#endif
