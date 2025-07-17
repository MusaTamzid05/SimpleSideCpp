#include "renderer.h"
#include "consts.h"
#include "page.h"
#include <raylib.h>
#include <iostream>

Renderer::Renderer():
    ready(false) {
}

Renderer::~Renderer() {
    CloseWindow();
}

void Renderer::init() {
    InitWindow(WIDTH, HEIGHT, "Window");
    SetTargetFPS(FPS);
    ready = true;
    background_color = (Color){44, 62, 80, 255};

}

bool Renderer::render_start() {
    if(!ready) {
        std::cerr << "Please init render\n";
        return false;
    }

    BeginDrawing();
        ClearBackground(background_color);

    return true;

}


void Renderer::render_end() {
    if(!ready) {
        std::cerr << "Please init render\n";
        return;
    }
    EndDrawing();

}

bool Renderer::window_should_close() const {
    return WindowShouldClose();
}


void Renderer::draw_rect(int x, int y, int width, int height) {
    DrawRectangle(x, y, width, height, LIGHTGRAY);
}

void Renderer::draw_rect_boundaries(int x, int y, int width, int height, const Color& color) {
    DrawRectangleLines(x, y, width, height, color);

}


void Renderer::draw_text(const std::string& text, int x, int y, int font_size, const Color& color) {
    DrawText(text.c_str(), x, y, font_size, color);
}
