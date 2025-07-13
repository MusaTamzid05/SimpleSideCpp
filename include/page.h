#ifndef PAGE_H
#define PAGE_H

#include "component.h"
#include "renderer.h"
#include <string>
#include <vector>

struct Page : Component {
    Page(const std::string& title);
    virtual ~Page();
    void update();
    void render(Renderer* renderer);

    std::string title;
    std::vector<TextFieldComponent*> text_field_components;

};


#endif
