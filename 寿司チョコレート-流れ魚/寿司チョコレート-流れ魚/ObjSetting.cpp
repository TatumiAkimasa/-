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

//コンストラクタ
CObjSetting::CObjSetting()
{
	R_flag = true;
	L_flag = true;
	U_flag = true;
	D_flag = true;
	setting_pos = 0;
	Hidden_flag = false;
}

//イニシャライズ
void CObjSetting::Init()
{
	//((UserData*)Save::GetData())->start_sp = 5.0f;
	//((UserData*)Save::GetData())->start_control_mirror = true;
}
//アクション
void CObjSetting::Action()
{
	//enterでタイトルに戻る
	if (Input::GetVKey(VK_RETURN) == true)
	{
		Scene::SetScene(new CSceneTitle());
	}
	//上下キーで設定したい欄に移動
	if (Input::GetVKey(VK_UP) == true)
	{
		if (U_flag == true)
		{
			Audio::Start(0);
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
			Audio::Start(0);
			if (Hidden_flag == true)
			{
				if (setting_pos < 2)
				{
					setting_pos += 1;
				}
				else
				{
					;
				}
			}
			else
			{
				if (setting_pos < 1)
				{
					setting_pos += 1;
				}
				else
				{
					;
				}
			}
			D_flag = false;
		}
	}
	else
	{
		D_flag = true;
	}


	//初期速度の変更可能処理
	if (setting_pos == 0)
	{
		if (((UserData*)Save::GetData())->start_sp < 20.0f)
		{
			if (Input::GetVKey(VK_RIGHT) == true)
			{

				if (R_flag == true)
				{
					Audio::Start(0);
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
					Audio::Start(1);
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


	//操作反転モード変更可能処理
	if (setting_pos == 1)
	{
		if (Input::GetVKey(VK_RIGHT) == true)
		{

			if (R_flag == true)
			{
				Audio::Start(0);
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
				Audio::Start(0);
				((UserData*)Save::GetData())->start_control_mirror = true;
				L_flag = false;
			}
		}
		else
		{
			L_flag = true;
		}
	}
	
	if (((UserData*)Save::GetData())->Achievement_flag[26] == true)
	{
		Hidden_flag = true;
		if (setting_pos == 2)
		{
			
			if (Input::GetVKey(VK_RIGHT) == true)
			{
				if (R_flag == true)
				{
					Audio::Start(0);
					((UserData*)Save::GetData())->space_flag = true;
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
					Audio::Start(1);
					((UserData*)Save::GetData())->space_flag = false;
					L_flag = false;
				}
				}
			else
			{
				L_flag = true;
			}
			
		}
	}
}
//ドロー
void CObjSetting::Draw()
{	
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[256];
	

	Font::StrDraw(L"設定(矢印キーで操作)", 170, 25, SET_INFO_SIZE, c);

	Font::StrDraw(L"初期速度", 80, 100, SET_INFO_SIZE, c);
	if (setting_pos == 0)
	{
		Font::StrDraw(L"________", 80, 110, SET_INFO_SIZE, c);
	}
	
	swprintf_s(str, L"<- %0.1f +>", ((UserData*)Save::GetData())->start_sp);
	Font::StrDraw(str, 500, 100, 50, c);

	Font::StrDraw(L"操作反転モード", 80, 200, SET_INFO_SIZE, c);
	if (setting_pos == 1)
	{
		Font::StrDraw(L"______________", 80, 210, SET_INFO_SIZE, c);
	}
	if (((UserData*)Save::GetData())->start_control_mirror == true)
	{
		Font::StrDraw(L"<  OFF  >", 500, 200, SET_INFO_SIZE, c);
	}
	else
	{
		Font::StrDraw(L"<  ON   >", 500, 200, SET_INFO_SIZE, c);
	}

	Font::StrDraw(L"エンターキーで戻る", 540, 540, 25, c);

	if (Hidden_flag == true)
	{
		Font::StrDraw(L"スキン変更", 80, 300, SET_INFO_SIZE, c);
		if (setting_pos == 2)
		{
			Font::StrDraw(L"__________", 80, 310, SET_INFO_SIZE, c);
		}
		if (((UserData*)Save::GetData())->space_flag == true)
		{
			Font::StrDraw(L"<  宇宙  >", 500, 300, SET_INFO_SIZE, c);
		}
		else
		{
			Font::StrDraw(L"<  地球 >", 500, 300, SET_INFO_SIZE, c);
		}
	}
	else
	{
		Font::StrDraw(L"???(20万点必要)", 80, 300, SET_INFO_SIZE, c);
	}
}