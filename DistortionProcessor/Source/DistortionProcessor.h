/*
  ==============================================================================

    DistortionProcessor.h
    Created: 28 Feb 2024 9:21:55pm
    Author:  Zachary Miller

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class DistortionProcessor {
public:
    
//    void prepareToPlay(double sampleRate);
    void process(float *buffer, int numSamples, int channel);
    float processSample(float x, int channel);
    void setThreshold(float threshVal);
    
private:
    
    float Fs = -1.f;
    float thresh = 1.f; // [0 (inf clip) - 1 (no dist)]
    
};
