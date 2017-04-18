#pragma once
#include "ofMain.h"

class basicParticle
{
public:
    basicParticle(ofVec2f, int, int, ofColor);
    ofVec2f location;
    ofVec2f velocity;
    ofVec2f acceleration;
    int radius;
    float mass;
    int lifespan;
    ofColor color;
    void update();
    void draw();
    void addForce(ofVec2f);
};
