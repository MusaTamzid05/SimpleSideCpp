#include "app.h"
#include "input.h"
#include <iostream>

App::App() {

}


App::~App() {
    delete m_renderer;

}

void App::init() {
    m_renderer = new Renderer();
    m_renderer->init();

}

void App::start() {
    while(m_renderer->window_should_close() == false) {
        update();
        m_renderer->render();

    }

}


void App::update() {
    if(Input::get_instance()->is_mouse_cliked()) {
        Vector2 position = Input::get_instance()->get_mouse_position();
        std::cout << position.x << " " << position.y << "\n";

    }

}
