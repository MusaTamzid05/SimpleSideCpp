#include "app.h"
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
        m_renderer->render();

    }

}
