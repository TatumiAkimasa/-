#pragma once
//使用するヘッダー
#include "GameL\SceneManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵機
class CSceneResult :public CScene
{
public:
	CSceneResult() {};
	~CSceneResult() {};
	void InitScene();
	void Scene();
private:
};
