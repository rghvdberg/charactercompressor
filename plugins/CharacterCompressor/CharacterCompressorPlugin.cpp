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
#include "DistrhoPlugin.hpp"
#include "CharacterCompressor.hpp"


START_NAMESPACE_DISTRHO

// -----------------------------------------------------------------------------------------------------------

class CharacterCompressorPlugin : public Plugin
{
public:
    CharacterCompressorPlugin()
        : Plugin(parameterCount, 0, 0)
    {
      ccDSP.init(getSampleRate());
       
    }

protected:
    const char* getLabel() const override
    {
        return "CharacterCompressor";
    }

     const char* getDescription() const override
    {
        return "Character Compressor";
    }

    const char* getMaker() const override
    {
        return "Clearly Broken Software";
    }

    const char* getHomePage() const override
    {
        return "https://github.com/clearly-broken-software/charactercompressor";
    }

    const char* getLicense() const override
    {
        return "GPL";
    }

   uint32_t getVersion() const override
    {
        return d_version(0, 0, 1);
    }

    int64_t getUniqueId() const override
    {
        return d_cconst('c', 'H', 'c', 'm');
    }

    void initParameter(uint32_t index, Parameter& parameter) override
    {
        switch (index)
        {
        case p_foo:
        parameter.hints = kParameterIsOutput;
        break;
        default:
        parameter.hints = kParameterIsAutomable;
        }
        
        parameter.ranges.min = ccDSP.parameter_range(index)->min;
        parameter.ranges.max = ccDSP.parameter_range(index)->max;
        parameter.ranges.def = ccDSP.parameter_range(index)->init;
        parameter.name = ccDSP.parameter_label(index);
        //parameter. = ccDSP.parameter_short_label(index);
        parameter.symbol= ccDSP.parameter_symbol(index);
        parameter.unit = ccDSP.parameter_unit(index);
    }

    float getParameterValue(uint32_t index) const override
    {
        return ccDSP.get_parameter(index);
    }

    void setParameterValue(uint32_t index, float value) override
    {       
     ccDSP.set_parameter(index,value);
    }

    void run(const float** inputs, float** outputs, uint32_t frames) override
    {
       ccDSP.process(inputs[0],inputs[1],outputs[0],outputs[1],frames);
     }

private:
    CharacterCompressor ccDSP;


    DISTRHO_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CharacterCompressorPlugin)
};


Plugin* createPlugin()
{
    return new CharacterCompressorPlugin();
}

END_NAMESPACE_DISTRHO
