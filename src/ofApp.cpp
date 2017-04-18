#include "ofApp.h"
#include <iostream>
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetFullscreen(1);
    particleNumber = 20000;
    upperLimit = 10000;
    lowerLimit = 100;
    mouseMass = 200;
    gravityConstant = 3;
    particleMass = 5;
    increment = 1;
    for(int ii = 0; ii < particleNumber; ii++)
    {
            ofVec2f randPos;
            randPos.x = ofRandom(10, ofGetWindowWidth()-10);
            randPos.y = ofRandom(10, ofGetWindowHeight()-10);
            ofColor color(ofRandom(50), ofRandom(50), ofRandom(100, 255), ofRandom(100, 200));
            basicParticle atest(randPos, particleMass, 255, color);


            test.push_back(atest);
    }

}

//--------------------------------------------------------------
void ofApp::update(){
ofVec2f updraft(0, -50);
    for(int ii = 0; ii < test.size(); ii++)
    {
        ofVec2f force = mousePosition - test[ii].location;
        float d2 = force.lengthSquared();
        if(d2 < lowerLimit)
        {
            d2 = lowerLimit;
        }
        if(d2 > upperLimit)
        {
            d2 = upperLimit;
        }
        force.normalize();
        float mag = (gravityConstant * mouseMass * test[ii].mass)/(d2);
        force *= mag;
        test[ii].addForce(force);
        //test[ii].addForce(updraft);
        if(test[ii].location.y <= 10 ||
           test[ii].location.y >= ofGetWindowHeight())
        {
            test[ii].velocity.y *= -1;
        }
        if(test[ii].location.x <= 10 ||
           test[ii].location.x >= ofGetWindowWidth()-10)
        {
            test[ii].velocity.x *= -1;
        }
        test[ii].velocity.limit(10);
        test[ii].update();
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int ii = 0; ii < test.size(); ii++)
    {

        test[ii].draw();
    }
    ofSetColor(0, 100, 200);
    ofDrawBitmapString("Space to reset, shift to increase increment. Increment: " + ofToString(increment), 10, 20);
    ofDrawBitmapString("1(Q, A, Z)Gravity Coefficient: "+ofToString(gravityConstant), 10, 40);
    ofDrawBitmapString("2(W, S)#of Particles: " + ofToString(particleNumber), 10, 60);
    ofDrawBitmapString("1(E, D)Particle Mass: " + ofToString(particleMass), 10, 80);
    ofDrawBitmapString("5(R, F)Upper Limit: " + ofToString(upperLimit), 10, 100);
    ofDrawBitmapString("2(T, G)Lower Limit: " + ofToString(lowerLimit), 10, 120);
    ofDrawBitmapString("FPS: " + ofToString(ofGetFrameRate()), 10, 140);
    ofSetColor(200, 100, 0, 100);
    ofCircle(mousePosition.x, mousePosition.y, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 32)
    {
        test.clear();
        for(int ii = 0; ii < particleNumber; ii++)
        {
            ofVec2f randPos;
            randPos.x = ofRandom(ofGetWindowWidth());
            randPos.y = ofRandom(ofGetWindowHeight());
            ofColor color(ofRandom(100, 255), ofRandom(50), ofRandom(50), ofRandom(100, 200));
            basicParticle atest(randPos, particleMass, 255, color);


            test.push_back(atest);
        }
    }
    else if(key == 113)
    {
        gravityConstant+= increment;
    }
    else if(key == 97)
    {
        gravityConstant-= increment;
    }
    else if(key == 122)
    {
        gravityConstant *= -1;
    }
    else if(key == 101)
    {
        particleMass+= increment;
    }
    else if(key == 100)
    {
        particleMass-= increment;
    }
    else if(key == 114)
    {
        upperLimit+= increment* 20;
    }
    else if(key == 146)
    {
        upperLimit-= increment * 20;
    }
    else if(key == 116)
    {
        lowerLimit+= increment;
    }
    else if(key == 113)
    {
        lowerLimit-= increment;
    }
    else if(key = 119)
    {
        particleNumber+= increment * 100;
    }
    else if(key == 115)
    {
        particleNumber-= increment * 100;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePosition.y = y;
    mousePosition.x = x;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
