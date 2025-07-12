#ifndef RENDERER_H
#define RENDERER_H

struct Renderer {
    Renderer();
    virtual ~Renderer();

    bool window_should_close() const;
    bool ready;

    void init();
    void render();
};

#endif
