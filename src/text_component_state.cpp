#include "text_component_state.h"
#include <iostream>

namespace TextFild {
    IdealState::IdealState(TextFieldComponent* component):component(component) {

    }

    IdealState::~IdealState() {

    }

    void IdealState::enter() {

    }

    void IdealState::render(Renderer* renderer) {
        int x = component->x;
        int y = component->y;
        int width  = component->width;
        int height = component->height;

        renderer->draw_rect(x, y, width, height);
    }

    void IdealState::update() {
        if(component->is_mouse_hover())
            component->state_machine->change_state(new FocusState(component));
    }

    void IdealState::exit() {

    }

    FocusState::FocusState(TextFieldComponent* component):component(component) {

    }

    FocusState::~FocusState() {

    }

    void FocusState::enter() {

    }

    void FocusState::render(Renderer* renderer) {
        int x = component->x;
        int y = component->y;
        int width  = component->width;
        int height = component->height;

        renderer->draw_rect(x, y, width, height);
        renderer->draw_rect_boundaries(x, y, width, height);

    }

    void FocusState::update() {
        if(component->is_mouse_hover() == false)
            component->state_machine->change_state(new IdealState(component));

    }

    void FocusState::exit() {

    }
}
