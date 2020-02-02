
//------------------------------------------------------------------------------
// This file was generated using the Faust compiler (https://faust.grame.fr),
// and the Faust post-processor (https://github.com/jpcima/faustpp).
//
// Source: CharacterCompressor.dsp
// Name: CharacterCompressor
// Author: Bart Brouns
// Copyright: (C) 2014 Bart Brouns
// License: 
// Version: 0.3.3
//------------------------------------------------------------------------------







#include "CharacterCompressor.hpp"



#include <utility>
#include <cmath>

class CharacterCompressor::BasicDsp {
public:
    virtual ~BasicDsp() {}
};

//------------------------------------------------------------------------------
// Begin the Faust code section

namespace {

template <class T> inline T min(T a, T b) { return (a < b) ? a : b; }
template <class T> inline T max(T a, T b) { return (a > b) ? a : b; }

class Meta {
public:
    // dummy
    void declare(...) {}
};

class UI {
public:
    // dummy
    void openHorizontalBox(...) {}
    void openVerticalBox(...) {}
    void closeBox(...) {}
    void declare(...) {}
    void addButton(...) {}
    void addCheckButton(...) {}
    void addVerticalSlider(...) {}
    void addHorizontalSlider(...) {}
    void addVerticalBargraph(...) {}
    void addHorizontalBargraph(...) {}
};

typedef CharacterCompressor::BasicDsp dsp;

} // namespace

#define FAUSTPP_VIRTUAL // do not declare any methods virtual
#define FAUSTPP_PRIVATE public // do not hide any members
#define FAUSTPP_PROTECTED public // do not hide any members

// define the DSP in the anonymous namespace
#define FAUSTPP_BEGIN_NAMESPACE namespace {
#define FAUSTPP_END_NAMESPACE }


#if defined(__GNUC__)
#   pragma GCC diagnostic push
#   pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

#ifndef FAUSTPP_PRIVATE
#   define FAUSTPP_PRIVATE private
#endif
#ifndef FAUSTPP_PROTECTED
#   define FAUSTPP_PROTECTED protected
#endif
#ifndef FAUSTPP_VIRTUAL
#   define FAUSTPP_VIRTUAL virtual
#endif

#ifndef FAUSTPP_BEGIN_NAMESPACE
#   define FAUSTPP_BEGIN_NAMESPACE
#endif
#ifndef FAUSTPP_END_NAMESPACE
#   define FAUSTPP_END_NAMESPACE
#endif

FAUSTPP_BEGIN_NAMESPACE

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 

/* link with : "" */
FAUSTPP_END_NAMESPACE
#include <algorithm>
#include <cmath>
#include <float.h>
#include <math.h>
FAUSTPP_BEGIN_NAMESPACE

static float mydsp_faustpower2_f(float value) {
	return (value * value);
	
}
static float mydsp_faustpower3_f(float value) {
	return ((value * value) * value);
	
}

#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif
#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

class mydsp : public dsp {
	
 FAUSTPP_PRIVATE:
	
	int fSamplingFreq;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider0;
	FAUSTFLOAT fHslider1;
	float fRec4[2];
	FAUSTFLOAT fHslider2;
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec5[2];
	FAUSTFLOAT fHslider5;
	FAUSTFLOAT fHslider6;
	FAUSTFLOAT fHslider7;
	float fConst2;
	FAUSTFLOAT fHslider8;
	float fConst3;
	FAUSTFLOAT fHslider9;
	float fVec0[3];
	float fRec7[3];
	float fConst4;
	FAUSTFLOAT fHslider10;
	float fConst5;
	float fVec1[2];
	float fConst6;
	float fVec2[3];
	float fConst7;
	float fVec3[7];
	float fConst8;
	float fVec4[15];
	float fConst9;
	int IOTA;
	float fVec5[32];
	float fConst10;
	float fVec6[64];
	float fConst11;
	float fVec7[128];
	float fConst12;
	float fVec8[256];
	float fConst13;
	float fVec9[512];
	float fConst14;
	float fVec10[1024];
	FAUSTFLOAT fHslider11;
	float fConst15;
	FAUSTFLOAT fHslider12;
	float fConst16;
	FAUSTFLOAT fHslider13;
	float fRec6[2];
	float fConst17;
	float fConst18;
	FAUSTFLOAT fHslider14;
	FAUSTFLOAT fHslider15;
	float fConst19;
	FAUSTFLOAT fHslider16;
	FAUSTFLOAT fHslider17;
	float fVec11[3];
	float fConst20;
	FAUSTFLOAT fHslider18;
	FAUSTFLOAT fHslider19;
	float fVec12[2];
	float fVec13[3];
	float fVec14[7];
	float fVec15[15];
	float fVec16[32];
	float fVec17[64];
	float fVec18[128];
	float fVec19[256];
	float fVec20[512];
	float fVec21[1024];
	FAUSTFLOAT fHslider20;
	float fRec8[2];
	FAUSTFLOAT fVbargraph0;
	float fVec22[2];
	float fRec3[2];
	float fRec2[3];
	float fRec10[2];
	float fRec9[3];
	float fRec0[2];
	float fVec23[2];
	float fRec12[2];
	float fRec11[3];
	float fRec14[2];
	float fRec13[3];
	float fRec1[2];
	FAUSTFLOAT fHslider21;
	float fRec15[2];
	
 public:
	
	void metadata(Meta* m) { 
		m->declare("analyzers.lib/name", "Faust Analyzer Library");
		m->declare("analyzers.lib/version", "0.0");
		m->declare("author", "Bart Brouns");
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.0");
		m->declare("copyright", "(C) 2014 Bart Brouns");
		m->declare("filename", "CharacterCompressor");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/version", "0.0");
		m->declare("lib/CharacterCompressor.lib/author", "Bart Brouns");
		m->declare("lib/CharacterCompressor.lib/copyright", "(C) 2014 Bart Brouns");
		m->declare("lib/CharacterCompressor.lib/name", "CharacterCompressor");
		m->declare("lib/CharacterCompressor.lib/version", "0.3.3");
		m->declare("lib/slidingReduce.lib/author", "Bart Brouns (bart@magnetophon.nl)");
		m->declare("lib/slidingReduce.lib/copyright", "Bart Brouns");
		m->declare("lib/slidingReduce.lib/license", "LGPL");
		m->declare("lib/slidingReduce.lib/name", "Sliding Reduce Library");
		m->declare("lib/slidingReduce.lib/version", "0.1");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.1");
		m->declare("name", "CharacterCompressor");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.0");
		m->declare("version", "0.3.3");
	}

	FAUSTPP_VIRTUAL int getNumInputs() {
		return 2;
		
	}
	FAUSTPP_VIRTUAL int getNumOutputs() {
		return 2;
		
	}
	FAUSTPP_VIRTUAL int getInputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	FAUSTPP_VIRTUAL int getOutputRate(int channel) {
		int rate;
		switch (channel) {
			case 0: {
				rate = 1;
				break;
			}
			case 1: {
				rate = 1;
				break;
			}
			default: {
				rate = -1;
				break;
			}
			
		}
		return rate;
		
	}
	
	static void classInit(int samplingFreq) {
		
	}
	
	FAUSTPP_VIRTUAL void instanceConstants(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = std::min<float>(192000.0f, std::max<float>(1.0f, float(fSamplingFreq)));
		fConst1 = (3.14159274f / fConst0);
		fConst2 = (6.28318548f / fConst0);
		fConst3 = (6.53275824f / fConst0);
		fConst4 = (2.26757365e-05f * fConst0);
		fConst5 = (44100.0f / fConst0);
		fConst6 = (22050.0f / fConst0);
		fConst7 = (11025.0f / fConst0);
		fConst8 = (5512.5f / fConst0);
		fConst9 = (2756.25f / fConst0);
		fConst10 = (1378.125f / fConst0);
		fConst11 = (689.0625f / fConst0);
		fConst12 = (344.53125f / fConst0);
		fConst13 = (172.265625f / fConst0);
		fConst14 = (86.1328125f / fConst0);
		fConst15 = (339.785217f / fConst0);
		fConst16 = (1812.18787f / fConst0);
		fConst17 = std::log(float(LDBL_MIN));
		fConst18 = std::log(float(LDBL_MAX));
		fConst19 = (1.0f / fConst0);
		fConst20 = (2.26757365e-07f * fConst0);
		
	}
	
	FAUSTPP_VIRTUAL void instanceResetUserInterface() {
		fHslider0 = FAUSTFLOAT(134.0f);
		fHslider1 = FAUSTFLOAT(0.0f);
		fHslider2 = FAUSTFLOAT(0.81100000000000005f);
		fHslider3 = FAUSTFLOAT(1.0f);
		fHslider4 = FAUSTFLOAT(-15.0f);
		fHslider5 = FAUSTFLOAT(94.0f);
		fHslider6 = FAUSTFLOAT(20.0f);
		fHslider7 = FAUSTFLOAT(1.0f);
		fHslider8 = FAUSTFLOAT(154.0f);
		fHslider9 = FAUSTFLOAT(0.0f);
		fHslider10 = FAUSTFLOAT(96.0f);
		fHslider11 = FAUSTFLOAT(-27.100000000000001f);
		fHslider12 = FAUSTFLOAT(23.699999999999999f);
		fHslider13 = FAUSTFLOAT(0.10000000000000001f);
		fHslider14 = FAUSTFLOAT(1.881f);
		fHslider15 = FAUSTFLOAT(0.0f);
		fHslider16 = FAUSTFLOAT(3813.0f);
		fHslider17 = FAUSTFLOAT(1020.0f);
		fHslider18 = FAUSTFLOAT(20000.0f);
		fHslider19 = FAUSTFLOAT(108.0f);
		fHslider20 = FAUSTFLOAT(50.0f);
		fHslider21 = FAUSTFLOAT(0.0f);
		
	}
	
	FAUSTPP_VIRTUAL void instanceClear() {
		for (int l0 = 0; (l0 < 2); l0 = (l0 + 1)) {
			fRec4[l0] = 0.0f;
			
		}
		for (int l1 = 0; (l1 < 2); l1 = (l1 + 1)) {
			fRec5[l1] = 0.0f;
			
		}
		for (int l2 = 0; (l2 < 3); l2 = (l2 + 1)) {
			fVec0[l2] = 0.0f;
			
		}
		for (int l3 = 0; (l3 < 3); l3 = (l3 + 1)) {
			fRec7[l3] = 0.0f;
			
		}
		for (int l4 = 0; (l4 < 2); l4 = (l4 + 1)) {
			fVec1[l4] = 0.0f;
			
		}
		for (int l5 = 0; (l5 < 3); l5 = (l5 + 1)) {
			fVec2[l5] = 0.0f;
			
		}
		for (int l6 = 0; (l6 < 7); l6 = (l6 + 1)) {
			fVec3[l6] = 0.0f;
			
		}
		for (int l7 = 0; (l7 < 15); l7 = (l7 + 1)) {
			fVec4[l7] = 0.0f;
			
		}
		IOTA = 0;
		for (int l8 = 0; (l8 < 32); l8 = (l8 + 1)) {
			fVec5[l8] = 0.0f;
			
		}
		for (int l9 = 0; (l9 < 64); l9 = (l9 + 1)) {
			fVec6[l9] = 0.0f;
			
		}
		for (int l10 = 0; (l10 < 128); l10 = (l10 + 1)) {
			fVec7[l10] = 0.0f;
			
		}
		for (int l11 = 0; (l11 < 256); l11 = (l11 + 1)) {
			fVec8[l11] = 0.0f;
			
		}
		for (int l12 = 0; (l12 < 512); l12 = (l12 + 1)) {
			fVec9[l12] = 0.0f;
			
		}
		for (int l13 = 0; (l13 < 1024); l13 = (l13 + 1)) {
			fVec10[l13] = 0.0f;
			
		}
		for (int l14 = 0; (l14 < 2); l14 = (l14 + 1)) {
			fRec6[l14] = 0.0f;
			
		}
		for (int l15 = 0; (l15 < 3); l15 = (l15 + 1)) {
			fVec11[l15] = 0.0f;
			
		}
		for (int l16 = 0; (l16 < 2); l16 = (l16 + 1)) {
			fVec12[l16] = 0.0f;
			
		}
		for (int l17 = 0; (l17 < 3); l17 = (l17 + 1)) {
			fVec13[l17] = 0.0f;
			
		}
		for (int l18 = 0; (l18 < 7); l18 = (l18 + 1)) {
			fVec14[l18] = 0.0f;
			
		}
		for (int l19 = 0; (l19 < 15); l19 = (l19 + 1)) {
			fVec15[l19] = 0.0f;
			
		}
		for (int l20 = 0; (l20 < 32); l20 = (l20 + 1)) {
			fVec16[l20] = 0.0f;
			
		}
		for (int l21 = 0; (l21 < 64); l21 = (l21 + 1)) {
			fVec17[l21] = 0.0f;
			
		}
		for (int l22 = 0; (l22 < 128); l22 = (l22 + 1)) {
			fVec18[l22] = 0.0f;
			
		}
		for (int l23 = 0; (l23 < 256); l23 = (l23 + 1)) {
			fVec19[l23] = 0.0f;
			
		}
		for (int l24 = 0; (l24 < 512); l24 = (l24 + 1)) {
			fVec20[l24] = 0.0f;
			
		}
		for (int l25 = 0; (l25 < 1024); l25 = (l25 + 1)) {
			fVec21[l25] = 0.0f;
			
		}
		for (int l26 = 0; (l26 < 2); l26 = (l26 + 1)) {
			fRec8[l26] = 0.0f;
			
		}
		for (int l27 = 0; (l27 < 2); l27 = (l27 + 1)) {
			fVec22[l27] = 0.0f;
			
		}
		for (int l28 = 0; (l28 < 2); l28 = (l28 + 1)) {
			fRec3[l28] = 0.0f;
			
		}
		for (int l29 = 0; (l29 < 3); l29 = (l29 + 1)) {
			fRec2[l29] = 0.0f;
			
		}
		for (int l30 = 0; (l30 < 2); l30 = (l30 + 1)) {
			fRec10[l30] = 0.0f;
			
		}
		for (int l31 = 0; (l31 < 3); l31 = (l31 + 1)) {
			fRec9[l31] = 0.0f;
			
		}
		for (int l32 = 0; (l32 < 2); l32 = (l32 + 1)) {
			fRec0[l32] = 0.0f;
			
		}
		for (int l33 = 0; (l33 < 2); l33 = (l33 + 1)) {
			fVec23[l33] = 0.0f;
			
		}
		for (int l34 = 0; (l34 < 2); l34 = (l34 + 1)) {
			fRec12[l34] = 0.0f;
			
		}
		for (int l35 = 0; (l35 < 3); l35 = (l35 + 1)) {
			fRec11[l35] = 0.0f;
			
		}
		for (int l36 = 0; (l36 < 2); l36 = (l36 + 1)) {
			fRec14[l36] = 0.0f;
			
		}
		for (int l37 = 0; (l37 < 3); l37 = (l37 + 1)) {
			fRec13[l37] = 0.0f;
			
		}
		for (int l38 = 0; (l38 < 2); l38 = (l38 + 1)) {
			fRec1[l38] = 0.0f;
			
		}
		for (int l39 = 0; (l39 < 2); l39 = (l39 + 1)) {
			fRec15[l39] = 0.0f;
			
		}
		
	}
	
	FAUSTPP_VIRTUAL void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	
	FAUSTPP_VIRTUAL void instanceInit(int samplingFreq) {
		instanceConstants(samplingFreq);
		instanceResetUserInterface();
		instanceClear();
	}
	
	FAUSTPP_VIRTUAL mydsp* clone() {
		return new mydsp();
	}
	
	FAUSTPP_VIRTUAL int getSampleRate() {
		return fSamplingFreq;
		
	}
	
	FAUSTPP_VIRTUAL void buildUserInterface(UI* ui_interface) {
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("CharacterCompressor");
		ui_interface->declare(0, "1", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(&fVbargraph0, "1", "");
		ui_interface->declare(&fVbargraph0, "tooltip", "input level in dB");
		ui_interface->declare(&fVbargraph0, "unit", "dB");
		ui_interface->addVerticalBargraph("0x557a5d2a0d80", &fVbargraph0, -60.0f, 0.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openHorizontalBox("0x00");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("detector");
		ui_interface->declare(&fHslider1, "1", "");
		ui_interface->declare(&fHslider1, "tooltip", "The input signal level is increased by this amount (in dB) to make up for the level lost due to compression");
		ui_interface->declare(&fHslider1, "unit", "dB");
		ui_interface->addHorizontalSlider("Input Gain", &fHslider1, 0.0f, -40.0f, 40.0f, 0.100000001f);
		ui_interface->declare(&fHslider7, "2", "");
		ui_interface->addHorizontalSlider("peak/RMS", &fHslider7, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider10, "3", "");
		ui_interface->declare(&fHslider10, "tooltip", "");
		ui_interface->addHorizontalSlider("RMS size", &fHslider10, 96.0f, 1.0f, 512.0f, 1.0f);
		ui_interface->declare(&fHslider11, "4", "");
		ui_interface->declare(&fHslider11, "tooltip", "When the signal level exceeds the Threshold (in dB), its level is compressed according to the Ratio");
		ui_interface->declare(&fHslider11, "unit", "dB");
		ui_interface->addHorizontalSlider("Threshold", &fHslider11, -27.1000004f, -80.0f, 0.0f, 0.100000001f);
		ui_interface->declare(&fHslider6, "5", "");
		ui_interface->declare(&fHslider6, "tooltip", "A compression Ratio of N means that for each N dB increase in input signal level above Threshold, the output level goes up 1 dB");
		ui_interface->addHorizontalSlider("Ratio", &fHslider6, 20.0f, 1.0f, 20.0f, 0.100000001f);
		ui_interface->declare(&fHslider12, "6", "");
		ui_interface->declare(&fHslider12, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new lower target level (the compression `kicking in')");
		ui_interface->declare(&fHslider12, "unit", "ms");
		ui_interface->addHorizontalSlider("Attack", &fHslider12, 23.7000008f, 0.100000001f, 500.0f, 0.100000001f);
		ui_interface->declare(&fHslider13, "7", "");
		ui_interface->declare(&fHslider13, "tooltip", "Time constant in ms (1/e smoothing time) for the compression gain to approach (exponentially) a new higher target level (the compression 'releasing')");
		ui_interface->declare(&fHslider13, "unit", "ms");
		ui_interface->addHorizontalSlider("Release", &fHslider13, 0.100000001f, 0.100000001f, 2000.0f, 0.100000001f);
		ui_interface->declare(&fHslider8, "8", "");
		ui_interface->declare(&fHslider8, "tooltip", "");
		ui_interface->addHorizontalSlider("sidechain hpf", &fHslider8, 154.0f, 1.0f, 400.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->declare(0, "1", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(0, "0", "");
		ui_interface->openVerticalBox("shape");
		ui_interface->declare(&fHslider14, "1", "");
		ui_interface->declare(&fHslider14, "tooltip", "");
		ui_interface->addHorizontalSlider("power", &fHslider14, 1.88100004f, -33.0f, 33.0f, 0.00100000005f);
		ui_interface->declare(&fHslider4, "2", "");
		ui_interface->declare(&fHslider4, "tooltip", "The maximum amount of gain reduction");
		ui_interface->declare(&fHslider4, "unit", "dB");
		ui_interface->addHorizontalSlider("Max Gain Reduction", &fHslider4, -15.0f, -60.0f, 0.0f, 0.100000001f);
		ui_interface->declare(&fHslider15, "3", "");
		ui_interface->declare(&fHslider15, "tooltip", "");
		ui_interface->addHorizontalSlider("curve", &fHslider15, 0.0f, -1.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider5, "4", "");
		ui_interface->declare(&fHslider5, "tooltip", "");
		ui_interface->addHorizontalSlider("shape", &fHslider5, 94.0f, 1.0f, 100.0f, 0.00100000005f);
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("0x00");
		ui_interface->declare(&fHslider9, "0", "");
		ui_interface->declare(&fHslider9, "tooltip", "");
		ui_interface->addHorizontalSlider("feedback/feedforward", &fHslider9, 0.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider0, "1", "");
		ui_interface->declare(&fHslider0, "tooltip", "");
		ui_interface->addHorizontalSlider("hi shelf freq", &fHslider0, 134.0f, 1.0f, 400.0f, 1.0f);
		ui_interface->declare(&fHslider2, "2", "");
		ui_interface->declare(&fHslider2, "tooltip", "");
		ui_interface->addHorizontalSlider("gain/hi-shelve crossfade", &fHslider2, 0.81099999f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider21, "3", "");
		ui_interface->declare(&fHslider21, "tooltip", "");
		ui_interface->addHorizontalSlider("output gain (dB)", &fHslider21, 0.0f, -40.0f, 40.0f, 0.100000001f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->declare(0, "2", "");
		ui_interface->openVerticalBox("ratelimit");
		ui_interface->declare(&fHslider3, "0", "");
		ui_interface->declare(&fHslider3, "tooltip", "");
		ui_interface->addHorizontalSlider("ratelimit amount", &fHslider3, 1.0f, 0.0f, 1.0f, 0.00100000005f);
		ui_interface->declare(&fHslider17, "1", "");
		ui_interface->declare(&fHslider17, "tooltip", "");
		ui_interface->declare(&fHslider17, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max attack", &fHslider17, 1020.0f, 6.0f, 8000.0f, 1.0f);
		ui_interface->declare(&fHslider16, "2", "");
		ui_interface->declare(&fHslider16, "tooltip", "");
		ui_interface->declare(&fHslider16, "unit", "dB/s");
		ui_interface->addHorizontalSlider("max decay", &fHslider16, 3813.0f, 6.0f, 8000.0f, 1.0f);
		ui_interface->declare(&fHslider18, "3", "");
		ui_interface->declare(&fHslider18, "tooltip", "");
		ui_interface->addHorizontalSlider("decayMult", &fHslider18, 20000.0f, 0.0f, 20000.0f, 0.00100000005f);
		ui_interface->declare(&fHslider20, "4", "");
		ui_interface->declare(&fHslider20, "tooltip", "");
		ui_interface->addHorizontalSlider("decayPower", &fHslider20, 50.0f, 0.0f, 50.0f, 0.00100000005f);
		ui_interface->declare(&fHslider19, "5", "");
		ui_interface->declare(&fHslider19, "tooltip", "");
		ui_interface->addHorizontalSlider("IM_size", &fHslider19, 108.0f, 1.0f, 512.0f, 1.0f);
		ui_interface->closeBox();
		ui_interface->closeBox();
		ui_interface->closeBox();
		
	}
	
	FAUSTPP_VIRTUAL void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) {
		FAUSTFLOAT* input0 = inputs[0];
		FAUSTFLOAT* input1 = inputs[1];
		FAUSTFLOAT* output0 = outputs[0];
		FAUSTFLOAT* output1 = outputs[1];
		float fSlow0 = std::tan((fConst1 * float(fHslider0)));
		float fSlow1 = (1.0f / fSlow0);
		float fSlow2 = (1.0f / (((fSlow1 + 1.0f) / fSlow0) + 1.0f));
		float fSlow3 = mydsp_faustpower2_f(fSlow0);
		float fSlow4 = (1.0f / fSlow3);
		float fSlow5 = (fSlow1 + 1.0f);
		float fSlow6 = (0.0f - (1.0f / (fSlow5 * fSlow0)));
		float fSlow7 = (0.00100000005f * std::pow(10.0f, (0.0500000007f * float(fHslider1))));
		float fSlow8 = float(fHslider2);
		float fSlow9 = (1.0f - fSlow8);
		float fSlow10 = float(fHslider3);
		float fSlow11 = (20.0f * (1.0f - fSlow10));
		float fSlow12 = (0.00100000005f * std::pow(10.0f, (0.0500000007f * float(fHslider4))));
		float fSlow13 = mydsp_faustpower2_f((101.0f - float(fHslider5)));
		float fSlow14 = (0.0500000007f * (1.0f - (1.0f / float(fHslider6))));
		float fSlow15 = float(fHslider7);
		float fSlow16 = (1.0f - fSlow15);
		float fSlow17 = float(fHslider8);
		float fSlow18 = (fConst2 * fSlow17);
		float fSlow19 = std::sin(fSlow18);
		float fSlow20 = (fSlow19 * float(sinhf(float((fConst3 * (fSlow17 / fSlow19))))));
		float fSlow21 = (1.0f / (fSlow20 + 1.0f));
		float fSlow22 = std::cos(fSlow18);
		float fSlow23 = (-1.0f - fSlow22);
		float fSlow24 = float(fHslider9);
		float fSlow25 = (1.0f - fSlow24);
		float fSlow26 = (0.5f * (fSlow22 + 1.0f));
		float fSlow27 = (2.0f * fSlow22);
		float fSlow28 = (fSlow20 + -1.0f);
		float fSlow29 = float(fHslider10);
		float fSlow30 = (fConst4 / fSlow29);
		float fSlow31 = (fConst5 * fSlow29);
		int iSlow32 = (1 & (fSlow31 == 0.0f));
		int iSlow33 = (int(std::floor(fSlow31)) % 2);
		int iSlow34 = (int(std::floor((fConst6 * fSlow29))) % 2);
		int iSlow35 = (int(std::floor((fConst7 * fSlow29))) % 2);
		int iSlow36 = (iSlow33 + (2 * iSlow34));
		int iSlow37 = (int(std::floor((fConst8 * fSlow29))) % 2);
		int iSlow38 = (iSlow36 + (4 * iSlow35));
		int iSlow39 = (int(std::floor((fConst9 * fSlow29))) % 2);
		int iSlow40 = (iSlow38 + (8 * iSlow37));
		int iSlow41 = (int(std::floor((fConst10 * fSlow29))) % 2);
		int iSlow42 = (iSlow40 + (16 * iSlow39));
		int iSlow43 = (int(std::floor((fConst11 * fSlow29))) % 2);
		int iSlow44 = (iSlow42 + (32 * iSlow41));
		int iSlow45 = (int(std::floor((fConst12 * fSlow29))) % 2);
		int iSlow46 = (iSlow44 + (64 * iSlow43));
		int iSlow47 = (int(std::floor((fConst13 * fSlow29))) % 2);
		int iSlow48 = (iSlow46 + (128 * iSlow45));
		int iSlow49 = (int(std::floor((fConst14 * fSlow29))) % 2);
		int iSlow50 = (iSlow48 + (256 * iSlow47));
		float fSlow51 = float(fHslider11);
		float fSlow52 = (fConst15 / float(fHslider12));
		float fSlow53 = (fConst16 / float(fHslider13));
		float fSlow54 = float(fHslider14);
		float fSlow55 = ((float((fSlow54 >= 0.0f)) / mydsp_faustpower3_f((fSlow54 + 1.0f))) + (float((fSlow54 < 0.0f)) * mydsp_faustpower3_f((1.0f - fSlow54))));
		float fSlow56 = std::exp((6.93147182f * (0.0f - float(fHslider15))));
		float fSlow57 = (fConst19 * float(fHslider16));
		float fSlow58 = (0.0f - (fConst19 * float(fHslider17)));
		float fSlow59 = float(fHslider19);
		float fSlow60 = (fConst20 * (float(fHslider18) / fSlow59));
		float fSlow61 = (fConst5 * fSlow59);
		int iSlow62 = (1 & (fSlow61 == 0.0f));
		int iSlow63 = (int(std::floor(fSlow61)) % 2);
		int iSlow64 = (int(std::floor((fConst6 * fSlow59))) % 2);
		int iSlow65 = (int(std::floor((fConst7 * fSlow59))) % 2);
		int iSlow66 = (iSlow63 + (2 * iSlow64));
		int iSlow67 = (int(std::floor((fConst8 * fSlow59))) % 2);
		int iSlow68 = (iSlow66 + (4 * iSlow65));
		int iSlow69 = (int(std::floor((fConst9 * fSlow59))) % 2);
		int iSlow70 = (iSlow68 + (8 * iSlow67));
		int iSlow71 = (int(std::floor((fConst10 * fSlow59))) % 2);
		int iSlow72 = (iSlow70 + (16 * iSlow69));
		int iSlow73 = (int(std::floor((fConst11 * fSlow59))) % 2);
		int iSlow74 = (iSlow72 + (32 * iSlow71));
		int iSlow75 = (int(std::floor((fConst12 * fSlow59))) % 2);
		int iSlow76 = (iSlow74 + (64 * iSlow73));
		int iSlow77 = (int(std::floor((fConst13 * fSlow59))) % 2);
		int iSlow78 = (iSlow76 + (128 * iSlow75));
		int iSlow79 = (int(std::floor((fConst14 * fSlow59))) % 2);
		int iSlow80 = (iSlow78 + (256 * iSlow77));
		float fSlow81 = float(fHslider20);
		float fSlow82 = (1.0f / fSlow5);
		float fSlow83 = (1.0f - fSlow1);
		float fSlow84 = (((fSlow1 + -1.0f) / fSlow0) + 1.0f);
		float fSlow85 = (2.0f * (1.0f - fSlow4));
		float fSlow86 = (0.0f - (2.0f / fSlow3));
		float fSlow87 = (0.00100000005f * float(fHslider21));
		for (int i = 0; (i < count); i = (i + 1)) {
			fRec4[0] = (fSlow7 + (0.999000013f * fRec4[1]));
			fRec5[0] = (fSlow12 + (0.999000013f * fRec5[1]));
			float fTemp0 = (1.0f - fRec5[0]);
			float fTemp1 = float(input1[i]);
			float fTemp2 = float(input0[i]);
			float fTemp3 = ((fSlow25 * (fRec0[1] + fRec1[1])) + (fSlow24 * (fRec4[0] * (fTemp1 + fTemp2))));
			fVec0[0] = fTemp3;
			fRec7[0] = (fSlow21 * (((((fSlow23 * fVec0[1]) + (fSlow26 * fTemp3)) + (fSlow26 * fVec0[2])) + (fSlow27 * fRec7[1])) + (fSlow28 * fRec7[2])));
			float fTemp4 = mydsp_faustpower2_f(fRec7[0]);
			fVec1[0] = fTemp4;
			float fTemp5 = (fTemp4 + fVec1[1]);
			fVec2[0] = fTemp5;
			float fTemp6 = (fTemp5 + fVec2[2]);
			fVec3[0] = fTemp6;
			float fTemp7 = (fTemp6 + fVec3[4]);
			fVec4[0] = fTemp7;
			float fTemp8 = (fTemp7 + fVec4[8]);
			fVec5[(IOTA & 31)] = fTemp8;
			float fTemp9 = (fTemp8 + fVec5[((IOTA - 16) & 31)]);
			fVec6[(IOTA & 63)] = fTemp9;
			float fTemp10 = (fTemp9 + fVec6[((IOTA - 32) & 63)]);
			fVec7[(IOTA & 127)] = fTemp10;
			float fTemp11 = (fTemp10 + fVec7[((IOTA - 64) & 127)]);
			fVec8[(IOTA & 255)] = fTemp11;
			float fTemp12 = (fTemp11 + fVec8[((IOTA - 128) & 255)]);
			fVec9[(IOTA & 511)] = fTemp12;
			fVec10[(IOTA & 1023)] = (fTemp12 + fVec9[((IOTA - 256) & 511)]);
			float fTemp13 = (20.0f * std::log10(((fSlow16 * fRec7[0]) + (fSlow15 * std::sqrt((fSlow30 * ((((((((((iSlow32?fTemp4:(iSlow33?fTemp4:0.0f)) + (iSlow34?fVec2[iSlow33]:0.0f)) + (iSlow35?fVec3[iSlow36]:0.0f)) + (iSlow37?fVec4[iSlow38]:0.0f)) + (iSlow39?fVec5[((IOTA - iSlow40) & 31)]:0.0f)) + (iSlow41?fVec6[((IOTA - iSlow42) & 63)]:0.0f)) + (iSlow43?fVec7[((IOTA - iSlow44) & 127)]:0.0f)) + (iSlow45?fVec8[((IOTA - iSlow46) & 255)]:0.0f)) + (iSlow47?fVec9[((IOTA - iSlow48) & 511)]:0.0f)) + (iSlow49?fVec10[((IOTA - iSlow50) & 1023)]:0.0f))))))));
			float fTemp14 = ((fTemp13 - fSlow51) * float((fSlow51 < fTemp13)));
			float fTemp15 = ((fTemp14 < fRec6[1])?fSlow53:fSlow52);
			fRec6[0] = ((fTemp14 * fTemp15) + (fRec6[1] * (1.0f - fTemp15)));
			float fTemp16 = std::max<float>(float(LDBL_MIN), std::min<float>(1.0f, std::pow(10.0f, (0.0f - (fSlow14 * fRec6[0])))));
			float fTemp17 = std::log(fTemp16);
			float fTemp18 = (std::pow(fTemp16, std::min<float>((fConst17 / fTemp17), std::max<float>((fConst18 / fTemp17), fSlow55))) - fRec5[0]);
			float fTemp19 = (fTemp18 / fTemp0);
			float fTemp20 = std::log10((fRec5[0] + (fTemp0 * (float(tanhf(float((fSlow13 * (std::pow(((fTemp18 * float((fTemp19 > 0.0f))) / fTemp0), fSlow56) + (-1.0f - std::pow(((0.0f - fTemp19) * float((fTemp19 <= 0.0f))), fSlow56))))))) + 1.0f))));
			float fTemp21 = ((20.0f * fTemp20) - fRec8[1]);
			fVec11[0] = fTemp21;
			float fTemp22 = std::fabs((fVec11[1] - fVec11[2]));
			fVec12[0] = fTemp22;
			float fTemp23 = (fTemp22 + fVec12[1]);
			fVec13[0] = fTemp23;
			float fTemp24 = (fTemp23 + fVec13[2]);
			fVec14[0] = fTemp24;
			float fTemp25 = (fTemp24 + fVec14[4]);
			fVec15[0] = fTemp25;
			float fTemp26 = (fTemp25 + fVec15[8]);
			fVec16[(IOTA & 31)] = fTemp26;
			float fTemp27 = (fTemp26 + fVec16[((IOTA - 16) & 31)]);
			fVec17[(IOTA & 63)] = fTemp27;
			float fTemp28 = (fTemp27 + fVec17[((IOTA - 32) & 63)]);
			fVec18[(IOTA & 127)] = fTemp28;
			float fTemp29 = (fTemp28 + fVec18[((IOTA - 64) & 127)]);
			fVec19[(IOTA & 255)] = fTemp29;
			float fTemp30 = (fTemp29 + fVec19[((IOTA - 128) & 255)]);
			fVec20[(IOTA & 511)] = fTemp30;
			fVec21[(IOTA & 1023)] = (fTemp30 + fVec20[((IOTA - 256) & 511)]);
			fRec8[0] = std::max<float>((20.0f * std::log10(fRec5[0])), std::min<float>(0.0f, (fRec8[1] + std::min<float>(fSlow57, std::max<float>(fSlow58, ((fTemp21 > 0.0f)?(fTemp21 * std::pow(10.0f, (0.0500000007f * (0.0f - std::fabs((std::pow(((fSlow60 * ((((((((((iSlow62?fTemp22:(iSlow63?fTemp22:0.0f)) + (iSlow64?fVec13[iSlow63]:0.0f)) + (iSlow65?fVec14[iSlow66]:0.0f)) + (iSlow67?fVec15[iSlow68]:0.0f)) + (iSlow69?fVec16[((IOTA - iSlow70) & 31)]:0.0f)) + (iSlow71?fVec17[((IOTA - iSlow72) & 63)]:0.0f)) + (iSlow73?fVec18[((IOTA - iSlow74) & 127)]:0.0f)) + (iSlow75?fVec19[((IOTA - iSlow76) & 255)]:0.0f)) + (iSlow77?fVec20[((IOTA - iSlow78) & 511)]:0.0f)) + (iSlow79?fVec21[((IOTA - iSlow80) & 1023)]:0.0f))) + 1.0f), fSlow81) + -1.0f)))))):fTemp21))))));
			float fTemp31 = std::pow(10.0f, (0.0500000007f * ((fSlow11 * fTemp20) + (fSlow10 * fRec8[0]))));
			float fTemp32 = std::log10(fTemp31);
			fVbargraph0 = FAUSTFLOAT((20.0f * fTemp32));
			float fTemp33 = (fRec4[0] * std::pow(10.0f, (fSlow9 * std::log10(fTemp31))));
			float fTemp34 = (fTemp33 * fTemp2);
			fVec22[0] = fTemp34;
			fRec3[0] = ((fSlow6 * fVec22[1]) - (fSlow82 * ((fSlow83 * fRec3[1]) - (fSlow1 * fTemp34))));
			fRec2[0] = (fRec3[0] - (fSlow2 * ((fSlow84 * fRec2[2]) + (fSlow85 * fRec2[1]))));
			float fTemp35 = std::pow(10.0f, (fSlow8 * fTemp32));
			fRec10[0] = (0.0f - (fSlow82 * ((fSlow83 * fRec10[1]) - (fTemp34 + fVec22[1]))));
			fRec9[0] = (fRec10[0] - (fSlow2 * ((fSlow84 * fRec9[2]) + (fSlow85 * fRec9[1]))));
			fRec0[0] = (fSlow2 * (((((fSlow4 * fRec2[0]) + (fSlow86 * fRec2[1])) + (fSlow4 * fRec2[2])) * fTemp35) + (fRec9[2] + (fRec9[0] + (2.0f * fRec9[1])))));
			float fTemp36 = (fTemp33 * fTemp1);
			fVec23[0] = fTemp36;
			fRec12[0] = ((fSlow6 * fVec23[1]) - (fSlow82 * ((fSlow83 * fRec12[1]) - (fSlow1 * fTemp36))));
			fRec11[0] = (fRec12[0] - (fSlow2 * ((fSlow84 * fRec11[2]) + (fSlow85 * fRec11[1]))));
			fRec14[0] = (0.0f - (fSlow82 * ((fSlow83 * fRec14[1]) - (fTemp36 + fVec23[1]))));
			fRec13[0] = (fRec14[0] - (fSlow2 * ((fSlow84 * fRec13[2]) + (fSlow85 * fRec13[1]))));
			fRec1[0] = (fSlow2 * ((fTemp35 * (((fSlow4 * fRec11[0]) + (fSlow86 * fRec11[1])) + (fSlow4 * fRec11[2]))) + (fRec13[2] + (fRec13[0] + (2.0f * fRec13[1])))));
			fRec15[0] = (fSlow87 + (0.999000013f * fRec15[1]));
			float fTemp37 = std::pow(10.0f, (0.0500000007f * fRec15[0]));
			output0[i] = FAUSTFLOAT((fRec0[0] * fTemp37));
			output1[i] = FAUSTFLOAT((fRec1[0] * fTemp37));
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			fVec0[2] = fVec0[1];
			fVec0[1] = fVec0[0];
			fRec7[2] = fRec7[1];
			fRec7[1] = fRec7[0];
			fVec1[1] = fVec1[0];
			fVec2[2] = fVec2[1];
			fVec2[1] = fVec2[0];
			for (int j0 = 6; (j0 > 0); j0 = (j0 - 1)) {
				fVec3[j0] = fVec3[(j0 - 1)];
				
			}
			for (int j1 = 14; (j1 > 0); j1 = (j1 - 1)) {
				fVec4[j1] = fVec4[(j1 - 1)];
				
			}
			IOTA = (IOTA + 1);
			fRec6[1] = fRec6[0];
			fVec11[2] = fVec11[1];
			fVec11[1] = fVec11[0];
			fVec12[1] = fVec12[0];
			fVec13[2] = fVec13[1];
			fVec13[1] = fVec13[0];
			for (int j2 = 6; (j2 > 0); j2 = (j2 - 1)) {
				fVec14[j2] = fVec14[(j2 - 1)];
				
			}
			for (int j3 = 14; (j3 > 0); j3 = (j3 - 1)) {
				fVec15[j3] = fVec15[(j3 - 1)];
				
			}
			fRec8[1] = fRec8[0];
			fVec22[1] = fVec22[0];
			fRec3[1] = fRec3[0];
			fRec2[2] = fRec2[1];
			fRec2[1] = fRec2[0];
			fRec10[1] = fRec10[0];
			fRec9[2] = fRec9[1];
			fRec9[1] = fRec9[0];
			fRec0[1] = fRec0[0];
			fVec23[1] = fVec23[0];
			fRec12[1] = fRec12[0];
			fRec11[2] = fRec11[1];
			fRec11[1] = fRec11[0];
			fRec14[1] = fRec14[0];
			fRec13[2] = fRec13[1];
			fRec13[1] = fRec13[0];
			fRec1[1] = fRec1[0];
			fRec15[1] = fRec15[0];
			
		}
		
	}

};
FAUSTPP_END_NAMESPACE


#if defined(__GNUC__)
#   pragma GCC diagnostic pop
#endif



//------------------------------------------------------------------------------
// End the Faust code section




CharacterCompressor::CharacterCompressor()
{

    mydsp *dsp = new mydsp;
    fDsp.reset(dsp);
    dsp->instanceResetUserInterface();

}

CharacterCompressor::~CharacterCompressor()
{
}

void CharacterCompressor::init(float sample_rate)
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.classInit(sample_rate);
    dsp.instanceConstants(sample_rate);
    clear();

}

void CharacterCompressor::clear() noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.instanceClear();

}

void CharacterCompressor::process(
    const float *in0,const float *in1,
    float *out0,float *out1,
    unsigned count) noexcept
{

    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    float *inputs[] = {
        const_cast<float *>(in0),const_cast<float *>(in1),
    };
    float *outputs[] = {
        out0,out1,
    };
    dsp.compute(count, inputs, outputs);

}

const char *CharacterCompressor::parameter_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Input Gain";
    
    case 1:
        return "peak/RMS";
    
    case 2:
        return "RMS size";
    
    case 3:
        return "Threshold";
    
    case 4:
        return "Ratio";
    
    case 5:
        return "Attack";
    
    case 6:
        return "Release";
    
    case 7:
        return "sidechain hpf";
    
    case 8:
        return "power";
    
    case 9:
        return "Max Gain Reduction";
    
    case 10:
        return "curve";
    
    case 11:
        return "shape";
    
    case 12:
        return "feedback/feedforward";
    
    case 13:
        return "hi shelf freq";
    
    case 14:
        return "gain/hi-shelve crossfade";
    
    case 15:
        return "output gain (dB)";
    
    case 16:
        return "ratelimit amount";
    
    case 17:
        return "max attack";
    
    case 18:
        return "max decay";
    
    case 19:
        return "decayMult";
    
    case 20:
        return "decayPower";
    
    case 21:
        return "IM_size";
    
    case 22:
        return "0x557a5d17bff0";
    
    default:
        return 0;
    }
}

const char *CharacterCompressor::parameter_short_label(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "";
    
    case 4:
        return "";
    
    case 5:
        return "";
    
    case 6:
        return "";
    
    case 7:
        return "";
    
    case 8:
        return "";
    
    case 9:
        return "";
    
    case 10:
        return "";
    
    case 11:
        return "";
    
    case 12:
        return "";
    
    case 13:
        return "";
    
    case 14:
        return "";
    
    case 15:
        return "";
    
    case 16:
        return "";
    
    case 17:
        return "";
    
    case 18:
        return "";
    
    case 19:
        return "";
    
    case 20:
        return "";
    
    case 21:
        return "";
    
    case 22:
        return "";
    
    default:
        return 0;
    }
}

const char *CharacterCompressor::parameter_symbol(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "Input_Gain";
    
    case 1:
        return "peak_RMS";
    
    case 2:
        return "RMS_size";
    
    case 3:
        return "Threshold";
    
    case 4:
        return "Ratio";
    
    case 5:
        return "Attack";
    
    case 6:
        return "Release";
    
    case 7:
        return "sidechain_hpf";
    
    case 8:
        return "power";
    
    case 9:
        return "Max_Gain_Reduction";
    
    case 10:
        return "curve";
    
    case 11:
        return "shape";
    
    case 12:
        return "feedback_feedforward";
    
    case 13:
        return "hi_shelf_freq";
    
    case 14:
        return "gain_hi_shelve_crossfade";
    
    case 15:
        return "output_gain__dB_";
    
    case 16:
        return "ratelimit_amount";
    
    case 17:
        return "max_attack";
    
    case 18:
        return "max_decay";
    
    case 19:
        return "decayMult";
    
    case 20:
        return "decayPower";
    
    case 21:
        return "IM_size";
    
    case 22:
        return "_x557a5d17bff0";
    
    default:
        return 0;
    }
}

const char *CharacterCompressor::parameter_unit(unsigned index) noexcept
{
    switch (index) {
    
    case 0:
        return "dB";
    
    case 1:
        return "";
    
    case 2:
        return "";
    
    case 3:
        return "dB";
    
    case 4:
        return "";
    
    case 5:
        return "ms";
    
    case 6:
        return "ms";
    
    case 7:
        return "";
    
    case 8:
        return "";
    
    case 9:
        return "dB";
    
    case 10:
        return "";
    
    case 11:
        return "";
    
    case 12:
        return "";
    
    case 13:
        return "";
    
    case 14:
        return "";
    
    case 15:
        return "";
    
    case 16:
        return "";
    
    case 17:
        return "dB/s";
    
    case 18:
        return "dB/s";
    
    case 19:
        return "";
    
    case 20:
        return "";
    
    case 21:
        return "";
    
    case 22:
        return "dB";
    
    default:
        return 0;
    }
}

const CharacterCompressor::ParameterRange *CharacterCompressor::parameter_range(unsigned index) noexcept
{
    switch (index) {
    
    case 0: {
        static const ParameterRange range = { 0, -40, 40 };
        return &range;
    }
    
    case 1: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 2: {
        static const ParameterRange range = { 96, 1, 512 };
        return &range;
    }
    
    case 3: {
        static const ParameterRange range = { -27.1, -80, 0 };
        return &range;
    }
    
    case 4: {
        static const ParameterRange range = { 20, 1, 20 };
        return &range;
    }
    
    case 5: {
        static const ParameterRange range = { 23.700001, 0.1, 500 };
        return &range;
    }
    
    case 6: {
        static const ParameterRange range = { 0.1, 0.1, 2000 };
        return &range;
    }
    
    case 7: {
        static const ParameterRange range = { 154, 1, 400 };
        return &range;
    }
    
    case 8: {
        static const ParameterRange range = { 1.881, -33, 33 };
        return &range;
    }
    
    case 9: {
        static const ParameterRange range = { -15, -60, 0 };
        return &range;
    }
    
    case 10: {
        static const ParameterRange range = { 0, -1, 1 };
        return &range;
    }
    
    case 11: {
        static const ParameterRange range = { 94, 1, 100 };
        return &range;
    }
    
    case 12: {
        static const ParameterRange range = { 0, 0, 1 };
        return &range;
    }
    
    case 13: {
        static const ParameterRange range = { 134, 1, 400 };
        return &range;
    }
    
    case 14: {
        static const ParameterRange range = { 0.81099999, 0, 1 };
        return &range;
    }
    
    case 15: {
        static const ParameterRange range = { 0, -40, 40 };
        return &range;
    }
    
    case 16: {
        static const ParameterRange range = { 1, 0, 1 };
        return &range;
    }
    
    case 17: {
        static const ParameterRange range = { 1020, 6, 8000 };
        return &range;
    }
    
    case 18: {
        static const ParameterRange range = { 3813, 6, 8000 };
        return &range;
    }
    
    case 19: {
        static const ParameterRange range = { 20000, 0, 20000 };
        return &range;
    }
    
    case 20: {
        static const ParameterRange range = { 50, 0, 50 };
        return &range;
    }
    
    case 21: {
        static const ParameterRange range = { 108, 1, 512 };
        return &range;
    }
    
    case 22: {
        static const ParameterRange range = { 0, -60, 0 };
        return &range;
    }
    
    default:
        return 0;
    }
}

bool CharacterCompressor::parameter_is_trigger(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool CharacterCompressor::parameter_is_boolean(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool CharacterCompressor::parameter_is_integer(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

bool CharacterCompressor::parameter_is_logarithmic(unsigned index) noexcept
{
    switch (index) {
    
    default:
        return false;
    }
}

float CharacterCompressor::get_parameter(unsigned index) const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        return dsp.fHslider1;
    
    case 1:
        return dsp.fHslider7;
    
    case 2:
        return dsp.fHslider10;
    
    case 3:
        return dsp.fHslider11;
    
    case 4:
        return dsp.fHslider6;
    
    case 5:
        return dsp.fHslider12;
    
    case 6:
        return dsp.fHslider13;
    
    case 7:
        return dsp.fHslider8;
    
    case 8:
        return dsp.fHslider14;
    
    case 9:
        return dsp.fHslider4;
    
    case 10:
        return dsp.fHslider15;
    
    case 11:
        return dsp.fHslider5;
    
    case 12:
        return dsp.fHslider9;
    
    case 13:
        return dsp.fHslider0;
    
    case 14:
        return dsp.fHslider2;
    
    case 15:
        return dsp.fHslider21;
    
    case 16:
        return dsp.fHslider3;
    
    case 17:
        return dsp.fHslider17;
    
    case 18:
        return dsp.fHslider16;
    
    case 19:
        return dsp.fHslider18;
    
    case 20:
        return dsp.fHslider20;
    
    case 21:
        return dsp.fHslider19;
    
    case 22:
        return dsp.fVbargraph0;
    
    default:
        (void)dsp;
        return 0;
    }
}

void CharacterCompressor::set_parameter(unsigned index, float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    switch (index) {
    
    case 0:
        dsp.fHslider1 = value;
        break;
    
    case 1:
        dsp.fHslider7 = value;
        break;
    
    case 2:
        dsp.fHslider10 = value;
        break;
    
    case 3:
        dsp.fHslider11 = value;
        break;
    
    case 4:
        dsp.fHslider6 = value;
        break;
    
    case 5:
        dsp.fHslider12 = value;
        break;
    
    case 6:
        dsp.fHslider13 = value;
        break;
    
    case 7:
        dsp.fHslider8 = value;
        break;
    
    case 8:
        dsp.fHslider14 = value;
        break;
    
    case 9:
        dsp.fHslider4 = value;
        break;
    
    case 10:
        dsp.fHslider15 = value;
        break;
    
    case 11:
        dsp.fHslider5 = value;
        break;
    
    case 12:
        dsp.fHslider9 = value;
        break;
    
    case 13:
        dsp.fHslider0 = value;
        break;
    
    case 14:
        dsp.fHslider2 = value;
        break;
    
    case 15:
        dsp.fHslider21 = value;
        break;
    
    case 16:
        dsp.fHslider3 = value;
        break;
    
    case 17:
        dsp.fHslider17 = value;
        break;
    
    case 18:
        dsp.fHslider16 = value;
        break;
    
    case 19:
        dsp.fHslider18 = value;
        break;
    
    case 20:
        dsp.fHslider20 = value;
        break;
    
    case 21:
        dsp.fHslider19 = value;
        break;
    
    default:
        (void)dsp;
        (void)value;
        break;
    }
}


float CharacterCompressor::get_Input_Gain() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider1;
}

float CharacterCompressor::get_peak_RMS() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider7;
}

float CharacterCompressor::get_RMS_size() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider10;
}

float CharacterCompressor::get_Threshold() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider11;
}

float CharacterCompressor::get_Ratio() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider6;
}

float CharacterCompressor::get_Attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider12;
}

float CharacterCompressor::get_Release() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider13;
}

float CharacterCompressor::get_sidechain_hpf() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider8;
}

float CharacterCompressor::get_power() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider14;
}

float CharacterCompressor::get_Max_Gain_Reduction() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider4;
}

float CharacterCompressor::get_curve() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider15;
}

float CharacterCompressor::get_shape() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider5;
}

float CharacterCompressor::get_feedback_feedforward() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider9;
}

float CharacterCompressor::get_hi_shelf_freq() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider0;
}

float CharacterCompressor::get_gain_hi_shelve_crossfade() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider2;
}

float CharacterCompressor::get_output_gain__dB_() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider21;
}

float CharacterCompressor::get_ratelimit_amount() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider3;
}

float CharacterCompressor::get_max_attack() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider17;
}

float CharacterCompressor::get_max_decay() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider16;
}

float CharacterCompressor::get_decayMult() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider18;
}

float CharacterCompressor::get_decayPower() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider20;
}

float CharacterCompressor::get_IM_size() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fHslider19;
}

float CharacterCompressor::get_foo() const noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    return dsp.fVbargraph0;
}


void CharacterCompressor::set_Input_Gain(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider1 = value;
}

void CharacterCompressor::set_peak_RMS(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider7 = value;
}

void CharacterCompressor::set_RMS_size(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider10 = value;
}

void CharacterCompressor::set_Threshold(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider11 = value;
}

void CharacterCompressor::set_Ratio(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider6 = value;
}

void CharacterCompressor::set_Attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider12 = value;
}

void CharacterCompressor::set_Release(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider13 = value;
}

void CharacterCompressor::set_sidechain_hpf(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider8 = value;
}

void CharacterCompressor::set_power(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider14 = value;
}

void CharacterCompressor::set_Max_Gain_Reduction(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider4 = value;
}

void CharacterCompressor::set_curve(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider15 = value;
}

void CharacterCompressor::set_shape(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider5 = value;
}

void CharacterCompressor::set_feedback_feedforward(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider9 = value;
}

void CharacterCompressor::set_hi_shelf_freq(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider0 = value;
}

void CharacterCompressor::set_gain_hi_shelve_crossfade(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider2 = value;
}

void CharacterCompressor::set_output_gain__dB_(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider21 = value;
}

void CharacterCompressor::set_ratelimit_amount(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider3 = value;
}

void CharacterCompressor::set_max_attack(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider17 = value;
}

void CharacterCompressor::set_max_decay(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider16 = value;
}

void CharacterCompressor::set_decayMult(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider18 = value;
}

void CharacterCompressor::set_decayPower(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider20 = value;
}

void CharacterCompressor::set_IM_size(float value) noexcept
{
    mydsp &dsp = static_cast<mydsp &>(*fDsp);
    dsp.fHslider19 = value;
}




