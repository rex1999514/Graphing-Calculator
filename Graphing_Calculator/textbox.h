#ifndef TEXTBOX_H
#define TEXTBOX_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#define BACK_SPACE 8
#define ENTER 13
using namespace std;


class Textbox
{
public:
    Textbox();
    Textbox(bool finish);
    void input_key(int key);
    void deletechar();
    void set_font(sf::Font &font);
    void set_position(sf::Vector2f pos);
    void set_limit(bool limit);
    void set_limit(bool limit, int lim);
    void set_finish(bool finish);
    bool has_finish();
    string return_text();
    void get_key(sf::Event input);
    void Draw(sf::RenderWindow& windows);
private:
    sf::Text textbox;
    vector<string> text;
    int _limit;
    bool has_limit;
    bool done;
    sf::RectangleShape window;

};

#endif // TEXTBOX_H
