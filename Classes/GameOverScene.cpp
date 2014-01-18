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

		UILabelAtlas* scoreLabel = dynamic_cast<UILabelAtlas*>(layer->getWidgetByName("yourscore"));
		UILabelAtlas* highscoreLabel = dynamic_cast<UILabelAtlas*>(layer->getWidgetByName("highscore"));
		char char_score[6];
		itoa(CCUserDefault::sharedUserDefault()->getIntegerForKey("Score"), char_score, 10); 
		scoreLabel->setStringValue(char_score);
		itoa(CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore"), char_score, 10); 
		highscoreLabel->setStringValue(char_score);

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
