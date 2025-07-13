#ifndef COMPONENT_H
#define COMPONENT_H

#include "renderer.h"

struct Component {
    virtual void update() = 0;
    virtual void render(Renderer* renderer) = 0;

};

struct TextFieldComponent : Component {
    TextFieldComponent(int x, int y, int width, int height);
    virtual ~TextFieldComponent();

    void update();
    void render(Renderer* renderer);

    int x;
    int y;
    int width;
    int height;
};

#endif
