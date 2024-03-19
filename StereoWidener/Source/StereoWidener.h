/*
  ==============================================================================

    StereoWidener.h
    Created: 17 Mar 2024 9:46:40pm
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once
#import <JuceHeader.h>

class StereoWidener {
public:
    
    void prepareToPlay(double sampleRate);
    
    void processStereo(float &xL, float &xR, int channel, float W);
    void process(float * buffer, int numSamples, int channel);
    
    void setWidth(float width);
        
private:
    
    float Fs = -1.f;
    float W = 1.f;
    float z = 0.f; // encoding output
    
    std::vector<float> hold; // left channel hold buffer
        
};
