//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameL/WinInputs.h"
#include "GameL/SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjMain.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMain::Init()
{
	f = 0;
	s_time = 0;
	m_time = 0;
	((UserData*)Save::GetData())->save_s_time = 0;//セーブ用m_time初期化
	((UserData*)Save::GetData())->save_m_time = 0;//セーブ用s_time初期化
}

//アクション
void CObjMain::Action()
{
	f++;
	//fが60回回ると1秒カウント
	if (f == 60)
	{
		f = 0;
		s_time++;
		//s_time++の時点でセーブ用s_timeもインクリメント
		((UserData*)Save::GetData())->save_s_time++;
	
	}
	//s_timeが60で1分です
	if (s_time == 60)
	{
		s_time = 0;
		m_time++;
		//m_time++の時点でセーブ用m_timeもインクリメント
		((UserData*)Save::GetData())->save_m_time++;
		((UserData*)Save::GetData())->save_s_time = 0;
	}
}

//ドロー
void CObjMain::Draw()
{
	float c[4] = { 1,1,1,1 };

	//仮マウス位置表示
	wchar_t str[256];
	swprintf_s(str, L"タイム　%d:%d", m_time, s_time);
	Font::StrDraw(str, 20, 40, 40, c);

}