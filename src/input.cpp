#include "input.h"

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
