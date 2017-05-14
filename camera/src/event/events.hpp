#ifndef __EVENTS_HPP_
#define __EVENTS_HPP_

#include <boost/statechart/event.hpp>

namespace sc = boost::statechart;

struct EvConfig : sc::event< EvConfig >
{
  EvConfig();
  ~EvConfig();
};

struct EvShutterHalf : sc::event< EvShutterHalf >
{
  EvShutterHalf();
  ~EvShutterHalf();
};

struct EvShutterFull : sc::event< EvShutterFull >
{
  EvShutterFull();
  EvShutterFull(const EvShutterFull &other);
  ~EvShutterFull();
};

struct EvShutterReleased : sc::event< EvShutterReleased >
{
  EvShutterReleased();
  ~EvShutterReleased();
};

struct EvInFocus : sc::event< EvInFocus >
{
  EvInFocus();
  ~EvInFocus();
};

struct EvStored : sc::event< EvStored >
{
  EvStored();
  ~EvStored();
};

#endif
