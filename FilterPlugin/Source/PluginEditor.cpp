/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
FilterPluginAudioProcessorEditor::FilterPluginAudioProcessorEditor (FilterPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Bounds
    setSize (600, 350);
    
    // Frequency slider
    freqSlider.setBounds(0, 75, 200, 200);
    freqSlider.setRange(20, 20000);
    freqSlider.setSkewFactorFromMidPoint(1000);
    freqSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    freqSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(freqSlider);
    freqSlider.addListener(this); // "this" being the class we are in
    
    // Resonance (Q) slider
    qSlider.setBounds(200, 75, 200, 200);
    qSlider.setRange(0, 10);
    qSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    qSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(qSlider);
    qSlider.addListener(this); // "this" being the class we are in
    
    // Amplitude slider
    ampSlider.setBounds(400, 75, 200, 200);
    ampSlider.setRange(-15.f, 15.f);
    ampSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    ampSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 75, 25);
    addAndMakeVisible(ampSlider);
    ampSlider.addListener(this); // "this" being the class we are in
    ampSlider.setEnabled(false);
    
    // Combo Box
    filterSelection.setBounds(200, 295, 200, 25);
    filterSelection.addItem("LPF",1);
    filterSelection.addItem("HPF",2);
    filterSelection.addItem("BPF",3);
    filterSelection.addItem("High Shelf",4);
    filterSelection.addItem("Low Shelf",5);
    filterSelection.addItem("Peak",6);
    filterSelection.setText("Select Filter Type...");
    addAndMakeVisible(filterSelection);
    filterSelection.addListener(this);
    
    // Bypass button
    bypassButton.setBounds(515, 275, 100, 100);
    bypassButton.setButtonText("Bypass");
    bypassButton.setToggleState(false,juce::dontSendNotification);
    addAndMakeVisible(bypassButton);
    bypassButton.addListener(this);
}

FilterPluginAudioProcessorEditor::~FilterPluginAudioProcessorEditor()
{
}

//==============================================================================
void FilterPluginAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    g.fillAll (juce::Colour (41, 42, 47));

    g.setColour(juce::Colours::white);
    g.setFont (24.f);
    g.drawFittedText ("1-Band EQ", getLocalBounds(), juce::Justification::centredTop, 1);
    
    g.setFont(18.f);
    g.drawText ("Frequency", 60, 40, 80, 30, juce::Justification::left, false);
    
    g.setFont(18.f);
    g.drawText ("Q", 260, 40, 80, 30, juce::Justification::centred, false);
    
    g.setFont(18.f);
    g.drawText ("Amplitude", 460, 40, 80, 30, juce::Justification::right, false);
}

void FilterPluginAudioProcessorEditor::resized()
{

}

void FilterPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider) {
    if (slider == &freqSlider) {
        audioProcessor.filterFrequency = freqSlider.getValue();
    }
    
    if (slider == &qSlider) {
        audioProcessor.filterQ = qSlider.getValue();
    }
    
    if (slider == &ampSlider) {
        audioProcessor.filterQ = ampSlider.getValue();
    }
    
}

void FilterPluginAudioProcessorEditor::comboBoxChanged(juce::ComboBox *comboBox) {
 
    if (comboBox == &filterSelection) {
        if (filterSelection.getSelectedId() == 1) {
            audioProcessor.filterType = Biquad::FilterType::LPF;
            ampSlider.setEnabled(false);
        }
        if (filterSelection.getSelectedId() == 2) {
            audioProcessor.filterType = Biquad::FilterType::HPF;
            ampSlider.setEnabled(false);
        }
        if (filterSelection.getSelectedId() == 3) {
            audioProcessor.filterType = Biquad::FilterType::BPF1;
            ampSlider.setEnabled(false);
        }
        if (filterSelection.getSelectedId() == 4) {
            audioProcessor.filterType = Biquad::FilterType::HSHELF;
            ampSlider.setEnabled(true);
        }
        if (filterSelection.getSelectedId() == 5) {
            audioProcessor.filterType = Biquad::FilterType::LSHELF;
            ampSlider.setEnabled(true);
        }
        if (filterSelection.getSelectedId() == 6) {
            audioProcessor.filterType = Biquad::FilterType::PEAK;
            ampSlider.setEnabled(true);
        }
    }
}

void FilterPluginAudioProcessorEditor::buttonClicked(juce::Button *button) {
    if (button == &bypassButton) {
        audioProcessor.bypass = bypassButton.getToggleState();
    }
}
