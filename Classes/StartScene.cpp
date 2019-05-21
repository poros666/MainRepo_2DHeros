#include "StartScene.h"
#include "SimpleAudioEngine.h"
#include"SettingsScene.h"
#include"ChooseHero.h"
USING_NS_CC;

Scene* StartScene::createScene()
{
    return StartScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

// on "init" you need to initialize your instance
bool StartScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    
	auto settingItem = MenuItemImage::create(
		"SettingsNormal.jpg",
		"SettingsSelected.jpg",
		CC_CALLBACK_1(StartScene::settingGameCallback, this));
	if (settingItem == nullptr ||
		settingItem->getContentSize().width <= 0 ||
		settingItem->getContentSize().height <= 0)
	{
		problemLoading("'SettingsNormal.png' and 'SettingsSelected.png'");
	}
	else
	{
		float x = origin.x  + visibleSize.width/2;
		float y = origin.y + visibleSize.height/2-200;
		settingItem->setPosition(Vec2(x, y));
	}
	auto startItem = MenuItemImage::create(
		"StartNormal.jpg",
		"StartSelected.jpg",
		CC_CALLBACK_1(StartScene::startGameCallback, this));
	if (startItem == nullptr ||
		startItem->getContentSize().width <= 0 ||
		startItem->getContentSize().height <= 0)
	{
		problemLoading("'StartNormal.png' and 'StartSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 2-40;
		startItem->setPosition(Vec2(x, y));
	}
    // create menu, it's an autorelease object
    auto menu = Menu::create(startItem,settingItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width/2,
                                origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }

    // add "StartScene" splash screen"
    auto sprite = Sprite::create("BackGround.jpg");
    if (sprite == nullptr)
    {
        problemLoading("'BackGround.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }
    return true;
}


void StartScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void StartScene::startGameCallback(Ref* pSender)
{
	auto scene = ChooseHero::createScene();
	auto reScene = TransitionFadeUp::create(1.0f, scene);
	Director::getInstance()->pushScene(reScene);
}
void StartScene::settingGameCallback(Ref* pSender) 
{
	auto scene = SettingsScene::createScene();
	auto reScene = TransitionFadeDown::create(1.0f, scene);
	Director::getInstance()->pushScene(reScene);
}