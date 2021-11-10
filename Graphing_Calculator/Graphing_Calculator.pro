TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
#WINDOWS
# put SFML file in the same location as project
LIBS += -L"..\SFML-2.5.1\lib" #change this
LIBS += -L"..\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "..\SFML-2.5.1\include" #change this
DEPENDPATH += "..\SFML-2.5.1\include" #change this

#MAC
#INCLUDEPATH += "/usr/local/include"
#DEPENDPATH += "/usr/local/include"

#-----------------------------------------

SOURCES += \
        main.cpp \
    animate.cpp \
    random.cpp \
    sidebar.cpp \
    points.cpp \
    ../RPN/evaluate.cpp \
    ../RPN/lparent.cpp \
    ../RPN/number.cpp \
    ../RPN/operator.cpp \
    ../RPN/rparent.cpp \
    ../RPN/rpn.cpp \
    ../RPN/shunting_yard.cpp \
    ../RPN/token.cpp \
    ../RPN/tokenize.cpp \
    ../RPN/variable.cpp \
    textbox.cpp

HEADERS += \
    animate.h \
    constants.h \
    random.h \
    sidebar.h \
    points.h \
    ../RPN/evaluate.h \
    ../RPN/constants.h \
    ../RPN/evaluate.h \
    ../RPN/lparent.h \
    ../RPN/number.h \
    ../RPN/operator.h \
    ../RPN/rparent.h \
    ../RPN/rpn.h \
    ../RPN/shunting_yard.h \
    ../RPN/token.h \
    ../RPN/tokenize.h \
    ../RPN/variable.h \
    textbox.h \
    z_work_report.h
