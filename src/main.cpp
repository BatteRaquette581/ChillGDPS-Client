#include <Geode/Geode.hpp>
#include <Geode/modify/GJGarageLayer.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>
#include "ChillClientLayer.hpp"
#include "MyDemonLayer.hpp"

using namespace geode::prelude;
CCSize size = CCDirector::sharedDirector()->getWinSize();

class $modify(PauseLayer) {
	void customSetup() {
        PauseLayer::customSetup();
        ChillClientLayer* layer = ChillClientLayer::create();
        layer->setButtonPosition(ccp(size.width * 0.4, size.height * 0.4));
        layer->createButton();
        addChild(layer);
    }
};

class $modify(GJGarageLayer) {
    bool init() {
        if (!GJGarageLayer::init()) return false;

        ChillClientLayer* layer = ChillClientLayer::create();
        layer->setButtonPosition(ccp(size.width * 0.25, size.height * 0.4));
        layer->createButton();
        addChild(layer);

        return true;
    }
};

class $modify(LevelInfoLayer) {
    bool init(GJGameLevel* level) {
        if (!LevelInfoLayer::init(level)) return false;

        ChillClientLayer* layer = ChillClientLayer::create();
        layer->setButtonPosition(ccp(size.width * 0.25, size.height * 0.4));
        layer->createButton();
        addChild(layer);

        return true;
    }
};

class $modify(LevelSearchLayer) {
    bool init() {
        if (!LevelSearchLayer::init()) return false;

        MyDemonLayer* layer = MyDemonLayer::create();
        addChild(layer);

        return true;
    }
};

