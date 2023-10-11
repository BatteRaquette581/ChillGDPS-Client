#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "ChillClientLayer.hpp"
#include "patcher.hpp"

using namespace geode::prelude;

bool reset = false;
bool safe_mode_toggled = false;

bool ChillClientLayer::init() {
    if (!CCLayer::init())
        return false;
    
    setZOrder(100);

    //ac_level_kick_bypass_toggled = mod->getSavedValue<bool>("ac-level-kick-bypass");
    //icon_bypass_toggled = mod->getSavedValue<bool>("icon-bypass");
    //noclip_toggled = mod->getSavedValue<bool>("noclip");
    //safe_mode_toggled = mod->getSavedValue<bool>("safe-mode");
    //practice_music_toggled = mod->getSavedValue<bool>("practice-music");
    //slider_limit_toggled = mod->getSavedValue<bool>("slider-limit");

    return true;
}

ChillClientLayer* ChillClientLayer::create() {
    auto ret = new ChillClientLayer();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

void ChillClientLayer::createButton() {
    auto menu = CCMenu::create();
    
    auto sprite = CircleButtonSprite::createWithSpriteFrameName("client_button.png"_spr, 1, geode::CircleBaseColor::Blue);
    auto button = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(ChillClientLayer::onButtonClick));
    button->setPosition(button_position);

    menu->addChild(button);
    addChild(menu);
}

void ChillClientLayer::setButtonPosition(CCPoint pos) {
    button_position = pos;
}

void ChillClientLayer::onButtonClick(CCObject* sender) {
    auto menu = getChildByID("menu"_spr);
    if (menu == nullptr) {
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        menu = CCMenu::create();
        menu->setPosition(ccp(0, 0));
        menu->setID("menu"_spr);

        auto close_button_sprite = CircleButtonSprite::createWithSpriteFrameName("close_menu_button.png"_spr, 1, geode::CircleBaseColor::Blue);
        auto close_button = CCMenuItemSpriteExtra::create(close_button_sprite, this, menu_selector(ChillClientLayer::closeMenu));
        close_button->setPosition(ccp(size.width * 0.13, size.height * 0.8));
        close_button->setZOrder(11);
        menu->addChild(close_button);

        auto background = CCSprite::createWithSpriteFrameName("menu_background.png"_spr);
        background->setAnchorPoint(ccp(-0.07, 0));
        background->setZOrder(10);
        background->setScale(4);
        menu->addChild(background);

        auto top_label = CCLabelBMFont::create("ChillGDPS Client", "bigFont.fnt");
        ccColor3B top_label_color(0, 255, 255);
        top_label->setPosition(ccp(size.width * 0.7, size.height * 0.835));
        top_label->setColor(top_label_color);
        top_label->setZOrder(11);
	    menu->addChild(top_label);

        auto ac_bypass_label = CCLabelBMFont::create("Disable Level Kick", "bigFont.fnt");
        ac_bypass_label->setScale(0.7);
        ac_bypass_label->setPosition(size.width * 0.3, size.height * 0.7);
        ac_bypass_label->setZOrder(11);
        menu->addChild(ac_bypass_label);

        auto ac_bypass_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        ac_bypass_toggler->setPosition(size.width * 0.46, size.height * 0.7);
        ac_bypass_toggler->setScale(0.7);
        ac_bypass_toggler->setTag(1);
        ac_bypass_toggler->setZOrder(11);
        ac_bypass_toggler->toggle(ac_level_kick_bypass_toggled);
        //ChillClientLayer::handleToggler(ac_bypass_toggler);
        menu->addChild(ac_bypass_toggler);

        auto icon_bypass_label = CCLabelBMFont::create("Icon Bypass", "bigFont.fnt");
        icon_bypass_label->setZOrder(11);
        icon_bypass_label->setScale(0.7);
        icon_bypass_label->setPosition(size.width * 0.3, size.height * 0.6);
        menu->addChild(icon_bypass_label);

        auto icon_bypass_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        icon_bypass_toggler->setZOrder(11);
        icon_bypass_toggler->setScale(0.7);
        icon_bypass_toggler->setPosition(size.width * 0.46, size.height * 0.6);
        icon_bypass_toggler->setTag(2);
        icon_bypass_toggler->toggle(icon_bypass_toggled);
        //ChillClientLayer::handleToggler(icon_bypass_toggler);
        menu->addChild(icon_bypass_toggler);

        auto safe_mode_label = CCLabelBMFont::create("Safe Mode", "bigFont.fnt");
        safe_mode_label->setZOrder(11);
        safe_mode_label->setScale(0.7);
        safe_mode_label->setPosition(size.width * 0.3, size.height * 0.5);
        menu->addChild(safe_mode_label);

        auto safe_mode_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        safe_mode_toggler->setZOrder(11);
        safe_mode_toggler->setScale(0.7);
        safe_mode_toggler->setPosition(size.width * 0.46, size.height * 0.5);
        safe_mode_toggler->setTag(3);
        safe_mode_toggler->toggle(safe_mode_toggled);
        //ChillClientLayer::handleToggler(safe_mode_toggler);
        menu->addChild(safe_mode_toggler);

        auto noclip_label = CCLabelBMFont::create("Noclip", "bigFont.fnt");
        noclip_label->setZOrder(11);
        noclip_label->setScale(0.7);
        noclip_label->setPosition(size.width * 0.3, size.height * 0.4);
        menu->addChild(noclip_label);

        auto noclip_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        noclip_toggler->setZOrder(11);
        noclip_toggler->setScale(0.7);
        noclip_toggler->setPosition(size.width * 0.46, size.height * 0.4);
        noclip_toggler->setTag(4);
        noclip_toggler->toggle(noclip_toggled);
        //ChillClientLayer::handleToggler(noclip_toggler);
        menu->addChild(noclip_toggler);

        //auto practice_music_label = CCLabelBMFont::create("Practice Music", "bigFont.fnt");
        //practice_music_label->setZOrder(11);
        //practice_music_label->setScale(0.7);
        //practice_music_label->setPosition(size.width * 0.3, size.height * 0.3);
        //menu->addChild(practice_music_label);
//
        //auto practice_music_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        //practice_music_toggler->setZOrder(11);
        //practice_music_toggler->setScale(0.7);
        //practice_music_toggler->setPosition(size.width * 0.46, size.height * 0.3);
        //practice_music_toggler->setTag(5);
        //practice_music_toggler->toggle(practice_music_toggled);
        //menu->addChild(practice_music_toggler);

        auto slider_limit_label = CCLabelBMFont::create("Slider Limit", "bigFont.fnt");
        slider_limit_label->setZOrder(11);
        slider_limit_label->setScale(0.7);
        slider_limit_label->setPosition(size.width * 0.3, size.height * 0.3);
        menu->addChild(slider_limit_label);

        auto slider_limit_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        slider_limit_toggler->setZOrder(11);
        slider_limit_toggler->setScale(0.7);
        slider_limit_toggler->setPosition(size.width * 0.46, size.height * 0.3);
        slider_limit_toggler->setTag(6);
        slider_limit_toggler->toggle(slider_limit_toggled);
        //ChillClientLayer::handleToggler(slider_limit_toggler);
        menu->addChild(slider_limit_toggler);

        auto ignore_esc_label = CCLabelBMFont::create("Prevent Exiting", "bigFont.fnt");
        ignore_esc_label->setZOrder(11);
        ignore_esc_label->setScale(0.7);
        ignore_esc_label->setPosition(size.width * 0.3, size.height * 0.2);
        menu->addChild(ignore_esc_label);

        auto ignore_esc_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        ignore_esc_toggler->setZOrder(11);
        ignore_esc_toggler->setScale(0.7);
        ignore_esc_toggler->setPosition(size.width * 0.46, size.height * 0.2);
        ignore_esc_toggler->setTag(7);
        ignore_esc_toggler->toggle(ignore_esc_toggled);
        //ChillClientLayer::handleToggler(ignore_esc_toggler);
        menu->addChild(ignore_esc_toggler);

        auto object_bypass_label = CCLabelBMFont::create("Object Bypass", "bigFont.fnt");
        object_bypass_label->setScale(0.7);
        object_bypass_label->setPosition(size.width * 0.6, size.height * 0.7);
        object_bypass_label->setZOrder(11);
        menu->addChild(object_bypass_label);

        auto object_bypass_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        object_bypass_toggler->setPosition(size.width * 0.75, size.height * 0.7);
        object_bypass_toggler->setScale(0.7);
        object_bypass_toggler->setTag(8);
        object_bypass_toggler->setZOrder(11);
        object_bypass_toggler->toggle(object_bypass_toggled);
        //ChillClientLayer::handleToggler(ac_bypass_toggler);
        menu->addChild(object_bypass_toggler);

        auto song_bypass_label = CCLabelBMFont::create("Song Bypass", "bigFont.fnt");
        song_bypass_label->setScale(0.7);
        song_bypass_label->setPosition(size.width * 0.6, size.height * 0.6);
        song_bypass_label->setZOrder(11);
        menu->addChild(song_bypass_label);

        auto song_bypass_toggler = CCMenuItemToggler::createWithStandardSprites(this, menu_selector(ChillClientLayer::handleToggler), 1);
        song_bypass_toggler->setPosition(size.width * 0.75, size.height * 0.6);
        song_bypass_toggler->setScale(0.7);
        song_bypass_toggler->setTag(9);
        song_bypass_toggler->setZOrder(11);
        song_bypass_toggler->toggle(song_bypass_toggled);
        //ChillClientLayer::handleToggler(ac_bypass_toggler);
        menu->addChild(song_bypass_toggler);

        addChild(menu);
    }
}

void ChillClientLayer::closeMenu(CCObject* sender) {
    auto menu = getChildByID("menu"_spr);
    if (menu != nullptr) menu->removeFromParent();
}

void ChillClientLayer::handleToggler(CCObject* sender) {
    CCMenuItemToggler* sender_cast = dynamic_cast<CCMenuItemToggler*>(sender);
    if (sender_cast == NULL) {
        FLAlertLayer::create("ChillGDPS Client", "Sender is not a toggler.", "OK")->show();
        return;
    }
    bool toggled = !sender_cast->isToggled();
    switch (sender_cast->getTag()) {
        case 1:
            toggle_ac_level_kick_bypass(toggled);
            ac_level_kick_bypass_toggled = toggled;
            mod->setSavedValue<bool>("ac-level-kick-bypass", toggled);
            break;

        case 2:
            toggle_icon_bypass(toggled);
            icon_bypass_toggled = toggled;
            mod->setSavedValue<bool>("icon-bypass", toggled);
            break;

        case 3:
            safe_mode_toggled = toggled;
            mod->setSavedValue<bool>("safe-mode", toggled);
            reset = true;
            break;

        case 4:
            toggle_noclip(toggled);
            noclip_toggled = toggled;
            mod->setSavedValue<bool>("noclip", toggled);
            safe_mode_toggled = toggled;
            mod->setSavedValue<bool>("safe-mode", toggled);
            break;

        case 5:
            //toggle_practice_music(toggled);
            practice_music_toggled = toggled;
            mod->setSavedValue<bool>("practice-music", toggled);
            break;

        case 6:
            toggle_slider_limit(toggled);
            slider_limit_toggled = toggled;
            mod->setSavedValue<bool>("slider-limit", toggled);
            break;

        case 7:
            toggle_ignore_esc(toggled);
            ignore_esc_toggled = toggled;
            mod->setSavedValue<bool>("ignore-esc", toggled);
            break;

        case 8:
            toggle_object_bypass(toggled);
            object_bypass_toggled = toggled;
            mod->setSavedValue<bool>("object-bypass", toggled);
            break;

        case 9:
            toggle_song_bypass(toggled);
            song_bypass_toggled = toggled;
            mod->setSavedValue<bool>("song-bypass", toggled);
            break;
        
        
        default:
            FLAlertLayer::create("ChillGDPS Client", "Invalid toggler.", "OK")->show();
    }
}

class $modify(PlayLayer) {
    //void resetLevel() {
    //    PlayLayer::resetLevel();
    //    bool has_startpos = m_startPos != nullptr;
    //    m_isTestMode = safe_mode_toggled || has_startpos;
    //    if (reset) {
    //        PlayLayer::resumeAndRestart();
    //        reset = false;
    //    }
    //}

    void levelComplete() {
        if (safe_mode_toggled or reset) PlayLayer::onExit();
        else {
            PlayLayer::levelComplete();
            reset = false;
        }
    }
};
