#include "renderer.h"
#include "consts.h"
#include "page.h"
#include <raylib.h>
#include <iostream>

Renderer::Renderer():
    ready(false),
    page(nullptr) {
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

void Renderer::render() {
    if(!ready) {
        std::cerr << "Please init render\n";
        return;
    }
    BeginDrawing();
        ClearBackground(background_color);
        DrawText(page->title.c_str() , 180, 200, 20, LIGHTGRAY);
    EndDrawing();

}

bool Renderer::window_should_close() const {
    return WindowShouldClose();
}
