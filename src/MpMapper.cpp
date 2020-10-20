#include "MpSeries.hpp"
#include "onChange.h"
#include "intToString.h"


//switch color of textfield
static int sC;


struct MpMapper : Module {
    
    //ClockDivider to process only every N samples for optimisation.

    dsp::ClockDivider UpdateDivider;

    onChange onChange_on_1;
    onChange onChange_on_2;
    onChange onChange_on_3;
    onChange onChange_on_4;
    
    onChange onChange_on_5;
    onChange onChange_on_6;
    onChange onChange_on_7;
    onChange onChange_on_8;
    
    onChange onChange_on_9;
    onChange onChange_on_10;
    onChange onChange_on_11;
    onChange onChange_on_12;


    intToString ValueDisplayText;
    intToString KnobDisplayNumber;

    intToString ThreeZerosText;
    intToString PresetNameText;
    intToString ctrlText;
    intToString DataText;

    

    char ValueDisplayScreen[4] = "";
    
    char KnobDisplayScreen[4] = "";


    char ThreeZerosScreen[8] = "";
    
    char PresetNameScreen[9] = "";

    char ctrlScreen[5] = "";
    
    char DataScreen[5] = "";
    
    char lineScreen[5] = "";

    
    enum ParamIds {
           kno_1_PARAM,
           kno_2_PARAM,
           kno_3_PARAM,
           kno_4_PARAM,
           kno_5_PARAM,
           kno_6_PARAM,
           kno_7_PARAM,
           kno_8_PARAM,
           kno_9_PARAM,
           kno_10_PARAM,
           kno_11_PARAM,
           kno_12_PARAM,
        ControlBank,
        dataDisplay,
        NUM_PARAMS

    };
    enum InputIds {
        NUM_INPUTS
    };
    enum OutputIds {
        mod_1_OUTPUT,
        mod_2_OUTPUT,
        mod_3_OUTPUT,
        mod_4_OUTPUT,
        mod_5_OUTPUT,
        mod_6_OUTPUT,
        mod_7_OUTPUT,
        mod_8_OUTPUT,
        mod_9_OUTPUT,
        mod_10_OUTPUT,
        mod_11_OUTPUT,
        mod_12_OUTPUT,
        NUM_OUTPUTS
    };
    enum LightIds {
        MpkYellowLight,
        MpkGreenLight,
        NUM_LIGHTS
    };


    
    void process(const ProcessArgs &args)override;
MpMapper() {
    config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
    configParam(kno_1_PARAM, 0, 10, 0, "K1");
    configParam(kno_2_PARAM, 0, 10, 0, "K2");
    configParam(kno_3_PARAM, 0, 10, 0, "K3");
    configParam(kno_4_PARAM, 0, 10, 0, "K4");
    configParam(kno_5_PARAM, 0, 10, 0, "K5");
    configParam(kno_6_PARAM, 0, 10, 0, "K6");
    configParam(kno_7_PARAM, 0, 10, 0, "K7");
    configParam(kno_8_PARAM, 0, 10, 0, "K8");
    configParam(kno_9_PARAM, 0, 10, 0, "K9");
    configParam(kno_10_PARAM, 0, 10, 0, "K10");
    configParam(kno_11_PARAM, 0, 10, 0, "K11");
    configParam(kno_12_PARAM, 0, 10, 0, "K12");
    configParam(MpkYellowLight, 0, 10, 0, "Conrol Bank A");
    configParam(MpkGreenLight, 0, 10, 0, "Conrol Bank B");
    configParam(ControlBank, 0, 1, 0, "Conrol Bank Button");
    configParam(dataDisplay, 0, 7, 0, "0-127 Midi Data Indicator");

    UpdateDivider.setDivision(128);

    }
};


void MpMapper::process(const ProcessArgs &args) {
    if (UpdateDivider.process()) {
        
        // Switch color ( MpLedDisplaytext Widget)
     sC = params[ControlBank].getValue();
        
        //    set light color Yellow Or Green , Bank A or Bank B

    float ControlBank_output = params[ControlBank].getValue();
    
        if (ControlBank_output  < 1) {
            lights[MpkYellowLight].setBrightness (1.f);
            lights[MpkGreenLight].setBrightness (0.f);

            
        } else {
            lights[MpkYellowLight].setBrightness (0.f);
            lights[MpkGreenLight].setBrightness (1.f);


        };
        

        
           



    // Output Knob value to Module Outputs

    float kno_1_PARAM_output = params[kno_1_PARAM].getValue();
    float kno_2_PARAM_output = params[kno_2_PARAM].getValue();
    float kno_3_PARAM_output = params[kno_3_PARAM].getValue();
    float kno_4_PARAM_output = params[kno_4_PARAM].getValue();
    
    float kno_5_PARAM_output = params[kno_5_PARAM].getValue();
    float kno_6_PARAM_output = params[kno_6_PARAM].getValue();
    float kno_7_PARAM_output = params[kno_7_PARAM].getValue();
    float kno_8_PARAM_output = params[kno_8_PARAM].getValue();
    
    float kno_9_PARAM_output = params[kno_9_PARAM].getValue();
    float kno_10_PARAM_output = params[kno_10_PARAM].getValue();
    float kno_11_PARAM_output = params[kno_11_PARAM].getValue();
    float kno_12_PARAM_output = params[kno_12_PARAM].getValue();
    
    
    outputs[mod_1_OUTPUT].setVoltage ( kno_1_PARAM_output);
    outputs[mod_2_OUTPUT].setVoltage ( kno_2_PARAM_output);
    outputs[mod_3_OUTPUT].setVoltage ( kno_3_PARAM_output);
    outputs[mod_4_OUTPUT].setVoltage ( kno_4_PARAM_output);
    
    outputs[mod_5_OUTPUT].setVoltage ( kno_5_PARAM_output);
    outputs[mod_6_OUTPUT].setVoltage ( kno_6_PARAM_output);
    outputs[mod_7_OUTPUT].setVoltage ( kno_7_PARAM_output);
    outputs[mod_8_OUTPUT].setVoltage ( kno_8_PARAM_output);
    
    outputs[mod_9_OUTPUT].setVoltage ( kno_9_PARAM_output);
    outputs[mod_10_OUTPUT].setVoltage ( kno_10_PARAM_output);
    outputs[mod_11_OUTPUT].setVoltage ( kno_11_PARAM_output);
    outputs[mod_12_OUTPUT].setVoltage ( kno_12_PARAM_output);
    

    
    //    On Change
        
    
        onChange_on_1.setinput(kno_1_PARAM_output);
        float on_1_output = onChange_on_1.getoutput();
        
        onChange_on_2.setinput(kno_2_PARAM_output);
        float on_2_output = onChange_on_2.getoutput();

        onChange_on_3.setinput(kno_3_PARAM_output);
        float on_3_output = onChange_on_3.getoutput();

        onChange_on_4.setinput(kno_4_PARAM_output);
        float on_4_output = onChange_on_4.getoutput();
        
        onChange_on_5.setinput(kno_5_PARAM_output);
        float on_5_output = onChange_on_5.getoutput();
        
        onChange_on_6.setinput(kno_6_PARAM_output);
        float on_6_output = onChange_on_6.getoutput();

        onChange_on_7.setinput(kno_7_PARAM_output);
        float on_7_output = onChange_on_7.getoutput();

        onChange_on_8.setinput(kno_8_PARAM_output);
        float on_8_output = onChange_on_8.getoutput();
        
        onChange_on_9.setinput(kno_9_PARAM_output);
        float on_9_output = onChange_on_9.getoutput();
        
        onChange_on_10.setinput(kno_10_PARAM_output);
        float on_10_output = onChange_on_10.getoutput();

        onChange_on_11.setinput(kno_11_PARAM_output);
        float on_11_output = onChange_on_11.getoutput();

        onChange_on_12.setinput(kno_12_PARAM_output);
        float on_12_output = onChange_on_12.getoutput();


    float dou2_out = 12.8;

    //     multiply knob value [0-10] by 12.8 to get screen show range of 0-127
    //  [0-10] * 12.8 = Screen Display Value

    float OP100A = kno_1_PARAM_output*dou2_out;
    float OP101A = kno_2_PARAM_output*dou2_out;
    float OP102A = kno_3_PARAM_output*dou2_out;
    float OP103A = kno_4_PARAM_output*dou2_out;
    float OP104A = kno_5_PARAM_output*dou2_out;
    float OP105A = kno_6_PARAM_output*dou2_out;
    float OP106A = kno_7_PARAM_output*dou2_out;
    float OP107A = kno_8_PARAM_output*dou2_out;
    float OP108A = kno_9_PARAM_output*dou2_out;
    float OP109A = kno_10_PARAM_output*dou2_out;
    float OP110A = kno_11_PARAM_output*dou2_out;
    float OP111A = kno_12_PARAM_output*dou2_out;


//  OP100C = (1* Value)

    float OP100C = on_1_output*OP100A;
    float OP101C = on_2_output*OP101A;
    float OP102C = on_3_output*OP102A;
    float OP103C = on_4_output*OP103A;
    float OP104C = on_5_output*OP104A;
    float OP105C = on_6_output*OP105A;
    float OP106C = on_7_output*OP106A;
    float OP107C = on_8_output*OP107A;
    float OP108C = on_9_output*OP108A;
    float OP109C = on_10_output*OP109A;
    float OP110C = on_11_output*OP110A;
    float OP111C = on_12_output*OP111A;



    ValueDisplayText.setinput(OP100C + OP101C + OP102C + OP103C + OP104C + OP105C + OP106C + OP107C + OP108C + OP109C + OP110C + OP111C );
        float K1changed = on_1_output* +1;
        float K2changed = on_2_output* 2;
        float K3changed = on_3_output* 3;
        float K4changed = on_4_output* 4;
        float K5changed = on_5_output* 5;
        float K6changed = on_6_output* 6;
        float K7changed = on_7_output* 7;
        float K8changed = on_8_output* 8;
        float K9changed = on_9_output* 9;
        float K10changed = on_10_output* 10;
        float K11changed = on_11_output* 11;
        float K12changed = on_12_output* 12;
        
    KnobDisplayNumber.setinput(K1changed + K2changed + K3changed + K4changed + K5changed + K6changed + K7changed + K8changed + K9changed + K10changed + K11changed + K12changed );
        
        
        // ( K1, K2 ,K3 etc..)
    char *KnobDisplayNumber_output = KnobDisplayNumber.getoutput();

    // ( 0-127 Knob Value )
    char *ValueDisplayText_output = ValueDisplayText.getoutput();
        
    // ( 000 )
    char *ThreeZerosText_output = ThreeZerosText.getoutput();

        
    // ( PRESET NAME )
    char *PresetNameText_output = PresetNameText.getoutput();
        
    // ("CTRL")
    char *ctrlText_output = ctrlText.getoutput();
        
    // ( "DATA" )
    char *DataText_output = DataText.getoutput();


        
        
        
        // copy text to screen
        

        strcpy(KnobDisplayScreen, KnobDisplayNumber_output);
        
    // 0-127 Knob Value
        strcpy(ValueDisplayScreen, ValueDisplayText_output);
        
    // ( 000 )
        strcpy(ThreeZerosScreen, ThreeZerosText_output);

    // PRESET NAME
        strcpy(PresetNameScreen, PresetNameText_output);

    // CTRL
        strcpy(ctrlScreen, ctrlText_output);
        
    // ( "DATA" )
        strcpy(DataScreen, DataText_output);
    
    
    //    Control DataDisplay
    
    float dou3_out = 12.8;

    float OP100D = OP100C/dou3_out;
    float OP101D = OP101C/dou3_out;
    float OP102D = OP102C/dou3_out;
    float OP103D = OP103C/dou3_out;
    float OP104D = OP104C/dou3_out;
    float OP105D = OP105C/dou3_out;
    float OP106D = OP106C/dou3_out;
    float OP107D = OP107C/dou3_out;
    float OP108D = OP108C/dou3_out;
    float OP109D = OP109C/dou3_out;
    float OP110D = OP110C/dou3_out;
    float OP111D = OP111C/dou3_out;

    
    
    params[dataDisplay].setValue (OP100D + OP101D + OP102D + OP103D + OP104D + OP105D + OP106D + OP107D + OP108D + OP109D + OP110D + OP111D );



}
};

struct MpMapperWidget : ModuleWidget {
    
    
    
    TextField* textField1;
    TextField* textField2;
    TextField* textField3;
    TextField* textField4;
    TextField* textField5;
    TextField* textField6;



    json_t* toJson() override {
        json_t* rootJ = ModuleWidget::toJson();

        // text
        json_object_set_new(rootJ, "text1", json_string(textField1->text.c_str()));
        json_object_set_new(rootJ, "text2", json_string(textField2->text.c_str()));
        json_object_set_new(rootJ, "text3", json_string(textField3->text.c_str()));
        json_object_set_new(rootJ, "text4", json_string(textField4->text.c_str()));
        json_object_set_new(rootJ, "text5", json_string(textField5->text.c_str()));
        json_object_set_new(rootJ, "text6", json_string(textField6->text.c_str()));


        return rootJ;
    }
    
    
    void fromJson(json_t* rootJ) override {
        ModuleWidget::fromJson(rootJ);

        // text  ( Group 1)
        json_t* text1 = json_object_get(rootJ, "text1");
        if (text1)
        textField1->text = json_string_value(text1);
        
        json_t* text2= json_object_get(rootJ, "text2");
        if (text2)
        textField2->text = json_string_value(text2);

        json_t* text3 = json_object_get(rootJ, "text3");
        if (text3)
        textField3->text = json_string_value(text3);

        // text  ( Group 2)

        json_t* text4 = json_object_get(rootJ, "text4");
        if (text4)
        textField4->text = json_string_value(text4);
        
        json_t* text5= json_object_get(rootJ, "text5");
        if (text5)
        textField5->text = json_string_value(text5);

        json_t* text6 = json_object_get(rootJ, "text6");
        if (text6)
        textField6->text = json_string_value(text6);

    
    }
    



    struct screen_MpMapper : LightWidget {
        MpMapper *module;
        std::shared_ptr<Font> font;
        screen_MpMapper () {
            font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/Segment14.ttf"));

        }
        
        
        //  ( 0-127 VALUE )
        void TextUpdate(NVGcontext *vg, Vec pos, NVGcolor DMDtextColor, char* Text) {
            //font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/Segment14.ttf"));

        nvgFontSize(vg, 12);
        nvgFontFaceId(vg, font->handle);
        nvgTextLetterSpacing(vg, 0);
        nvgFillColor(vg, nvgTransRGBA(nvgRGB( 230, 230, 230), 0xff));
        nvgText(vg, pos.x, pos.y, Text, NULL);
        }
    
        //  ( PRESET NAME)

            void TextUpdate2(NVGcontext *vg, Vec pos, NVGcolor DMDtextColor, char* Text) {
                //font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/LEDCounter7.ttf"));
            nvgFontSize(vg, 12);
            nvgFontFaceId(vg, font->handle);
            nvgTextLetterSpacing(vg, 0);
            nvgFillColor(vg, nvgTransRGBA(nvgRGB( 230, 230, 230), 0xff));
            nvgText(vg, pos.x, pos.y, "MpMapper", NULL);
            }
        
        
        //  ( 000 )

            void TextUpdate3(NVGcontext *vg, Vec pos, NVGcolor DMDtextColor, char* Text) {
            //font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/DSEG14Modern-Regular.ttf"));

            nvgFontSize(vg, 12);
            nvgFontFaceId(vg, font->handle);
            nvgTextLetterSpacing(vg, 0);
            nvgFillColor(vg, nvgTransRGBA(nvgRGB( 61, 83, 160), 0xff));
            nvgText(vg, pos.x, pos.y, "~~~", NULL);
            }
        
        
        //  ( "CTRL" )

            void TextUpdate4(NVGcontext *vg, Vec pos, NVGcolor DMDtextColor, char* Text) {
                //font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/Segment14.ttf"));

            nvgFontSize(vg, 3.5);
            nvgFontFaceId(vg, font->handle);
            nvgTextLetterSpacing(vg, 0);
            nvgFillColor(vg, nvgTransRGBA(nvgRGB( 230, 230, 230), 0xff));
            nvgText(vg, pos.x, pos.y, "CTRL", NULL);
            }
        
        //  ( "DATA" )

            void TextUpdate5(NVGcontext *vg, Vec pos, NVGcolor DMDtextColor, char* Text) {
                //font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/Segment14.ttf"));

            nvgFontSize(vg, 3);
            nvgFontFaceId(vg, font->handle);
            nvgTextLetterSpacing(vg, 0);
            nvgFillColor(vg, nvgTransRGBA(nvgRGB( 230, 230, 230), 0xff));
            nvgText(vg, pos.x, pos.y, "DATA", NULL);
            }
        
         // Line Shape
            void line(NVGcontext *vg, Vec pos, NVGcolor, char* text ) {
            nvgBeginPath(vg);
            nvgRect(vg, -51, -10, 84,0.7);
            nvgFillColor(vg, nvgRGBA(230, 230, 230,255));
            nvgFill(vg);
            }
        
        // Knob Number
            void TextUpdate6(NVGcontext *vg, Vec pos, NVGcolor DMDtextColor, char* Text) {
                //font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/Segment14.ttf"));

            nvgFontSize(vg, 12);
            nvgFontFaceId(vg, font->handle);
            nvgTextLetterSpacing(vg, 0);
            nvgFillColor(vg, nvgTransRGBA(nvgRGB( 230, 230, 230), 0xff));
            nvgText(vg, pos.x, pos.y, Text, NULL);
            }

            

    
        
        
        
        void draw(const DrawArgs &args) override {
        
        if(module){
            
            //  ( 000 )
          TextUpdate3(args.vg,Vec( 5, 5), nvgRGB(0x08, 0x08, 0x08), module->ThreeZerosScreen);
            
          TextUpdate3(args.vg,Vec( -37, 5), nvgRGB(0x08, 0x08, 0x08), module->ThreeZerosScreen);


            // 0-127 Value
          TextUpdate(args.vg, Vec( 5, 5), nvgRGB(0x08, 0x08, 0x08), module->ValueDisplayScreen);
            
            // PRESET
          TextUpdate2(args.vg,Vec(-50, -13), nvgRGB(0x08, 0x08, 0x08), module->PresetNameScreen);

            // CTRL
          TextUpdate4(args.vg,Vec( -50, -3), nvgRGB(0x08, 0x08, 0x08), module->ctrlScreen);
            
            // DATA
            TextUpdate5(args.vg,Vec( 23, 10), nvgRGB(0x08, 0x08, 0x08), module->DataScreen);
            
            // 1 , 2 , 3 .... 12
            TextUpdate6(args.vg,Vec( -37, 5), nvgRGB(0x08, 0x08, 0x08), module->KnobDisplayScreen);

            // Line shape
            line(args.vg,Vec(0,0), nvgRGB(0x08, 0x08, 0x08), module->lineScreen);


            
         }
        }
        
        
              
    };
  


    
   MpMapperWidget(MpMapper *module);


};

MpMapperWidget::MpMapperWidget(MpMapper *module) {
    
   setModule(module);
   box.size = Vec(270, 380);
   {
       SvgPanel *panel = new SvgPanel();
       panel->box.size = box.size;
       panel->setBackground(APP->window->loadSvg(asset::plugin(pluginInstance, "res/MpMapper.svg")));
       addChild(panel);
    }
    
    
    {
        screen_MpMapper *display_screen= new screen_MpMapper();
        display_screen->module = module;
        display_screen->box.pos = Vec(140, 42);
        display_screen->box.size = Vec(234, 234);
        addChild(display_screen);
    }
    
    


    struct MpLedDisplayText : LedDisplayTextField {
        MpLedDisplayText() {
        font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/ShareTechMono-Regular.ttf"));
        color = nvgRGB(243, 205, 19);
        textOffset = math::Vec(1, 0);
        box.size = mm2px(Vec(84.5, 6));
            visible = true;
            multiline = false;
            
            

            }
                                 
        void onChange(const event::Change& e) override {

            if (sC < 1) {
                
                color = nvgRGB(243, 205, 19);
            } else {
                color = nvgRGB(154, 213, 66);
            }
        
            

            }

    };


   

    struct MpLedDisplayText2 : LedDisplayTextField {
        MpLedDisplayText2() {
                // TO DO -  change font to smaller one using  DSEG fonts(downloads)
      font = APP->window->loadFont(asset::plugin(pluginInstance, "res/fonts/ShareTechMono-Regular.ttf"));
        color = nvgRGB( 230, 230, 230);
        textOffset = math::Vec(1, 0);
        box.size = mm2px(Vec(84.5, 6));

            visible = true;
            multiline = false;

          }

    };



//      -----   ( Group 1  ) -----
    

    textField1 = createWidget<MpLedDisplayText>(Vec(10.2,81));
    addChild(textField1);
    textField2 = createWidget<MpLedDisplayText>(Vec(10.2,177));
    
    addChild(textField2);
    
    textField3 = createWidget<MpLedDisplayText>(Vec(10.2,273));
    addChild(textField3);
    

    
    //      -----   ( Group 2  ) -----   (x , y+20)

    
    textField4 = createWidget<MpLedDisplayText2>(Vec(10.2,101));
    addChild(textField4);
    
    textField5 = createWidget<MpLedDisplayText2>(Vec(10.2,197));
    addChild(textField5);

    textField6 = createWidget<MpLedDisplayText2>(Vec(10.2,293));
    addChild(textField6);


    
//    mpBKnobs
    
     // Knob number, pos in svg file ( x+11 , y+37)
    
    addParam(createParam<mpBKnob>(Vec(30,123), module, MpMapper::kno_1_PARAM));
    addParam(createParam<mpBKnob>(Vec(89,123), module, MpMapper::kno_2_PARAM));
    addParam(createParam<mpBKnob>(Vec(149,123), module, MpMapper::kno_3_PARAM));
    addParam(createParam<mpBKnob>(Vec(208,123), module, MpMapper::kno_4_PARAM));


    addParam(createParam<mpBKnob>(Vec(30,219), module, MpMapper::kno_5_PARAM));
    addParam(createParam<mpBKnob>(Vec(89,219), module, MpMapper::kno_6_PARAM));
    addParam(createParam<mpBKnob>(Vec(149,219), module, MpMapper::kno_7_PARAM));
    addParam(createParam<mpBKnob>(Vec(208,219), module, MpMapper::kno_8_PARAM));
    

    addParam(createParam<mpBKnob>(Vec(30,315), module, MpMapper::kno_9_PARAM));
    addParam(createParam<mpBKnob>(Vec(89,315), module, MpMapper::kno_10_PARAM));
    addParam(createParam<mpBKnob>(Vec(149,315), module, MpMapper::kno_11_PARAM));
    addParam(createParam<mpBKnob>(Vec(208,315), module, MpMapper::kno_12_PARAM));
    
//  Jacks
    int xOffset = 6;
    int yOffset = (-3);
    addOutput(createOutput<jack>(Vec(53+xOffset,150+yOffset), module, MpMapper::mod_1_OUTPUT));
    addOutput(createOutput<jack>(Vec(112+xOffset,150+yOffset), module, MpMapper::mod_2_OUTPUT));
    addOutput(createOutput<jack>(Vec(172+xOffset,150+yOffset), module, MpMapper::mod_3_OUTPUT));
    addOutput(createOutput<jack>(Vec(231+xOffset,150+yOffset), module, MpMapper::mod_4_OUTPUT));
    
    addOutput(createOutput<jack>(Vec(53+xOffset,246+yOffset), module, MpMapper::mod_5_OUTPUT));
    addOutput(createOutput<jack>(Vec(112+xOffset,246+yOffset), module, MpMapper::mod_6_OUTPUT));
    addOutput(createOutput<jack>(Vec(172+xOffset,246+yOffset), module, MpMapper::mod_7_OUTPUT));
    addOutput(createOutput<jack>(Vec(231+xOffset,246+yOffset), module, MpMapper::mod_8_OUTPUT));
    
    addOutput(createOutput<jack>(Vec(53+xOffset,342+yOffset), module, MpMapper::mod_9_OUTPUT));
    addOutput(createOutput<jack>(Vec(112+xOffset,342+yOffset), module, MpMapper::mod_10_OUTPUT));
    addOutput(createOutput<jack>(Vec(172+xOffset,342+yOffset), module, MpMapper::mod_11_OUTPUT));
    addOutput(createOutput<jack>(Vec(231+xOffset,342+yOffset), module, MpMapper::mod_12_OUTPUT));
    

//Lights
    
    
    addChild(createLight<SmallLight<YellowLight>>(Vec(215,22), module, MpMapper::MpkYellowLight));
    addChild(createLight<SmallLight<GreenLight>>(Vec(231,22), module, MpMapper::MpkGreenLight));
    addParam(createParam<ButtonMp>(Vec(217,43), module, MpMapper::ControlBank));
    
//    Screen
    
    addParam(createParam<MpDataLight>(Vec(151,53), module, MpMapper::dataDisplay));

    
    
    
    
    // Screws
    
    addChild(createWidget<screw>(Vec(RACK_GRID_WIDTH, 0)));
    addChild(createWidget<screw>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
    addChild(createWidget<screw>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
    addChild(createWidget<screw>(
            Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));



}

Model *modelMpMapper = createModel<MpMapper,MpMapperWidget>("MpMap");
