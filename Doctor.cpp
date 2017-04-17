#include "Doctor.hpp"

Doctor::Doctor() {
    name = "Doctor";
}

void Doctor::draw(int x, int y) {
    this->x = x;
    this->y = y;
    
    ofSetColor(color);
    ofNoFill();
    ofSetLineWidth(5);
    ofDrawEllipse(x, y, 200, 75);
    ofDrawBitmapString(name, x - 60, y);
}

void Doctor::treat(Patient *patient) {
    ++patient->treatProgress;
}

