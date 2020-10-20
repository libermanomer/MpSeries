#include "MpSeries.hpp"

//this module is based on CV-CC written by Andrew Belt
//special thanks to Dave French from Studio 6+1 for helping me
//understand deeply every piece of the code

static constexpr int numControllers = 35;


int ccs[numControllers] = {20, 21, 23, 24, 25, 26, 28, 29, 46, 47,
48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58,
59, 60, 61, 62, 63, 80, 81, 82, 83, 84, 85,
86, 87, 88};

struct CCMidiOutput : midi::Output {
    int lastValues[128];

    CCMidiOutput() {
        reset();
    }

    void reset() {
        for (int n = 0; n < 128; n++) {
            lastValues[n] = -1;
        }
    }

    void setValue(int value, int cc) {
            if (value == lastValues[cc])
                return;
            lastValues[cc] = value;
            // CC
            midi::Message m;
            m.setStatus(0xb);
            m.setNote(cc);
            m.setValue(value);
            sendMessage(m);
        }
    };


struct Mp09 : Module {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
          ENUMS(CC_INPUTS, numControllers),
//          BD_1_INPUT,
//          BD_2_INPUT,
//          BD_3_INPUT,
//          BD_4_INPUT,
//          SD_5_INPUT,
//          SD_6_INPUT,
//          SD_7_INPUT,
//          SD_8_INPUT,
//          LT_9_INPUT,
//          LT_10_INPUT,
//          LT_11_INPUT,
//          MT_12_INPUT,
//          MT_13_INPUT,
//          MT_14_INPUT,
//          HT_15_INPUT,
//          HT_16_INPUT,
//          HT_17_INPUT,
//          RS_18_INPUT,
//          RS_19_INPUT,
//          RS_20_INPUT,
//          HC_21_INPUT,
//          HC_22_INPUT,
//          HC_23_INPUT,
//          CH_24_INPUT,
//          CH_25_INPUT,
//          CH_26_INPUT,
//          OH_27_INPUT,
//          OH_28_INPUT,
//          OH_29_INPUT,
//          CC_30_INPUT,
//          CC_31_INPUT,
//          CC_32_INPUT,
//          RC_33_INPUT,
//          RC_34_INPUT,
//          RC_35_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        NUM_OUTPUTS
    };
    enum LightIds {
        NUM_LIGHTS
    };
    
    
    CCMidiOutput midiOutput;
    
    float rateLimitPhase;

    Mp09() {
        config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
        onReset();
    }
    
    void onReset() override {
        midiOutput.reset();
        midiOutput.midi::Output::reset();
    }
    
    void process(const ProcessArgs &args) override {
        const float rateLimiterPeriod = 0.010f;
        rateLimitPhase += args.sampleTime / rateLimiterPeriod;
        if (rateLimitPhase >= 1.f) {
            rateLimitPhase -= 1.f;
        } else {
            return;
        }
        
        
        
        for (int i = 0; i < numControllers; i++) {
                int value = (int) std::round(inputs[CC_INPUTS + i].getVoltage() / 10.f * 127);
                value = clamp(value, 0, 127);
                midiOutput.setValue(value, ccs[i]);
            }
        }
    
        // saves the selected midi interface
        json_t *dataToJson() override {
            json_t *rootJ = json_object();
            json_object_set_new(rootJ, "midi", midiOutput.toJson());
            return rootJ;
        }

        // restore the saved midi interface
        void dataFromJson(json_t* rootJ) override {
            json_t* midiJ = json_object_get(rootJ, "midi");
            if (midiJ)
                midiOutput.fromJson(midiJ);
        }

    };

        


struct Mp09Widget : ModuleWidget {
    Mp09Widget(Mp09 *module) {
        setModule(module);
        setPanel(APP->window->loadSvg(asset::plugin(pluginInstance, "res/CV-09.svg")));
        
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addChild(createWidget<ScrewSilver>(
                Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

   
    addInput(createInputCentered<PJ301M>(mm2px(Vec(8.36, 21.95)), module, Mp09::CC_INPUTS + 0));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(8.36, 35.95)), module, Mp09::CC_INPUTS + 1));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(20.49, 35.95)), module, Mp09::CC_INPUTS + 2));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(20.49, 21.95)), module, Mp09::CC_INPUTS + 3));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(32.61, 21.95)), module, Mp09::CC_INPUTS + 4));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(32.61, 35.95)), module, Mp09::CC_INPUTS + 5));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(44.74, 35.95)), module, Mp09::CC_INPUTS + 6));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(44.74, 21.95)), module, Mp09::CC_INPUTS + 7));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(58.88, 21.95)), module, Mp09::CC_INPUTS + 8));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(58.88, 35.95)), module, Mp09::CC_INPUTS + 9));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(58.88, 49.95)), module, Mp09::CC_INPUTS + 10));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(75.05, 21.95)), module, Mp09::CC_INPUTS + 11));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(75.05, 35.95)), module, Mp09::CC_INPUTS + 12));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(75.05, 49.95)), module, Mp09::CC_INPUTS + 13));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(91.21, 21.95)), module, Mp09::CC_INPUTS + 14));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(91.21, 35.95)), module, Mp09::CC_INPUTS + 15));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(91.21, 49.95)), module, Mp09::CC_INPUTS + 16));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(8.36, 68.75)), module, Mp09::CC_INPUTS + 17));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(8.36, 82.75)), module, Mp09::CC_INPUTS + 18));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(8.36, 96.75)), module, Mp09::CC_INPUTS + 19));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(20.49, 68.75)), module, Mp09::CC_INPUTS + 20));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(20.49, 82.75)), module, Mp09::CC_INPUTS + 21));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(20.49, 96.75)), module, Mp09::CC_INPUTS + 22));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(32.61, 68.75)), module, Mp09::CC_INPUTS + 23));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(32.61, 82.75)), module, Mp09::CC_INPUTS + 24));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(32.61, 96.75)), module, Mp09::CC_INPUTS + 25));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(44.74, 68.75)), module, Mp09::CC_INPUTS + 26));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(44.74, 82.75)), module, Mp09::CC_INPUTS + 27));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(44.74, 96.75)), module, Mp09::CC_INPUTS + 28));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(75.05, 68.75)), module, Mp09::CC_INPUTS + 29));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(75.05, 82.75)), module, Mp09::CC_INPUTS + 30));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(75.05, 96.75)), module, Mp09::CC_INPUTS + 31));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(91.21, 68.75)), module, Mp09::CC_INPUTS + 32));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(91.21, 82.75)), module, Mp09::CC_INPUTS + 33));
    addInput(createInputCentered<PJ301M>(mm2px(Vec(91.21, 96.75)), module, Mp09::CC_INPUTS + 34));

        
    auto* midiAInWidget = createWidget<MidiWidget> (mm2px (Vec(31, 104)));
                midiAInWidget->box.size = mm2px (Vec (40, 18));
                midiAInWidget->setMidiPort (module ? &module->midiOutput : NULL);
                addChild (midiAInWidget);
            }
        };



Model *modelMp09 = createModel<Mp09,Mp09Widget>("Mp09");
