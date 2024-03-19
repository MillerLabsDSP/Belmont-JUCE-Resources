/*
  ==============================================================================

    SignalGenerator.cpp
    Created: 27 Feb 2024 12:56:53pm
    Author:  Zachary Miller

  ==============================================================================
*/

#include "SignalGenerator.h"

void SignalGenerator::prepareToPlay(double sampleRate) {
    if (Fs != sampleRate) {
        Fs = (float) sampleRate; // cast as float
        setAngleChange();
    }
}

void SignalGenerator::process(float *buffer, int numSamples, int channel) {
    for (int n = 0; n < numSamples; n++) {
        float x = buffer[n];
        buffer[n] = processSample(x, channel);
    }
}

float SignalGenerator::processSample(float x, int channel) {
    float y = std::sin(currentAngle[channel]);
    
    currentAngle[channel] += angleChange;
    
    if (currentAngle[channel] > PIx2) {
        currentAngle[channel] -= PIx2;
    }
    
    return y;
}

void SignalGenerator::setFrequency(float freq) {
    if (freq >= 20.f && freq <= 20000.f) {
        freqHz = freq;
        setAngleChange();
    }
}

void SignalGenerator::setAngleChange() {
    angleChange = freqHz * PIx2 / Fs;
}

