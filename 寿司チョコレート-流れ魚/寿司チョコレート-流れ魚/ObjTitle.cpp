//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>


//使用するネームスペース
using namespace GameL;

int CObjTitle::key_num_T()
{
	return num;
}

bool CObjTitle::key_num2_T()
{
	return R_flag;
}
//イニシャライズ
void CObjTitle::Init()
{
	R_flag = false;
	L_flag = false;
	num = 0;//描画優先度
}
//アクション
void CObjTitle::Action()
{
	//スペースキーを押してシーン：ゲーム説明に移行する。/
	if (Input::GetVKey(VK_RIGHT) == true)
	{

		if (R_flag == true)
		{

			//+=2でタイトル戻るときたまに2回タップしかダメ
			num ++;
			
			R_flag = false;
		}
	}
	else
	{
		R_flag = true;
	}

	//スペースキーを押してシーン：ゲーム説明に移行する。/
	if (Input::GetVKey(VK_LEFT) == true)
	{

		if (L_flag == true)
		{

			//+=2でタイトル戻るときたまに2回タップしかダメ
			num--;
			L_flag = false;
		}
	}
	else
	{
		L_flag = true;
	}

	if (num > 4)
	{
		num = 4;
	}
	else if (num < 0)
	{
		num = 0;
	}

	//エンターキーを押してシーン：ゲームメインに移行する。
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//開始時ＳＥ
		Audio::Start(1);
		std::this_thread::sleep_for(std::chrono::seconds(2)); 
			Scene::SetScene(new CSceneMain());

	}
	
}
//ドロー//タイトル
void CObjTitle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	if (num == 0)
	{
		//切り取り位置の表示
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 1020.0f;
		src.m_bottom = 680.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
	}
	else
	{
		//切り取り位置の表示
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 765.0f;
		src.m_bottom = 640.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 616.0f;
	}
	

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(num, &src, &dst, c, 0.0f);
}