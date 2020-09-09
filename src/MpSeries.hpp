#include "rack.hpp" 

using namespace rack;
extern Plugin* pluginInstance;

extern Model* modelMpMapper;
extern Model* modelMp09;



struct jack : SvgPort{
jack() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/jack.svg")));
    }
};
struct mediumKnob : SvgKnob{
mediumKnob() {
    box.size = Vec(25, 25);
    minAngle = -0.75*M_PI;
    maxAngle = 0.75*M_PI;
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/mpKnob.svg")));
    SvgWidget *shadow = new SvgWidget();
    shadow->setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/mediumknobShadow.svg")));
    addChild(shadow);
    }
};
struct switchmpkled_0 : SvgSwitch {
switchmpkled_0() {
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchmpkled_0.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchmpkled_1.svg")));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct mpknobsnap : SvgKnob{
mpknobsnap() {
    box.size = Vec(25, 25);
    minAngle = -0.75*M_PI;
    maxAngle = 0.75*M_PI;
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/mpknob.svg")));
    SvgWidget *shadow = new SvgWidget();
    shadow->setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/mediumRotaryShadow.svg")));
    addChild(shadow);
    }
};
struct mpknobsnap_snap : mpknobsnap{
    mpknobsnap_snap() {
    snap = true;
    }
};
struct mpKnob : SvgKnob{
mpKnob() {
    box.size = Vec(25, 25);
    minAngle = -0.75*M_PI;
    maxAngle = 0.75*M_PI;
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/mpKnob.svg")));
    SvgWidget *shadow = new SvgWidget();
    shadow->setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/mediumknobShadow.svg")));
    addChild(shadow);
    }
};
struct mpBKnob : SvgKnob{
mpBKnob() {
    box.size = Vec(25, 25);
    minAngle = -0.75*M_PI;
    maxAngle = 0.75*M_PI;
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/mpBKnob.svg")));
    SvgWidget *shadow = new SvgWidget();
    shadow->setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/LargeknobShadow.svg")));
    addChild(shadow);
    }
};
struct switch_0 : SvgSwitch {
switch_0() {
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchMpk_0.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchMpk_1.svg")));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct switchMpk_0 : SvgSwitch {
switchMpk_0() {
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchMpk_0.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchMpk_1.svg")));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct mpcvKnob : SvgKnob{
mpcvKnob() {
    box.size = Vec(25, 25);
    minAngle = -0.75*M_PI;
    maxAngle = 0.75*M_PI;
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/mpcvKnob.svg")));
    SvgWidget *shadow = new SvgWidget();
    shadow->setSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/mediumknobShadow.svg")));
    addChild(shadow);
    }
};
struct ButtonMp : SvgSwitch {
    ButtonMp(){
    momentary = true;
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ButtonMp.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ButtonMpPushed.svg")));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct button : SvgSwitch {
    button(){
    momentary = true;
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ButtonMp.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ButtonMpPushed.svg")));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct switchPos_0 : SvgSwitch {
switchPos_0() {
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchPos_0.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchPos_1.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchPos_2.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/switchPos_3.svg")));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct screw : SvgScrew {
screw() {
    sw->svg = APP->window->loadSvg(asset::plugin(pluginInstance,"res/screw.svg"));
    sw->wrap();
    box.size = sw->box.size;
    }
};
struct MpSlider : SvgSlider {
    MpSlider() {
        Vec margin = Vec(3.6, 3.6);
        maxHandlePos = Vec(11.0, 0.0).plus(margin);
        minHandlePos = Vec(11.0, 140.0).plus(margin);
        setBackgroundSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/slider.svg")));
        setHandleSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/sliderhandle.svg")));
        background->box.pos = margin;
        box.size = background->box.size.plus(margin.mult(2));
    }
};

struct MpSlidePot : SvgSlider {
    MpSlidePot() {
        Vec margin = Vec(4, 4);
        maxHandlePos = Vec(0.0, -5.0).plus(margin);
        minHandlePos = Vec(0.0, 90.0).plus(margin);
        setBackgroundSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/SlidePot.svg")));
        setHandleSvg(APP->window->loadSvg(asset::plugin(pluginInstance, "res/SlidePotHandle.svg")));
        background->box.pos = margin;
        box.size = background->box.size.plus(margin.mult(2));
    }
};

struct PJ301M : SvgPort{
PJ301M() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/PJ301M.svg")));
    }
};


