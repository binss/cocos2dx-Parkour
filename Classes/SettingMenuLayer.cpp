#include "SettingMenuLayer.h"

bool SettingMenuLayer::init(int effectStatus, int volumn)
{
	if(UILayer::init())
	{
		//GameScene* parentScene = GameScene::shareGameScene();
		//CCDirector::sharedDirector()->pause();
		//parentScene->playLayer->setTouchEnabled(false);
		//parentScene->menuLayer->settingBtn->setTouchEnable(false);

		Widget * myWidget =  dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("UI/SettingMenu/SettingMenu_1.json"));
		this->addWidget(myWidget);

		musicVolumeSlider = dynamic_cast<UISlider*>(this->getWidgetByName("volume_bar"));
		musicEffectSlider = dynamic_cast<UISlider*>(this->getWidgetByName("effect_bar"));
		musicVolumeCheckBox = dynamic_cast<UICheckBox*>(this->getWidgetByName("volume_CheckBox"));
		musicEffectCheckBox = dynamic_cast<UICheckBox*>(this->getWidgetByName("effect_CheckBox"));
		UIButton* resumeBtn = dynamic_cast<UIButton*>(this->getWidgetByName("resume"));
		UIButton* quitBtn = dynamic_cast<UIButton*>(this->getWidgetByName("quit"));
		resumeBtn->addTouchEventListener(this, toucheventselector(SettingMenuLayer::resumeGame));
		quitBtn->addTouchEventListener(this, toucheventselector(SettingMenuLayer::quitGame));


		musicEffectStatus = effectStatus;

		if(musicEffectStatus == 0)
		{
			musicEffectSlider->setPercent(15);
		}
		else if(musicEffectStatus == 1)
		{

			musicEffectSlider->setPercent(95);
		}
		musicVolumeSlider->setPercent(volumn);

		musicVolumeSlider->addEventListenerSlider(this, sliderpercentchangedselector(SettingMenuLayer::musicVolumeSliderCallFunc));
		musicEffectSlider->addEventListenerSlider(this, sliderpercentchangedselector(SettingMenuLayer::musicEffectSliderCallFunc));

		return true;
	}

	return false;
}


void SettingMenuLayer::musicEffectSliderCallFunc(cocos2d::CCObject *pSender, SliderEventType type)
{
	float voice = 0.0f;
	if(type == SLIDER_PERCENTCHANGED)
	{
		voice = musicVolumeSlider->getPercent();
		if(musicVolumeSlider->getPercent()<8)
		{
			musicVolumeSlider->setPercent(8);
			voice=0.0f;
		}
		else if(musicVolumeSlider->getPercent()>95)
		{
			musicVolumeSlider->setPercent(95);
			voice=100.0f;
		}
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(voice/100);
	}
	/*

	GameScene::shareGameScene()->menuLayer->musicEffect = musicEffectStatus;
	//set effect state.
	CCLog("musicEffectStatus:%d.", musicEffectStatus);
	if (musicEffectStatus == 1) {
		AudioPlayer::sharedAudio()->setEffectPlay(false);
	}
	else{
		AudioPlayer::sharedAudio()->setEffectPlay(true);
	}
	*/
}

void SettingMenuLayer::musicVolumeSliderCallFunc(cocos2d::CCObject *pSender, SliderEventType type)
{
	float voice = 0.0f;
	if(type == SLIDER_PERCENTCHANGED)
	{
		voice = musicVolumeSlider->getPercent();
		if(musicVolumeSlider->getPercent()<8)
		{
			musicVolumeSlider->setPercent(8);
			voice=0.0f;
		}
		else if(musicVolumeSlider->getPercent()>95)
		{
			musicVolumeSlider->setPercent(95);
			voice=100.0f;
		}
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(voice/100);
	}
	
	//GameScene::shareGameScene()->menuLayer->musicVolume = musicVolumeSlider->getPercent();
	//set audio voice.
	//AudioPlayer::sharedAudio()->setVolume(voice/100);
}

void SettingMenuLayer::resumeGame(cocos2d::CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED  )
	{
		CCDirector::sharedDirector()->resume();
		this->removeAllChildren();
		this->removeFromParentAndCleanup(true);
	}
}

void SettingMenuLayer::quitGame(cocos2d::CCObject *pSender, TouchEventType type)
{
	CCDirector::sharedDirector()->end();
}
