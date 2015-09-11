#ifndef HOBO_H
#define HOBO_H

#include "../include/Animation.h"
#include "../include/AnimatedSprite.h"
#include <SFML/Graphics.hpp>

enum HoboState {FALL, JUMP};

class fireball
{
    public:
        fireball();
        fireball(sf::Texture);
        virtual ~fireball();
        AnimatedSprite get_sprite();
        void update();
        float gravityaffect(int);
        float jumpaffect(int);
        void space_to_jump();
        void reset_variables();
    protected:
        sf::Texture texture;
        Animation *anim;
        Animation floating;
        Animation shooting;
        AnimatedSprite anspr;
        sf::Clock frame_time;
        sf::Clock grav_time;
        sf::Clock jump_clock;
        float xpos;
        float ypos;
        HoboState state;
    private:
};

#endif // HOBO_H
