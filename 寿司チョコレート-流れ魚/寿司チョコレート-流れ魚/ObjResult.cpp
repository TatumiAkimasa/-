#include "GameHead.h"
#include "ObjResult.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL\WinInputs.h"

//使用するゲームスペース
using namespace GameL;

//コンストラクタ
CObjResult::CObjResult()
{

}

//イニシャライズ
void CObjResult::Init()
{
	m_key_flag = false;
}

//アクション
void CObjResult::Action()
{
	//エンターキーを押してシーン：ゲームタイトルに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag == false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjResult::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	Font::StrDraw(L"終了！", 300, 250, 64, c);
	Font::StrDraw(L"Puth Enter", 230, 400, 64, c);
}