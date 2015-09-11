#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "../include/AnimatedSprite.h"
#include "../include/Animation.h"

class background
{
    public:
        background();
        background(sf::Texture);
        virtual ~background();
        void update();
        sf::Sprite get_sprite();
        sf::Sprite get_second_sprite();
    protected:
        sf::Texture texture;
        sf::Sprite bg1;
        sf::Sprite bg2;
        float xpos;
    private:
};

#endif // BACKGROUND_H
