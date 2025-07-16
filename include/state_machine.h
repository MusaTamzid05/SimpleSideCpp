#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "renderer.h"

struct State {
    virtual void enter() = 0;
    virtual void render(Renderer* renderer) = 0;
    virtual void update() = 0;
    virtual void exit() = 0;

};

struct StateMachine {
    StateMachine();
    virtual ~StateMachine();

    void change_state(State* new_state);

    State* current_state;


};


#endif

