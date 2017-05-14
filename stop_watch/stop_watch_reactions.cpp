#include <boost/statechart/event.hpp>
#include <boost/statechart/state_machine.hpp>
#include <boost/statechart/simple_state.hpp>
#include <boost/statechart/transition.hpp>
#include <iostream>

namespace sc = boost::statechart;

struct EvStartStop : sc::event<EvStartStop> {};
struct EvReset     : sc::event<EvReset> {};

struct Active;
struct StopWatch : sc::state_machine<StopWatch, Active> {};

struct Stopped;

// the simple_state class template accepts up to four parameters:
// - The third parameter specifies the inner initial state, if
//   there is one. Here, only Active has inner states, which is
//   why it needs to pass its inner initial state Stopped to its
//   base
// - The fourth parameter specifies whether and what kind of
//   history is kept

// Active is the outermost state and therefore needs to pass the
// state machine class it belongs to
struct Active : sc::simple_state<Active, StopWatch, Stopped>
{
  typedef sc::transition<EvReset, Active> reactions;
};

// Stopped and Running both specify Active as their Context,
// which makes them nested inside Active
struct Running : sc::simple_state<Running, Active>
{
  typedef sc::transition<EvStartStop, Stopped> reactions;

  Running() { std::cout << "Running!\n"; }
  ~Running() { std::cout << "~Running!\n"; }
};

struct Stopped : sc::simple_state<Stopped, Active>
{
  typedef sc::transition<EvStartStop, Running> reactions;

  Stopped() { std::cout << "Stopped!\n"; }
  ~Stopped() { std::cout << "~Stopped!\n"; }
};

// A state can define an arbitrary number of reactions. That's
// why we have to put them input an mpl::list<> as soon as there
// is more than one of them

// Because the context of a state must be a complete type (i.e.
// not forward decalred), a machine must be defined from
// "outside to inside". That is, we always start with the state
// machine, followed by outermost states, followed by the direct
// inner states of outermost states and so on. We can do so in a
// breadth-first or depth-first way or employ a mixture of the
// two.

int main()
{
  StopWatch myWatch;
  myWatch.initiate();
  myWatch.process_event(EvStartStop());
  myWatch.process_event(EvStartStop());
  myWatch.process_event(EvStartStop());
  myWatch.process_event(EvReset());

  return 0;
}
   
