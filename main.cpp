// Ryder McDowell
// This program models a triage. A variable number of doctors and patients can be
// inserted, but patients add themselves based on chance and time. Doctors will
// treat patients with the highest priority(severity) until they are healed. If a
// patients life remaining reaches 0, they die.

#include "ofMain.h"
#include "ofApp.h"


int main() {
	ofSetupOpenGL(1280,800,OF_WINDOW);
    ofSeedRandom();
	ofRunApp(new ofApp());
}
