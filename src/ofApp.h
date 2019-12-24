#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
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
		
		void colorReset();

		static const int num = 100;

		glm::vec2 loc[num];
		glm::vec2 vel[num];
		float circlesize[num];
		float colorR[num];
		float colorB[num];
		glm::vec2 rectpos;
		float rectsize;
		float rectcolorR;

		float rectcolorG;

		//float circleSize;
};
