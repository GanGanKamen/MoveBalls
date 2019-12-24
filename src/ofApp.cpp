#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(0);
	for (int i = 0; i < num; i++)
	{
		loc[i] = glm::vec2(ofGetWidth() / 2, ofGetHeight() / 2);
		circlesize[i] = ofRandom(5, 20);
		vel[i] = glm::vec2(ofRandom(100/-circlesize[i], 100/circlesize[i]), ofRandom(100/-circlesize[i], 100/circlesize[i]));
		colorR[i] = 0;
	}
	rectsize = 20;
}

//--------------------------------------------------------------
void ofApp::update(){
	for (int i = 0; i < num; i++)
	{
		loc[i] += vel[i];
		colorB[i] = ofRandom(0, 255);
	}

	rectpos = ofVec2f(mouseX -rectsize/2, mouseY - rectsize / 2);
	rectcolorR = (mouseX + mouseY) * ofRandom(0.01, 0.1);
	rectcolorG = 255;
}

//--------------------------------------------------------------
void ofApp::draw(){
	for (int i = 0; i < num; i++)
	{
		ofSetColor(colorR[i], 0, colorB[i]);
		ofDrawCircle(loc[i], circlesize[i]);
		if (loc[i].x < 0 || loc[i].x > ofGetWidth()) {
			vel[i].x = -vel[i].x;
			
		}
		if (loc[i].y < 0 || loc[i].y> ofGetHeight()) {
			vel[i].y = -vel[i].y;
		}
		if (rectpos.x > loc[i].x) {
			if (rectpos.y > loc[i].y) {
				if (rectpos.x - loc[i].x < (rectsize + circlesize[i]) / 2 &&rectpos.y - loc[i].y <( rectsize+circlesize[i])/2) {
					vel[i].x = -vel[i].x;
					vel[i].y = -vel[i].y;
					colorR[i] = 255;
				}
			}
			else if (rectpos.y < loc[i].y) {
				if (rectpos.x - loc[i].x < (rectsize + circlesize[i]) / 2 &&loc[i].y - rectpos.y < (rectsize + circlesize[i]) / 2) {
					vel[i].x = -vel[i].x;
					vel[i].y = -vel[i].y;
					colorR[i] = 255;
				}
			}
		}
		else if(rectpos.x < loc[i].x)
		{
			if (rectpos.y > loc[i].y) {
				if (loc[i].x - rectpos.x < (rectsize + circlesize[i]) / 2 &&rectpos.y - loc[i].y < (rectsize + circlesize[i]) / 2) {
					vel[i].x = -vel[i].x;
					vel[i].y = -vel[i].y;
					colorR[i] = 255;
				}
			}
			else if (rectpos.y < loc[i].y) {
				if (loc[i].x - rectpos.x  < (rectsize + circlesize[i]) / 2 &&loc[i].y - rectpos.y < (rectsize + circlesize[i]) / 2) {
					vel[i].x = -vel[i].x;
					vel[i].y = -vel[i].y;
					colorR[i] = 255;
				}
			}
		}
		if (colorR[i] > 0) {
			colorR[i] -= 1;
		}
	}

	ofSetColor(rectcolorR, rectcolorG, 0);
	ofDrawRectangle(rectpos, rectsize,rectsize);
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
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
	if (button == 0 && rectsize <= 95) {
		rectsize += 5;
	}
	else if (button == 2 && rectsize >= 15)
	{
		rectsize -= 5;
	}
	else if(button == 1)
	{
		colorReset();
	}
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

void ofApp::colorReset() {
	for (int i = 0; i < num; i++)
	{
		colorR[i] = 0;
	}
}
