#ifndef COMPONENT_H
#define COMPONENT_H

struct Component {
    virtual void update() = 0;

};

struct TextFieldComponent : Component {
    TextFieldComponent(int x, int y, int width, int height);
    virtual ~TextFieldComponent();

    void update();

    int x;
    int y;
    int width;
    int height;
};

#endif
