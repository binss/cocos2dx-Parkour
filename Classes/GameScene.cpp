//  GameScene.cpp
//  ParkourSample
//
//  Created by Ken on 13-10-10.
//
//

#include "GameScene.h"

bool GameScene::init()
{    
	menuLayer = new MenuLayer();        //加载菜单

	if(menuLayer && menuLayer->init(100, "0"))
	{
		menuLayer->autorelease();
	}else{

		CC_SAFE_DELETE(menuLayer);
	}
	
	this->addChild(menuLayer, 2);


	
    playLayer = new GameScenePlayLayer();   //加载人物
	
	if(playLayer && playLayer->init()){
		
		playLayer->autorelease();
	}else{
		
		CC_SAFE_DELETE(playLayer);
	}
	
    this->addChild(playLayer, 0);
	
    return true;
}

static GameScene *_sharedGameScene = NULL;
GameScene* GameScene::shareGameScene()
{
    if (!_sharedGameScene) {
        _sharedGameScene = new GameScene();
        if (!_sharedGameScene->init())
        {
            CC_SAFE_DELETE(_sharedGameScene);
        }
    }
    return _sharedGameScene;
}
GameScene* GameScene::newGameScene()
{
     _sharedGameScene = new GameScene();
    if (!_sharedGameScene->init())
    {
		CC_SAFE_DELETE(_sharedGameScene);
    }
    
    return _sharedGameScene;
}
