#include "points.h"
#include "constants.h"
#include <cmath>
#include "../RPN/evaluate.h"
#include <string>

Points::Points()
{
    //initialize my points with coordinate of zeros
    count = 1;
    domain = sf::Vector2f(-10, 10);
    range = sf::Vector2f(domain.x * (SCREEN_HEIGHT/WORK_PANEL), domain.y * (SCREEN_HEIGHT/ WORK_PANEL));
    for (int i = 0; i < 1000; i++)
    {
        pos[i] = sf::Vector2f(0,0);
    }
    point = sf::CircleShape(1);
    point.setPosition(pos[0]);
    point.setOrigin(point.getOrigin().x + 5, point.getOrigin().y + 5);
    point.setFillColor((sf::Color::Red));
    equation = "";
    origin = sf::Vector2f(WORK_PANEL / (domain.y - domain.x) * (0 - domain.x), (SCREEN_HEIGHT*-1) / (range.y - range.x) * (0 - range.y));
    polar = false;
}

void Points::Find_POS(string _equation)
{
    //if equation is not blank
    equation = _equation;
    if(equation != "")
    {
        //turn up the update
        update = true;
        //find a single block
        float block = (abs(domain.x) + abs(domain.y)) / 1000;
        //num if domain of x from lowest bound
        double num = domain.x;
        string str(equation);
        for (int i = 0; i < 1000; i++)
        {
            //evaluate will return the y value for giving x in a equation
            Evaluate e(str, num);
            //form the posision
            pos[i] = sf::Vector2f(num , e.eval());
            //if polar is true, turn the coordinate to polar coordinate
            if (polar)
            {
                float r = sqrt(pos[i].x* pos[i].x+pos[i].y*pos[i].y);
                float x = pos[i].y*cos(pos[i].x);
                float y = pos[i].y*sin(pos[i].x);
                pos[i] = (sf::Vector2f(x, y));
            }
            //linear transformation from cartecian to polar coordinate
            pos[i] = sf::Vector2f(WORK_PANEL / (domain.y - domain.x) * (pos[i].x - domain.x), (SCREEN_HEIGHT*-1) / (range.y - range.x) * (pos[i].y - range.y));
            //num + block is the x value for the next dot
            num = num + block;
        }
        //keep track of the position of the origin
        origin = sf::Vector2f(WORK_PANEL / (domain.y - domain.x) * (0 - domain.x), (SCREEN_HEIGHT*-1) / (range.y - range.x) * (0 - range.y));
        //size of the point is 1 pixel
        point = sf::CircleShape(1);
        point.setPosition(pos[0]);
        //set the origin so that the graph will not "off"
        point.setOrigin(point.getOrigin().x + 1, point.getOrigin().y + 1);
        point.setFillColor((sf::Color::Red));
        count = 1;
        //change the update to false after drawing the graph
        update = false;
    }
}
void Points::set_update(bool _update)
{
    update = _update;
}
void Points::set_polar(bool _polar)
{
    polar = _polar;
}

bool Points::return_polar()
{
    return polar;
}

sf::Vector2f Points::return_domain()
{
    return domain;
}

sf::Vector2f Points::return_origin()
{
    return origin;
}

void Points::Step(int command)
{
    //give the command to the points
    float total = abs(domain.x) + abs(domain.y);
    switch (command)
    {
    case 0:
        Find_POS(equation);
        update = true;
        break;
    case 4:
        //transform left and right according to the domain
        domain.x -= total / 10;
        domain.y -= total / 10;
        Find_POS(equation);
        update = false;
        break;
    case 5:
        domain.x += total / 10;
        domain.y += total / 10;
        Find_POS(equation);
        update = false;
        break;
    case 6:
        //transform up and down according to the range
        range.x += total / 10;
        range.y += total / 10;
        Find_POS(equation);
        update = false;
        break;
    case 7:
        range.x -= total / 10;
        range.y -= total / 10;
        Find_POS(equation);
        update = false;
        break;
    case 8:
        //zoom in
        domain.x = domain.x / 2;
        domain.y = domain.y / 2;
        range.x = range.x / 2;
        range.y = range.y / 2;
        Find_POS(equation);
        update = false;
        break;
    case 9:
        //zoom out
        domain.x = domain.x * 2;
        domain.y = domain.y * 2;
        range.x = range.x * 2;
        range.y = range.y * 2;
        Find_POS(equation);
        update = false;
        break;
    case 10:
        //switch between polar
        Find_POS(equation);
        update = false;
        break;
    }
}

void Points::Draw(sf::RenderWindow &window)
{
    string str;
    str = equation;
    //if the equation is new
    //draw if instead of appear it immediately
    if (update)
    {
        if (count < 1000)
        {
            point.setPosition(pos[count]);
            point.setFillColor(sf::Color::Green);
            window.draw(point);
            count++;
        }
        if (count == 1000)
        {
            //after finish, turn the graph to red
            update = false;
            point.setFillColor(sf::Color::Red);
        }
    }
    else {
        //if the graph is not new, does not need the drawing animation
        window.clear();
        while (count < 1000)
        {
            point.setPosition(pos[count]);
            window.draw(point);
            count++;
        }
    }
    //never goes out of bound
    if (count  == 1000)
    {
        count = 0;
    }
}

bool Points::return_update()
{
    return update;
}
