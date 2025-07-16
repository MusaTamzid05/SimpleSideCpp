#include "component.h"
#include "text_component_state.h"


TextFieldComponent::TextFieldComponent(int x, int y, int width, int height):
    x(x),
    y(y),
    width(width),
    height(height) {
        state_machine = new StateMachine();
        state_machine->change_state(new TextFild::IdealState(this));

    }

TextFieldComponent::~TextFieldComponent() {

}

void TextFieldComponent::update() {
    state_machine->current_state->update();
}

void TextFieldComponent::render(Renderer* renderer) {
    state_machine->current_state->render(renderer);
}
