#ifndef APP_H
#define APP_H

#include "renderer.h"

struct App  {
    App();
    virtual ~App();

    void init();
    void start();
    Renderer* m_renderer;

};


#endif
