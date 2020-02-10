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

START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class CharacterCompressorUI : public UI,
    public NanoKnob::Callback,
    public IdleCallback
{
public: 
    CharacterCompressorUI();

protected:
    void parameterChanged(uint32_t index, float value) override;
    void onNanoDisplay() override;
    void nanoKnobValueChanged( NanoKnob* nanoKnob, const float value) override;
    void idleCallback() override;
private:
    
    ScopedPointer<NanoMeter> fNanoMeter;
    ScopedPointer<NanoKnob> fInGain,fThreshold,fRatio,fAttack,fRelease;
    FontId fNanoFont;
    float fInputLevel, fOutputLevel, fdBInput, fdBOutput, fdBGainReduction;
    float fInVolumeHistory[500];
    float fOutVolumeHistory[500];
    float fGainReductionHistory[500];
    int historyHead;

    // Parameters

    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CharacterCompressorUI)
};

END_NAMESPACE_DISTRHO
