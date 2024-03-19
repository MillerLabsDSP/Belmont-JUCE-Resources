/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class StereoWidenerAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                            public juce::Slider::Listener 
{
public:
    StereoWidenerAudioProcessorEditor (StereoWidenerAudioProcessor&);
    ~StereoWidenerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider * slider) override;

private:
    StereoWidenerAudioProcessor& audioProcessor;
    
    juce::Slider widenerSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StereoWidenerAudioProcessorEditor)
};
