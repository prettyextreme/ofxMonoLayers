#include "ofxMonoLayers.h"


void ofxMonoLayers::draw(int style, int speed){
    
    frame += (float)speed/10;
    
    //rotation += (float)speed/1000;
    
    switch(style){
        case 0:
            drawSimpleCircles(speed);
            break;
        case 1:
            drawSimpleCircles2(speed);
            break;
        case 2:
            drawSimpleCircles3(speed);
            break;
        case 3:
            drawSimpleCircles4(speed);
            break;
        case 4:
            drawSimpleCircles5(speed);
            break;
    }
}

void ofxMonoLayers::drawSimpleCircles(int speed){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    glRotatef(0.1*noise.noise(frame/1000.0f)*180,0,0,1);
    for(int r = ofGetWidth()*0.4;r>50;r-=5){
        glRotatef(frame/2.0f+0.2*noise.noise(frame/5000.0f)*180,0,0,1);
        float theta = 0;//PI * noise.noise(frame/30.0+r*10);
        ofDrawRadialSegment(true, 64, r-7, r, theta, theta+1, 0);
        //ofPopMatrix();
    }
    
    ofPopMatrix();
    
}

void ofxMonoLayers::drawSimpleCircles2(int speed){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    glRotatef(0.1*noise.noise(frame/1000.0f)*180,0,0,1);
    for(int r = ofGetWidth()*0.4;r>ofGetHeight()*0.4;r-=5){
        glRotatef(frame/2.0f+0.2*noise.noise(frame/5000.0f)*180,0,0,1);
        float theta = PI * noise.noise(frame/30.0+r*10);
        ofDrawRadialSegment(true, 64, r-7, r, theta, theta+1, 0);    }
    
    ofPopMatrix();
    
}

void ofxMonoLayers::drawSimpleCircles3(int speed){
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    glRotatef(0.1*noise.noise(frame/1000.0f)*180,0,0,1);
    float innerRad = ofGetHeight()*0.3;
    float outerRad = ofGetHeight()*0.6;
    for(int r = 0;r<100;r++){
        glRotatef(frame/20.0f+0.2*noise.noise(frame/5000.0f)*180,0,0,1);
        float theta = PI * noise.noise(frame/3000.0+r*10);
        ofDrawRadialSegment(true, 2, innerRad, outerRad, theta, theta+0.01, 0);    }
    
    ofPopMatrix();
    
}

void ofxMonoLayers::drawSimpleCircles4(int speed){
    
    static float rotation = 0;
    rotation += (float)speed/1000;
    modRotation(rotation);
    
    static float myFrame = 0;
    myFrame += (float)speed/500.0f;
    myFrame = negSafeModf(myFrame, 1000.0f);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    glRotatef(noiseLoop(myFrame, 1000)*180.0f,0,0,1);
    float innerRad = ofGetHeight()*0.3;
    float outerRad = ofGetHeight()*0.6;
    for(int r = 0;r<32;r++){
        //glRotatef(frame/20.0f+0.2*noise.noise(frame/5000.0f)*180,0,0,1);
        float theta = TWO_PI * r / 32;// * noise.noise(frame/3000.0+r*10);
        float mf = myFrame + 0.1*r;
        mf = negSafeModf(mf, 1000);
        float offset = 100.0f*noiseLoop(mf, 1000);
        ofDrawRadialSegment(true, 2, innerRad-offset, outerRad+offset, theta, theta+0.1, 0);
    }
    
    ofPopMatrix();
    
}

void ofxMonoLayers::drawSimpleCircles5(int speed){
    static float rotation = 0;
    rotation += (float)speed/1000;
    modRotation(rotation);
    
    static float myFrame = 0;
    myFrame += (float)speed/5;
    myFrame = negSafeModf(myFrame, 360);
    
    static float myFrame2 = 0;
    myFrame2 += (float)speed/477.0f;
    myFrame2 = negSafeModf(myFrame2, TWO_PI);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
    glRotatef(myFrame,0,0,1);
    float innerRad = ofGetHeight()*0.5;
    float outerRad = innerRad+50;
    for(int r = 0;r<=32;r++){
        float theta = PI * r / 32;
        
        float mf = myFrame + 0.1*r;
        mf = negSafeModf(mf, 1000);
        //float offset = 100.0f*noiseLoop(mf, 1000);
        ofDrawRadialSegment(true, 2, innerRad, outerRad, theta, theta+0.02, 0);
    }
    
    ofDrawRadialSegment(true, 2, innerRad-20, innerRad+20, myFrame2, myFrame2+PI, 0);
    ofDrawRadialSegment(true, 2, innerRad-60, innerRad-20, myFrame2*2, myFrame2*2-PI, 0);
    ofDrawRadialSegment(true, 2, innerRad-100, innerRad-60, myFrame2*3+PI/8, myFrame2*3-PI+PI/8, 0);
    
    
    
    ofPopMatrix();
    
}


float ofxMonoLayers::noiseLoop(float x, float loopAt){
    if(x<0)
        x = loopAt - fmod(-x,loopAt);
    x = fmod(x, loopAt);
    
    x = negSafeModf(x, loopAt);
    float retval = ofMap(x,0,loopAt,1,0)*noise.noise(x)+ofMap(x,0,loopAt,0,1)*noise.noise(-loopAt+x);
    return retval;
}

float ofxMonoLayers::negSafeModf(float f, float mod){
    if(f<0)
        f = mod - fmod(-f,mod);
    return fmod(f, mod);
}