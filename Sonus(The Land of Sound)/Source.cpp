

//Preprocessor Directives
#include <iostream>
//Included SFML GUI libraries
#include <SFML\Graphics.hpp>
#include <SFML/Audio.hpp>


using namespace std; //std lib

void startgame();
bool sGameIsRunning = false;
bool exitProgram = false;

sf::RenderTexture framedata; // background render
sf::Sprite frameholder;
	sf::RenderWindow window(sf::VideoMode(1000,675),
	"Sonus", sf::Style::Titlebar | sf::Style::Close); //Prevent user from maximizing or changing window size
	
	sf::Texture town;
	sf::Sprite background;
	sf::Texture kai;
	sf::Sprite move1;
	sf::Texture landscape;
	sf::Sprite pathmover;
	sf::Texture kaibig;
	sf::Sprite move2;



enum Direction {Down, Left, Up, Right}; //specifies direction, value of up 0, left 1, down 2, right 3

	sf::Vector2i source1(1, Down);
	sf::Vector2i source2(1, Right);

	float frameCounter1 = 0, switchFrame1= 85, frameSpeed1 = 600;


	int main()
	{
		window.setFramerateLimit(144);

		kaibig.setSmooth(true);
		kaibig.loadFromFile("kaik1.png");
		move2.setTexture(kaibig);
		move2.move(sf::Vector2f(50.f, 539.f));
		

		kai.setSmooth(true);
		kai.loadFromFile("kaiS.png");
		move1.setTexture(kai);
		move1.move(sf::Vector2f(385.f, 400.f));
		//move1.rotate();
		town.setSmooth(true);
		town.loadFromFile("thisishom3.png");
		background.setTexture(town);

		landscape.setSmooth(true);
		landscape.loadFromFile("landscape.png");
		pathmover.setTexture(landscape);

		sf::Clock clock1;
		sf::Clock clock2;

		bool gamerun = false;
		while (window.isOpen())
		{


			sf::Event event;
			while (window.pollEvent(event))
			{
				
			}
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::B)))
			{
				gamerun = true;
			}
			
					

					 if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						source1.y = Down;
						move1.move(0, 1);
					}
					 else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					 {
						 source1.y = Up;
						 move1.move(0, -1);
					 }
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					{

						source1.y = Right;
						move1.move(1, 0);
						
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					{
						source1.y = Left;
						move1.move(-1, 0);
						
					}
					frameCounter1 += frameSpeed1 * clock1.restart().asSeconds();
					if (frameCounter1 >= switchFrame1)
					{
						frameCounter1 = 0;
						source2.x++;
						if(source2.x * 64 >= kaibig.getSize().x)
							source2.x = 0;
						source1.x++;
						if (source1.x * 32 >= kai.getSize().x)
							source1.x = 0;
					}
					if (gamerun == true)
					{
						if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
						{
							source2.y = Left;
							move2.move(-1, 0);
						}
						else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
						{
							source2.y = Right;
							move2.move(1, 0);
							
						}
						window.clear();
						//move2.setPosition
						window.draw(pathmover); //draw frameholder to the window
						window.draw(move2);
						window.display();
						
					}
					else
					{
						window.clear();
						window.draw(background); //draw frameholder to the window
						window.draw(move1);
						window.display();
						window.clear();
					}

					move1.setTextureRect(sf::IntRect(source1.x * 32, source1.y * 32, 32, 32));
					move2.setTextureRect(sf::IntRect(source2.x * 64, source2.y * 64, 64, 64));
					

					

		}
	}








	void startgame()
	{
		
		
		framedata.create(1000, 675); //setting texture to the size of the window
		framedata.draw(pathmover); //drawing background "gamemap" onto the framedata texture
		framedata.setSmooth(true); //remove sharp edges
		frameholder.setTexture(framedata.getTexture()); //placing framedata into the frameholder
window.clear();
window.draw(frameholder); //draw frameholder to the window
window.draw(move1);
		window.display();
		 //draw frame

		sf::Event event;

		while (window.isOpen() && sGameIsRunning)
		{

		}
	
		
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed) //Check if event closed
			{
				
			}


		}
		
//close the progam
		return;
	}



	
