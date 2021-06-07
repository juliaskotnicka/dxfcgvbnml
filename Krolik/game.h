#ifndef GAME_H
#define GAME_H


#include <ctime>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "rabbit.h"
#include <vector>
#include <sstream>
#include "ball.h"
#include <SFML/Audio.hpp>

class Game
{
private:

    sf::VideoMode videoMode;

    bool endGame;
std::vector<Ball> balls;
float time;
float maxtime;
int maxball;

sf::Texture backgroundTexture;
sf::Sprite  background;
sf::Music music;
sf::Text endText;

    void initVariables();

    void initBackground();
    void initMusic();
    void initRabbit();
    void initFont();
    void initText();



public:
    Game();
    ~Game();
    sf::Event event;
    sf::RenderWindow* window;
       void initWindow();
    Rabbit* rabbit;
    int points;
    sf::Font font;
    sf::Text text;
    const bool& GameEnd();
    const  bool open() const;
    void pollEvents();
    void createball();
    void updateRabbit();
    int randomize() ;
    void remove();
    void moving();
    void renderBackground();
    void rendertext(sf::RenderTarget* target);
    void updatePoints();
    void update();
    void render();
};

#endif // GAME_H
