//设置菜单场景
//任冬晨
//version 0.5
//time 5/21

#pragma once
#include"cocos2d.h"
#include"StartScene.h"
#include"Music.h"
class SettingsScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuBackCallback(cocos2d::Ref* pSender);
	void BGMsetBottomCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(SettingsScene);
};