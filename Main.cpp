#include <SFML/Graphics.hpp>
#include <string>

// for debugging
#include <iostream>

#include "SceneManager.cpp"

typedef sf::Keyboard k;
using namespace std;

class Scene {
public:
	Scene() {

	}
};


int main()
{
	sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
	sf::RenderWindow w(fullscreenMode, "Fullscreen window", sf::Style::Fullscreen);
	sf::Event event;
	

	cout << sf::VideoMode::getDesktopMode().width << endl;
	cout << sf::VideoMode::getDesktopMode().height << endl;
	while (w.isOpen()) {
		while (w.pollEvent(event)) {
			if (event.type == sf::Event::Closed||k::isKeyPressed(k::Escape)) w.close();
		}

		w.clear();

		w.display();
	}
	return 0;
}