#include "MpSeries.hpp"

struct MpMapper : Module {
    enum ParamIds {
           kno_303_PARAM,
           kno_302_PARAM,
           kno_301_PARAM,
           kno_300_PARAM,
           kno_309_PARAM,
           kno_310_PARAM,
           kno_311_PARAM,
           kno_312_PARAM,
           kno_323_PARAM,
           kno_324_PARAM,
           kno_325_PARAM,
           kno_326_PARAM,
        NUM_PARAMS
    };
    enum InputIds {
        NUM_INPUTS
    };
    enum OutputIds {
          mod_320_OUTPUT,
          mod_327_OUTPUT,
          mod_328_OUTPUT,
          mod_329_OUTPUT,
          mod_330_OUTPUT,
          mod_331_OUTPUT,
          mod_332_OUTPUT,
          mod_333_OUTPUT,
          mod_339_OUTPUT,
          mod_341_OUTPUT,
          mod_342_OUTPUT,
          mod_343_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        NUM_LIGHTS 
    };
    void process(const ProcessArgs &args)override;
MpMapper() {
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(kno_303_PARAM, 0, 10, 0);
    configParam(kno_302_PARAM, 0, 10, 0);
    configParam(kno_301_PARAM, 0, 10, 0);
    configParam(kno_300_PARAM, 0, 10, 0);
    configParam(kno_309_PARAM, 0, 10, 0);
    configParam(kno_310_PARAM, 0, 10, 0);
    configParam(kno_311_PARAM, 0, 10, 0);
    configParam(kno_312_PARAM, 0, 10, 0);
    configParam(kno_323_PARAM, 0, 10, 0);
    configParam(kno_324_PARAM, 0, 10, 0);
    configParam(kno_325_PARAM, 0, 10, 0);
    configParam(kno_326_PARAM, 0, 10, 0);
}
};

void MpMapper::process(const ProcessArgs &args) {
    float kno_303_PARAM_output = params[kno_303_PARAM].getValue();
    float kno_302_PARAM_output = params[kno_302_PARAM].getValue();
    float kno_301_PARAM_output = params[kno_301_PARAM].getValue();
    float kno_300_PARAM_output = params[kno_300_PARAM].getValue();
    float kno_309_PARAM_output = params[kno_309_PARAM].getValue();
    float kno_310_PARAM_output = params[kno_310_PARAM].getValue();
    float kno_311_PARAM_output = params[kno_311_PARAM].getValue();
    float kno_312_PARAM_output = params[kno_312_PARAM].getValue();
    float kno_323_PARAM_output = params[kno_323_PARAM].getValue();
    float kno_324_PARAM_output = params[kno_324_PARAM].getValue();
    float kno_325_PARAM_output = params[kno_325_PARAM].getValue();
    float kno_326_PARAM_output = params[kno_326_PARAM].getValue();
    outputs[mod_327_OUTPUT].setVoltage ( kno_300_PARAM_output);
    outputs[mod_328_OUTPUT].setVoltage ( kno_301_PARAM_output);
    outputs[mod_329_OUTPUT].setVoltage ( kno_302_PARAM_output);
    outputs[mod_330_OUTPUT].setVoltage ( kno_303_PARAM_output);
    outputs[mod_331_OUTPUT].setVoltage ( kno_324_PARAM_output);
    outputs[mod_332_OUTPUT].setVoltage ( kno_325_PARAM_output);
    outputs[mod_333_OUTPUT].setVoltage ( kno_326_PARAM_output);
    outputs[mod_339_OUTPUT].setVoltage ( kno_309_PARAM_output);
    outputs[mod_341_OUTPUT].setVoltage ( kno_310_PARAM_output);
    outputs[mod_342_OUTPUT].setVoltage ( kno_311_PARAM_output);
    outputs[mod_343_OUTPUT].setVoltage ( kno_312_PARAM_output);
    outputs[mod_320_OUTPUT].setVoltage ( kno_323_PARAM_output);

}
struct MpMapperWidget : ModuleWidget {
    TextField* textField1;
    TextField* textField2;
    TextField* textField3;


    json_t* toJson() override {
        json_t* rootJ = ModuleWidget::toJson();

        // text
        json_object_set_new(rootJ, "text", json_string(textField1->text.c_str()));
        json_object_set_new(rootJ, "text", json_string(textField2->text.c_str()));
        json_object_set_new(rootJ, "text", json_string(textField3->text.c_str()));

        return rootJ;
    }
    
    
    void fromJson(json_t* rootJ) override {
        ModuleWidget::fromJson(rootJ);

        // text
        json_t* text1 = json_object_get(rootJ, "text");
        if (text1)
        textField1->text = json_string_value(text1);
        
        json_t* text2= json_object_get(rootJ, "text");
        if (text2)
        textField2->text = json_string_value(text2);

        json_t* text3 = json_object_get(rootJ, "text");
        if (text3)
        textField3->text = json_string_value(text3);


    
    }

    
   MpMapperWidget(MpMapper *module);
};

MpMapperWidget::MpMapperWidget(MpMapper *module) {
   setModule(module);
   box.size = Vec(270, 380);
   {
       SvgPanel *panel = new SvgPanel();
       panel->box.size = box.size;
       panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/mpmapper.svg")));
       addChild(panel);
    }
    
    textField1 = createWidget<LedDisplayTextField>(Vec(10.2,81));
    textField1->box.size = mm2px(Vec(84.5, 12));
    textField1->multiline = true;
    addChild(textField1);
    
    textField2 = createWidget<LedDisplayTextField>(Vec(10.2,177));
    textField2->box.size = mm2px(Vec(84.5, 12));
    textField2->multiline = true;
    addChild(textField2);
    
    textField3 = createWidget<LedDisplayTextField>(Vec(10.2,273));
    textField3->box.size = mm2px(Vec(84.5, 12));
    textField3->multiline = true;
    addChild(textField3);
    
//    mpBKnobs
    
    addParam(createParam<mpBKnob>(Vec(30,123), module, MpMapper::kno_300_PARAM));
    addParam(createParam<mpBKnob>(Vec(89,123), module, MpMapper::kno_301_PARAM));
    addParam(createParam<mpBKnob>(Vec(149,123), module, MpMapper::kno_302_PARAM));
    addParam(createParam<mpBKnob>(Vec(208,123), module, MpMapper::kno_303_PARAM));

    addParam(createParam<mpBKnob>(Vec(30,219), module, MpMapper::kno_309_PARAM));
    addParam(createParam<mpBKnob>(Vec(89,219), module, MpMapper::kno_310_PARAM));
    addParam(createParam<mpBKnob>(Vec(149,219), module, MpMapper::kno_311_PARAM));
    addParam(createParam<mpBKnob>(Vec(208,219), module, MpMapper::kno_312_PARAM));
    
    addParam(createParam<mpBKnob>(Vec(30,315), module, MpMapper::kno_323_PARAM));
    addParam(createParam<mpBKnob>(Vec(89,315), module, MpMapper::kno_324_PARAM));
    addParam(createParam<mpBKnob>(Vec(149,315), module, MpMapper::kno_325_PARAM));
    addParam(createParam<mpBKnob>(Vec(208,315), module, MpMapper::kno_326_PARAM));
    
//  Jacks
    
    addOutput(createOutput<jack>(Vec(53,150), module, MpMapper::mod_327_OUTPUT));
    addOutput(createOutput<jack>(Vec(112,150), module, MpMapper::mod_328_OUTPUT));
    addOutput(createOutput<jack>(Vec(172,150), module, MpMapper::mod_329_OUTPUT));
    addOutput(createOutput<jack>(Vec(231,150), module, MpMapper::mod_330_OUTPUT));
    
    addOutput(createOutput<jack>(Vec(53,246), module, MpMapper::mod_339_OUTPUT));
    addOutput(createOutput<jack>(Vec(112,246), module, MpMapper::mod_341_OUTPUT));
    addOutput(createOutput<jack>(Vec(172,246), module, MpMapper::mod_342_OUTPUT));
    addOutput(createOutput<jack>(Vec(231,246), module, MpMapper::mod_343_OUTPUT));
    
    addOutput(createOutput<jack>(Vec(53,342), module, MpMapper::mod_320_OUTPUT));
    addOutput(createOutput<jack>(Vec(112,342), module, MpMapper::mod_331_OUTPUT));
    addOutput(createOutput<jack>(Vec(172,342), module, MpMapper::mod_332_OUTPUT));
    addOutput(createOutput<jack>(Vec(231,342), module, MpMapper::mod_333_OUTPUT));


    
}
Model *modelMpMapper = createModel<MpMapper,MpMapperWidget>("MpMap");
