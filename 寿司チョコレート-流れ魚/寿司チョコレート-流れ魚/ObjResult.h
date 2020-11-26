#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

#define COMMENT_POS 400
#define COMMENT_SIZE 48

//オブジェクト：敵機
class CObjResult :public CObj
{
public:
	~CObjResult() {};
	void Init();	//イニシャライズ
	void Action();  //アクション
	void Draw();	//ドロー
private:
	bool m_key_flag;
	int m_time;
	int s_time;
	int m_score;
};