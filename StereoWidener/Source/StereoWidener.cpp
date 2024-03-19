/*
  ==============================================================================

    StereoWidener.cpp
    Created: 17 Mar 2024 9:46:40pm
    Author:  Zachary Miller

  ==============================================================================
*/

#include "StereoWidener.h"

void StereoWidener::prepareToPlay(double sampleRate) {
    if (Fs != sampleRate) {
        Fs = (float) sampleRate;
    }
}

float StereoWidener::processStereo(float &xL, float &xR, int channel, float W) {

    float y = x;

    return y;
}

void StereoWidener::process(float * buffer, int numSamples, int channel) {
    for (int n = 0; n < numSamples; n++) {
    }
}

void StereoWidener::setWidth(float width) {
    if (width >= 0 || width <= 2) {
        W = width;
    }
}
