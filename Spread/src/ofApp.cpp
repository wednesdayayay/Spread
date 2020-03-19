#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetFrameRate(30);
    ofHideCursor();
    
    //ofToggleFullscreen();
    
    cam.setDeviceID(0); //video input
    cam.setDesiredFrameRate(30);
    cam.setup(640,480);
    
    fbo1.allocate(640, 480,GL_RGBA);
    fbo2.allocate(640, 480,GL_RGBA);
    fbo3.allocate(640, 480,GL_RGBA);
    fbo4.allocate(640, 480,GL_RGBA);
    fbo5.allocate(640, 480,GL_RGBA);
    fbo6.allocate(640, 480,GL_RGBA);
    fbo7.allocate(640, 480,GL_RGBA);
    fbo8.allocate(640, 480,GL_RGBA);
    
    
    /////
    
    
    /*
     gui.setup();
     gui.add(uiColor.set("color", ofVec3f(1, 1, 1), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold.set("threshold", 1.5, 0, 1.5));
     
     gui.add(uispread.set("spread", 0.5, 0.003, 0.5));
     
     
     gui.add(uiColor2.set("color2", ofVec3f(1, 0, 0), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold2.set("threshold2", 0.0, 0, 1.5));
     
     
     
     gui.add(uiColor3.set("color3", ofVec3f(1, .648, 0), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold3.set("threshold3", 0.025, 0, 1));
     
     
     gui.add(uiColor4.set("color4", ofVec3f(1, 1, 0), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold4.set("threshold4", 0.09, 0, 1));
     
     
     gui.add(uiColor5.set("color5", ofVec3f(0, 1, 0), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold5.set("threshold5", 0.75, 0, 1));
     
     
     gui.add(uiColor6.set("color6", ofVec3f(0, 0, 1), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold6.set("threshold6", 0.830, 0, 1));
     
     gui.add(uiColor7.set("color7", ofVec3f(.29, 0, .51), ofVec3f(0, 0, 0), ofVec3f(1, 1, 1)));
     gui.add(uiThreshold7.set("threshold7", 0.715, 0, 1));
     
     */
    
    
    shader.load("shader");
    shader2.load("shader2");
    shader3.load("shader3");
    shader4.load("shader4");
    shader5.load("shader5");
    shader6.load("shader6");
    shader7.load("shader7");
    colorize.load("colorize");
    
    
    /////
    
    
    
    fbo1.begin();
    ofClear(0);
    fbo1.end();
    
    fbo2.begin();
    ofClear(0);
    fbo2.end();
    
    fbo3.begin();
    ofClear(0);
    fbo3.end();
    
    fbo4.begin();
    ofClear(0);
    fbo4.end();
    
    fbo5.begin();
    ofClear(0);
    fbo5.end();
    
    fbo6.begin();
    ofClear(0);
    fbo6.end();
    
    fbo7.begin();
    ofClear(0);
    fbo7.end();
    
    fbo8.begin();
    ofClear(0);
    fbo8.end();
    
    
    
    ////MIDI stuff
    midiIn.listInPorts();  // print input ports to console
    //if MIDI isn't working check your device number in the consdole when you first make it change the (0) to whatever your MIDI controller is
    //midiIn.openPort(0); // computer
    midiIn.openPort(1); // RPI
    midiIn.ignoreTypes(false, false, false);
    midiIn.addListener(this);
    midiIn.setVerbose(true); // print received messages to the console
    ////
    
    color1 = ofVec3f(1.0f,1.0f,1.0f);
    color2 = ofVec3f(1.0f,0.0f,0.0f);
    color3 = ofVec3f(1.0f,.648f,0.0f);
    color4 = ofVec3f(1.0f,1.0f,0.0f);
    color5 = ofVec3f(0.0f,1.0f,0.0f);
    color6 = ofVec3f(0.0f,0.0f,1.0f);
    color7 = ofVec3f(.29f,0.0f,.51f);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
   /*
    if(slowmo > 0){
        if (ofGetFrameNum() % slowmo == 0){
            cam.update();}}
    else {cam.update();}
    */
    

    cam.update();
    
    //invert key (white <> black)
    if(ofGetKeyPressed('r')){
        color1 =  1.0 - color1;
    }
    
 
    
    //if(ofGetKeyPressed('k')){if (ofGetFrameNum() % slowmo == 0){randomalpha = ofRandom(255);}}
    
    
     if(ofGetKeyPressed('q')){
    r1 = 1.0;
     g1 = 1.0;
     b1 = 1.0;
     
     r2 = 1.0;
     g2 = 0.0;
     b2 = 0.0;
     
     r3 = 1.0;
     g3 = .648;
     b3 = 0.0;
     
     r4 = 1.0;
     g4 = 1.0;
     b4 = 0.0;
     
     r5 = 0.0;
     g5 = 1.0;
     b5 = 0.0;
     
     r6 = 0.0;
     g6 = 0.0;
     b6 = 1.0;
     
     r7 = 0.29;
     g7 = 0.0;
     b7 = .51;
     
     }
     
     
     
     
     if(colorizestate == true){
     if(slowmo > 0){
     if(ofGetFrameNum() % slowmo * 4 == 0){
     
     r1 = ofRandom(1.);
     g1 = ofRandom(1.);
     b1 = ofRandom(1.);
     
     
     r2 = ofRandom(1.);
     g2 = ofRandom(1.);
     b2 = ofRandom(1.);
     
     
     r3 = ofRandom(1.);
     g3 = ofRandom(1.);
     b3 = ofRandom(1.);
     
     
     r4 = ofRandom(1.);
     g4 = ofRandom(1.);
     b4 = ofRandom(1.);
     
     
     r5 = ofRandom(1.);
     g5 = ofRandom(1.);
     b5 = ofRandom(1.);
     
     
     r6 = ofRandom(1.);
     g6 = ofRandom(1.);
     b6 = ofRandom(1.);
     
     
     r7 = ofRandom(1.);
     g7 = ofRandom(1.);
     b7 = ofRandom(1.);
         
         
         color1 = ofVec3f(r1,g1,b1);
         color2 = ofVec3f(r2,g2,b2);
         color3 = ofVec3f(r3,g3,b3);
         color4 = ofVec3f(r4,g4,b4);
         color5 = ofVec3f(r5,g5,b5);
         color6 = ofVec3f(r6,g6,b6);
         color7 = ofVec3f(r7,g7,b7);
         
            }}}
         
         if(ofGetKeyPressed('g')){
         r1 = ofRandom(1.);
         g1 = ofRandom(1.);
         b1 = ofRandom(1.);
         
         
         r2 = ofRandom(1.);
         g2 = ofRandom(1.);
         b2 = ofRandom(1.);
         
         
         r3 = ofRandom(1.);
         g3 = ofRandom(1.);
         b3 = ofRandom(1.);
         
         
         r4 = ofRandom(1.);
         g4 = ofRandom(1.);
         b4 = ofRandom(1.);
         
         
         r5 = ofRandom(1.);
         g5 = ofRandom(1.);
         b5 = ofRandom(1.);
         
         
         r6 = ofRandom(1.);
         g6 = ofRandom(1.);
         b6 = ofRandom(1.);
         
         
         r7 = ofRandom(1.);
         g7 = ofRandom(1.);
         b7 = ofRandom(1.);
             
             color1 = ofVec3f(r1,g1,b1);
             color2 = ofVec3f(r2,g2,b2);
             color3 = ofVec3f(r3,g3,b3);
             color4 = ofVec3f(r4,g4,b4);
             color5 = ofVec3f(r5,g5,b5);
             color6 = ofVec3f(r6,g6,b6);
             color7 = ofVec3f(r7,g7,b7);
             
         }
     
     
     
  
     
     
     /*
     threshold2 = r2+g2+b2/10.;
     threshold3 = r3+g3+b3/8.;
     threshold4 = r4+g4+b4/6.;
     threshold5 = r5+g5+b5/4.;
     threshold6 = r6+g6+b6/3.;
     threshold7 = r7+g7+b7/2.;
     
     
     
     if(colorizestate == true){
     if(slowmo > 0){
     if(ofGetFrameNum() % slowmo == 0){
     color1 = ofVec3f(r1,g1,b1);
     color2 = ofVec3f(r2,g2,b2);
     color3 = ofVec3f(r3,g3,b3);
     color4 = ofVec3f(r4,g4,b4);
     color5 = ofVec3f(r5,g5,b5);
     color6 = ofVec3f(r6,g6,b6);
     color7 = ofVec3f(r7,g7,b7);
     }}}
      
      */
    
    
    //reset all alpha settings
    if(ofGetKeyPressed('j'))
    {   random1=255;
        random2=255;
        random3=255;
        random4=255;
        random5=255;
        random6=255;
        random7=255;
    }
    
    
    if(ofGetKeyPressed('u'))
    {   random1=ofRandom(2,10);
        random2=ofRandom(6,35);
        random3=ofRandom(12,40);
        random4=ofRandom(20,60);
        random5=ofRandom(15,55);
        random6=ofRandom(8,35);
        random7=ofRandom(5,15);}
    
    
    
    //lighter colors weirder?
    if(ofGetKeyPressed('i'))
    {   random1=ofRandom(20,40);
        random2=ofRandom(30,60);
        random3=ofRandom(20,80);
        random4=ofRandom(30,100);
        random5=ofRandom(60,20);
        random6=ofRandom(20,90);
        random7=ofRandom(23,55);
    }
    
    
    //full range
    if(ofGetKeyPressed('o'))
    {   random1=ofRandom(1, 255);
        random2=ofRandom(1, 255);
        random3=ofRandom(1, 255);
        random4=ofRandom(1, 255);
        random5=ofRandom(1, 255);
        random6=ofRandom(1, 255);
        random7=ofRandom(1, 255);
    }
    
    
    
    if(slowmo > 0){
        if(ofGetFrameNum() % slowmo*4 == 0){
            if(randomizealpha == true){random1 = ofRandom(1, 255);}
            if(randomizealpha == true){random2 = ofRandom(1, 255);}
            if(randomizealpha == true){random3 = ofRandom(1, 255);}
            if(randomizealpha == true){random4 = ofRandom(1, 255);}
            if(randomizealpha == true){random5 = ofRandom(1, 255);}
            if(randomizealpha == true){random6 = ofRandom(1, 255);}
            if(randomizealpha == true){random7 = ofRandom(1, 255);}
        }}
    
    
    //
    
    /*first try threshold
    if(thresholdstate == true){
        threshold2 = thresholdall/2.;
        threshold3 = thresholdall/1.5;
        threshold4 = thresholdall/1.8;
        threshold5 = thresholdall/2.23;
        threshold6 = thresholdall/.75;
        threshold7 = thresholdall/.95;
    }
     */
    
    /*//try 2 working pretty well
    if(thresholdstate == true){
        threshold2 = thresholdall/spreadall - thresholdmain;
        threshold3 = thresholdall/spreadall + .05 - thresholdmain;
        threshold4 = thresholdall/spreadall + .10 - thresholdmain;
        threshold5 = thresholdall/spreadall + .15 - thresholdmain;
        threshold6 = thresholdall/spreadall + .20 - thresholdmain;
        threshold7 = thresholdall/spreadall + .25 - thresholdmain;
    }
     
    
    
    
    if(thresholdstate == true){
        threshold2 = thresholdall/thresholdmain - spreadall;
        threshold3 = thresholdall/thresholdmain - spreadall + .05;
        threshold4 = thresholdall/thresholdmain - spreadall + .10;
        threshold5 = thresholdall/thresholdmain - spreadall + .15;
        threshold6 = thresholdall/thresholdmain - spreadall + .20;
        threshold7 = thresholdall/thresholdmain - spreadall + .25;
    }
    */
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    /*
    //red
    fbo1.begin();
    ofPushStyle();
    ofSetColor(255,0,0, random1);
    //ofSetColor(color1.x,color1.y,color1.z, random1);
    //ofSetColor(r1*255,g1*255,b1*255, random1);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random1%slowmoint+3) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo1.end();
    
    
    //orange
    fbo2.begin();
    ofPushStyle();
    ofSetColor(255,165,0, random2);
    //ofSetColor(r2*255,g2*255,b2*255, random2);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random2%slowmoint+5) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo2.end();
    
    
    //yellow
    fbo3.begin();
    ofPushStyle();
    ofSetColor(255,255,0, random3);
    //ofSetColor(r3*255,g3*255,b3*255, random3);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random3%slowmoint+2) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo3.end();
    
    
    //green
    fbo4.begin();
    ofPushStyle();
    ofSetColor(0,255,0, random4);
    //ofSetColor(r4*255,g4*255,b4*255, random4);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random4%slowmoint+6) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo4.end();
    
    
    //blue
    fbo5.begin();
    ofPushStyle();
    ofSetColor(0,0,255, random5);
    //ofSetColor(r5*255,g5*255,b5*255, random5);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random5%slowmoint+4) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo5.end();
    
    
    //indigo
    fbo6.begin();
    ofPushStyle();
    ofSetColor(75,0,130, random6);
    //ofSetColor(r6*255,g6*255,b6*255, random6);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random6%slowmoint+6) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo6.end();
    
    
    //violet
    fbo7.begin();
    ofPushStyle();
    ofSetColor(238,130,238, random7);
    //ofSetColor(r7*255,g7*255,b7*255, random7);
    if(slowmoint > 0){
        if (ofGetFrameNum() % (random7%slowmoint+2) == 0){
            cam.draw(0,0);}}
    else {cam.draw(0,0);}
    ofPopStyle();
    fbo7.end();
    
    
     //last
     fbo8.begin();
     ofPushStyle();
     colorize.begin();
     colorize.setUniform1f("u_x0", threshold2*15.0);
     colorize.setUniform1f("u_x1", threshold3*3.0);
     colorize.setUniform1f("u_x2", threshold4*3.0);
     colorize.setUniform3f("u_color", color1);
     cam.draw(0,0);
     colorize.end();
     ofPopStyle();
     fbo8.end();
    
    ////////////////////
    ///start drawing///
    ///////////////////
    
    
    
    fbo7.draw(0,0);
    
    /////
    
    shader7.begin();
    //shader7.setUniform3f("u_color7", uiColor7->x, uiColor7->y, uiColor7->z);
    //shader7.setUniform1f("u_threshold7", uiThreshold7);
    //shader7.setUniform1f("u_spread", uispread);
    shader7.setUniform3f("u_color7", .2,.2,.2);
    //shader7.setUniform3f("u_color7", color7);
    shader7.setUniform1f("u_threshold7", threshold7);
    shader7.setUniform1f("u_spread", spreadall);
    fbo6.draw(0,0);
    shader7.end();
    
    ////
    
    shader6.begin();
    //shader6.setUniform3f("u_color6", uiColor6->x, uiColor6->y, uiColor6->z);
    //shader6.setUniform1f("u_threshold6", uiThreshold6);
    //shader6.setUniform1f("u_spread", uispread);
    shader6.setUniform3f("u_color6", .3,.3,.3);
    //shader6.setUniform3f("u_color6", color6);
    shader6.setUniform1f("u_threshold6", threshold6);
    shader6.setUniform1f("u_spread", spreadall);
    fbo5.draw(0,0);
    shader6.end();
    
    /////
    
    shader5.begin();
    //shader5.setUniform3f("u_color5", uiColor5->x, uiColor5->y, uiColor5->z);
    //shader5.setUniform1f("u_threshold5", uiThreshold5);
    //shader5.setUniform1f("u_spread", uispread);
    shader5.setUniform3f("u_color5", .4,.4,.4);
    //shader5.setUniform3f("u_color5", color5);
    shader5.setUniform1f("u_threshold5", threshold5);
    shader5.setUniform1f("u_spread", spreadall);
    fbo4.draw(0,0);
    shader5.end();
    
    ////
    
    shader4.begin();
    //shader4.setUniform3f("u_color4", uiColor4->x, uiColor4->y, uiColor4->z);
    //shader4.setUniform1f("u_threshold4", uiThreshold4);
    //shader4.setUniform1f("u_spread", uispread);
    shader4.setUniform3f("u_color4", .5,.5,.5);
    //shader4.setUniform3f("u_color4",color4);
    shader4.setUniform1f("u_threshold4", threshold4);
    shader4.setUniform1f("u_spread", spreadall);
    fbo3.draw(0,0);
    shader4.end();
    
    /////
    
    shader3.begin();
    
    //shader3.setUniform3f("u_color3", uiColor3->x, uiColor3->y, uiColor3->z);
    //shader3.setUniform1f("u_threshold3", uiThreshold3);
    //shader3.setUniform1f("u_spread", uispread);
    shader3.setUniform3f("u_color3", .6,.6,.6);
    //shader3.setUniform3f("u_color3", color3);
    shader3.setUniform1f("u_threshold3", threshold3);
    shader3.setUniform1f("u_spread", spreadall);
    fbo2.draw(0,0);
    shader3.end();
    
    ///////
    
    shader2.begin();
    //shader2.setUniform3f("u_color2", uiColor2->x, uiColor2->y, uiColor2->z);
    //shader2.setUniform1f("u_threshold2", uiThreshold2);
    //shader2.setUniform1f("u_spread", uispread);
    shader2.setUniform3f("u_color2", .8,.8,.8);
    //shader2.setUniform3f("u_color2", color2);
    shader2.setUniform1f("u_threshold2", threshold2);
    shader2.setUniform1f("u_spread", spreadall);
    fbo1.draw(0,0);
    shader2.end();
  
    ///////
    
    shader.begin();
    //shader.setUniform3f("u_color", uiColor->x, uiColor->y, uiColor->z);
    //shader.setUniform1f("u_threshold", uiThreshold);
    //shader.setUniform3f("u_color", 1,1,1);
    shader.setUniform3f("u_color", color2);
    shader.setUniform1f("u_threshold", thresholdmain);
    //shader.setUniform1f("u_threshold", spreadall);
  
    //fbo8.draw(0,0);
    //cam.draw(0,0);
    
    //shader.end();
       */
    
    /////////
    

    
    colorize.begin();
    colorize.setUniform1f("u_x0", threshold2*15.0);
    colorize.setUniform1f("u_x1", threshold3*3.0);
    colorize.setUniform1f("u_x2", threshold4);
    colorize.setUniform3f("u_color", color1);
    cam.draw(0,0,720,480);
    colorize.end();
    
    
    
    
    ///////
    
  
    
    
    
    /*
    //gui.draw();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 20, 20);
    
    ofDrawBitmapString(ofToString(thresholdall), 20, 40);
    ofDrawBitmapString("thresholdall", 100, 40);
      ofDrawBitmapString(ofToString(thresholdmain), 20, 60);
    ofDrawBitmapString("thesholdmain", 100, 60);
    ofDrawBitmapString(ofToString(spreadall), 20, 80);
    ofDrawBitmapString("spreadall", 100, 80);
    
    
    ///
    
    
    ofDrawBitmapString(ofToString(threshold2), 20, 100);
    ofDrawBitmapString("threshold2", 100, 100);
    ofDrawBitmapString(ofToString(threshold3), 20, 120);
    ofDrawBitmapString("threshold3", 100, 120);
    ofDrawBitmapString(ofToString(threshold4), 20, 140);
    ofDrawBitmapString("threshold4", 100, 140);
    
    ofDrawBitmapString(ofToString(threshold5), 20, 160);
    ofDrawBitmapString("threshold5", 100, 160);
    ofDrawBitmapString(ofToString(threshold6), 20, 180);
    ofDrawBitmapString("threshold6", 100, 180);
    ofDrawBitmapString(ofToString(threshold7), 20, 200);
    ofDrawBitmapString("threshold7", 100, 200);
    
    ///
    
    ofDrawBitmapString(ofToString(color1), 20, 220);
    ofDrawBitmapString(ofToString(random1), 140, 220);
    ofDrawBitmapString("color1", 170, 220);
    
    ofDrawBitmapString(ofToString(color2), 20, 240);
    ofDrawBitmapString(ofToString(random2),140, 240);
    ofDrawBitmapString("color2", 170, 240);
    
    ofDrawBitmapString(ofToString(color3), 20, 260);
    ofDrawBitmapString(ofToString(random3),140, 260);
    ofDrawBitmapString("color3", 170, 260);
    
    ofDrawBitmapString(ofToString(color4), 20, 280);
    ofDrawBitmapString(ofToString(random4),140, 280);
    ofDrawBitmapString("color4", 170, 280);
    
    ofDrawBitmapString(ofToString(color5), 20, 300);
    ofDrawBitmapString(ofToString(random5),140, 300);
    ofDrawBitmapString("color5", 170, 300);
    
    ofDrawBitmapString(ofToString(color6), 20, 320);
    ofDrawBitmapString(ofToString(random6),140, 320);
    ofDrawBitmapString("color6", 170, 320);
    
    ofDrawBitmapString(ofToString(color7), 20, 340);
    ofDrawBitmapString(ofToString(random7),140, 340);
    ofDrawBitmapString("color7", 170, 340);
    */
    
    
}


//--------------------------------------------------------------


void ofApp::keyPressed(int key){



//color value R add Y
if (key == 'q') {thresholdall += .05;}
//color value R subtract U
if (key == 'w') {thresholdall -= .05;}
    
    //color value R add Y
    if (key == 'a') {thresholdmain += .10;}
    //color value R subtract U
    if (key == 's') {thresholdmain -= .10;}
    
    //color value R add Y
    if (key == 'z') {spreadall += .025;}
    //color value R subtract U
    if (key == 'x') {spreadall -= .025;}
    
}
//--------------------------------------------------------------

    
void ofApp::newMidiMessage(ofxMidiMessage& message){
    
    
    
    
    
    if(message.control==120){
        slowmo = (message.value*.1);
        slowmoint = (message.value/127*9+1);
    }
    
    if(message.control==121){spreadall = (message.value/180.);}
    
    
    //-1, 2.5 works nicely//
    if(message.control==122){thresholdall = (message.value/84.66);}
    
    if(message.control==16){thresholdmain = (message.value/44.66);}
    
       if(message.control==17){threshold2 = (message.value/84.66);}
    
       if(message.control==18){threshold3 = (message.value/84.66);}
    
       if(message.control==19){threshold4 = (message.value/84.66);}
    
       if(message.control==20){threshold5 = (message.value/200.66);}
    
       if(message.control==21){threshold6 = (message.value/215.66);}
    
       if(message.control==22){threshold7 = (message.value/280.66);}
    
    
    if(message.control==32){
        if(message.value==127){randomizealpha = true;}
        if(message.value==0){randomizealpha = false;}
    }
    
    if(message.control==64){
        if(message.value==127){colorizestate = true;}
        if(message.value==0){colorizestate = false;}
    }
    
   
    if(message.control==33){
        if(message.value==127){thresholdstate = true;
            //if(thresholdstate == true){
                /*
                threshold2 = thresholdall/20.;
                threshold3 = thresholdall/15.;
                threshold4 = thresholdall/10.;
                threshold5 = thresholdall/4.;
                threshold6 = thresholdall/2.;
                threshold7 = thresholdall/.05;}
                 */
        }
        if(message.value==0){thresholdstate = false;}
    }
    
    
    //invert key (white <> black)
    if(message.control==65){
    if(message.value==127){color1 =  1.0 - color1;}
    if(message.value==0){color1 =  1.0 - color1;}
    }
    
    
    //in order to see in the console what MIDI messages are coming through
    cout << message.control << endl;
    cout << message.value << endl;
    
}


//--------------------------------------------------------------
