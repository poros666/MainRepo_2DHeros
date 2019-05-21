#pragma once
#include"cocos2d.h"
class ChooseHero : public cocos2d::Scene 
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuHouyiChoosedCallBack(cocos2d::Ref* pSender);
	void menuDaJiChoosedCallBack(cocos2d::Ref* pSender);
	void menuXiangYuChoosedCallBack(cocos2d::Ref* pSender);
	CREATE_FUNC(ChooseHero);
};