//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"

//使用するネームスペース
using namespace GameL;

int CObjDescription::key_num_D()
{
	return numd;
}

//イニシャライズ
void CObjDescription::Init()
{
	m_key_flag = false;
	numd = 10;//描画優先度
	int i = 1;
}
//アクション
void CObjDescription::Action()
{
	CObjTitle* obj = (CObjTitle*)Objs::GetObj(OBJ_TITLE);

	numd = obj->key_num_T();

	//スペースキーを押してシーン：ゲームタイトルに移行する。
	if (Input::GetVKey(VK_LEFT) == true)
	{
		if (m_key_flag == true)
		{
			numd++;
			//タイトルオブジェクト作成
			CObjTitle* obj = new CObjTitle();
			Objs::InsertObj(obj, OBJ_TITLE, numd);


			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}
//ドロー//タイトル
void CObjDescription::Draw()
{

	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の表示
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 776.0f;
	src.m_bottom = 616.0f;

	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;

	if (Input::GetVKey(VK_RIGHT) == true)
	{
		i++;
	}

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画
	Draw::Draw(i, &src, &dst, c, 0.0f);

	
}