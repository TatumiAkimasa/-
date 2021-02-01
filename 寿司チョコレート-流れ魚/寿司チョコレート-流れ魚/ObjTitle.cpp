//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"
#include <thread>
#include <chrono>


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjTitle::CObjTitle()
{
	R_flag = false;
	L_flag = false;
	D_flag = false;
	num = 0;//描画優先度
}

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
	//((UserData*)Save::GetData())->sp_lv = 0;//スピードレベル初期化

	static bool init_point = false;
	if (init_point == false)
	{
		//ランキング初期化
		for (int i = 0; i < 11; i++)
		{
			((UserData*)Save::GetData())->Ranking[i] = 0;
		}

		Save::Open();//同フォルダ「UserData」からデータ取得

		//点数を0にする
		((UserData*)Save::GetData())->save_score = 0;
		init_point = true;
	}

	//得点ランキング最下位(描写圏外)に登録
	((UserData*)Save::GetData())->Ranking[10] = ((UserData*)Save::GetData())->save_score;

	//得点が高い順に並び替えをする
	RankingSort(((UserData*)Save::GetData())->Ranking);

	//ゲーム実行して一回のみ以外、ランキングを自動セーブする
	if (init_point == true)
	{
		Save::Seve();//UserDataの情報を同じフォルダ「UserData」を作成する
	}
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
	//上下キーを押してシーン：ランキングに移行する。/
	if (Input::GetVKey(VK_DOWN) == true)
	{
		if (D_flag == true)
		{
			Scene::SetScene(new CSceneRanking());
			D_flag = false;
		}
	}
	else
	{
		D_flag = true;
	}

	//Sキーで設定欄に移動
	if (Input::GetVKey('S') == true)
	{
		Scene::SetScene(new CSceneSetting());
	}

	//描画数（説明画面）
	if (num > 7)
	{
		num = 7;
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
		std::this_thread::sleep_for(std::chrono::seconds(2)); //開始時処理を2秒止める(開始SEを鳴らすため）
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
		src.m_right = 1024.0f;
		src.m_bottom = 683.0f;

		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;
	}
	

	//0番目に登録したグラフィックをsrc・dst・cの情報を元に描画です

	Draw::Draw(num, &src, &dst, c, 0.0f);


}

//ランキングソートメソッド
//引数1　int[11] :ランキング用配列
//高順でバブルソートを行う
void CObjTitle::RankingSort(int rank[11])
{
	//値交換用変数
	int w;

	//バブルソート
	for (int i = 0; i < 10; i++)
	{
		for (int j = i + 1; j < 11; j++)
		{
			if (rank[i] < rank[j])
			{
				//値の交換
				w = rank[i];
				rank[i] = rank[j];
				rank[j] = w;
			}
		}
	}

}