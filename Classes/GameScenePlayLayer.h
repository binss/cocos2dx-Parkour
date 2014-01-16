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

USING_NS_CC;

using namespace extension;

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
	CCSprite* background;
	CCSprite* backgroundCopy;
	CCSprite* shop;
	CCSprite* sun;
	CCSprite* ground;
	CCSprite* groundCopy;

	CCSize winSize;
 	int actionNum;
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
