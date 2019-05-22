#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"Music.h"
#include"SettingsScene.h"
#include"ChooseHeroScene.h"
class StartScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
	void startGameCallback(cocos2d::Ref* pSender);
	void settingGameCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    CREATE_FUNC(StartScene);
};

#endif // __HELLOWORLD_SCENE_H__
