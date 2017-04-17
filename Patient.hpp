#pragma once
#include "ofMain.h"

class Patient {
    
public:
    int x;
    int y;
    
    int severity;
    int treatTime;
    int treatProgress;
    int lifeRemaining;
    int id;
    ofColor color;
    
    Patient();
    
    struct Comparator {
        bool operator() (const Patient *a, const Patient *b) const {
            return a->severity < b->severity;
        }
    };
    
    void draw(int x, int y);
    void update();
    bool dead();
    bool healed();
    
};
