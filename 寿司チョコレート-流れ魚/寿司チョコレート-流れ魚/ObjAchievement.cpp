//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/DrawFont.h"
#include "GameL/UserData.h"

#include "GameHead.h"
#include "ObjAchievement.h"
#include "GameL/DrawTexture.h"
#include "GameL\Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjAchievement::Init()
{
	
}
//�A�N�V����
void CObjAchievement::Action()
{
	//�㉺�L�[�������ăV�[���F�^�C�g���Ɉڍs����B/
	if (Input::GetVKey(VK_UP) == true)
	{
		Scene::SetScene(new CSceneRanking());
	}
}
//�h���[
void CObjAchievement::Draw()
{
	
}