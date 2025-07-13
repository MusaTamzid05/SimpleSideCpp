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
    Page* page = pages[current_page_index];

    for(TextFieldComponent* text_field_component : page->text_field_components) {
        int x = text_field_component->x;
        int y = text_field_component->y;
        int width  = text_field_component->width;
        int height = text_field_component->height;
        m_renderer->draw_rect(x, y, height, width);
    }


    m_renderer->render_end();

}
