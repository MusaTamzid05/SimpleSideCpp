#include "page.h"
#include "input.h"
#include "consts.h"
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
        bool already_component_exists = false;

        for(TextFieldComponent* text_field_component : text_field_components) {
            if(text_field_component->is_inside(position)) {
                already_component_exists = true;
                break;
            }

        }

        if(already_component_exists)
            return;

        text_field_components.push_back(new TextFieldComponent(
                    position.x,
                    position.y,
                    TEXT_COMPONENT_DEFAULT_SIZE ,
                    TEXT_COMPONENT_DEFAULT_SIZE));

    }

    for(TextFieldComponent* text_field_component : text_field_components)
        text_field_component->update();
}

void Page::render(Renderer* renderer) {
    for(TextFieldComponent* text_field_component : text_field_components)
        text_field_component->render(renderer);
    


}
