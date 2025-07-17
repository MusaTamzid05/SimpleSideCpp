#ifndef COMPONENT_H
#define COMPONENT_H

#include "renderer.h"
#include "state_machine.h"
#include <string>

struct Component {
    virtual void update() = 0;
    virtual void render(Renderer* renderer) = 0;

};

struct TextComponent : Component {
    TextComponent(int x, int y, const std::string& text="");
    virtual ~TextComponent();

    void update();
    void render(Renderer* renderer);

    std::string text;

    int x;
    int y;
    int font_size;


};

struct TextFieldComponent : Component {
    TextFieldComponent(int x, int y, int width, int height);
    virtual ~TextFieldComponent();

    void update();
    void render(Renderer* renderer);
    bool is_mouse_hover() const;
    bool is_inside(const Vector2& target) const;

    void increase(int size);
    void decrease(int size);

    void draw(Renderer* renderer, const Color& color);
    void draw_boundary(Renderer* renderer, const Color& color);

    int x;
    int y;
    int width;
    int height;

    StateMachine* state_machine;
    TextComponent* text_component;
};


#endif
