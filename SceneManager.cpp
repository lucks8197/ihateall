#include <SFML/Graphics.hpp>

// personal hell

struct SceneInfo {

};

class SceneManager : public sf::Drawable {
public:
	SceneManager() {

	}
	void tick() {

	}

private: // there are some things in life that we just don't question and move on
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {

	};
};

class Grid: public sf::Drawable {
public:
	sf::Vector2i pos;
	sf::Texture texture;
	sf::Sprite s;
	float scale = 5;

	Grid(){}

	Grid(sf::Texture t) {
		t.setSmooth(false);
		texture = t;
		s.setTexture(texture);
		this->pos = sf::Vector2i(0,0);
		setPos(pos.x, pos.y);
		setScale(5);
	}
	void setScale(float sc) {
		scale = sc;
		s.setScale(sf::Vector2f(scale / texture.getSize().x, scale / texture.getSize().y));
	}
	void setPos(int x, int y) {
		pos.x = x;
		pos.y = y;
		s.setPosition(sf::Vector2f(pos.x*scale, pos.y*scale));
	}

	void tick(SceneInfo& p) {

	}

private: // there are some things in life that we just don't question and move on
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		target.draw(s);
	}
};
