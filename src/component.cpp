#include "component.h"
#include "text_component_state.h"
#include "input.h"
#include "consts.h"
#include "utils.h"
#include <iostream>


TextFieldComponent::TextFieldComponent(int x, int y, int width, int height):
    x(x),
    y(y),
    width(width),
    height(height) {

        text_component = new TextComponent(this, "");
        state_machine = new StateMachine();
        state_machine->change_state(new TextFild::IdealState(this));

    }

TextFieldComponent::~TextFieldComponent() {
    delete text_component;
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
    if((height  <= TEXT_COMPONENT_MIN_SIZE) || (width <+ TEXT_COMPONENT_MIN_SIZE))
        return;

    x += size;
    width -= (size * 2);
    y += size;
    height -= (size * 2);
}


void TextFieldComponent::draw(Renderer* renderer, const Color& color) {
    renderer->draw_rect(x, y, width, height);
    text_component->render(renderer);

}


void TextFieldComponent::draw_boundary(Renderer* renderer, const Color& color) {
    renderer->draw_rect_boundaries(x, y, width, height, color);

}

bool TextFieldComponent::is_inside(const Vector2& target) const {
    int pos_x = target.x;
    int pos_y = target.y;

    int max_x = x + width;
    int max_y = y + height;

    if((pos_x >= x) && (pos_x <= max_x)
            && (pos_y >= y) && (pos_y <= max_y))
        return true;

    return false;
}

TextComponent::TextComponent(TextFieldComponent* parent, const std::string& text):
    text(text), 
    parent(parent),
    font_size(FONT_SIZE) {

}


TextComponent::~TextComponent() {

}

void TextComponent::update() {

}
void TextComponent::render(Renderer* renderer) {

    std::vector<std::string> texts;
    std::string line = "";
    int parent_width = parent->width;

    for(char current_char : text)  {
        line += current_char;

        if(utils::get_render_text_size(line, font_size) >= parent_width ) {
            line.pop_back();
            texts.push_back(line);

            line = "";
            line += current_char;
        }
    }

    texts.push_back(line);
    int y_axis_offset = 0;
    const int MAX_Y_LINE_OFFSET = 20;

    for(const std::string line : texts) {
        renderer->draw_text(line,
                parent->x + TEXT_OFFSET,
                parent->y + TEXT_OFFSET + y_axis_offset,
                font_size, BLACK);

        y_axis_offset += MAX_Y_LINE_OFFSET;

    }
}





