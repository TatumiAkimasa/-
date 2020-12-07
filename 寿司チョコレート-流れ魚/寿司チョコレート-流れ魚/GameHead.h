#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_BACK_GROUND,
	OBJ_BACK_GROUND_2,
	OBJ_BACK_GROUND_STATS,
	OBJ_WATER_FLOW,
	OBJ_TITLE,
	OBJ_RESULT,
	OBJ_10ENN,
	OBJ_FISH_PLAYER,
	OBJ_MAIN,
	OBJ_LIFE_ITEM,
	OBJ_SP_UP,
	OBJ_SP_DOWN,
	OBJ_FLOW,
	OBJ_MIRROR,
	OBJ_TREEITEM,
	OBJ_TREE,
	OBJ_100ENN,
	OBJ_1000ENN,
	OBJ_10000ENN,
	OBJ_BAD_LIFE,
	OBJ_RANKING,
	OBJ_TATAMI,
	OBJ_ACHIEVEMENT,

};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
	ELEMENT_HEAL,
	ELEMENT_COIN,
	ELEMENT_MIRROR,
	ELEMENT_TREEITEM,
	ELEMENT_TREE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{
	int mSeveData;			//サンプルセーブデータ
	int save_s_time;		//s_timeセーブ用変数
	int save_m_time;		//m_timeセーブ用変数
	int save_score;		    //scoreセーブ用変数
	float sp;				//スピード用変数
	int sp_lv = 1;			//スピード管理用変数
	int life_point = 3;		//主人公のライフ
	bool Tree_flag;			//木用フラグ
	int Tree_time = 0;		//木の表示時間用変数
	bool Tree_said;			//木の表示用フラグ
	bool key_flag_mirror;	//操作反転用フラグ
	int Ranking[11];        //ランキングの表示用変数
	bool Achievement_flag[29];//実績が解放されているかのフラグ

};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--
//特殊効果なしの障害物
enum FLOW_OBJ_ID
{
	FLOW1,//
	FLOW2,//
	FLOW3,//
	

};
//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ------------------
#include "ObjBackground.h"
#include "ObjBackground_2.h"
#include "ObjBackground_stats.h"
#include "Objwater_flow.h"
#include "ObjTitle.h"
#include "ObjFishPlayer.h"
#include "Obj10enn.h"
#include "ObjResult.h"
#include "ObjMain.h"
#include "ObjLifeItem.h"
#include "Objsp_up.h"
#include "Objsp_down.h"
#include "ObjFlow.h"
#include "Objmirror.h"
#include "ObjTreeItem.h"
#include "ObjTree.h"
#include "Obj100enn.h"
#include "Obj1000enn.h"
#include "Obj10000enn.h"
#include "Objbadlife.h"
#include "ObjRanking.h"
#include "ObjTatami.h"
#include "ObjAchievement.h"

//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneRanking.h"
#include "SceneAchievement.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------