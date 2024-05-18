
#include <SFML/Graphics.hpp>
#include <iostream>
#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "It works!");
	
	window.setFramerateLimit(60);

	std::cout << "Game started" << std::endl;

	sf::RectangleShape rectangle(sf::Vector2f(100, 50));
	rectangle.setOrigin(50, 25);
	rectangle.setPosition(400, 300);
	rectangle.setFillColor(sf::Color(0, 255,0));	

	sf::CircleShape circle(100, 3);
	circle.setPosition(150, 500);
	circle.setRadius(50);
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color::Red);
	circle.setFillColor(sf::Color::Blue);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}			
		}

		//Logic handling
		rectangle.move(0.2f, 0);
		rectangle.rotate(1.0f);

		circle.move(0.3f,0);
		circle.rotate(1.0f);

		//Rendering part of the main game loop
		window.clear();

		//Draw Things
		window.draw(rectangle);
		window.draw(circle);
		window.display();
		
	}

	return 0;
}