//设置菜单场景
//任冬晨
//version 0.5
//time 5/21
#include"SettingsScene.h"
#include"StartScene.h"
USING_NS_CC;
Scene* SettingsScene::createScene()
{
	return SettingsScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool SettingsScene::init()
{
	if (!Scene::init())//判断初始化是否成功
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//生成返回按钮
	auto backItem = MenuItemImage::create(
		"BackNormal.jpg",
		"BackSelected.jpg",
		CC_CALLBACK_1(SettingsScene::menuBackCallback, this));

	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width /2;
		float y = origin.y + visibleSize.height / 2 - 240;
		backItem->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	//设置背景图片
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

void SettingsScene::menuBackCallback(Ref* pSender)//按返回键返回主菜单
{
	auto scene = StartScene::createScene();
	auto reScene = TransitionFadeDown::create(1.0f, scene);
	Director::getInstance()->pushScene(reScene);
}