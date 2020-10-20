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
    momentary = false;
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ButtonMp.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/ButtonMp.svg")));
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

struct MpData : SvgSwitch {
MpData() {

    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_0.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_1.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_2.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_3.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_4.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_5.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_6.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_7.svg")));

    sw->wrap();
    box.size = sw->box.size;
    shadow->hide ();
    
    }
};
 


// Lit Svg Widget, Thanks to Aria Salvatrice https://github.com/AriaSalvatrice

// ---- BASE For Light SVG WIDGETS----

struct LitSvgWidget : LightWidget {
    FramebufferWidget *fb;
    std::shared_ptr<Svg> svg;
    bool hidden = false;

    void wrap() {
        if (svg && svg->handle) {
            box.size = math::Vec(svg->handle->width, svg->handle->height);
        }
        else {
            box.size = math::Vec();
        }
    }

    void setSvg(std::shared_ptr<Svg> svg) {
        this->svg = svg;
        hidden = false;
        wrap();
    }

    void hide() {
        hidden = true;
    }

    void show() {
        hidden = false;
    }

    void draw(const DrawArgs& args) override {
        if (svg && svg->handle && !hidden) {
            svgDraw(args.vg, svg->handle);
        }
    }
};


// This is a SvgSwitch with special support for Lights Off: every frame past the first
// is displayed as a lit overlay, while the first frame is constantly displayed unlit.
struct LitSvgSwitch : Switch {
    FramebufferWidget* fb;
    CircularShadow* shadow;
    SvgWidget* sw;
    LitSvgWidget* lsw;
    std::vector<std::shared_ptr<Svg>> frames;

    LitSvgSwitch()  {
        fb = new FramebufferWidget;
        addChild(fb);

        shadow = new CircularShadow;
        fb->addChild(shadow);
        shadow->box.size = math::Vec();

        sw = new SvgWidget;
        fb->addChild(sw);

        lsw = new LitSvgWidget;
        fb->addChild(lsw);
    }

    /** Adds an SVG file to represent the next switch position */
    void addFrame(std::shared_ptr<Svg> svg) {
        frames.push_back(svg);
        // If this is our first frame, automatically set SVG and size
        if (!sw->svg) {
            sw->setSvg(svg);
            box.size = sw->box.size;
            lsw->box.size = sw->box.size;
            fb->box.size = sw->box.size;
            // Move shadow downward by 10%
            shadow->box.size = sw->box.size;
            shadow->box.pos = math::Vec(0, sw->box.size.y * 0.10);
        }
    }

    void onChange(const event::Change& e) override {
        if (!frames.empty() && paramQuantity) {
            int index = (int) std::round(paramQuantity->getValue() - paramQuantity->getMinValue());
            index = math::clamp(index, 0, (int) frames.size() - 1);
            sw->setSvg(frames[0]);
            if (index >= 0) {
                lsw->setSvg(frames[index]);
            } else {
                lsw->hide();
            }
            fb->dirty = true;
        }
        ParamWidget::onChange(e);
    }
 
};



struct MpDataLight : LitSvgSwitch {
MpDataLight() {

    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_0.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_1.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_2.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_3.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_4.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_5.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_6.svg")));
    addFrame(APP->window->loadSvg(asset::plugin(pluginInstance,"res/MpData_7.svg")));

    sw->wrap();
    box.size = sw->box.size;
    shadow->hide ();
    
    }
};
 


