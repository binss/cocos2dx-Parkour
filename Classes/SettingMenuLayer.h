
#ifndef ChenXiaoGe_SettingMenuLayer_h
#define ChenXiaoGe_SettingMenuLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;
using namespace extension;
using namespace gui;
using namespace CocosDenshion;

class MenuLayer;

class SettingMenuLayer : public UILayer
{
public:
	bool init(bool musicVolumeClosed, bool musicEffectClosed,int musicVolume, int musicEffect);
	void settingBtnCallback(CCObject *pSender, TouchEventType type);
	void resumeGame(cocos2d::CCObject *pSender, TouchEventType type);
	void quitGame(cocos2d::CCObject *pSender, TouchEventType type);
	void musicVolumeSliderCallFunc(cocos2d::CCObject *pSender, SliderEventType type);
	void musicEffectSliderCallFunc(cocos2d::CCObject *pSender, SliderEventType type);

	void musicVolumeCheckBoxCallFunc(cocos2d::CCObject *pSender, CheckBoxEventType type);
	void musicEffectCheckBoxCallFunc(cocos2d::CCObject *pSender, CheckBoxEventType type);

	UISlider* musicVolumeSlider;
	UISlider* musicEffectSlider;
	UICheckBox * musicVolumeCheckBox;
	UICheckBox * musicEffectCheckBox;
	int musicEffectStatus;

};



#endif