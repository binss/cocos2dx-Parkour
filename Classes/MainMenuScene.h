//
//  MainMenuScene.h
//  ParkourSample
//
//  Created by Ken on 13-10-10.
//
//

#ifndef ParkourSamplen_MainMenuScene_h
#define ParkourSample_MainMenuScene_h

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;

using namespace extension;

class MainMenuScene : public cocos2d::CCScene
{
public:
    
    bool init();
    
    void startBtnCallFunc(CCObject* pSender);

private:
	 CCMenu* mainMenu;
	 CCLayer* menuLayer;
	 int loadingCount;
	 void dataLoaded(float percent);
	  enum
	{
		ACTION_RUN = 0,
		ACTION_WELCOME,
	};
};

#endif
