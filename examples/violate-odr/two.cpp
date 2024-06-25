#include <iostream>

#include "tinyfsm.hpp"

struct Two : tinyfsm::Fsm<Two>
{
  virtual void entry() {}
};

struct FirstState : Two
{
  void entry() override { std::cout << "entering Firstate of Two" << std::endl; }
};

FSM_INITIAL_STATE(Two, FirstState);


void init_two()
{
  Two::start();
}
