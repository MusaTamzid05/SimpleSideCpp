#ifndef TEXT_COMPONENT_STATE_H
#define TEXT_COMPONENT_STATE_H

#include "state_machine.h"
#include "component.h"

namespace TextFild {
    struct IdealState : State {
        IdealState(TextFieldComponent* component);
        virtual ~IdealState();

        void enter();
        void render(Renderer* renderer);
        void update();
        void exit();

        TextFieldComponent* component;

    };


    struct FocusState : State {
        FocusState(TextFieldComponent* component);
        virtual ~FocusState();

        void enter();
        void render(Renderer* renderer);
        void update();
        void exit();

        TextFieldComponent* component;

    };

    struct ResizeState : State {
        ResizeState(TextFieldComponent* component, int add_value);
        virtual ~ResizeState();

        void enter();
        void render(Renderer* renderer);
        void update();
        void exit();

        TextFieldComponent* component;
        int add_value;

    };

}


#endif
