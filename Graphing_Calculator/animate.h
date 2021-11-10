#ifndef ANIMATE_H
#define ANIMATE_H

#include <SFML/Graphics.hpp>
#include "sidebar.h"
#include "points.h"
#include "textbox.h"

class Animate
{
public:
    Animate();
    void run();
    void processEvents();
    void update();
    void render();
    void Draw();
    void button_range();
    void equa_file();
    void load_equa();
private:
    sf::RenderWindow window;
    sf::CircleShape mousePoint;
    int command;
    sf::Font font;
    sf::Text myTextLabel;
    Points points;
    bool mouseIn;
    Sidebar sidebar;
    bool need_update;
    Textbox t;
    int index = 0;
};

#endif // ANIMATE_H
