#include "Patient.hpp"

Patient::Patient() {
    severity = ofRandom(50);
    treatTime = 1000 + severity*(ofRandom(10));
    lifeRemaining = 2001 - severity*(ofRandom(10));
    treatProgress = 0;
    id =  ofGetFrameNum();
    color = ofColor(ofRandom(255), ofRandom(255), ofRandom(255));
}

void Patient::draw(int x, int y) {
    this->x = x;
    this->y = y;
    
    ofSetColor(color);
    ofNoFill();
    ofSetLineWidth(5);
    ofSetCircleResolution(100);
    ofDrawEllipse(x, y, 200, 75);
    ofDrawBitmapString("Severity: " + ofToString(severity), x - 60, y - 15);
    ofDrawBitmapString("TreatTime: " + ofToString(treatTime), x - 60, y - 5);
    ofDrawBitmapString("LifeRemain: " + ofToString(lifeRemaining), x - 60, y + 5);
    ofDrawBitmapString("TreatProgress: " + ofToString(treatProgress), x - 60, y + 15);
}

void Patient::update() {
    --lifeRemaining;
}

bool Patient::dead() {
    if (lifeRemaining <= 0) {
        return true;
    }
}

bool Patient::healed() {
    if (treatProgress >= treatTime) {
        return true;
    }
}



