/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
StereoWidenerAudioProcessorEditor::StereoWidenerAudioProcessorEditor (StereoWidenerAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Bounds
    setSize (500, 500);
    
    // Main stereo widening knob
    widenerSlider.setBounds(100,100,300,300);
    widenerSlider.setRange(0,2);
    widenerSlider.setValue(1.f);
    widenerSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    widenerSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 30);
    addAndMakeVisible(widenerSlider);
    widenerSlider.addListener(this);
}

StereoWidenerAudioProcessorEditor::~StereoWidenerAudioProcessorEditor()
{
}

//==============================================================================
void StereoWidenerAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (20.f);
    g.drawFittedText ("Stereo Widener", getLocalBounds(), juce::Justification::centredTop, 1);
}

void StereoWidenerAudioProcessorEditor::resized() {

}

void StereoWidenerAudioProcessorEditor::sliderValueChanged(juce::Slider * slider) {
    if (slider == &widenerSlider) {
        audioProcessor.width = widenerSlider.getValue();
    }
}
