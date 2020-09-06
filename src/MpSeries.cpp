#include "MpSeries.hpp"
#include <math.h>
    float getSampleRate()
    {
        return APP->engine->getSampleRate();
    }

Plugin* pluginInstance;
void init(rack::Plugin *p) {
    pluginInstance = p;
    
    p->addModel(modelMpMapper);
}
