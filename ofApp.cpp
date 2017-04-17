#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(15);
    int deathCount = 0;
    int healedCount = 0;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofLog(OF_LOG_NOTICE, "%d", ofGetFrameNum());
    if (ofGetFrameNum() % 200 == 0) {
        float probability = ofRandom(1.0);
        if (probability < 0.5) {
            Patient *patient = new Patient();
            patientPriority.push(patient);
            waitingRoom.push_back(patient);
        }
    }
    for (int i = 0; i < waitingRoom.size(); ++i) {
        waitingRoom[i]->update();
        if (waitingRoom[i]->dead() == true) {
            waitingRoom.erase(waitingRoom.begin() + i);
            ++deathCount;
        }
        if (waitingRoom[i]->healed() == true) {
            waitingRoom.erase(waitingRoom.begin() + i);
        }
        for (int j = 0; j < beingTreated.size(); ++j) {
            if (waitingRoom[i]->id == beingTreated[j]->id) {
                std::cout << "Beep\n";
                waitingRoom.erase(waitingRoom.begin() + i);
            }
        }
    }
    for (int i = 0; i < doctors.size(); ++i) {
        if (patientPriority.size() > 0) {
            if (doctors.size() > beingTreated.size()) {
                beingTreated.push_back(patientPriority.top());
                patientPriority.pop();
            }
            if (beingTreated[i]->severity < patientPriority.top()->severity) {
                waitingRoom.push_back(beingTreated[i]);
                patientPriority.push(beingTreated[i]);
                beingTreated.erase(beingTreated.begin() + i);
                beingTreated.insert(beingTreated.begin() + i, patientPriority.top());
                patientPriority.pop();
            }
        }
    }
    for (int i = 0; i < beingTreated.size(); ++i) {
        if (beingTreated.size() > 0) {
            beingTreated[i]->update();
            if (beingTreated[i]->healed() == false) {
                doctors[i].treat(beingTreated[i]);
            } else {
                beingTreated.erase(beingTreated.begin() + i);
                ++healedCount;
            }
            if (beingTreated[i]->dead() == true) {
                beingTreated.erase(beingTreated.begin() + i);
            }
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    for (int i = 0; i < beingTreated.size(); ++i) {
        int x = 880;
        int y = (i +1) * 80;
        beingTreated[i]->draw(x, y);
    }
    for (int i = 0; i < waitingRoom.size(); ++i) {
        int x = 100;
        int y = (i + 1) * 80;
        waitingRoom[i]->draw(x, y);
    }
    for (int i = 0; i < doctors.size(); ++i) {
        int x = 1100;
        int y = (i + 1) * 80;
        doctors[i].draw(x, y);
    }
    ofSetColor(255);
    ofDrawBitmapString("Healed Count: " + ofToString(healedCount), ofGetWidth()/2 - 20, 30);
    ofDrawBitmapString("Death Count: " + ofToString(deathCount), ofGetWidth()/2 - 20, 40);
    ofDrawBitmapString("*Press Spacebar to add doctors.*", ofGetWidth()/4, ofGetHeight()/2 - 10);
    ofDrawBitmapString("*Click to add patients manually*\n(they will come on their own as well).", ofGetWidth()/4, ofGetHeight()/2 + 10);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == ' ') {
        Doctor doctor;
        doctors.push_back(doctor);
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    Patient *patient = new Patient();
    patientPriority.push(patient);
    waitingRoom.push_back(patient);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

