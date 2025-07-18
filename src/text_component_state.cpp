#include "text_component_state.h"
#include <iostream>
#include "input.h"

namespace TextFild {
    IdealState::IdealState(TextFieldComponent* component):text_field_component(component) {

    }

    IdealState::~IdealState() {

    }

    void IdealState::enter() {

    }

    void IdealState::render(Renderer* renderer) {
        text_field_component->draw(renderer, RAYWHITE);
    }

    void IdealState::update() {
        if(text_field_component->is_mouse_hover())
            text_field_component->state_machine->change_state(new FocusState(text_field_component));
    }

    void IdealState::exit() {

    }

    FocusState::FocusState(TextFieldComponent* component):text_field_component(component) {

    }

    FocusState::~FocusState() {

    }

    void FocusState::enter() {

    }

    void FocusState::render(Renderer* renderer) {
        text_field_component->draw(renderer, RAYWHITE);
        text_field_component->draw_boundary(renderer, RED);

    }

    void FocusState::update() {
        if(text_field_component->is_mouse_hover() == false)
            text_field_component->state_machine->change_state(new IdealState(text_field_component));

        if(Input::get_instance()->resize_press())
            text_field_component->state_machine->change_state(new ResizeState(text_field_component, 10));

        else if(Input::get_instance()->edit_press()) 
            text_field_component->state_machine->change_state(new EditTextState(text_field_component));


    }

    void FocusState::exit() {

    }


    ResizeState::ResizeState(TextFieldComponent* component, int add_value):text_field_component(component), add_value(add_value) {

    }

    ResizeState::~ResizeState() {

    }

    void ResizeState::enter() {

    }

    void ResizeState::render(Renderer* renderer) {
        text_field_component->draw(renderer, RAYWHITE);
        text_field_component->draw_boundary(renderer, YELLOW);
    }

    void ResizeState::update() {
        if(Input::get_instance()->resize_press())
            text_field_component->state_machine->change_state(new IdealState(text_field_component));

        if(Input::get_instance()->add_press()) 
            text_field_component->increase(add_value);

        else if(Input::get_instance()->reduce_press()) 
            text_field_component->decrease(add_value);

        

    }

    void ResizeState::exit() {

    }

    EditTextState::EditTextState(TextFieldComponent* component):
        text_field_component(component) {

        }

    EditTextState::~EditTextState() {

    }

    void EditTextState::enter() {

    }

    void EditTextState::render(Renderer* renderer) {
        text_field_component->draw(renderer, RAYWHITE);
        text_field_component->draw_boundary(renderer, BLUE);
    }

    void EditTextState::update() {
        std::string input = Input::get_instance()->get_input_as_string();

        if(input == "")
            return;


        TextComponent* text_component = text_field_component->text_component;

        if(input == Input::get_instance()->BACKSPACE) {
            if(text_component->text.size())
                text_component->text.pop_back();
            return;
        }

        text_component->text += input;


    }

    void EditTextState::exit() {

    }
}





















