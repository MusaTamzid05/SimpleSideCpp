#ifndef COMPONENT_H
#define COMPONENT_H

#include "renderer.h"
#include "state_machine.h"
#include <string>
#include <vector>

struct Component {
    virtual void update() = 0;
    virtual void render(Renderer* renderer) = 0;

};

struct TextFieldComponent;

struct TextComponent : Component {
    TextComponent(TextFieldComponent* parent, const std::string& text="");
    virtual ~TextComponent();

    void update();
    void render(Renderer* renderer);

    std::string text;

    // we cannot directly render text on screen
    // bacause we need add line break when we
    // reach the parent width, this func
    // breaks the line when we hit the parent
    // width

    TextFieldComponent* parent;
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
