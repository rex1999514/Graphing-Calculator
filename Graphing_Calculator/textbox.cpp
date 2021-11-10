#include "textbox.h"
#include "constants.h"

Textbox::Textbox()
{

}

Textbox::Textbox(bool finish)
{
    //set the text size and color of the characters in the text box
    textbox.setCharacterSize(20);
    textbox.setColor(sf::Color::Yellow);
    //finish is true when user is finish typing
    done = finish;
    if (!finish)
    {
        //beginning of the string
        textbox.setString("f(x) =_");
        text.push_back("f(x) = ");
    }
    else {
        textbox.setString("");
    }
    //set the popup of window
    window.setSize(sf::Vector2f(WORK_PANEL / 2, 100));
    window.setFillColor(sf::Color::Black);
    window.setOutlineThickness(5);
    window.setOutlineColor(sf::Color::Yellow);
}

void Textbox::set_font(sf::Font &font)
{
    //allow user to set the font if needed
    textbox.setFont(font);
}

void Textbox::set_position(sf::Vector2f pos)
{
    //set the position of the small window
    window.setPosition(pos);
    float xPos = (pos.x + window.getLocalBounds().width / 10 - textbox.getLocalBounds().width / 2);
    float yPos = (pos.y + window.getLocalBounds().height / 3 - textbox.getLocalBounds().height / 2);
    //text's position should go with the position of the window
    textbox.setPosition({xPos, yPos});
}

void Textbox::set_limit(bool limit)
{
    has_limit = limit;
}

void Textbox::set_limit(bool limit, int lim)
{
    has_limit = limit;
    _limit = lim;
    cout << "lim" << _limit << endl;
}

void Textbox::set_finish(bool finish)
{
    done = finish;
}

string Textbox::return_text()
{
    string input;
    for (vector<string>::iterator it = text.begin(); it!= text.end(); it++)
    {
        //use iterator to add the character to a input string
        input += it->c_str();
    }
    return input;
}

void Textbox::Draw(sf::RenderWindow &windows)
{
    //draw implement how the textbox should be displayed
    string temp = "f(x) = ";
    windows.draw(window);
    textbox.setString(temp + return_text() + "_");
    windows.draw(textbox);
}

void Textbox::get_key(sf::Event input)
{
    //the event input follows the ASCII table
    int count = 0;
    if (!done)
    {
        for (vector<string>::iterator it = text.begin(); it!= text.end(); it++)
        {
            count++;
        }
        int key = input.text.unicode;
        //set the key range within all the letters and numbers
        if(key < 128)
        {
            //if not reaching the limit
            if (has_limit)
            {
                if (count <= _limit)
                {
                    input_key(key);
                }
                //otherwise not being able to input after the limit
                else if(count > _limit && key == BACK_SPACE)
                {
                    deletechar();
                }
            }
            else {
                deletechar();
            }
        }
    }
}

bool Textbox::has_finish()
{
    return done;
}

void Textbox::input_key(int key)
{
    string input;
    //if key is not backspace or enter, it is typing a character
    if (key != BACK_SPACE && key != ENTER)
    {
        string temp = "";
        temp = temp + static_cast<char>(key);
        text.push_back(temp);
    }
    //if key is backspace, delete the last character
    else if (key == BACK_SPACE)
    {
        if (!text.empty())
        {
            deletechar();
        }
    }
    for (vector<string>::iterator it = text.begin(); it!= text.end(); it++)
    {
        input += it->c_str();
    }
    //set the string to input + underline
    textbox.setString(input + "_");
}

//delete for a vector is to pop back the last character
void Textbox::deletechar()
{
    text.pop_back();
    string t;
    for (vector<string>::iterator it = text.begin(); it!= text.end(); it++)
    {
        t += it->c_str();
    }
    textbox.setString(t);
}
