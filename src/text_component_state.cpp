#include "text_component_state.h"
#include <iostream>
#include "input.h"

namespace TextFild {
    IdealState::IdealState(TextFieldComponent* component):component(component) {

    }

    IdealState::~IdealState() {

    }

    void IdealState::enter() {

    }

    void IdealState::render(Renderer* renderer) {
        component->draw(renderer, RAYWHITE);
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
        component->draw(renderer, RAYWHITE);
        component->draw_boundary(renderer, RED);

    }

    void FocusState::update() {
        if(component->is_mouse_hover() == false)
            component->state_machine->change_state(new IdealState(component));

        if(Input::get_instance()->resize_press())
            component->state_machine->change_state(new ResizeState(component, 10));

        else if(Input::get_instance()->edit_press()) 
            component->state_machine->change_state(new EditTextState(component));


    }

    void FocusState::exit() {

    }


    ResizeState::ResizeState(TextFieldComponent* component, int add_value):component(component), add_value(add_value) {

    }

    ResizeState::~ResizeState() {

    }

    void ResizeState::enter() {

    }

    void ResizeState::render(Renderer* renderer) {
        component->draw(renderer, RAYWHITE);
        component->draw_boundary(renderer, YELLOW);
    }

    void ResizeState::update() {
        if(Input::get_instance()->resize_press())
            component->state_machine->change_state(new IdealState(component));

        if(Input::get_instance()->add_press()) 
            component->increase(add_value);

        else if(Input::get_instance()->reduce_press()) 
            component->decrease(add_value);

        

    }

    void ResizeState::exit() {

    }

    EditTextState::EditTextState(TextFieldComponent* component):
        component(component) {

        }

    EditTextState::~EditTextState() {

    }

    void EditTextState::enter() {

    }

    void EditTextState::render(Renderer* renderer) {
        component->draw(renderer, RAYWHITE);
        component->draw_boundary(renderer, BLUE);
    }

    void EditTextState::update() {
        std::string input = Input::get_instance()->get_input_as_string();

        if(input == "")
            return;


        TextComponent* text_component = component->text_component;

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





















