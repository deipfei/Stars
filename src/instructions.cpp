#include "../include/instructions.h"

#include <stdio.h>
#include <iostream>

using namespace std;

instructions::instructions()
{
    if (!tex.loadFromFile("resources/instructions.png")){
        cout << "could not load instructions.png" << endl;
        exit(-1);
    }

    spr = sf::Sprite(tex);
}

instructions::instructions(sf::Texture& t){
    spr = sf::Sprite(t);
}

instructions::~instructions()
{
    //dtor
}

sf::Sprite instructions::get_sprite(){
    return spr;
}
