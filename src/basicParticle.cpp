#include "ofMain.h"
#include "basicParticle.h"

basicParticle::basicParticle(ofVec2f pos, int r, int l, ofColor c)
{
    location = pos;
    velocity.x = 0.f;
    velocity.y = 0.f;
    acceleration.x = 0.f;
    acceleration.y = 0.f;
    radius = r;
    lifespan = l;
    mass = r*r*3.1415;
    color = c;

}
void basicParticle::update()    //returns false if lifespan is greater than 0
{
    velocity += acceleration;
    location += velocity;
    acceleration -= acceleration;
    //lifespan-=2;
}

void basicParticle::draw()
{
    ofSetColor(color);
    ofFill();
    ofCircle(location.x, location.y, radius);
}

void basicParticle::addForce(ofVec2f force)
{
    acceleration += (force/mass);
}

