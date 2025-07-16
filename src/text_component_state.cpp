#include "text_component_state.h"

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

    }

    void FocusState::exit() {

    }
}
