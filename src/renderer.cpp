#include "renderer.h"
#include "consts.h"
#include <raylib.h>
#include <iostream>

Renderer::Renderer():ready(false) {
}

Renderer::~Renderer() {
    CloseWindow();
}

void Renderer::init() {
    InitWindow(WIDTH, HEIGHT, "Window");
    SetTargetFPS(FPS);
    ready = true;

}

void Renderer::render() {
    if(!ready) {
        std::cerr << "Please init render\n";
        return;
    }
    BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("This is a test" , 180, 200, 20, LIGHTGRAY);
    EndDrawing();

}

bool Renderer::window_should_close() const {
    return WindowShouldClose();
}
