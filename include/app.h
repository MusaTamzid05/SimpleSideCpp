#ifndef APP_H
#define APP_H

#include "renderer.h"
#include <vector>
#include "page.h"

struct App {
    App();
    virtual ~App();

    void init();
    void start();

    void update();
    void render();

    Renderer* m_renderer;
    std::vector<Page*> pages;
    int current_page_index;

};


#endif
