#include "app.h"
#include <iostream>

App::App():current_page_index(0) {

}


App::~App() {
    for(Page* page : pages)
        delete page;

    delete m_renderer;

}

void App::init() {
    m_renderer = new Renderer();
    m_renderer->init();
    pages.push_back(new Page("This is pages"));

}

void App::start() {
    while(m_renderer->window_should_close() == false) {
        update();
        render();

    }

}


void App::update() {
    pages[current_page_index]->update();

}

void App::render() {
    m_renderer->render_start();
    pages[current_page_index]->render(m_renderer);


    m_renderer->render_end();

}
