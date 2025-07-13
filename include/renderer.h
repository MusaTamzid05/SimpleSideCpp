#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>


struct Page;

struct Renderer {
    Renderer();
    virtual ~Renderer();

    bool window_should_close() const;
    bool ready;

    void init();
    bool render_start();
    void render_end();

    void draw_rect(int x, int y, int width, int height);

    Color background_color;
};

#endif
