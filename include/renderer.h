#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>

struct Renderer {
    Renderer();
    virtual ~Renderer();

    bool window_should_close() const;
    bool ready;

    void init();
    void render();

    Color background_color;
};

#endif
