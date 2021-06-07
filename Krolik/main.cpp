#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "game.h"
#include "rabbit.h"
#include "menu.h"

int main()
{
    srand(static_cast<unsigned>(time(0)));

        sf::RenderWindow window(sf::VideoMode(600, 600), "menu");

        Menu menu(window.getSize().x, window.getSize().y);
        Game game();
        while (window.isOpen())
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        switch (menu.GetPressedItem())
                        {
                        case 0:
                            game();
                            break;
                        case 1:
                            std::cout << "Option button has been pressed" << std::endl;
                            break;
                        case 2:
                            window.close();
                            break;
                        }

                        break;
                    }

                    break;
                case sf::Event::Closed:
                    window.close();

                    break;

                }
            }

            window.clear();

            menu.draw(window);

            window.display();
        }
    }


