#pragma once
#include"cocos2d.h"
#include "StartScene.h"
#include"Music.h"
class ChooseHeroScene : public cocos2d::Scene 
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuHouyiChoosedCallBack(cocos2d::Ref* pSender);
	void menuDaJiChoosedCallBack(cocos2d::Ref* pSender);
	void menuXiangYuChoosedCallBack(cocos2d::Ref* pSender);
	void menuBackCallback(Ref* pSender);

	CREATE_FUNC(ChooseHeroScene);
};