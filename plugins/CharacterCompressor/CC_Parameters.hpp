#ifndef CC_PARAMETERS_H_INCLUDED
#define CC_PARAMETERS_H_INCLUDED
struct parameter
{
  const float def;
  const float min;
  const float max;
};

const char *paramNames[]{
    "Threshold",
    "strength",
    "Attack",
    "Release",
    "Input Gain",
    "peak/RMS",
    "detector Ratio",
    "Release2",
    "sidechain hpf",
    "power",
    "Max Gain Reduction",
    "curve",
    "shape",
    "feedback/feedforward",
    "hi shelf freq",
    "gain/hi-shelve crossfade",
    "output gain (dB)",
    "ratelimit amount",
    "max attack",
    "max decay",
    "decayMult",
    "decayPower",
    "0x55e237ea8330"};

const parameter paramRange[]{
    {-27.1, -80, 0},
    {1, 0, 2},
    {23.700001, 0.1, 500},
    {0.48199999, 0, 1},
    {0, -40, 40},
    {1, 0, 1},
    {20, 1, 20},
    {0.1, 0.1, 2000},
    {154, 1, 400},
    {1.881, -33, 33},
    {-15, -60, 0},
    {0, -1, 1},
    {94, 1, 100},
    {0, 0, 1},
    {134, 1, 400},
    {0.81099999, 0, 1},
    {0, -40, 40},
    {1, 0, 1},
    {1020, 6, 8000},
    {3813, 6, 8000},
    {20000, 0, 20000},
    {50, 0, 50},
    {0, -60, 0}};

const char *parameterUnits[]{
    "dB",
    "",
    "ms",
    "",
    "dB",
    "",
    "",
    "ms",
    "",
    "",
    "dB",
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    "dB/s",
    "dB/s",
    "",
    "",
    "dB"
};

#endif