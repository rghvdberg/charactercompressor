/*
 * DISTRHO Plugin Framework (DPF)
 * Copyright (C) 2012-2015 Filipe Coelho <falktx@falktx.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any purpose with
 * or without fee is hereby granted, provided that the above copyright notice and this
 * permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD
 * TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN
 * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "DistrhoPluginInfo.h"
#include "DistrhoUI.hpp"
#include "CC_Parameters.hpp"
#include "Widgets/NanoMeter.hpp"
#include "Widgets/NanoKnob.hpp"
#include "Widgets/NanoHistogram.hpp"
#include "Widgets/NanoSlider.hpp"
#include "Resources/Colors.hpp"
#include <chrono>

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class CharacterCompressorUI : public UI,
    public NanoKnob::Callback,
    public NanoSlider::Callback,
    public IdleCallback,
    public CbWidget::PopUp
{
public: 
    CharacterCompressorUI();

protected:
    void parameterChanged(uint32_t index, float value) override;
    void onNanoDisplay() override;
    void nanoKnobValueChanged( NanoKnob* nanoKnob, const float value) override;
    void nanoSliderValueChanged( NanoSlider* nanoSlider, const float value) override;
    void cbPopUp( CbWidget* widget, const bool hasMouse, const Point<int> mouse) override;
    void idleCallback() override;
    bool onMotion( const MotionEvent &ev) override;
private:
    
    ScopedPointer<NanoMeter> fNanoMeter;
    ScopedPointer<NanoKnob> fThreshold,fRatio,fAttack,fRelease;
    ScopedPointer<NanoHistogram> fHistogram;
    ScopedPointer<NanoSlider> fInGain;
    FontId fNanoFont;
    float fInputLevel, fOutputLevel, fdBInput, fdBOutput, fdBGainReduction;
    Point<int> popUp; 
//    void printFPS();
    std::chrono::high_resolution_clock::time_point oldTime,newTime;
    CbWidget * widgetHasMouse;
      
    // Parameters

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CharacterCompressorUI)
};


END_NAMESPACE_DISTRHO
