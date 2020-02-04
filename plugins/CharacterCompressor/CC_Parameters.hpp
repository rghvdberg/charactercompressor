#ifndef CC_PARAMETERS_H_INCLUDED
#define CC_PARAMETERS_H_INCLUDED
//TODO : make #defines out of this ?
const char* portNames[] {
    "Input Gain",           "peak/RMS",         "RMS size",
    "Threshold",            "Ratio",            "Attack",
    "Release",              "sidechain hpf",    "power",
    "Max Gain Reduction",   "curve",            "shape",
    "feedback/feedforward", "hi shelf freq",    "gain/hi-shelve crossfade",
    "output gain (dB)",     "ratelimit amount", "max attack",
    "max decay",            "decayMult",        "decayPower",
    "IM_size", "foo"      
};

const float defaultValues[]{
    0.000000,   1.000000,   96.000000,
    -27.100000, 20.000000,  23.700001,
    0.100000,   154.000000, 1.881000,
    -15.0,      0.0,        94.0,
    0.0,        134.0,      0.811000,
    0.0,        1.0,        1020.0,
    3813.0,     2000.0,     50.0,
    108.0,      -60.0      
};

const float minimumValues[]{
    -40.000000, 0.000000,   1.000000,
    -80.000000, 1.000000,   0.1000000,
    0.100000,   1.0,        -33.0,
    -60.0,      -1,         1.0,
    0.0,        1,          0.0,
    -40.0,      0.0,        6.0,
    6.0,        0.0,        0.0,
    1.0,        -60.0        
};

const float maximumValues[]{
    40.000000,  1.000000,   512.000000, 
    0.000000,   20.000000,  500.000000,
    2000.00000, 400.0,      33.0,
    0.0,        1.0,        100.0,
    1.0,        400,        1.0,
    40.0,       1.0,        8000.0,
    8000.0,     20000.0,    50.0,
    512.0,      0.0
};

const char* parameterUnits[]{
    "dB",       "",         "",
    "dB",       "",         "ms",
    "ms",       "",         "",
    "dB",       "",         "",
    "",         "",         "",
    "",         "",         "dB/s",
    "dB/s",     "",         "",
    "",         "dB"
};

#endif