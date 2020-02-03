/*
 * Copyright (C) 20202 Rob van den Berg <rghvdberg at gmail dot org>
 *
 * This file is part of CharacterCompressor
 *
 * Nnjas2 is free software: you can redistribute it and/or modify
 * it under the of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Ninjas2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Uprising.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef DISTRHO_PLUGIN_INFO_H_INCLUDED
#define DISTRHO_PLUGIN_INFO_H_INCLUDED

#define DISTRHO_PLUGIN_BRAND "Clearly Broken Software"
#define DISTRHO_PLUGIN_NAME  "Character Compressor"
#define DISTRHO_PLUGIN_URI   "https://github.com/rghvdberg/CharacterCompressor"

#define DISTRHO_PLUGIN_IS_SYNTH 0
#define DISTRHO_PLUGIN_HAS_UI       1
#define DISTRHO_PLUGIN_IS_RT_SAFE   1
#define DISTRHO_PLUGIN_NUM_INPUTS 2
#define DISTRHO_PLUGIN_NUM_OUTPUTS  2
#define DISTRHO_PLUGIN_WANT_STATE   0
#define DISTRHO_PLUGIN_WANT_FULL_STATE 0
#define DISTRHO_UI_USE_NANOVG 1
#define DISTRHO_PLUGIN_WANT_DIRECT_ACCESS   0

#define DISTRHO_PLUGIN_LV2_CATEGORY "lv2:CompressorPlugin"

enum Parameters // exposed to the host
{
    p_Input_Gain,
    p_peak_RMS,
    p_RMS_size,
    p_Threshold,
    p_Ratio,
    p_Attack,
    p_Release,
    p_sidechain_hpf,
    p_power,
    p_Max_Gain_Reduction,
    p_curve,
    p_shape,
    p_feedback_feedforward,
    p_hi_shelf_freq,
    p_gain_hi_shelve_crossfade,
    p_output_gain__dB_,
    p_ratelimit_amount,
    p_max_attack,
    p_max_decay,
    p_decayMult,
    p_decayPower,
    p_IM_size,
    p_foo, // output
    parameterCount
   
};


#endif // DISTRHO_PLUGIN_INFO_H_INCLUDED
