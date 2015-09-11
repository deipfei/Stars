#include "../include/pipe.h"
#include <iostream>
#include <stdio.h>

using namespace std;

pipe::pipe()
{
    //ctor
}

pipe::pipe(sf::Texture t, int mid){
    //if (!texture.loadFromFile("resources/fullpipe.png")){
    //    cout << "Could not load pipe" << endl;
    //    exit(-1);
    //}
    texture = t;
    /*flash.setSpriteSheet(texture);
    flash.addFrame(sf::IntRect(0, 0, 50, 600));
    flash.addFrame(sf::IntRect(50, 0, 50, 600));
    flash.addFrame(sf::IntRect(100, 0, 50, 600));
    flash.addFrame(sf::IntRect(150, 0, 50, 600));
    flash.addFrame(sf::IntRect(100, 0, 50, 600));
    flash.addFrame(sf::IntRect(50, 0, 50, 600));*/

    //top_spr = AnimatedSprite(sf::seconds(.2f), false, true);
    //bot_spr = AnimatedSprite(sf::seconds(.2f), false, true);

    top_spr = sf::Sprite(texture);
    bot_spr = sf::Sprite(texture);

    //anim = &flash;
    //anim2 = &flash;

    xpos = 500;
    top_ypos = -600 + (mid - 100);
    bot_ypos = mid + 100;

    top_spr.setPosition(sf::Vector2f(xpos, top_ypos));
    bot_spr.setPosition(sf::Vector2f(xpos, bot_ypos));

    //top_spr.setAnimation(flash);
    //top_spr.play();
    //bot_spr.setAnimation(flash);
    //bot_spr.play();
//    top_spr.play(*anim);
//    bot_spr.play(*anim2);

    top_coll = top_spr.getGlobalBounds();
    bot_coll = bot_spr.getGlobalBounds();

    cout << "pipe made" << endl;

}

pipe::~pipe()
{
    //dtor
}

sf::Sprite pipe::get_top_sprite(){
    return top_spr;
}

sf::Sprite pipe::get_bot_sprite(){
    return bot_spr;
}

sf::FloatRect pipe::get_top_coll(){
    //return top_coll;
    sf::FloatRect rect (top_spr.getPosition().x + 3, top_spr.getPosition().y + 3, 19, 19);
    return rect;
}

sf::FloatRect pipe::get_bot_coll(){
//    return bot_coll;
    sf::FloatRect rect (bot_spr.getPosition().x + 3, bot_spr.getPosition().y + 3, 19, 19);
    return rect;
}

void pipe::update(){

    cout << "updating pipe" << endl;
    xpos -= 5;
    top_spr.setPosition(sf::Vector2f(xpos, top_ypos));
    bot_spr.setPosition(sf::Vector2f(xpos, bot_ypos));

    cout << "updating bounds" << endl;
    top_coll = top_spr.getGlobalBounds();
    bot_coll = bot_spr.getGlobalBounds();

    //cout << "updating animations" << endl;
    //sf::Time t = frame_time.restart();

    //top_spr.update(t);
    //bot_spr.update(t);

}

float pipe::get_xpos(){
    return xpos;
}
