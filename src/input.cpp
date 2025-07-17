#include "input.h"
#include <iostream>

Input* Input::m_instance = nullptr;

Input::Input() {

}


Input::~Input() {

}


Vector2 Input::get_mouse_position() const {
    return GetMousePosition();
}


Input* Input::get_instance() {
    if(m_instance == nullptr)
        m_instance = new Input();

    return m_instance;


}



bool Input::is_mouse_cliked() const {
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}


bool Input::resize_press() const {
    return IsKeyPressed(KEY_R);
}

bool Input::add_press() const {
    return IsKeyPressed(KEY_A);
}

bool Input::edit_press() const {
    return IsKeyPressed(KEY_E);
}

bool Input::reduce_press() const {
    return IsKeyPressed(KEY_D);
}

std::string Input::get_input_as_string() const {
    int key = GetKeyPressed();

    if(key == 0)
        return "";

    if(key == KEY_BACKSPACE) 
        return BACKSPACE;
    
    if((key >= 32) && (key <= 125)) {

        char key_char = (char) key;
        return std::string(1, key_char);
    }

    return "";
}
