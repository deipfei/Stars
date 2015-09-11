#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <SFML/Graphics.hpp>


class instructions
{
    public:
        instructions();
        instructions(sf::Texture&);
        virtual ~instructions();
        sf::Sprite get_sprite();
    protected:
        sf::Texture tex;
        sf::Sprite spr;
    private:
};

#endif // INSTRUCTIONS_H
