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

        // check for keyboard event that 
        // are responsible for making
        // a differnce
        bool resize_press() const;
        bool add_press() const;
        bool reduce_press() const;

    private:
        static Input* m_instance;


};

#endif
