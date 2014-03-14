//
//  GameScene.cpp
//  HogeGame
//
//  Created by 高橋優 on 2014/03/07.
//
//

#include "GameScene.h"

using namespace cocos2d;
using namespace std;

Scene *GameScene::createScene()
{
    Scene *scene = Scene::create();
    GameScene *layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init()
{
    if (! CCLayer::init()) {
        return false;
    }
    movePiece = 0;
    
    setTouchEnabled(true);
    setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
    
    // 背景を作成する.
    makeBackground();
    //駒を配置する
    makePieces();
    return true;
}

// 背景を作成する.
void GameScene::makeBackground()
{
    Size winSize = Director::getInstance()->getWinSize();
    Sprite *spBG = Sprite::create("japanese-chess-b02.jpg");
    spBG->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5));
    this->addChild(spBG);
}

//駒を配置する
void GameScene::makePieces(){
    Size winSize = Director::getInstance()->getWinSize();
    Sprite *spPiece = Sprite::create("sgl01.png");
    Size pieceSize = spPiece->getContentSize();
    spPiece->setPosition(Point(winSize.width * 0.5, winSize.height * 0.5 - 4 * pieceSize.height));
    spPiece->setTag(1);
    this->addChild(spPiece);
}

bool GameScene::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    Director *pDirector = Director::getInstance();
    Point touchPoint = pDirector->convertToGL(pTouch->getLocationInView());
    Node *pPiece = this->getChildByTag(1);
    if(!pPiece){
        return false;
    }
    Rect pieceRect = pPiece->getBoundingBox();
    if(pieceRect.containsPoint(touchPoint)){
        movePiece = 1;
        return true;
    }
    return false;
}

void GameScene::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)
{
    if(movePiece == 0){
        return;
    }
    Node *pPiece = this->getChildByTag(movePiece);
    if(!pPiece){
        return;
    }
    Director *pDirector = Director::getInstance();
    Point touchPoint = pDirector->convertToGL(pTouch->getLocationInView());
    pPiece->setPosition(touchPoint);
}

void GameScene::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent){
    movePiece = 0;
}