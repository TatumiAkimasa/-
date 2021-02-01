#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

#define SET_INFO_SIZE 50

//オブジェクト：タイトル
class CObjSetting :public CObj
{
public:
	CObjSetting() {};
	~CObjSetting() {};
	void Init();
	void Action();
	void Draw();
private:
	bool R_flag;//キーフラグ(右）
	bool L_flag;//キーフラグ（左）
	bool U_flag;//キーフラグ(上）
	bool D_flag;//キーフラグ（下）
	bool S_flag;//初期速度を初期化するためのフラグ
	bool M_flag;//操作反転モードを初期化するためのフラグ
	int setting_pos;//自分が設定したい欄への移動
	bool Hidden_flag;//隠されたもの管理用（数が多いならintへ変更）
};