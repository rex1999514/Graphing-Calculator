TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    token.cpp \
    number.cpp \
    operator.cpp \
    rpn.cpp \
    shunting_yard.cpp \
    evaluate.cpp \
    lparent.cpp \
    rparent.cpp \
    tokenize.cpp \
    variable.cpp

HEADERS += \
    token.h \
    constants.h \
    number.h \
    operator.h \
    rpn.h \
    shunting_yard.h \
    evaluate.h \
    lparent.h \
    rparent.h \
    z_output.h \
    z_work_report.h \
    tokenize.h \
    variable.h
