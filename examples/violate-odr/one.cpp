#include <iostream>

#include "tinyfsm.hpp"

struct One : tinyfsm::Fsm<One>
{
  virtual void entry() {}
};

struct FirstState : One
{
  void entry() override { std::cout << "entering Firstate of One" << std::endl; }
};

FSM_INITIAL_STATE(One, FirstState);


void init_one()
{
  One::start();
}
