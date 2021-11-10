#ifndef Z_WORK_REPORT_H
#define Z_WORK_REPORT_H
/*
    Features:
        -Not Implemented:
                            - Did not implement the numbers on the axis
                            - Did not implement a number pads on the screen
                            - Did not allow the user to drag the graph using mouse
                            - Did not allow user to analyze the graph
                            - Did not allow user to see two graph at the same time
                            - Did not implement previewing the graph of the equation on the sidebar
                            - Did not add the back ground to the calculator so that it looks like a grid
        -Implemented:
                            - The program has a drawing animation
                            - Linear Transformation for every points, including transformation
                            - Input textbox window
                                    * implement the initial string as f(x)
                                    * has a limit of 10 on the textbox
                                    * does not allow user to backspace a empty function
                            - In stream and out stream of the side bar
                                    * keep and read the equation from file
                            - Click the equation on the sidebar to draw the graph
                            - keep track of the damain
                            - Zoom in and Zoom out
                            - Move, Left, Right, Up Down
                            - All basic trig function
                            - Pi is implemented
                            - Polar Coordinate
                            - distinguish two line using different color to see their interaction
                            - Throw and catch
                                    * Input Error
                                      #missing parenthese
                                      #invalid operator
                                      #Ending function with operator
                                    * Poping empty stack or queue
                            - Error message appears on the left bottom side
                            - Points is in its own class, Text Box is in its own class
                            - The position is base on the Work_panel so it the program will work if
                            we enlarge the program
                            - Save the current graph to the side bar
                            - A Tokenizer for the program so that input string does not need to contain spaces
                            - rpn has a max function
        -Partly implemented: I might be able to show the coordinate if have more time
                             I did not make sin(x)tan(x) automatically become sin(x)*tan(x)
                             Did not allow user to move the underline in the text box forward


    Bugs     : equations below had been tested and are implemented are bug-free.
cos(x)
sin(tan(x))
cos(x)
5-sin(x)
cos(x)
tan(cos(x))
cos(x)
cos(x)
sin(x)*tan(x)
csc(x)
cos(x)^2+sin(x)^2
sec(csc(tan(x)))
sin(x)/tan(x)*csc(x)
sin(cos(tan(csc(x))))
x^5+6*x^4+7*x^2


    Reflections:
    It is hard to study use sfml at first, but it make me feel happier when i finish everything by researching and thinking


*/
#endif // Z_WORK_REPORT_H
