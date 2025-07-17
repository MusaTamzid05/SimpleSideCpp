#include "component.h"
#include "text_component_state.h"
#include "input.h"


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


bool TextFieldComponent::is_mouse_hover() const {
    int max_x = x + width;
    int max_y = y + height;

    Vector2 mouse_pos = Input::get_instance()->get_mouse_position();
    int mouse_pos_x = mouse_pos.x;
    int mouse_pos_y = mouse_pos.y;

    if((mouse_pos_x >= x) && (mouse_pos_x <= max_x)
            && (mouse_pos_y >= y) && (mouse_pos_y <= max_y))
        return true;

    return false;



}


void TextFieldComponent::increase(int size) {
    x -= size;
    width += (size * 2);
    y -= size;
    height  += (size * 2);
}

void TextFieldComponent::decrease(int size) {
    x += size;
    width -= (size * 2);
    y += size;
    height -= (size * 2);
}


void TextFieldComponent::draw(Renderer* renderer, const Color& color) {
    renderer->draw_rect(x, y, width, height);

}


void TextFieldComponent::draw_boundary(Renderer* renderer, const Color& color) {
    renderer->draw_rect_boundaries(x, y, width, height, color);

}
