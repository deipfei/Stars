#include "../include/mainmenu.h"
#include <iostream>
#include <stdio.h>

using namespace std;

mainmenu::mainmenu()
{
    if (!tex.loadFromFile("resources/mainmenu.png")){
        cout << "could not load mainmenu.png" << endl;
        exit(-1);
    }
    spr = sf::Sprite(tex);
}

mainmenu::mainmenu(sf::Texture& t){
    spr = sf::Sprite(t);
}

mainmenu::~mainmenu()
{
    //dtor
}

sf::Sprite mainmenu::get_sprite(){
    return spr;
}
