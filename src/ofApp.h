#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "fisheye.h"
#include "ofxVideoRecorder.h"

class ofApp : public ofBaseApp{
    public:
        void setup();
        void update();
        void draw();
        void exit();
        
        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y);
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);

        void audioIn(float * input, int bufferSize, int nChannels);
        void recordingComplete(ofxVideoRecorderOutputFileCompleteEventArgs& args);
        
    private:
        ofxPanel gui;
        fisheye* leftEye;
        fisheye* rightEye;
        ofxVideoRecorder videoRecorder;
        ofSoundStream soundStream;
        
        bool bRecording;
        int sampleRate;
        int channels;
        string fileName;
        string fileExt;
        ofFbo recordFbo;
        ofPixels recordPixels;
};
