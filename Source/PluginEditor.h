/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/

class OtherLookAndFeel : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::red);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centreX, centreY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(-5.0f, -radius, 10.0f, radius * 0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
        
    }
    
};

class OtherLookAndFeel2 : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::yellowgreen);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centreX, centreY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(-5.0f, -radius, 10.0f, radius * 0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
        
    }
    
};

class OtherLookAndFeel3 : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        float diameter = jmin(width, height);
        float radius = diameter / 2;
        float centreX = x + width / 2;
        float centreY = y + height / 2;
        float rx = centreX - radius;
        float ry = centreY - radius;
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
        
        std::cout << rotaryStartAngle << " " << rotaryEndAngle << std::endl;
        
        Rectangle<float> dialArea (rx, ry, diameter, diameter);
        
        g.setColour(Colours::orangered);
        //g.drawRect(dialArea);
        g.fillEllipse(dialArea);
        
        g.setColour(Colours::black);
        //g.fillEllipse(centreX, centreY, 5, 5);
        
        Path dialTick;
        dialTick.addRectangle(-3.0f, -radius, 6.0f, radius * 0.33);
        
        g.fillPath(dialTick, AffineTransform::rotation(angle).translated(centreX, centreY));
        
        g.setColour(Colours::black);
        g.drawEllipse(rx, ry, diameter, diameter, 5.0f);
        
    }
    
};

class TokyoRe_verbAudioProcessorEditor  : public AudioProcessorEditor, Slider::Listener
{
public:
    TokyoRe_verbAudioProcessorEditor (TokyoRe_verbAudioProcessor&);
    ~TokyoRe_verbAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    
    juce::Image backGround;
    
    OtherLookAndFeel otherLookAndFeel;
    OtherLookAndFeel2 otherLookAndFeel2;
    OtherLookAndFeel3 otherLookAndFeel3;
    
    Slider filterCutoffDial;
    Slider filterResDial;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    //std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    //std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    
    
    Label filterCutoffLabel;
    Label filterResLabel;
    
    //Slider reverbDryDial;
    //Slider reverbWetDial;
    Slider reverbMixDial;
    Slider reverbRoomDial;
    Slider reverbDampDial;
    Slider reverbWidthDial;
    
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> reverbDryValue;
    //ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> reverbWetValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> reverbMixValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> reverbRoomValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> reverbDampValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> reverbWidthValue;
    
    //Label reverbDryLabel;
    //Label reverbWetLabel;
    Label reverbMixLabel;
    Label reverbRoomLabel;
    Label reverbDampLabel;
    Label reverbWidthLabel;
    
    /*Slider distDriveDial;
    Slider distRangeDial;
    Slider distBlendDial;
    Slider distVolumeDial;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> distDriveValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> distRangeValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> distBlendValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> distVolumeValue;
    
    Label distDriveLabel;
    Label distRangeLabel;
    Label distBlendLabel;
    Label distVolumeLabel;*/
    
    Slider mixSlider;
    Label mixLabel;
    
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
    
    void sliderValueChanged(Slider * slider) override;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    TokyoRe_verbAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TokyoRe_verbAudioProcessorEditor)
};
