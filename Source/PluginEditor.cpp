/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "JuceHeader.h"

//==============================================================================
TokyoRe_verbAudioProcessorEditor::TokyoRe_verbAudioProcessorEditor (TokyoRe_verbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true);
    setSize (700, 394);
    
    filterCutoffDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    filterCutoffDial.setSize(80, 80);
    
    // dont change these two
    filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
    filterResDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterResDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    filterResDial.setSize(80, 80);
    
    // dont change these two
    filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
    // dont change these two
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "cutoff", filterCutoffDial);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "resonance", filterResDial);
    
    filterCutoffDial.setLookAndFeel(&otherLookAndFeel);
    filterResDial.setLookAndFeel(&otherLookAndFeel);
    
    //addAndMakeVisible(filterCutoffLabel);
    mixLabel.attachToComponent(&filterCutoffDial, false);
    
    addAndMakeVisible(filterResLabel);
    filterResLabel.attachToComponent(&filterResDial, false);
    
    reverbMixDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    reverbMixDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbMixDial.setSize(80, 80);
    
    // dont change these two
    reverbMixDial.addListener(this);
    addAndMakeVisible(reverbMixDial);
    
    reverbRoomDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    reverbRoomDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbRoomDial.setSize(80, 80);
    
    // dont change these two
    reverbRoomDial.addListener(this);
    addAndMakeVisible(reverbRoomDial);
    
    reverbDampDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    reverbDampDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbDampDial.setSize(80, 80);

    // dont change these two
    reverbDampDial.addListener(this);
    addAndMakeVisible(reverbDampDial);
    
    reverbWidthDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	reverbWidthDial.setSize(80, 80);
	reverbWidthDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    
	// dont change these two
    reverbWidthDial.addListener(this);
    addAndMakeVisible(reverbWidthDial);
    
    //reverbDryValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "dry", reverbDryDial);
    //reverbWetValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "wet", reverbWetDial);
    reverbMixValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "mix", reverbMixDial);
    reverbRoomValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "room", reverbRoomDial);
    reverbDampValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "damp", reverbDampDial);
    reverbWidthValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "width", reverbWidthDial);

    reverbMixDial.setLookAndFeel(&otherLookAndFeel);
    reverbRoomDial.setLookAndFeel(&otherLookAndFeel);
    reverbDampDial.setLookAndFeel(&otherLookAndFeel);
    reverbWidthDial.setLookAndFeel(&otherLookAndFeel);
    
    addAndMakeVisible(reverbMixLabel);
    reverbMixLabel.attachToComponent(&reverbMixDial, false);
    
    addAndMakeVisible(reverbRoomLabel);
    reverbRoomLabel.attachToComponent(&reverbRoomDial, false);
    
    addAndMakeVisible(reverbDampLabel);
    reverbDampLabel.attachToComponent(&reverbDampDial, false);
    
    addAndMakeVisible(reverbWidthLabel);
    reverbWidthLabel.attachToComponent(&reverbWidthDial, false);
    

    
}

TokyoRe_verbAudioProcessorEditor::~TokyoRe_verbAudioProcessorEditor()
{
}

//==============================================================================
void TokyoRe_verbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our plugin background is opaque, so we must completely fill the background with a solid colour or image)
    
    Image background = ImageCache::getFromMemory(BinaryData::KanekiWing_png, BinaryData::KanekiWing_pngSize);
    g.drawImageAt(background, 0, 0);
 
}

void TokyoRe_verbAudioProcessorEditor::resized()
{
	//area where you progam the position of the sliders 

	filterCutoffDial.setBounds(53, getHeight() - 113, 80, 80);
	filterResDial.setBounds(158, getHeight() - 113, 80, 80);
  
	reverbWidthDial.setBounds(258, getHeight() - 113, 80, 80);
    reverbRoomDial.setBounds(358, getHeight()-113, 80, 80);
    reverbDampDial.setBounds(458, getHeight()-113, 80, 80);
	reverbMixDial.setBounds(568, getHeight() - 113, 80, 80);
}

void TokyoRe_verbAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
    if (slider == &mixSlider)
    {
        // dont change any of this void function
        // get the value on the current slider, pass to audio processor
        processor.mixLevel.setTargetValue(mixSlider.getValue());
        
    }
    
    /*if (slider == &filterCutoffDial)
     {
     
     // get the value on the current slider, pass to audio processor
     processor.freqLevel.setTargetValue(filterCutoffDial.getValue());
     
     }
     
     if (slider == &filterResDial)
     {
     
     // get the value on the current slider, pass to audio processor
     processor.resLevel.setTargetValue(filterResDial.getValue());
     
     }*/
    
}
