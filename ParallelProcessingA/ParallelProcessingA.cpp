// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ���񏈗��̐݌v
//
// CPU�̐������X���b�h���N�����āA�X���b�h�̒��ŏ����ԍ����擾�A
// �S�Ă̏������I������܂ŌJ��Ԃ��B
// 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "stdafx.h"

#include <vector>
#include <iostream>

#include "IncrementNumber.h"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// �K���ȏ����֐�
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void hoge(std::vector<int32_t> &c ,const int32_t &a )
{
	c[a] = a * 2;	// �z�񏘐��̔{�̐��l���i�[
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// ���C��
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::thread> threads;
	std::vector<int32_t>	data(1024);

	// ��������U��p�f�[�^���i�[
	IncrementNumber	na(data.size());

	// �X���b�h�N��
	int32_t i;
	int32_t	end = std::thread::hardware_concurrency();
	for (i = 0; i < end; i++){
		threads.emplace_back([&data,&na](){
			int32_t n;
			while (na.increment(n)){	// �����ԍ��擾 �������false
				hoge(data ,n);			// ���Z
			}
		});
	}

	// �S�X���b�h�̏I����
	for (auto&& t : threads) {
		t.join();
	}

	// �v�Z����
	end = data.size();
	for (i = 0; i < end; i++){
		std::cout << data[i] << ",";
	}

	getchar();

	return 0;
}

