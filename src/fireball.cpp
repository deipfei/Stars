#include "../include/fireball.h"
#include "../include/Animation.h"
#include "../include/AnimatedSprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>

using namespace std;

fireball::fireball()
{
    //ctor
}

fireball::fireball(sf::Texture t){
    texture = t;
    floating.setSpriteSheet(texture);
    shooting.setSpriteSheet(texture);

    floating.addFrame(sf::IntRect(0, 0, 50, 50));
    floating.addFrame(sf::IntRect(50, 0, 50, 50));

    shooting.addFrame(sf::IntRect(0, 50, 50, 50));
    shooting.addFrame(sf::IntRect(50, 50, 50, 50));
    anspr = AnimatedSprite(sf::seconds(.2f), false, true);
    anim = &floating;

    xpos = 20;
    ypos = 100;
    anspr.setPosition(xpos, ypos);
    anspr.play(*anim);

    state = FALL;

}

fireball::~fireball()
{
    //dtor
}

AnimatedSprite fireball::get_sprite(){
    return anspr;
}

void fireball::update(){
    space_to_jump();
    if (state == JUMP && jump_clock.getElapsedTime().asMilliseconds() < 500){
        if (ypos > 0){
            ypos -= jumpaffect(jump_clock.getElapsedTime().asMilliseconds());

        }
        grav_time.restart();
        anspr.play(shooting);

    } else {
        anspr.play(floating);
        state = FALL;
        ypos += gravityaffect(grav_time.getElapsedTime().asMilliseconds());
    }
    //cout << xpos << ", " << ypos << endl;
    anspr.setPosition(xpos, ypos);
    anspr.update(frame_time.restart());
}

float fireball::gravityaffect(int milli){
    float grav = 9.8 * pow(((milli/1000.0) * 2), 2);
    //cout << grav << endl;
    return grav;
}

float fireball::jumpaffect(int milli){
    float jump = 9.8 * pow(((.5 - milli/1000.0) * 2), 2);
    return jump;
}

void fireball::space_to_jump(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            state = JUMP;
            jump_clock.restart();
    }
}

void fireball::reset_variables(){
    ypos = 100;
    anspr.setPosition(xpos, ypos);
    jump_clock.restart();
    grav_time.restart();
    state = FALL;
}


