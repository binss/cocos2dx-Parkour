//
//  GameScenePlayLayer.h
//  ChenXiaoGe
//
//  Created by Ken on 13-10-10.
//
//

#ifndef ChenXiaoGe_GameScenePlayLayer_h
#define ChenXiaoGe_GameScenePlayLayer_h
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"



using namespace std;
USING_NS_CC;
using namespace extension;
using namespace CocosDenshion;

class GameScene;

class GameScenePlayLayer : public cocos2d::CCLayer
{
  public:
    
    bool init();
    
	void running();
    void runJump();
	void death();
	void backgroundInit();

	CCArmature *chenxiaogeArmature;
	CCPoint chenxiaogePosition;

private:

	void update(float dt);
	void resetBackground();
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	void createCoin(float dt);
	void rubbishCollection(CCObject *object);
	void changeSeason(float dt);
	void gameOver();
	
	CCSpriteFrame* background_spring;
	CCSpriteFrame* background_summer;
	CCSpriteFrame* background_autumn;
	CCSpriteFrame* background_winter;
	CCSpriteFrame* ground_spring;
	CCSpriteFrame* ground_summer;
	CCSpriteFrame* ground_autumn;
	CCSpriteFrame* ground_winter;


	CCSprite* background;
	CCSprite* backgroundCopy;
	CCSprite* shop;
	CCSprite* sun;
	CCSprite* ground;
	CCSprite* groundCopy;

	CCParticleSystem *particle;
	CCParticleSystem *particle2;
	CCSize winSize;
 	int actionNum;
	int season;
	int score;
	CCArray *crashArray;

	enum
	{
		ACTION_RUN = 0,
        ACTION_RUN_JUMP,
		ACTION_DEATH
	};
 
    CREATE_FUNC(GameScenePlayLayer);
};

#endif
