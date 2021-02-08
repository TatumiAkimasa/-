#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define ACHIEVEMENT_POS_L 100
#define ACHIEVEMENT_POS_R 450
#define ACHIEVEMENT_SIZE 20

typedef struct STRUCT_ACHIEVEMENT
{
	char coment[40];
	int hight;
}achi;

//オブジェクト：タイトル
class CObjAchievement :public CObj
{
public:
	CObjAchievement() {};
	~CObjAchievement() {};
	void Init();
	void Action();
	void Draw();
private:
	
};