#include "../include/background.h"

background::background()
{
    //ctor
}

background::background(sf::Texture t){
    texture = t;
    bg1 = sf::Sprite(texture);
    xpos = 0;
    bg1.setPosition(xpos, 0);

    bg2 = sf::Sprite(texture);
    bg2.setPosition(xpos + 3100, 0);
}

background::~background()
{
    //dtor
}

void background::update(){
    xpos -= .5f;
    if (xpos == -3100){
        xpos = 0;
    }
    bg1.setPosition(xpos, 0);
    bg2.setPosition(xpos + 3100, 0);
}

sf::Sprite background::get_sprite(){
    return bg1;
}

sf::Sprite background::get_second_sprite(){
    return bg2;
}
