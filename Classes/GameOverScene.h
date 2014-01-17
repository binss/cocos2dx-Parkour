
#ifndef ChenXiaoGe_GameOverScene_h
#define ChenXiaoGe_GameOverScene_h

#include "cocos2d.h"
#include "cocos-ext.h"
//#include "GameScene.h"

USING_NS_CC;
using namespace extension;
using namespace gui;

class GameOverScene : public CCScene
{
public:
	GameOverScene();
	~GameOverScene();
	virtual bool init();
	CREATE_FUNC(GameOverScene);
	void restartGame(CCObject *pSender, TouchEventType type);
	void quitGame(CCObject *pSender, TouchEventType type);
};

#endif