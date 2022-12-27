﻿#include <SFML/Graphics.hpp> 
#include <SFML/Audio.hpp>
#include <Ball.cpp>
#include <vector>
#include <iostream>

using namespace sf;
using namespace Game;
int main()
{
    Ball ball;
    
    RenderWindow window(sf::VideoMode(800, 600), "Game");
    window.setFramerateLimit(60);
	ball.shape.setRadius(20);
    Texture textureOfBackground;
    textureOfBackground.loadFromFile("cherry.jpg");
    Sprite background(textureOfBackground);
 
    while (window.isOpen()) //До тех пор пока открыто окно выполняется:
    {
        //Добавление работы окна
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        ball.Move(window);
        ball.ColorChange();

        window.clear();//Отчистка буфера


        window.draw(background);
        window.draw(ball.shape);

        window.display();
    }
}