//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjSetting.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjSetting::Init()
{
	R_flag = true;
	L_flag = true;
	U_flag = true;
	D_flag = true;
	setting_pos = 0;
}
//アクション
void CObjSetting::Action()
{
	//bkeyでタイトルに戻る
	if (Input::GetVKey('B') == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
	//上下キーで設定したい欄に移動
	if (Input::GetVKey(VK_UP) == true)
	{
		if (U_flag == true)
		{
			if (setting_pos > 0)
			{
				setting_pos -= 1;
			}
			else
			{
				;
			}
			U_flag = false;
		}
	}
	else
	{
		U_flag = true;
	}
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (D_flag == true)
		{
			if (setting_pos < 1)
			{
				setting_pos += 1;
			}
			else
			{
				;
			}
			D_flag = false;
		}
	}
	else
	{
		D_flag = true;
	}

	if (setting_pos == 0)
	{
		if (((UserData*)Save::GetData())->start_sp < 20.0f)
		{
			if (Input::GetVKey(VK_RIGHT) == true)
			{

				if (R_flag == true)
				{
					((UserData*)Save::GetData())->start_sp += 0.5f;
					R_flag = false;
				}
			}
			else
			{
				R_flag = true;
			}
		}

		if (((UserData*)Save::GetData())->start_sp > 5.0f)
		{
			if (Input::GetVKey(VK_LEFT) == true)
			{

				if (L_flag == true)
				{
					((UserData*)Save::GetData())->start_sp -= 0.5f;
					L_flag = false;
				}
			}
			else
			{
				L_flag = true;
			}
		}
	}

	if (setting_pos == 1)
	{
		if (Input::GetVKey(VK_RIGHT) == true)
		{

			if (R_flag == true)
			{
				((UserData*)Save::GetData())->start_control_mirror = false;
				R_flag = false;
			}
		}
		else
		{
			R_flag = true;
		}

		if (Input::GetVKey(VK_LEFT) == true)
		{

			if (L_flag == true)
			{
				((UserData*)Save::GetData())->start_control_mirror = true;
				L_flag = false;
			}
		}
		else
		{
			L_flag = true;
		}
	}
	
}
//ドロー
void CObjSetting::Draw()
{	
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[256];
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	Font::StrDraw(L"設定", 330, 25, 50, c);

	Font::StrDraw(L"初期速度", 80, 100, 50, c);
	if (setting_pos == 0)
	{
		Font::StrDraw(L"________", 80, 110, 50, c);
	}
	
	swprintf_s(str, L"%0.1f", ((UserData*)Save::GetData())->start_sp);
	Font::StrDraw(str, 400, 100, 50, c);

	Font::StrDraw(L"操作反転モード", 80, 200, 50, c);
	if (setting_pos == 1)
	{
		Font::StrDraw(L"______________", 80, 210, 50, c);
	}
}