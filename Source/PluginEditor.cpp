/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "JuceHeader.h"

AnimatedComponent::AnimatedComponent() {
	currentImage = bg;
}

void AnimatedComponent::paint(juce::Graphics &g)
{
	g.drawImageAt(currentImage, 0, 0);
}


void AnimatedComponent::mouseExit(const juce::MouseEvent &e)  
{
	Point<int> p = e.getPosition();
	int x = p.getX();
	int y = p.getY(); //256
	DBG(x);
	DBG(y);
	DBG("blaExit");
	if (y > 256 && y < 360)setImage(x);
	repaint();
	
}

void AnimatedComponent::mouseEnter(const juce::MouseEvent &e)
{
	currentImage = bg;
	repaint();
	DBG("blaEnering-------");
}

void AnimatedComponent::setImage(int x) {
	if (x >= 258 && x <= 337) {
		currentImage = k3;
	}
	else if (x >= 358 && x <= 437) {
		currentImage = k4;
	}
	else if (x >= 458 && x <= 537) {
		currentImage = k5;
	}
	else if (x >= 558 && x <= 637) {
		currentImage = k6;
	}
}


//==============================================================================
TokyoRe_verbAudioProcessorEditor::TokyoRe_verbAudioProcessorEditor (TokyoRe_verbAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

	addAndMakeVisible(Comp);
	//addAndMakeVisible(Comp1);
    setOpaque(true);
    setSize (700, 394);
    //knob one
    filterCutoffDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    filterCutoffDial.setSize(80, 80);
    
    // dont change these two
    filterCutoffDial.addListener(this);
    addAndMakeVisible(filterCutoffDial);
    
	//knob two
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
    
	//knob 3
    reverbMixDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    reverbMixDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbMixDial.setSize(80, 80);
    
    // dont change these two
    reverbMixDial.addListener(this);
    addAndMakeVisible(reverbMixDial);
    
	//knob 4
    reverbRoomDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    reverbRoomDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbRoomDial.setSize(80, 80);
    
    // dont change these two
    reverbRoomDial.addListener(this);
    addAndMakeVisible(reverbRoomDial);
    //knob 5
    reverbDampDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    reverbDampDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    reverbDampDial.setSize(80, 80);

    // dont change these two
    reverbDampDial.addListener(this);
    addAndMakeVisible(reverbDampDial);
    //knob 6
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


	//////////////////////////HERE
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
    
    Image background = ImageCache::getFromMemory(BinaryData::Animation1_png, BinaryData::Animation1_pngSize);
	//MYpaint(g, background);
	g.drawImageAt(background, 0, 0);
 
}

void TokyoRe_verbAudioProcessorEditor::MYpaint(Graphics& g, Image i) {
	g.drawImageAt(i, 0, 0);
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

	Comp.setBounds(getLocalBounds());
	//Comp1.setBounds(getLocalBounds());
	
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
