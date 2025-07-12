#ifndef INPUT_H
#define INPUT_H

#include <raylib.h>

class Input {
    public:
        Input();
        virtual ~Input();

        Vector2 get_mouse_position() const;
        static Input* get_instance();

        void update();
        bool is_mouse_cliked() const;

    private:
        static Input* m_instance;


};

#endif
