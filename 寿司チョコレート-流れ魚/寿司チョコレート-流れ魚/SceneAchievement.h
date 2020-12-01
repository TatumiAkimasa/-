#pragma once
//使用するヘッダー
#include "GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機
class CSceneAchievement :public CScene
{
public:
	CSceneAchievement();
	~CSceneAchievement() {};
	void InitScene();	//イニシャライズ
	void Scene();  //アクション
private:
};