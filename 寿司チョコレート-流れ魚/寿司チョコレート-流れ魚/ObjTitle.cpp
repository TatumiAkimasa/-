//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

int CObjTitle::key_num_T()
{
	return num;
}

//イニシャライズ
void CObjTitle::Init()
{
	m_key_flag = false;
	num = 10;//描画優先度
}
//アクション
void CObjTitle::Action()
{
	CObjDescription* obj = (CObjDescription*)Objs::GetObj(OBJ_DESCRIPTION);

	num = obj->key_num_D();

	//エンターキーを押してシーン：ゲームメインに移行する。
	if (Input::GetVKey(VK_RETURN) == true)
	{
		//開始時ＳＥ
		Audio::Start(1);

		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}

	//上下キーを押してシーン：ランキングに移行する。/
	if (Input::GetVKey(VK_DOWN) == true)
	{
		Scene::SetScene(new CSceneRanking());
	}
	

	//左右キーを押してシーン：ゲーム説明に移行する。/
	if (Input::GetVKey(VK_RIGHT) == true)
	{

		if (m_key_flag == true)
		{

			//+=2でタイトル戻るときたまに2回タップしかダメ
			num += 2;
			//説明オブジェクト作成
			CObjDescription* obj = new CObjDescription();
			Objs::InsertObj(obj, OBJ_DESCRIPTION, num);

			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー//タイトル
void CObjTitle::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

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

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}