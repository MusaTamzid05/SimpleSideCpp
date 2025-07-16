#include "state_machine.h"



StateMachine::StateMachine() {

}

StateMachine::~StateMachine() {
}



void StateMachine::change_state(State* new_state) {
    if(current_state != nullptr)
        current_state->exit();

    new_state->enter();
    current_state = new_state;

}

