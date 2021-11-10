#ifndef POINTS_H
#define POINTS_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "../RPN/evaluate.h"


class Points
{
public:
    Points();
    void Step(int command);
    int Size();
    void Draw(sf::RenderWindow& window);
    void set_update(bool _update);
    void Find_POS(string _equation);
    void set_polar(bool _polar);
    bool return_polar();
    bool return_update();
    sf::Vector2f return_domain();
    sf::Vector2f return_origin();
private:
    int count;
    sf::Vector2f domain;
    sf::Vector2f range;
    sf::Vector2f origin;
    sf::CircleShape point;
    sf::Vector2f pos[1000];
    string equation;
    bool polar;
    bool update;
};

#endif // POINTS_H
