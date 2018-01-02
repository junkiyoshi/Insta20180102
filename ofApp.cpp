#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(30);
	ofBackground(255);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {
	int size = 60;
	int tri_size = size * 0.95;
	int y_count = 0;
	int y_max;
	ofColor tri_color;

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	ofRotate(180);
	ofTranslate(-ofGetWidth() / 2, -ofGetHeight() / 2);
	for (int x = 0; x < ofGetWidth() + size / 2; x += size / 2) {
		y_count = 0;
		y_max = ofNoise(x * 0.005, ofGetFrameNum() * 0.025) * ofGetHeight();
		for (int y = 0; y < y_max; y += size) {
			tri_color.setHsb(ofNoise(x, y) * 255, 255, 255);

			if (y + size < y_max) {
				ofSetColor(tri_color);
			} else {
				ofSetColor(0);
			}

			if (x % size == 0) {
				if (y_count % 2 == 0) {
					ofDrawTriangle(ofVec3f(x - tri_size / 2, y), ofVec3f(x + tri_size / 2, y), ofVec3f(x, y + tri_size));
				}else {
					ofDrawTriangle(ofVec3f(x - tri_size / 2, y + tri_size), ofVec3f(x + tri_size / 2, y + tri_size), ofVec3f(x, y));
				}
			} else {
				if (y_count % 2 == 0) {
					ofDrawTriangle(ofVec3f(x - tri_size / 2, y + tri_size), ofVec3f(x + tri_size / 2, y + tri_size), ofVec3f(x, y));
				} else {
					ofDrawTriangle(ofVec3f(x - tri_size / 2, y), ofVec3f(x + tri_size / 2, y), ofVec3f(x, y + tri_size));
				}
			}
			y_count++;
		}
	}
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}