#pragma once
#include "ofMain.h"
#include "Patient.hpp"
#include "Doctor.hpp"
#include <vector>
#include <queue>

class ofApp : public ofBaseApp{

	public:
		
        std::priority_queue<Patient*, std::vector<Patient*>, Patient::Comparator> patientPriority;
        vector<Patient*> waitingRoom;
        vector<Doctor> doctors;
        vector<Patient*> beingTreated;
    
    
        int deathCount;
        int healedCount;

        void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
