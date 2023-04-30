#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>

// for debugging
#include <iostream>

#include "SceneManager.cpp"

typedef sf::Keyboard k;
using namespace std;

struct SceneData {
	unsigned int width;
	unsigned int height;

};

void buildGlFromFile(string fname, Grid**& gl, int& gsize, sf::Texture* t, SceneData& sd) {
	gsize = 0;
	int maxx = 0;
	int maxy = 0;
	int x = 0;
	int y = 0;
	// get number of grids
	ifstream input_file(fname);
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			for (char c : line) {
				if (c == '#') {
					gsize++;

				}
				x++;

			}
			if (x > maxx) maxx = x;
			x = 0;
			y++;
		}
		input_file.close();
	}
	else return; // error
	maxy = y;

	// intialize grids
	gl = new Grid * [gsize];
	x = 0;
	y = 0;
	int ctr = 0;
	float theScale;
	if (sd.width / maxx > sd.height / maxy) {
		theScale = sd.height / maxy;
	}
	else theScale = sd.width / maxx;
	input_file = ifstream(fname);
	if (input_file.is_open()) {
		std::string line;
		while (std::getline(input_file, line)) {
			for (char c : line) {
				if (c == '#') {
					gl[ctr] = new Grid(*t);
					gl[ctr]->setScale(theScale);
					gl[ctr]->setPos(x, y);
					ctr++;
				}
				x++;
			}
			y++;
			x = 0;
		}
		input_file.close();
	}
	else return; // error
}

int main()
{
	sf::VideoMode fullscreenMode = sf::VideoMode::getFullscreenModes()[0];
	sf::RenderWindow w(fullscreenMode, "i hate all", sf::Style::Fullscreen);
	sf::Event event;
	
	sf::Texture* t = new sf::Texture();
	if (!(t->loadFromFile("assets/tile.png"))) return -1;

	int gsize;
	Grid** gl = NULL;
	SceneData scenedata;
	scenedata.width = sf::VideoMode::getDesktopMode().width;
	scenedata.height = sf::VideoMode::getDesktopMode().height;
	buildGlFromFile("levels/a.lvl", gl, gsize, t, scenedata);

	while (w.isOpen()) {
		while (w.pollEvent(event)) {
			if (event.type == sf::Event::Closed||k::isKeyPressed(k::Escape)) w.close();
		}

		w.clear();
		for (int i = 0; i < gsize; i++) w.draw(*gl[i]);
		w.display();
	}
	return 0;
}