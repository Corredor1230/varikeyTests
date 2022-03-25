/*
  ==============================================================================

    NoteTuning.h
    Created: 24 Mar 2022 5:25:44am
    Author:  User

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

//class Note2 {
//    void setMidiAlteration(int note, float value) {
//        midiAlteration[note] = value;
//    }
//    float alterPitch(int midiNote) {
//        return midiAlterations[midiNote % 12] + midiNote;
//    }
//
//    void alterAllPtiches(std::vector<float>& data);
//    void alterAllPitches(float* dataPtr) {
//
//        for (int i = 0 i < 12 i++) {
//            midiAlterations[i] = dataPtr[i];
//        }
//        dataPtr[0]
//    }
//    std::array<float, 12> midiAlterations;
//};
//
//float midiAlteration[12]{ 0.02f, 0.13f, 0.15f};
//float midiNote{};
//int midiModulus = midiNote % 12;
//
//for (int i = 0; i < 12; i++)
//{
//    if (midiMo)
//}

class NoteTuning
{
public:


    float alterMidiPitch(const float c
        , const float ces
    , const float d
    , const float des
    , const float e
    , const float f
    , const float fes
    , const float g
    , const float ges
    , const float a
    , const float aes
    , const float b);

    float midiToHertz(const float midiNoteNumber);


    int getModulus(const int midiNoteNumber);

    


private:
};

