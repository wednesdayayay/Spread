#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
  
    ofGLESWindowSettings settings;
    settings.glesVersion=2;
    settings.setSize(720,480);
    //settings.windowMode = OF_WINDOW;
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
}
