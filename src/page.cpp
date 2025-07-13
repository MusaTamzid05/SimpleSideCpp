#include "page.h"
#include "input.h"
#include <iostream>

Page::Page(const std::string& title):title(title) {

}

Page::~Page() {
    for(TextFieldComponent* text_field_component : text_field_components)
        delete text_field_component;
}




void Page::update() {
    if(Input::get_instance()->is_mouse_cliked()) {
        Vector2 position = Input::get_instance()->get_mouse_position();
        std::cout << position.x << " " << position.y << "\n";
        text_field_components.push_back(new TextFieldComponent(position.x, position.y , 100, 100));

    }

}

void Page::render(Renderer* renderer) {
    for(TextFieldComponent* text_field_component : text_field_components)
        text_field_component->render(renderer);
    


}
