#include"ChooseHeroScene.h"
USING_NS_CC;
using namespace CocosDenshion;
Scene* ChooseHeroScene::createScene()
{
	return ChooseHeroScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool ChooseHeroScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto HouyiItem = MenuItemImage::create(
		"reimu.png",
		"reimu.png",
		CC_CALLBACK_1(ChooseHeroScene::menuHouyiChoosedCallBack,this));
	if (HouyiItem == nullptr ||
		HouyiItem->getContentSize().width <= 0 ||
		HouyiItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 2;
		HouyiItem->setPosition(Vec2(x, y));
	}
	auto backItem = MenuItemImage::create(
		"BackNormal.jpg",
		"BackSelected.jpg",
		CC_CALLBACK_1(ChooseHeroScene::menuBackCallback, this));

	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x+130;
		float y = origin.y + visibleSize.height-45;
		backItem->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(backItem,HouyiItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	auto sprite = Sprite::create("SettingBackGround.png");
	if (sprite == nullptr)
	{
		problemLoading("'SettingBackGround.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	return true;
}
void ChooseHeroScene::menuHouyiChoosedCallBack(cocos2d::Ref* pSender) 
{
	Director::getInstance()->end();
}
void ChooseHeroScene::menuDaJiChoosedCallBack(cocos2d::Ref* pSender) 
{

}
void ChooseHeroScene::menuXiangYuChoosedCallBack(cocos2d::Ref* pSender) 
{
}
void ChooseHeroScene::menuBackCallback(Ref* pSender)//按返回键返回主菜单
{
	auto scene = StartScene::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
}