
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "main.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "It works!");
	
	window.setFramerateLimit(60);

	std::cout << "Game started" << std::endl;

	sf::Texture box_texture;
	if (box_texture.loadFromFile("x64/Data/box.png")==false) 
	{
		std::cout << "Loading image Failed" << std::endl;
	}
	box_texture.setSmooth(true);

	//Font file
	sf::Font font;
	if(font.loadFromFile("x64/Data/Recky.ttf"))
	{
		//
	}

	sf::RectangleShape rectangle(sf::Vector2f(500, 500));
	rectangle.setOrigin(50, 25);
	rectangle.setPosition(400, 300);
	//rectangle.setFillColor(sf::Color(0, 255,0));	
	rectangle.setTexture(&box_texture);

	sf::CircleShape circle(100, 3);
	circle.setPosition(150, 500);
	circle.setRadius(50);
	circle.setOutlineThickness(10);
	circle.setOutlineColor(sf::Color::Red);
	circle.setFillColor(sf::Color::Blue);
	//circle.setTexture(&box_texture);

	sf::Sprite box;
	box.setTexture(box_texture);
	box.setScale(0.5f, 0.5f);

	// Text object
	sf::Text text;
	text.setFont(font);
	text.setString("This is a Text, Hi");
	text.setCharacterSize(30);
	text.setPosition(250, 0);
	text.setFillColor(sf::Color::Blue);
	text.setStyle(sf::Text::Italic);

	//Sounds
	//sf::SoundBuffer ball_buffer;
	//if (ball_buffer.loadFromFile("x64/Data/classic-alarm.wav")==false) 
	//{
	//	//
	//}
	//sf::Sound ball_sound;
	//ball_sound.setBuffer(ball_buffer);
	//ball_sound.play();
	/*ball_sound.setPitch(1.5f);
	ball_sound.setLoop(true);*/

	//Music
	sf::Music music;
	if (music.openFromFile("x64/Data/retro-game-notification.wav") == false) 
	{
		return 1;
	}
	music.play();
	music.setPitch(0.5f);
	music.setPlayingOffset(sf::seconds(5));

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

		text.move(0, 1);

		//Rendering part of the main game loop
		window.clear();

		//Draw Things
		window.draw(rectangle);
		window.draw(circle);
		window.draw(box);
		window.draw(text);
		window.display();		
	}
	return 0;
}