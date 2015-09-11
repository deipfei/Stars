#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "include/mainmenu.h"
#include "include/instructions.h"
#include "include/fireball.h"
#include "include/pipe.h"
#include "include/background.h"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

enum State {MENU, INSTRUCTIONS, PLAYING, SCORE};
State state = MENU;
bool seen_instructions = false;

sf::Clock button_timer;

mainmenu men;
sf::Texture mentex;
instructions instr;
sf::Texture instrtex;
sf::Texture hobtex;
sf::Texture backgroundtex;
sf::Texture pipetex;
sf::Music bgmus;

vector<pipe> pipes;
vector<int> pipe_heights;
int next_pipe = 0;

int score = 0;
sf::Font scorefont;
sf::Text scoretext;

//patch for MinGW not recognizing to_string
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

void reset_variables(fireball &f){
    next_pipe = 0;
    score = 0;
    f.reset_variables();
    pipes.clear();
}

void listen_for_space(fireball &f){
    if (state != PLAYING && sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && button_timer.getElapsedTime().asMilliseconds() > 500){
        button_timer.restart();
        if (state == MENU){
            if (!seen_instructions){
                state = INSTRUCTIONS;
                seen_instructions = true;
            } else {
                reset_variables(f);
                state = PLAYING;

            }
        } else if (state == INSTRUCTIONS) {
            reset_variables(f);
            state = PLAYING;

        } else if (state == SCORE){
            state = MENU;
            reset_variables(f);
        }
    }
}

void check_collision(fireball h, vector<pipe> vec){
    sf::FloatRect hobcol = h.get_sprite().getGlobalBounds();
    if (hobcol.top + hobcol.height >= 600){
        scoretext.setString("Score: " + patch::to_string(score));
        state = SCORE;
        button_timer.restart();
    }
    for (size_t i = 0; i < vec.size(); i++){
        if (hobcol.intersects(vec.at(i).get_top_sprite().getGlobalBounds()) || hobcol.intersects(vec.at(i).get_bot_sprite().getGlobalBounds())){
            scoretext.setString("Score: " + patch::to_string(score));
            state = SCORE;
            button_timer.restart();
        }
    }
}

void check_pipes(){
    if (pipes.size() == 0){
        pipe pip(pipetex, 300);
        pipes.insert(pipes.end(), pip);
    }
    else if (pipes.size() == 1){
        if (pipes.at(0).get_xpos() == 240){
            pipe pip(pipetex, pipe_heights.at(next_pipe) * 100);
            pipes.insert(pipes.end(), pip);
            next_pipe++;
        }
    } else {
        if (pipes.at(0).get_xpos() == -30){
            pipes.erase(pipes.begin());
            pipe pip(pipetex, pipe_heights.at(next_pipe) * 100);
            pipes.insert(pipes.end(), pip);
            next_pipe++;
            score++;
        }
    }

    if (next_pipe == pipe_heights.size()){
        next_pipe = 0;
    }

}

void draw_pipes(sf::RenderWindow& w){
    for (size_t i = 0; i < pipes.size(); i++){
        pipe temp = pipes.at(i);
        w.draw(temp.get_top_sprite());
        w.draw(temp.get_bot_sprite());
    }
}

void update_pipes(){
    for (size_t i = 0; i < pipes.size(); i++){
        pipes.at(i).update();
    }
}

void draw_background(sf::RenderWindow &w, background &bg){
    w.draw(bg.get_sprite());
    w.draw(bg.get_second_sprite());
    bg.update();
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 600), "Stars");
    window.setFramerateLimit(30);

    //srand (time(NULL));

    srand(0);

    for (size_t i = 0; i < 100; i++){
        pipe_heights.insert(pipe_heights.end(), rand() % 5 + 1);
    }

    if (!scorefont.loadFromFile("resources/Square.ttf")){
        cout << "Could not load Square.ttf" << endl;
        return -1;
    }
    scoretext.setFont(scorefont);
    scoretext.setPosition(150, 300);

    if (!mentex.loadFromFile("resources/mainmenu.png")){
        cout << "Could not load mainmenu.png" << endl;
        return -1;
    }
    men = mainmenu(mentex);


    if (!instrtex.loadFromFile("resources/instructions.png")){
        cout << "Could not load instructions.png" << endl;
        return -1;
    }
    instr = instructions(instrtex);

    if (!hobtex.loadFromFile("resources/fireballspritesheet.png")){
        cout << "Could not load fireballspritesheet.png" << endl;
        return -1;
    }
    fireball hob(hobtex);

    if (!pipetex.loadFromFile("resources/pipe2.PNG")){
        cout << "could not load pipespritesheet.png" << endl;
        return -1;
    }

    if (!backgroundtex.loadFromFile("resources/spacebackgroundbig.png")){
        cout << "Could not load spacebackground.png" << endl;
        return -1;
    }
    background bg(backgroundtex);

    if (!bgmus.openFromFile("resources/Sunset at Glengorm.wav")){
        cout << "Could not load music" << endl;
        return -1;
    }

    bgmus.setLoop(true);
    bgmus.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        if (state == MENU){
            window.draw(sf::Sprite(men.get_sprite()));
            listen_for_space(hob);
        } else if (state == INSTRUCTIONS){
            window.draw(instr.get_sprite());
            listen_for_space(hob);
        } else if (state == SCORE) {
            window.draw(bg.get_sprite());
            window.draw(scoretext);
            listen_for_space(hob);
        } else {
            draw_background(window, bg);
            window.draw(hob.get_sprite());
            check_pipes();
            draw_pipes(window);
            hob.update();

            update_pipes();
            check_collision(hob, pipes);

        }


        window.display();
    }

    return 0;
}

