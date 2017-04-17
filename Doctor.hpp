#pragma once
#include "ofMain.h"
#include "Patient.hpp"

class Doctor {
    
public:
    int x;
    int y;

    string name;
    
    ofColor color;
    
    Doctor();
    
    void draw(int x, int y);
    void treat(Patient *patient);
    
};
