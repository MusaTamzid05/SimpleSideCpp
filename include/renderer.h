#ifndef RENDERER_H
#define RENDERER_H

#include <raylib.h>
#include <string>


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
    void draw_rect_boundaries(int x, int y, int width, int height, const Color& color);
    void draw_text(const std::string& text, int x, int y, int font_size, const Color& color);

    Color background_color;
};

#endif
