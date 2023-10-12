#include <Geode/Geode.hpp>

using namespace geode::prelude;

class ChillClientLayer : public CCLayer {
private:
    CCPoint button_position;

public:
    bool init();
    static ChillClientLayer* create();
    void createButton();
    void setButtonPosition(CCPoint pos);
    void onButtonClick(CCObject* sender);
    void closeMenu(CCObject* sender);
    void handleToggler(CCObject* sender);
};
