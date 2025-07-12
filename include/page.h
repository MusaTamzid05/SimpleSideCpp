#ifndef PAGE_H
#define PAGE_H

#include "component.h"
#include "renderer.h"
#include <string>

struct Page : Component {
    Page(const std::string& title);
    virtual ~Page();
    void update();

    std::string title;

};


#endif
