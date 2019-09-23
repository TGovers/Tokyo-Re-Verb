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
	
	Image img1 = ImageCache::getFromMemory(BinaryData::purple_png, BinaryData::purple_pngSize);
	void drawRotarySlider(Graphics &g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
	{
		if (img1.isValid())
		{
			const double rotation = (slider.getValue()
				- slider.getMinimum())
				/ (slider.getMaximum()
					- slider.getMinimum());

			const int frames = img1.getHeight() / img1.getWidth();
			const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
			const float radius = jmin(width / 2.0f, height / 2.0f);
			const float centerX = x + width * 0.5f;
			const float centerY = y + height * 0.5f;
			const float rx = centerX - radius - 1.0f;
			const float ry = centerY - radius;

			g.drawImage(img1,
				(int)rx,
				(int)ry,
				2 * (int)radius,
				2 * (int)radius,
				0,
				frameId*img1.getWidth(),
				img1.getWidth(),
				img1.getWidth());
		}
		
		
		
	}
		
};

	class TokyoRe_verbAudioProcessorEditor : public AudioProcessorEditor, Slider::Listener
	{
	public:
		TokyoRe_verbAudioProcessorEditor(TokyoRe_verbAudioProcessor&);
		~TokyoRe_verbAudioProcessorEditor();

		//==============================================================================
		void paint(Graphics&) override;
		void resized() override;

	private:

		juce::Image backGround;

		OtherLookAndFeel otherLookAndFeel;


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



		Slider mixSlider;
		Label mixLabel;

		std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> mixAttachment;

		void sliderValueChanged(Slider * slider) override;

		// This reference is provided as a quick way for your editor to
		// access the processor object that created it.
		TokyoRe_verbAudioProcessor& processor;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TokyoRe_verbAudioProcessorEditor)
	};
