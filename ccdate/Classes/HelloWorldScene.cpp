#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "CCDate.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    date = CCDate::createWithCurrentTime();
    date->retain();
    
    CCLabelTTF *label1 = CCLabelTTF::create("123", "Marker Felt", 30);
    
    label1->setString(CCString::createWithFormat("%d %d %d %d %d %d %ld"
                                                 ,date->getYear()
                                                 ,date->getMonth()
                                                 ,date->getDay()
                                                 ,date->getHours()
                                                 ,date->getMinutes()
                                                 ,date->getSeconds()
                                                 ,date->getMilliseconds())->getCString());
    label1->setTag(1);
    label1->setPosition(ccp(512,700));
    this->addChild(label1);
    
    CCLabelTTF *label2 = CCLabelTTF::create("123", "Marker Felt", 30);
    
    label2->setString(CCString::createWithFormat("%d %d %d %d %d %d %ld"
                                                 ,date->getYear()
                                                 ,date->getMonth()
                                                 ,date->getDay()
                                                 ,date->getHours()
                                                 ,date->getMinutes()
                                                 ,date->getSeconds()
                                                 ,date->getMilliseconds())->getCString());
    label2->setTag(2);
    label2->setPosition(ccp(512,600));
    this->addChild(label2);
    
    this->scheduleUpdate();
    
    CCMenu *menu = CCMenu::create(NULL);
    
    CCMenuItemFont *temp = CCMenuItemFont::create("+01:00 TimezoneOffset", this, menu_selector(HelloWorld::addTimezoneOffset));
    temp->setPosition(ccp(512,100));
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-01:00 TimezoneOffset", this, menu_selector(HelloWorld::subTimezoneOffset));
    temp->setPosition(ccp(512,200));
    menu->addChild(temp);

    temp = CCMenuItemFont::create("+1second", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(250,300));
    temp->setTag(6);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-1second", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(750,300));
    temp->setTag(-6);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("+1minute", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(250,250));
    temp->setTag(5);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-1minute", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(750,250));
    temp->setTag(-5);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("+1hour", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(250,200));
    temp->setTag(4);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-1hour", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(750,200));
    temp->setTag(-4);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("+1day", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(250,150));
    temp->setTag(3);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-1day", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(750,150));
    temp->setTag(-3);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("+1month", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(250,100));
    temp->setTag(2);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-1month", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(750,100));
    temp->setTag(-2);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("+1year", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(250,50));
    temp->setTag(1);
    menu->addChild(temp);
    
    temp = CCMenuItemFont::create("-1year", this, menu_selector(HelloWorld::modify));
    temp->setPosition(ccp(750,50));
    temp->setTag(-1);
    menu->addChild(temp);
    
    menu->setPosition(ccp(0,0));
    this->addChild(menu);
    return true;
}

void HelloWorld::addTimezoneOffset()
{
    date->setTimezoneOffset(date->getTimezoneOffset() + 60 * 60);
}

void HelloWorld::subTimezoneOffset()
{
    date->setTimezoneOffset(date->getTimezoneOffset() - 60 * 60);
}

void HelloWorld::modify(CCNode *Sender)
{
    switch (Sender->getTag())
    {
        case 6:
            date->setSeconds(date->getSeconds() + 1);
            break;
        case -6:
            date->setSeconds(date->getSeconds() - 1);
            break;
        case 5:
            date->setMinutes(date->getMinutes() + 1);
            break;
        case -5:
            date->setMinutes(date->getMinutes() - 1);
            break;
        case 4:
            date->setHours(date->getHours() + 1);
            break;
        case -4:
            date->setHours(date->getHours() - 1);
            break;
        case 3:
            date->setDay(date->getDay() + 1);
            break;
        case -3:
            date->setDay(date->getDay() - 1);
            break;
        case 2:
            date->setMonth(date->getMonth() + 1);
            break;
        case -2:
            date->setMonth(date->getMonth() - 1);
            break;
        case 1:
            date->setYear(date->getYear() + 1);
            break;
        case -1:
            date->setYear(date->getYear() - 1);
            break;
    }
}

void HelloWorld::update(float dt)
{
    CCLabelTTF *label1, *label2;
    label1 = (CCLabelTTF*)this->getChildByTag(1);
    label2 = (CCLabelTTF*)this->getChildByTag(2);
    
//    date->initWithCurrentTime();
    label1->setString(CCString::createWithFormat("Local %d %d %d %d %d %d %d"
                                                ,date->getYear()
                                                ,date->getMonth()
                                                ,date->getDay()
                                                ,date->getHours()
                                                ,date->getMinutes()
                                                ,date->getSeconds()
                                                ,date->getTimezoneOffset()
                                                )->getCString());
    
    label2->setString(CCString::createWithFormat("UTC %d %d %d %d %d %d"
                                                ,date->getUTCYear()
                                                ,date->getUTCMonth()
                                                ,date->getUTCDay()
                                                ,date->getUTCHours()
                                                ,date->getUTCMinutes()
                                                ,date->getUTCSeconds()
                                                )->getCString());
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
