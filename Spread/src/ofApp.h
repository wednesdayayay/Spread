#pragma once

#include "ofMain.h"
//#include "ofxGui.h"
#include "ofxMidi.h"


class ofApp : public ofBaseApp, public ofxMidiListener{
    
public:
    void setup();
    void update();
    void draw();
     void keyPressed(int key);
    
    void newMidiMessage(ofxMidiMessage& message);
    
    
    ofxMidiIn midiIn;
    std::vector<ofxMidiMessage> midiMessages;
    std::size_t maxMessages = 10; //< max number of messages to keep track of
    
    
    /*
     ofxPanel gui;
     ofParameter <ofVec3f> uiColor;
     ofParameter <float> uiThreshold;
     
     
     ofParameter <ofVec3f> uiColor2;
     ofParameter <float> uiThreshold2;
     ofParameter <float> uispread;
     
     
     ofParameter <ofVec3f> uiColor3;
     ofParameter <float> uiThreshold3;
     
     
     ofParameter <ofVec3f> uiColor4;
     ofParameter <float> uiThreshold4;
     
     
     ofParameter <ofVec3f> uiColor5;
     ofParameter <float> uiThreshold5;
     
     
     ofParameter <ofVec3f> uiColor6;
     ofParameter <float> uiThreshold6;
     
     ofParameter <ofVec3f> uiColor7;
     ofParameter <float> uiThreshold7;
     */
    
    ofShader shader;
    ofShader shader2;
    ofShader shader3;
    ofShader shader4;
    ofShader shader5;
    ofShader shader6;
    ofShader shader7;
    ofShader colorize;
    
    
    ofVideoGrabber cam;
    
    
    ofFbo fbo1;
    ofFbo fbo2;
    ofFbo fbo3;
    ofFbo fbo4;
    ofFbo fbo5;
    ofFbo fbo6;
    ofFbo fbo7;
    ofFbo fbo8;
    
    
    int W = 340;
    int H = 480;
    
    
    float spread = .1;
    
    int randomalpha = 255;
    bool randomizealpha = false;
    int slowmo = 0;
    
    int random1 = 255;
    int random2 = 255;
    int random3 = 255;
    int random4 = 255;
    int random5 = 255;
    int random6 = 255;
    int random7 = 255;
    
    
    ofVec3f color1;
    ofVec3f color2;
    ofVec3f color3;
    ofVec3f color4;
    ofVec3f color5;
    ofVec3f color6;
    ofVec3f color7;
    
    
    
    //initial channel should be black or white
    float r1 = 1.0;
    float g1 = 1.0;
    float b1 = 1.0;
    
    float r2 = 1.0;
    float g2 = 0.0;
    float b2 = 0.0;
    
    float r3 = 1.0;
    float g3 = .648;
    float b3 = 0.0;
    
    float r4 = 1.0;
    float g4 = 1.0;
    float b4 = 0.0;
    
    float r5 = 0.0;
    float g5 = 1.0;
    float b5 = 0.0;
    
    float r6 = 0.0;
    float g6 = 0.0;
    float b6 = 1.0;
    
    float r7 = 0.29;
    float g7 = 0.0;
    float b7 = .51;
    
    bool colorizestate = false;
    
    float spreadall = .5;
    
    //float threshold1 = 1.5;
    float threshold2 = 0.0;
    float threshold3 = 0.025;
    float threshold4 = 0.09;
    float threshold5 = 0.75;
    float threshold6 = 0.830;
    float threshold7 = 0.715;
    
    bool thresholdstate = true;
     //bool thresholdstate = false;
    float thresholdall = 1.0;
    float thresholdmain = 1.5;
    int slowmoint = 0;
};










