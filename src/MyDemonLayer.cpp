#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include "MyDemonLayer.hpp"

using namespace geode::prelude;

bool MyDemonLayer::init() {
    if (!CCLayer::init())
        return false;

    auto menu = CCMenu::create();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    auto sprite = CircleButtonSprite::createWithSpriteFrameName("my_demon_button.png"_spr, 1, geode::CircleBaseColor::Blue);
    auto button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(MyDemonLayer::onButtonClick));
    button->setPosition(ccp(-size.width * 0.4, -size.height * 0.4));

    menu->addChild(button);
    addChild(menu);

    return true;
}

MyDemonLayer* MyDemonLayer::create() {
    auto ret = new MyDemonLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void MyDemonLayer::onButtonClick(CCObject* sender) {
    auto res = web::fetch("https://mydemonapi.batteraquette58.repl.co/");
    if (res.isErr()) {
        FLAlertLayer::create("ChillGDPS Client", "Failed to fetch resource.", "OK")->show();
        return;
    }
    std::string id = res.value();
    auto scene = LevelBrowserLayer::scene(GJSearchObject::create(SearchType::Search, id));
    CCDirector* shared_director = CCDirector::sharedDirector();
    shared_director->popScene();
    shared_director->pushScene(scene);
}
