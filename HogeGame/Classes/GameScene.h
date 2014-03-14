//
//  GameScene.h
//  HogeGame
//
//  Created by 高橋優 on 2014/03/07.
//
//
#ifndef __HogeGame__GameScene__
#define __HogeGame__GameScene__

#include "cocos2d.h"

class GameScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(GameScene);
    
    virtual bool onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
    virtual void onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent);
private:
    int movePiece;
    
    void makeBackground();
    void makePieces();
};

#endif /* defined(__HogeGame__GameScene__) */
