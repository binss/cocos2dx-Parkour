
#ifndef ChenXiaoGe_MenuLayer_h
#define ChenXiaoGe_MenuLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SettingMenuLayer.h"

USING_NS_CC;
using namespace extension;
using namespace gui;


class GameScene;
class SettingMenuLayer;
class MenuLayer : public UILayer
{
public:
	 bool init(int broodBarPercent, const char *value);
	 void settingBtnCallback(CCObject *pSender, TouchEventType type);
	 void setScore(const char *value);
	 const char* MenuLayer::getScore();
	 UILabelAtlas* scoreLabel;
	 int musicEffect;
	 int musicVolume;
	//virtual bool init();
};



#endif