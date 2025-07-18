#include "utils.h"
#include <raylib.h>

namespace utils {
    int get_render_text_size(const std::string& str, int font_size) {
        return MeasureText(str.c_str(), font_size);
    }
}
