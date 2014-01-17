#include "GameOverScene.h"

GameOverScene::GameOverScene()
{

}

GameOverScene::~GameOverScene()
{

}

bool GameOverScene::init()
{
	bool bRet = true;
	do 
	{
		if (!CCScene::init())
		{
			bRet = false;
			break;
		}
			//CCLayer *layer = CCLayer::create();
		//layer->addChild(myWidget);
		UILayer  *layer = UILayer::create();
		layer->setTouchEnabled(true);
		layer->setTouchMode(kCCTouchesOneByOne);
		Widget * myWidget =  dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("UI/gameOverMenu/gameOverMenu_1.json"));
		layer->addWidget(myWidget);

		UIButton  * button1 = (UIButton *)layer->getWidgetByName("restart"); 
		button1->setTouchEnabled(true);
		button1->setPressedActionEnabled(true);        
		button1->addTouchEventListener(this, toucheventselector(GameOverScene::restartGame));

		UIButton  * button2 = (UIButton *)layer->getWidgetByName("exit"); 	
		button2->setTouchEnabled(true);
		button2->setPressedActionEnabled(true);   
		button2->addTouchEventListener(this, toucheventselector(GameOverScene::quitGame));	

		this->addChild(layer);
		
	} while (0);

	return bRet;
}

void GameOverScene::restartGame(CCObject *pSender, TouchEventType type)
{
	//CCLOG("touch restart");
	if(type ==  TOUCH_EVENT_ENDED)
	{
		CCScene *hello = GameScene::newGameScene();
		CCDirector::sharedDirector()->replaceScene(hello);
	}
}

void GameOverScene::quitGame(CCObject *pSender, TouchEventType type)
{
	if(type ==  TOUCH_EVENT_ENDED)
	{
		CCDirector::sharedDirector()->end();
	}
}
/*
void GameOverLayer::restartGame(CCObject* obj)
{
	CCScene *hello = HelloWorld::scene();
	CCDirector::sharedDirector()->replaceScene(hello);
}

void GameOverLayer::quitGame(CCObject* obj)
{
	CCDirector::sharedDirector()->end();
}
*/