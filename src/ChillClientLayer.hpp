#include <Geode/Geode.hpp>

using namespace geode::prelude;

class ChillClientLayer : public CCLayer {
private:
    CCPoint button_position;

    bool ac_level_kick_bypass_toggled = false;
    bool icon_bypass_toggled = false;
    bool noclip_toggled = false;
    bool practice_music_toggled = false;
    bool slider_limit_toggled = false;
    bool ignore_esc_toggled = false;
    bool object_bypass_toggled = false;
    bool song_bypass_toggled = false;

public:
    bool init();
    static ChillClientLayer* create();
    void createButton();
    void setButtonPosition(CCPoint pos);
    void onButtonClick(CCObject* sender);
    void closeMenu(CCObject* sender);
    void handleToggler(CCObject* sender);
};
