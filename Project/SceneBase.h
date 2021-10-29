#pragma once
#include<memory>

namespace Game
{
	//�V�[���̊��N���X
	class SceneBase
	{
	protected:

		//�V�[���ύX�t���O
		bool changeFlag; 

		//�ύX��V�[��
		int nextScene;

	public:
		//�f�X�g���N�^
	 virtual~SceneBase() = default;

	 //�ǂݍ���
	 virtual bool Load() = 0;
	 //������
	 virtual void Initialize() = 0;
	 //�X�V
	 virtual void Update() = 0;
	 //�`��
	 virtual void Render() = 0;
	 //���
	 virtual void Release() = 0;

	 //�V�[���ύX�t���O�̎擾
	 bool IsChange() const noexcept 
	 {
		 return changeFlag;
	 }
	 //���̃X�e�[�W���̎擾
	 int GetNextScene() const noexcept 
	 {
		 return nextScene;
	 }
	};
	//�|�C���^���̒u������
	using ScenePtr = std::shared_ptr<SceneBase>;
}
