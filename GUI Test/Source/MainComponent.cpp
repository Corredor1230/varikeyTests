#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    varikeyLookAndFeel.setColourPalette(VarikeyLookAndFeel::palette::vaporwave);
    setLookAndFeel(&varikeyLookAndFeel);
    addAndMakeVisible(tuner);

    addAndMakeVisible(additiveLeft);
    addAndMakeVisible(additiveRight);
    addAndMakeVisible(genLeft);
    addAndMakeVisible(genRight);
    addAndMakeVisible(karpLeft);
    addAndMakeVisible(karpRight);
    addAndMakeVisible(noiseLeft);
    addAndMakeVisible(noiseRight);
    addAndMakeVisible(lfo1);
    addAndMakeVisible(lfo2);
    addAndMakeVisible(pitchwheel);

    addAndMakeVisible(leftOscChoice);
    addAndMakeVisible(rightOscChoice);

    addAndMakeVisible(fmLeft);
    addAndMakeVisible(fmRight);
    addAndMakeVisible(crossSlider);
    addAndMakeVisible(crossLabel);

    addAndMakeVisible(filters);
    addAndMakeVisible(ampAdsr);
    addAndMakeVisible(modAdsr);

    addAndMakeVisible(volumeSlider);
    addAndMakeVisible(volumeLabel);

    volumeSlider.setSliderStyle(juce::Slider::SliderStyle::LinearVertical);
    volumeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    volumeSlider.setRange(-60.0, 0.0, 0.01);
    volumeSlider.setValue(-20.0);
    volumeLabel.setText("Volume", juce::dontSendNotification);
    volumeLabel.setJustificationType(juce::Justification::centred);

    crossSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
    crossSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    crossSlider.setRange(-1.0, 1.0, 0.01);
    crossLabel.setText("Mix", juce::sendNotification);
    crossLabel.setJustificationType(juce::Justification::centred);

    josefinSans.setFontSizeAndStyle(60.f, "plain", 1.f, 0.f);


    juce::String rightRegionTitle = "Osc 2: ";
    additiveRight.setRegionTitle(rightRegionTitle);
    genRight.setRegionTitle(rightRegionTitle);
    karpRight.setRegionTitle(rightRegionTitle);
    noiseRight.setRegionTitle(rightRegionTitle);

    juce::String lfo2Region1 = "3";
    juce::String lfo2Region2 = "4";
    lfo2.setRegionTitle(lfo2Region1, lfo2Region2);

    std::initializer_list<const char*> synthList{ "Generator", "Additive", "Karplus", "Noise" };
    leftOscChoice.addItemList(juce::StringArray(synthList), 1);
    leftOscChoice.setJustificationType(juce::Justification::centred);
    leftOscChoice.setTextWhenNothingSelected("Generator");
    leftOscChoice.setSelectedId(1);
    rightOscChoice.addItemList(juce::StringArray(synthList), 1);
    rightOscChoice.setJustificationType(juce::Justification::centred);
    rightOscChoice.setTextWhenNothingSelected("Generator");
    rightOscChoice.setSelectedId(1);
    
    tuner.setCustomLookAndFeel(&varikeyLookAndFeel);
    additiveLeft.setCustomLookAndFeel(&varikeyLookAndFeel);
    additiveRight.setCustomLookAndFeel(&varikeyLookAndFeel);
    genLeft.setCustomLookAndFeel(&varikeyLookAndFeel);
    genRight.setCustomLookAndFeel(&varikeyLookAndFeel);
    karpLeft.setCustomLookAndFeel(&varikeyLookAndFeel);
    karpRight.setCustomLookAndFeel(&varikeyLookAndFeel);
    noiseLeft.setCustomLookAndFeel(&varikeyLookAndFeel);
    noiseRight.setCustomLookAndFeel(&varikeyLookAndFeel);
    fmLeft.setCustomLookAndFeel(&varikeyLookAndFeel);
    fmRight.setCustomLookAndFeel(&varikeyLookAndFeel);
    filters.setCustomLookAndFeel(&varikeyLookAndFeel);
    ampAdsr.setCustomLookAndFeel(&varikeyLookAndFeel);
    modAdsr.setCustomLookAndFeel(&varikeyLookAndFeel);
    lfo1.setCustomLookAndFeel(&varikeyLookAndFeel);
    lfo2.setCustomLookAndFeel(&varikeyLookAndFeel);
    pitchwheel.setCustomLookAndFeel(&varikeyLookAndFeel);

    setSize (700, 700);
}

MainComponent::~MainComponent()
{
    setLookAndFeel(nullptr);
    tuner.setCustomLookAndFeel(nullptr);
    additiveLeft.setCustomLookAndFeel(nullptr);
    additiveRight.setCustomLookAndFeel(nullptr);
    genLeft.setCustomLookAndFeel(nullptr);
    genRight.setCustomLookAndFeel(nullptr);
    karpLeft.setCustomLookAndFeel(nullptr);
    karpRight.setCustomLookAndFeel(nullptr);
    noiseLeft.setCustomLookAndFeel(nullptr);
    noiseRight.setCustomLookAndFeel(nullptr);
    fmLeft.setCustomLookAndFeel(nullptr);
    fmRight.setCustomLookAndFeel(nullptr);
    filters.setCustomLookAndFeel(nullptr);
    ampAdsr.setCustomLookAndFeel(nullptr);
    modAdsr.setCustomLookAndFeel(nullptr);
    lfo1.setCustomLookAndFeel(nullptr);
    pitchwheel.setCustomLookAndFeel(nullptr);
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll(varikeyLookAndFeel.getColourFromPalette(VarikeyLookAndFeel::paletteColours::gDark));

    getBounds().removeFromLeft(5);
    getBounds().removeFromRight(5);
    getBounds().removeFromTop(5);
    getBounds().removeFromBottom(5);
    int height = getHeight();
    int width = getWidth();

    int padding = 10;
    int firstRowStartX = 0;
    int firstRowStartY = 0;
    int firstRowHeight = 2 * (height / 9);
    int secondRowHeight = height / 2.75;
    int firstColumnWidth = width / 3;
    int filterWidth = firstColumnWidth * 0.8;
    int adsrWidth = width / 2 - filterWidth;
    int secondColumnWidth = width / 3;

    int fmRowHeight = (height / 9);
    int lfoHeight = (3 * secondRowHeight) / 8;
    int pitchwheelHeight = secondRowHeight - lfoHeight * 2;
    int labelHeight = 18;
    int labelWidth = 50;
    int labelStartX = firstColumnWidth + (secondColumnWidth / 2) - (labelWidth / 2);
    int crossHeight = fmRowHeight - labelHeight;

    int secondRowStartX = 0;
    int secondRowStartY = height / 3;

    int thirdRowStartX = 0;
    int thirdRowStartY = firstRowHeight + fmRowHeight + secondRowHeight;
    int thirdRowHeight = height - firstRowHeight - fmRowHeight - secondRowHeight;
    int volumeWidth = width / 12 + padding * 2;
    int tunerWidth = 2 * firstColumnWidth + secondColumnWidth - volumeWidth;

    int volumeStartX = tunerWidth - padding;
    int topStartY = 8 + padding / 2.5;
    int volumeHeight = thirdRowHeight - labelHeight - 1.7 * padding - topStartY;


    int oscChoiceWidth = (secondColumnWidth / 2) - padding;
    int oscChoiceHeight = (firstRowHeight / 4) - 1.5 * padding;



    leftOscChoice.setBounds(firstColumnWidth + (padding / 2), firstRowHeight - oscChoiceHeight - (padding / 1.5),
        oscChoiceWidth, oscChoiceHeight);
    rightOscChoice.setBounds(leftOscChoice.getRight() + padding, firstRowHeight - oscChoiceHeight - (padding / 1.5),
        oscChoiceWidth, oscChoiceHeight);

    genLeft.setBounds(firstRowStartX, firstRowStartY, firstColumnWidth, firstRowHeight);
    additiveLeft.setBounds(firstRowStartX, firstRowStartY, firstColumnWidth, firstRowHeight);
    karpLeft.setBounds(firstRowStartX, firstRowStartY, firstColumnWidth, firstRowHeight);
    noiseLeft.setBounds(firstRowStartX, firstRowStartY, firstColumnWidth, firstRowHeight);

    genRight.setBounds(firstColumnWidth + secondColumnWidth, firstRowStartY, firstColumnWidth, firstRowHeight);
    additiveRight.setBounds(firstColumnWidth + secondColumnWidth, firstRowStartY, firstColumnWidth, firstRowHeight);
    karpRight.setBounds(firstColumnWidth + secondColumnWidth, firstRowStartY, firstColumnWidth, firstRowHeight);
    noiseRight.setBounds(firstColumnWidth + secondColumnWidth, firstRowStartY, firstColumnWidth, firstRowHeight);



    switch (getComboBoxIndex(leftOscChoice.getText()))
    {
    case 0:
        genLeft.setVisible(true);
        additiveLeft.setVisible(false);
        karpLeft.setVisible(false);
        noiseLeft.setVisible(false);
        break;
    case 1:
        genLeft.setVisible(false);
        additiveLeft.setVisible(true);
        karpLeft.setVisible(false);
        noiseLeft.setVisible(false);
        break;
    case 2:
        genLeft.setVisible(false);
        additiveLeft.setVisible(false);
        karpLeft.setVisible(true);
        noiseLeft.setVisible(false);
        break;
    case 3:
        genLeft.setVisible(false);
        additiveLeft.setVisible(false);
        karpLeft.setVisible(false);
        noiseLeft.setVisible(true);
        break;
    default:
        genLeft.setVisible(true);
        additiveLeft.setVisible(false);
        karpLeft.setVisible(false);
        noiseLeft.setVisible(false);
        break;
    }

    switch (getComboBoxIndex(rightOscChoice.getText()))
    {
    case 0:
        genRight.setVisible(true);
        additiveRight.setVisible(false);
        karpRight.setVisible(false);
        noiseRight.setVisible(false);
        break;
    case 1:
        genRight.setVisible(false);
        additiveRight.setVisible(true);
        karpRight.setVisible(false);
        noiseRight.setVisible(false);
        break;
    case 2:
        genRight.setVisible(false);
        additiveRight.setVisible(false);
        karpRight.setVisible(true);
        noiseRight.setVisible(false);
        break;
    case 3:
        genRight.setVisible(false);
        additiveRight.setVisible(false);
        karpRight.setVisible(false);
        noiseRight.setVisible(true);
        break;
    default:
        genRight.setVisible(true);
        additiveRight.setVisible(false);
        karpRight.setVisible(false);
        noiseRight.setVisible(false);
        break;
    }

    fmLeft.setBounds(firstRowStartX, firstRowHeight - padding / 2, firstColumnWidth, fmRowHeight + padding);
    fmRight.setBounds(firstColumnWidth + secondColumnWidth, firstRowHeight - padding / 2, firstColumnWidth, fmRowHeight + padding);
    crossSlider.setBounds(firstColumnWidth, crossLabel.getBottom(), secondColumnWidth, crossHeight);
    crossLabel.setBounds(labelStartX, firstRowHeight, labelWidth, labelHeight);

    filters.setBounds(firstRowStartX, secondRowStartY, filterWidth, secondRowHeight);
    ampAdsr.setBounds(filters.getRight(), secondRowStartY, adsrWidth, secondRowHeight / 2);
    modAdsr.setBounds(filters.getRight(), ampAdsr.getBottom(), adsrWidth, secondRowHeight / 2);
    lfo1.setBounds(modAdsr.getRight(), secondRowStartY, width - modAdsr.getRight(), lfoHeight);
    lfo2.setBounds(modAdsr.getRight(), lfo1.getBottom(), width - modAdsr.getRight(), lfoHeight);
    pitchwheel.setBounds(modAdsr.getRight(), lfo2.getBottom(), width - modAdsr.getRight(), pitchwheelHeight);

    tuner.setBounds(firstRowStartX, thirdRowStartY, tunerWidth, thirdRowHeight);
    volumeLabel.setBounds(volumeStartX, thirdRowStartY + topStartY, volumeWidth, labelHeight);
    volumeSlider.setBounds(volumeStartX, volumeLabel.getBottom(), volumeWidth, volumeHeight);
}

void MainComponent::resized()
{
}

int MainComponent::getComboBoxIndex(juce::String& string)
{
    if (string == "Generator")
        return 0;
    else if (string == "Additive")
        return 1;
    else if (string == "Karplus")
        return 2;
    else if (string == "Noise")
        return 3;
    else
        return 0;
}