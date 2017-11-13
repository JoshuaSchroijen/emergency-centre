TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    sensorgroup.cpp \
    sensorinterface.cpp \
    sensordatagenerator.cpp \
    smokesensordatagenerator.cpp \
    sensor.cpp \
    toxicgassensordatagenerator.cpp \
    firealarm.cpp \
    evacuationalarm.cpp \
    policealarm.cpp \
    smokesensor.cpp \
    motionsensor.cpp \
    motionsensordatagenerator.cpp \
    toxicgassensor.cpp \
    alarm.cpp \
    generalsensorobserver.cpp

HEADERS += \
    sensorinterface.h \
    sensorgroup.h \
    sensorinterface.h \
    sensorinterface.h \
    sensordatagenerator.h \
    smokesensordatagenerator.h \
    sensor.h \
    toxicgassensordatagenerator.h \
    alarm.h \
    firealarm.h \
    evacuationalarm.h \
    policealarm.h \
    smokesensor.h \
    motionsensor.h \
    motionsensordatagenerator.h \
    toxicgassensor.h \
    sensorobserver.hpp \
    generalsensorobserver.h
