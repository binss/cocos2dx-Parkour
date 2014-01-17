#include "MenuLayer.h"

bool MenuLayer::init(int broodBarPercent, const char *value)
{
	UILayer::init();

	this->setTouchEnabled(true);
	this->setTouchMode(kCCTouchesOneByOne);

	Widget * myWidget =  dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("UI/Menu/Menu_1.json"));
	this->addWidget(myWidget);
	UIButton* settingBtn = dynamic_cast<UIButton*>(this->getWidgetByName("setBt"));
	settingBtn->setTouchEnabled(true);
	settingBtn->setPressedActionEnabled(true);        
	settingBtn->addTouchEventListener(this, toucheventselector(MenuLayer::settingBtnCallback));


	scoreLabel = dynamic_cast<UILabelAtlas*>(this->getWidgetByName("score"));
	setScore(value);

	return true;
}
void MenuLayer::settingBtnCallback(CCObject *pSender, TouchEventType type)
{
	if(type == TOUCH_EVENT_ENDED)
	{
		CCLOG("game setting show");
	}
}

void MenuLayer::setScore(const char *value)
{
	scoreLabel->setStringValue(value);

}

const char* MenuLayer::getScore()
{
	return scoreLabel->getStringValue();
}