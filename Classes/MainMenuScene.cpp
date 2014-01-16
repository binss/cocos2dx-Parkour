//
//  MainMenuScene.cpp
//  ParkourSample
//
//  Created by Ken on 13-10-10.
//
//

#include "MainMenuScene.h"
#include "GameScene.h"

bool MainMenuScene::init()
{    
	menuLayer = CCLayer::create();
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    
    // Add backgrounbdPic
    CCSprite* backGroundPic = CCSprite::create("pictures/mainMenuBackGround.png");
    backGroundPic->setAnchorPoint(ccp(0, 0));
    
    menuLayer->addChild(backGroundPic,0);
	
	// Add ChenXiaoG welcome armature
	CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("animations/ChenXiaoGeWelcome.ExportJson");
	CCArmature *armature = CCArmature::create("ChenXiaoGeWelcome");
	armature->getAnimation()->play("Animation1");
	armature->getAnimation()->setSpeedScale(1.5f);
	armature->setAnchorPoint(ccp(0,0));
	armature->setPosition(ccp(size.width/8, size.height/6));
	armature->setScale(0.5);
	menuLayer->addChild(armature,1);

    
    //Add StartBtn
    CCSprite* start     = CCSprite::create("pictures/startbtn.png");
    CCSprite* startPush = CCSprite::create("pictures/startbtnPush.png");
    
    CCMenuItemSprite * startBtn = CCMenuItemSprite::create(start, startPush, this, menu_selector(MainMenuScene::startBtnCallFunc));
    
    //Add Menu
    mainMenu = CCMenu::create(startBtn, NULL);
    mainMenu->setAnchorPoint(ccp(0, 0));
    mainMenu->setPosition(ccp(size.width/6, size.height/1.3));
    menuLayer->addChild(mainMenu,2);

	//Add snow particle
	CCParticleSystem *particle = CCParticleSnow::create();
	particle->setTexture(CCTextureCache::sharedTextureCache()->addImage("pictures/snow.png"));
	menuLayer->addChild(particle,3);

    this->addChild(menuLayer ,0);

    return true;
}

void MainMenuScene::startBtnCallFunc(CCObject* pSender)
{	
	CCPoint mainMenuPosition = mainMenu->getPosition();

	CCParticleSystem *meteor=CCParticleSystemQuad::create("pictures/qwe.plist");
	meteor->setScale(0.4);
	meteor->setPosition(ccp(mainMenuPosition.x,mainMenuPosition.y -50)); 
	menuLayer->addChild(meteor,2); 

	CCSprite * activity = CCSprite::create("pictures/loading.png");
	activity->setPosition(ccp(mainMenuPosition.x,mainMenuPosition.y-50));
	menuLayer->addChild(activity,2);

	CCRotateBy * rotateAction = CCRotateBy::create(0.5f,180.0f);
	activity->runAction(CCRepeatForever::create(rotateAction));

	loadingCount = 0;
	dataLoaded(loadingCount);
}

void MainMenuScene::dataLoaded(float percent)
{
	switch (loadingCount)
	{
		case ACTION_RUN:
		{
			CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfoAsync("animations/ChenXiaoGeRunning.ExportJson",this, schedule_selector(MainMenuScene::dataLoaded));
		}
		break;
	
	default:
		{

			CCScene * newscene  = CCScene::create();
			GameScene* gameScene =  GameScene::newGameScene();
			CCTransitionFade* gameSceneTransition =  CCTransitionFade::create(0.5, gameScene, ccWHITE);
			CCDirector::sharedDirector()->replaceScene(gameSceneTransition);
		}
		break;
	}	
	loadingCount++;
}