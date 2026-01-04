#include "plugin.hpp"
#include "imagepanel.cpp"   // Blatantly stolen from Questionable Modules
#include <vector>

const int MODULE_SIZE = 20;

struct UBBO : Module {

};


struct UBBOWidget : ModuleWidget {
    ImagePanel *backdrop = nullptr;
    UBBOWidget(UBBO* module) {
        setModule(module);

        backdrop = new ImagePanel();
                backdrop->box.size = Vec(MODULE_SIZE * RACK_GRID_WIDTH, RACK_GRID_HEIGHT);
                backdrop->imagePath = asset::plugin(pluginInstance, "res/UBBO-new.png");
                backdrop->scalar = 4.0;
                backdrop->visible = true;
        setPanel(backdrop);

        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, 0)));
        addChild(createWidget<ScrewSilver>(Vec(RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));
        addChild(createWidget<ScrewSilver>(Vec(box.size.x - 2 * RACK_GRID_WIDTH, RACK_GRID_HEIGHT - RACK_GRID_WIDTH)));

    }
};

Model* modelUBBO = createModel<UBBO, UBBOWidget>("UBBO");
