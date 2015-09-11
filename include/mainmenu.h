#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>


class mainmenu
{
    public:
        mainmenu();
        mainmenu(sf::Texture&);
        virtual ~mainmenu();
        sf::Sprite get_sprite();
    protected:
        sf::Texture tex;
        sf::Sprite spr;
    private:
};

#endif // MAINMENU_H
