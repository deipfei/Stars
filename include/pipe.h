#ifndef PIPE_H
#define PIPE_H

#include <SFML/Graphics.hpp>
#include "../include/Animation.h"
#include "../include/AnimatedSprite.h"


class pipe
{
    public:
        pipe();
        virtual ~pipe();
        pipe(sf::Texture, int);
        sf::Sprite get_top_sprite();
        sf::Sprite get_bot_sprite();
        sf::FloatRect get_top_coll();
        sf::FloatRect get_bot_coll();
        void update();
        float get_xpos();
    protected:
        float xpos;
        float top_ypos;
        float bot_ypos;
        sf::Texture texture;
        sf::Sprite top_spr;
        sf::Sprite bot_spr;
        sf::FloatRect top_coll;
        sf::FloatRect bot_coll;
        Animation* anim;
        Animation* anim2;
        Animation flash;
        //AnimatedSprite top_spr;
        //AnimatedSprite bot_spr;
        sf::Clock frame_time;
    private:
};

#endif // PIPE_H
