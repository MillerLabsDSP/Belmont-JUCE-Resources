/*
  ==============================================================================

    DistortionProcessor.cpp
    Created: 28 Feb 2024 9:21:55pm
    Author:  Zachary Miller

  ==============================================================================
*/

#include "DistortionProcessor.h"
#include "SignalGenerator.h"

// Grab buffer for processing (by ref)
void DistortionProcessor::process(float *buffer, int numSamples, int channel) {
    for (int n = 0; n < numSamples; n++) {
        float x = buffer[n];
        buffer[n] = processSample(x,channel);
    }
}

// Do the effect (to one sample) and return output
float DistortionProcessor::processSample(float x, int channel) {
    float y = x;
    if (y > thresh) {
        y = thresh;
    } else {
        y = y;
    }
    return y;
}

void DistortionProcessor::setThreshold(float threshVal) {
    if (threshVal >= 0 && threshVal <= 1) {
        thresh = threshVal;
    }
}
