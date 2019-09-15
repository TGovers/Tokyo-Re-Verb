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
    setSize (540, 450);
    
    filterCutoffDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    filterCutoffDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    filterCutoffDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterCutoffDial.setNumDecimalPlacesToDisplay(0);
    filterCutoffDial.setSize(150, 100);
    //filterCutoffDial.setRange(20.0, 20000.0);
    filterCutoffDial.setTextValueSuffix("hz");
    //filterCutoffDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
    filterResDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 50,30);
    filterResDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    filterResDial.setSliderStyle(Slider::SliderStyle::Rotary);
    filterResDial.setSize(150, 100);
    //filterResDial.setRange(1.0, 5.0);
    filterResDial.setTextValueSuffix("Q");
    //filterResDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    filterResDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    
    // dont change these two
    filterResDial.addListener(this);
    addAndMakeVisible(filterResDial);
    
    // dont change these two
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "cutoff", filterCutoffDial);
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "resonance", filterResDial);
    
    filterCutoffDial.setSkewFactorFromMidPoint(1000.0f);
    
    filterCutoffDial.setLookAndFeel(&otherLookAndFeel2);
    filterResDial.setLookAndFeel(&otherLookAndFeel2);
    
    //addAndMakeVisible(filterCutoffLabel);
    // filterCutoffLabel.setText("Cutoff Freq", dontSendNotification);
    mixLabel.attachToComponent(&filterCutoffDial, false);
    
    addAndMakeVisible(filterResLabel);
    //filterResLabel.setText("Q", dontSendNotification);
    filterResLabel.attachToComponent(&filterResDial, false);
    
    /*reverbDryDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    reverbDryDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    reverbDryDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    reverbDryDial.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbDryDial.setNumDecimalPlacesToDisplay(0);
    reverbDryDial.setSize(150, 100);
    reverbDryDial.setTextValueSuffix("%");

    // dont change these two
    reverbDryDial.addListener(this);
    addAndMakeVisible(reverbDryDial);
    
    reverbWetDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    reverbWetDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    reverbWetDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    reverbWetDial.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbWetDial.setNumDecimalPlacesToDisplay(0);
    reverbWetDial.setSize(150, 100);
    reverbWetDial.setTextValueSuffix("%");
    
    // dont change these two
    reverbWetDial.addListener(this);
    addAndMakeVisible(reverbWetDial);*/
    
    reverbMixDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    reverbMixDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    reverbMixDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    reverbMixDial.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbMixDial.setNumDecimalPlacesToDisplay(0);
    reverbMixDial.setSize(150, 100);
    reverbMixDial.setTextValueSuffix("%");
    
    // dont change these two
    reverbMixDial.addListener(this);
    addAndMakeVisible(reverbMixDial);
    
    reverbRoomDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    reverbRoomDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    reverbRoomDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    reverbRoomDial.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbRoomDial.setNumDecimalPlacesToDisplay(0);
    reverbRoomDial.setSize(150, 100);
    reverbRoomDial.setTextValueSuffix("%");
    
    // dont change these two
    reverbRoomDial.addListener(this);
    addAndMakeVisible(reverbRoomDial);
    
    reverbDampDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    reverbDampDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    reverbDampDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    reverbDampDial.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbDampDial.setNumDecimalPlacesToDisplay(0);
    reverbDampDial.setSize(150, 100);
    reverbDampDial.setTextValueSuffix("%");
    
    // dont change these two
    reverbDampDial.addListener(this);
    addAndMakeVisible(reverbDampDial);
    
    reverbWidthDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    reverbWidthDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    reverbWidthDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    reverbWidthDial.setSliderStyle(Slider::SliderStyle::Rotary);
    reverbWidthDial.setNumDecimalPlacesToDisplay(0);
    reverbWidthDial.setSize(150, 100);
    reverbWidthDial.setTextValueSuffix("%");
    
    // dont change these two
    reverbWidthDial.addListener(this);
    addAndMakeVisible(reverbWidthDial);
    
    //reverbDryValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "dry", reverbDryDial);
    //reverbWetValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "wet", reverbWetDial);
    reverbMixValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "mix", reverbMixDial);
    reverbRoomValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "room", reverbRoomDial);
    reverbDampValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "damp", reverbDampDial);
    reverbWidthValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "width", reverbWidthDial);
    
    //reverbDryDial.setLookAndFeel(&otherLookAndFeel3);
    //reverbWetDial.setLookAndFeel(&otherLookAndFeel3);
    reverbMixDial.setLookAndFeel(&otherLookAndFeel3);
    reverbRoomDial.setLookAndFeel(&otherLookAndFeel2);
    reverbDampDial.setLookAndFeel(&otherLookAndFeel2);
    reverbWidthDial.setLookAndFeel(&otherLookAndFeel2);
    
    //addAndMakeVisible(reverbDryLabel);
    //reverbDryLabel.attachToComponent(&reverbDryDial, false);
    
    //addAndMakeVisible(reverbWetLabel);
    //reverbWetLabel.attachToComponent(&reverbWetDial, false);
    
    addAndMakeVisible(reverbMixLabel);
    reverbMixLabel.attachToComponent(&reverbMixDial, false);
    
    addAndMakeVisible(reverbRoomLabel);
    reverbRoomLabel.attachToComponent(&reverbRoomDial, false);
    
    addAndMakeVisible(reverbDampLabel);
    reverbDampLabel.attachToComponent(&reverbDampDial, false);
    
    addAndMakeVisible(reverbWidthLabel);
    reverbWidthLabel.attachToComponent(&reverbWidthDial, false);
    
    
    /*
    distDriveDial.setSliderStyle(Slider::SliderStyle::Rotary);
    distDriveDial.setSize(150, 100);
    //distDriveDial.setRange(20.0, 20000.0);
    distDriveDial.setTextValueSuffix("%");
    //distDriveDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distDriveDial.addListener(this);
    addAndMakeVisible(distDriveDial);
    
    distRangeDial.setSliderStyle(Slider::SliderStyle::Rotary);
    distRangeDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    distRangeDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    distRangeDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    
    distRangeDial.setSize(150, 100);
    //distRangeDial.setRange(20.0, 20000.0);
    distRangeDial.setTextValueSuffix("f");
    //distRangeDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distRangeDial.addListener(this);
    addAndMakeVisible(distRangeDial);
    
    distBlendDial.setSliderStyle(Slider::SliderStyle::Rotary);
    distBlendDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    distBlendDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    distBlendDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    distBlendDial.setNumDecimalPlacesToDisplay(2);
    distBlendDial.setSize(150, 100);
    //distBlendDial.setRange(20.0, 20000.0);
    distBlendDial.setTextValueSuffix("%");
    
    //distBlendDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distBlendDial.addListener(this);
    addAndMakeVisible(distBlendDial);
    
    distVolumeDial.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    distVolumeDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, true, 100, 30);
    distVolumeDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    distVolumeDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    distVolumeDial.setSize(100, 70);
    //distVolumeDial.setRange(20.0, 20000.0);
    distVolumeDial.setTextValueSuffix("%");
    //distVolumeDial.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::yellowgreen);
    
    // dont change these two
    distVolumeDial.addListener(this);
    addAndMakeVisible(distVolumeDial);
    
    distDriveDial.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxAbove, true, 55, 30);
    distDriveDial.setColour(Slider::ColourIds::textBoxTextColourId, Colours::black);
    distDriveDial.setColour(Slider::ColourIds::textBoxOutlineColourId, Colour());
    distDriveDial.setLookAndFeel(&otherLookAndFeel);
    distRangeDial.setLookAndFeel(&otherLookAndFeel);
    distBlendDial.setLookAndFeel(&otherLookAndFeel);
    distVolumeDial.setLookAndFeel(&otherLookAndFeel3);
    
    
    // dont change these four
    distDriveValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "drive", distDriveDial);
    distRangeValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "range", distRangeDial);
    distBlendValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "blend", distBlendDial);
    distVolumeValue = new AudioProcessorValueTreeState::SliderAttachment (processor.mState, "volume", distVolumeDial);
     */
    
}

TokyoRe_verbAudioProcessorEditor::~TokyoRe_verbAudioProcessorEditor()
{
}

//==============================================================================
void TokyoRe_verbAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    
    /*Image background = ImageCache::getFromMemory(BinaryData::ayaya7_png, BinaryData::ayaya7_pngSize);
    g.drawImageAt(background, 0, 0);*/
    
    g.fillAll (Colours::darkorchid);
    
    // g.setColour (Colours::aqua);
    //g.setFont (15.0f);
    // g.drawFittedText ("GOVERSA2 PLUGIN", getLocalBounds(), Justification::centred, 1);
    
    g.setColour(Colours::black);
    g.setFont(Font ("Arial", 20.0f, Font::italic));
    //g.drawFittedText("Random Test Font! Hi There!", 10, 10, getWidth(), 50,
    //
}

void TokyoRe_verbAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    //mixSlider.setBounds(10, getHeight()-100, 80, 80);
    filterCutoffDial.setBounds(0, getHeight()-130, 80, 80);
    filterResDial.setBounds(100, getHeight()-130, 80, 80);
    
    /*distDriveDial.setBounds(200, getHeight()-130, 80, 80);
    distRangeDial.setBounds(300, getHeight()-130, 80, 80);
    distBlendDial.setBounds(400, getHeight()-130, 80, 80);
    distVolumeDial.setBounds(425, getHeight()-310, 80, 80);*/
    
    //reverbDryDial.setBounds(0, getHeight()-280, 80, 80);
    //reverbWetDial.setBounds(100, getHeight()-280, 80, 80);
    reverbMixDial.setBounds(0, getHeight()-280, 80, 80);
    reverbRoomDial.setBounds(0, getHeight()-450, 80, 80);
    reverbDampDial.setBounds(100, getHeight()-450, 80, 80);
    reverbWidthDial.setBounds(150, getHeight()-450, 80, 80);
    
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
