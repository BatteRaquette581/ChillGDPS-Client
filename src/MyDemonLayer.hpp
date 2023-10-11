#include <Geode/Geode.hpp>

using namespace geode::prelude;

class MyDemonLayer : public CCLayer {
private:

public:
    bool init();
    static MyDemonLayer* create();
    void onButtonClick(CCObject* sender);
};