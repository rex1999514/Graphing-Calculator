#include "animate.h"
#include "constants.h"
#include <iostream>
#include "points.h"
#include "textbox.h"
#include <fstream>
using namespace std;

Animate::Animate():sidebar(WORK_PANEL, SIDE_BAR), t(true)
{
    //the index of the sidebar starts at four
    index = 4;
    string input;
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Graphing_Calculator");
    points = Points();
    window.setFramerateLimit(120);

    mouseIn = true;

    cout << "Game CTOR. Preparing to load the font." << endl;
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }
    command = 0;
    //initialize the textlabel to empty string
    need_update = true;
    myTextLabel = sf::Text("", font);
    myTextLabel.setCharacterSize(20);
    myTextLabel.setStyle(sf::Text::Bold);
    myTextLabel.setColor(sf::Color::Green);
    myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
    //set the font of my text box
    t.set_font(font);
    t.set_position({WORK_PANEL / 5, SCREEN_HEIGHT / 4});
    t.set_limit(true, 20);
    load_equa();
    cout << "animate instantiated successfully/" << endl;
}

void Animate::Draw()
{
    //draw the point
    points.Draw(window);
    sf::RectangleShape xaxis(sf::Vector2f(WORK_PANEL, 5));
    xaxis.setPosition(0, points.return_origin().y);
    window.draw(xaxis);
    sf::RectangleShape yaxis(sf::Vector2f(SCREEN_HEIGHT, 5));
    yaxis.setPosition(points.return_origin().x, 0);
    yaxis.rotate(90);
    window.draw(yaxis);
    window.draw(myTextLabel);
    sidebar.draw(window);
    //show the domain on the sidebar
    sidebar[0] = "( " + to_string(points.return_domain().x) + " , " + to_string(points.return_domain().y) + " )";
    sidebar[1] = "HISTORY";
    sidebar[2] = ": ";
    //draw the textbox if the user has not finish typing
    if (!t.has_finish())
    {
        t.Draw(window);
        //finish if user press enter
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            //set finish to true, finish typing
            t.set_finish(true);
            //find the new position according to the new equation
            points.Find_POS(t.return_text());
            //clear the error message
            myTextLabel = sf::Text("", font);
            myTextLabel.setCharacterSize(20);
            myTextLabel.setStyle(sf::Text::Bold);
            myTextLabel.setColor(sf::Color::Green);
            myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
            //tell the points to update
            points.set_update(true);
        }
    }
}


void Animate::update()
{
    points.Step(command);
}

void Animate::render()
{
    //draw and display
    Draw();
    window.display();
}

void Animate::processEvents()
{
    float mouseX, mouseY;
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::TextEntered:
            if (!sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            {
                //get key will get what user is typeing
                t.get_key(event);
            }
            break;
            //controling the mouse
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;
        case sf::Event::MouseLeft:
            mouseIn = false;
            break;
        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            break;
            //by clicking the left button, the program will find its position
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                cout << "mouse x" << event.mouseButton.x << endl;
                cout << "mouse y" << event.mouseButton.y << endl;
                //check the posistion where the mouse is pointing and draw the graph according to that equation
                points.Find_POS(sidebar.equation_pos(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)));
                //tell the points to update
                points.set_update(true);
            }
            break;
        case sf::Event::KeyPressed:
            switch(event.key.code)
            {
            //close the program
            case sf::Keyboard::Escape:
                sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
                window.close();
                break;
                //move the graph to the right (see left part more)
            case sf::Keyboard::Left:
                sidebar[SB_KEY_PRESSED] = "Left: Move Left";
                command = 4;
                need_update = true;
                break;
            case sf::Keyboard::Right:
                //move the graph to the left (see right part more)
                sidebar[SB_KEY_PRESSED] = "Right: Move Right";
                command = 5;
                need_update = true;
                break;
            case sf::Keyboard::Up:
                //move the graph to the up
                sidebar[SB_KEY_PRESSED] = "Up: Move Up";
                command = 6;
                need_update = true;
                break;
            case sf::Keyboard::Down:
                //move the graph to the down
                sidebar[SB_KEY_PRESSED] = "Down: Move Down";
                command = 7;
                need_update = true;
                break;
            case sf::Keyboard::Z:
                //zoom in
                sidebar[SB_KEY_PRESSED] = "Z: Zoom in";
                command = 8;
                need_update = true;
                break;
            case sf::Keyboard::Space:
                //zoom out
                sidebar[SB_KEY_PRESSED] = "Space: Zoom out";
                command = 9;
                need_update = true;
                break;
            case sf::Keyboard::F:
                //when user press f, pop the text box
                t.set_finish(false);
                break;
            case sf::Keyboard::P:
                //switch between polar and non-polar by pressing p
                if (points.return_polar())
                {
                    sidebar[SB_KEY_PRESSED] = "Polar Off";
                    points.set_polar(false);
                    command = 10;
                    need_update = true;
                }
                else {
                    sidebar[SB_KEY_PRESSED] = "Polar On";
                    points.set_polar(true);
                    command = 10;
                    need_update = true;
                }
                break;
            case sf::Keyboard::LControl:
                //press left control to save the graph to the side bar
                sidebar[index] = t.return_text();
                index++;
                //never goes out of the range of vector
                if (index == 28)
                {
                    index = 4;
                }
                break;
            }
        default:
            break;
        }
    }
}

//output the equation in the sidebar to a file
void Animate::equa_file()
{
    ofstream outs;
    outs.open("equations.txt");
    if (outs.fail())
    {
        cout << "output file opening fail.\n";
        exit(1);
    }
    for (int i = 4; i < 26; i++)
    {
        if (!sidebar[i].empty())
        {
            outs << sidebar[i] << endl;
        }
    }
    outs.close();
}

//input the equation from the file to the sidebar
void Animate::load_equa()
{
    ifstream ins;
    int i = 4;
    string str;
    ins.open("equations.txt");
    if (ins.fail())
    {
        cout << "Input File opening fail.\n";
        exit(1);
    }
    while(ins)
    {
        getline(ins, str);
        if(str != "")
        {
            sidebar[i] = str;
            i++;
        }
    }
    index = i;
    ins.close();
}

//run
void Animate::run()
{
    while (window.isOpen())
    {
        try {
            processEvents();
            if (need_update)
            {
                update();
                need_update = false;
            }
            render();
            //error checking
        } catch (TOKEN_ERROR e) {
            switch(e)
            {
            case no_Para:
                //set the position to normal, pop the error message at the left bottom
                points.Find_POS("");
                myTextLabel = sf::Text("Please Check your parentheses", font);
                myTextLabel.setCharacterSize(20);
                myTextLabel.setStyle(sf::Text::Bold);
                myTextLabel.setColor(sf::Color::Green);
                myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
                break;
            case OP_error:
                points.Find_POS("");
                myTextLabel = sf::Text("Ending with operator is not allowed", font);
                myTextLabel.setCharacterSize(20);
                myTextLabel.setStyle(sf::Text::Bold);
                myTextLabel.setColor(sf::Color::Green);
                myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
                break;
            }
        }
        catch (EMPTY e)
        {
            switch (e)
            {
            case EMPTY_S:
                points.Find_POS("");
                myTextLabel.setString("No number or variable in the equation(Empty stack)");
                myTextLabel.setCharacterSize(20);
                myTextLabel.setStyle(sf::Text::Bold);
                myTextLabel.setColor(sf::Color::Green);
                myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
                break;
            case EMPTY_Q:
                points.Find_POS("");
                myTextLabel.setString("No number or variable in the equation(Empty Queue)");
                myTextLabel.setCharacterSize(20);
                myTextLabel.setStyle(sf::Text::Bold);
                myTextLabel.setColor(sf::Color::Green);
                myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
                break;
            case UNRECOGNIZE_OP:
                points.Find_POS("");
                myTextLabel.setString("Operator is not recognizable");
                myTextLabel.setCharacterSize(20);
                myTextLabel.setStyle(sf::Text::Bold);
                myTextLabel.setColor(sf::Color::Green);
                myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));
                break;
            }
        }
    }
    //out stream the equation at the sidebar to a file.
    equa_file();
    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}
