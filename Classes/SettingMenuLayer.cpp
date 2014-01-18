#include "SettingMenuLayer.h"
#include "GameScene.h"
bool SettingMenuLayer::init(bool musicVolumeClosed, bool musicEffectClosed,int musicVolume, int musicEffect)
{
	if(UILayer::init())
	{
		this->setTouchEnabled(true);
		this->setTouchMode(kCCTouchesOneByOne);
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();

		CCDirector::sharedDirector()->pause();

		Widget * myWidget =  dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("UI/SettingMenu/SettingMenu_1.json"));
		this->addWidget(myWidget);

		musicVolumeSlider = dynamic_cast<UISlider*>(this->getWidgetByName("volume_bar"));
		musicEffectSlider = dynamic_cast<UISlider*>(this->getWidgetByName("effect_bar"));
		musicVolumeCheckBox = dynamic_cast<UICheckBox*>(this->getWidgetByName("volume_CheckBox"));
		musicEffectCheckBox = dynamic_cast<UICheckBox*>(this->getWidgetByName("effect_CheckBox"));
		UIButton* resumeBtn = dynamic_cast<UIButton*>(this->getWidgetByName("resume"));
		UIButton* quitBtn = dynamic_cast<UIButton*>(this->getWidgetByName("quit"));
				
		musicVolumeCheckBox->addEventListenerCheckBox(this,checkboxselectedeventselector(SettingMenuLayer::musicVolumeCheckBoxCallFunc));
		musicEffectCheckBox->addEventListenerCheckBox(this,checkboxselectedeventselector(SettingMenuLayer::musicEffectCheckBoxCallFunc));
		musicVolumeSlider->addEventListenerSlider(this, sliderpercentchangedselector(SettingMenuLayer::musicVolumeSliderCallFunc));
		musicEffectSlider->addEventListenerSlider(this, sliderpercentchangedselector(SettingMenuLayer::musicEffectSliderCallFunc));
		resumeBtn->addTouchEventListener(this, toucheventselector(SettingMenuLayer::resumeGame));
		quitBtn->addTouchEventListener(this, toucheventselector(SettingMenuLayer::quitGame));

		musicVolumeCheckBox->setSelectedState(musicVolumeClosed);
		musicEffectCheckBox->setSelectedState(musicEffectClosed);
		musicVolumeSlider->setPercent(musicVolume);
		musicEffectSlider->setPercent(musicEffect);

		return true;
	}

	return false;
}

void SettingMenuLayer::musicVolumeCheckBoxCallFunc(cocos2d::CCObject *pSender, CheckBoxEventType type)
{
	switch (type)
	{
	case CHECKBOX_STATE_EVENT_UNSELECTED:
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(musicVolumeSlider->getPercent()/100.0);
		break;

	case CHECKBOX_STATE_EVENT_SELECTED:
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0);
		break;

	default:
		break;
	}
	
}
void SettingMenuLayer::musicEffectCheckBoxCallFunc(cocos2d::CCObject *pSender, CheckBoxEventType type)
{
	switch (type)
	{
	case CHECKBOX_STATE_EVENT_UNSELECTED:
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(musicEffectSlider->getPercent()/100.0);
		break;
	case CHECKBOX_STATE_EVENT_SELECTED:
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(0);
		break;

	default:
		break;
	}
}


void SettingMenuLayer::musicEffectSliderCallFunc(cocos2d::CCObject *pSender, SliderEventType type)
{
	float voice = 0.0f;
	if(type == SLIDER_PERCENTCHANGED)
	{
		voice = musicVolumeSlider->getPercent();
		if(musicVolumeSlider->getPercent()<5)
		{
			musicVolumeSlider->setPercent(5);
			voice=0.0f;
		}
		else if(musicVolumeSlider->getPercent()>95)
		{
			musicVolumeSlider->setPercent(95);
			voice=100.0f;
		}
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(voice/100);
	}
}

void SettingMenuLayer::musicVolumeSliderCallFunc(cocos2d::CCObject *pSender, SliderEventType type)
{
	float voice = 0.0f;
	if(type == SLIDER_PERCENTCHANGED)
	{
		voice = musicVolumeSlider->getPercent();
		if(musicVolumeSlider->getPercent()<5)
		{
			musicVolumeSlider->setPercent(5);
			voice=0.0f;
		}
		else if(musicVolumeSlider->getPercent()>95)
		{
			musicVolumeSlider->setPercent(95);
			voice=100.0f;
		}
		CCLOG("%f",voice);
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(voice/100);
	}

}

void SettingMenuLayer::resumeGame(cocos2d::CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED  )
	{
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
		CCDirector::sharedDirector()->resume();
		this->removeAllChildren();
		this->removeFromParentAndCleanup(true);
	}
	GameScene::shareGameScene()->menuLayer->setVoice(musicVolumeCheckBox->getSelectedState(),musicEffectCheckBox->getSelectedState(),
		musicVolumeSlider->getPercent(),musicEffectSlider->getPercent());
	
}

void SettingMenuLayer::quitGame(cocos2d::CCObject *pSender, TouchEventType type)
{
	CCDirector::sharedDirector()->end();
}
