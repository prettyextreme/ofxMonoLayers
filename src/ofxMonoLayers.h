#ifndef ___MONOLAYERS__
#define ___MONOLAYERS__

#include "ofMain.h"

#include "ofxPerlin.h"
#include "ofxPrettyExtremeUtils.h"

class ofxMonoLayers
{
public:
    ofxMonoLayers(){
        frame = 0;
    }
    ~ofxMonoLayers(){}
    
    void draw(int style, int speed);
    
    void drawSimpleCircles(int speed);
    void drawSimpleCircles2(int speed);
    void drawSimpleCircles3(int speed);
    void drawSimpleCircles4(int speed);
    void drawSimpleCircles5(int speed);

private:
    double frame;
    
    ofxPerlin noise;
    
    void modRotation(float& rotation){
        while(rotation>TWO_PI)
            rotation -= TWO_PI;
        while(rotation<0)
            rotation += TWO_PI;
    }
    
    float noiseLoop(float x, float loopAt);
    
    float negSafeModf(float f, float mod);

};

#endif