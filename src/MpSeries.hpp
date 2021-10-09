#include "rack.hpp"

using namespace rack;
extern Plugin* pluginInstance;

extern Model* modelMp09;



struct jack : SvgPort{
jack() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/jack.svg")));
    }
};

struct screw : SvgScrew {
screw() {
    sw->svg = APP->window->loadSvg(asset::plugin(pluginInstance,"res/screw.svg"));
    sw->wrap();
    box.size = sw->box.size;
    }
};

struct PJ301M : SvgPort{
PJ301M() {
    setSvg(APP->window->loadSvg(asset::plugin(pluginInstance,"res/PJ301M.svg")));
    }
};

 


