// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// IncrementNumber.h
//
//  
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


#ifndef NUMBERALLOCATION_H
#define NUMBERALLOCATION_H


#include "stdafx.h"

#include <thread>
#include <mutex>

class IncrementNumber{
public:

	typedef int32_t number_t;

	// �P���C���N�������g�p
	IncrementNumber();

	// 1�����C���N�������g�p
	IncrementNumber(number_t xEnd);

	// 2�����C���N�������g�p
	IncrementNumber(number_t xEnd, number_t yEnd);

	// 3�����C���N�������g�p
	IncrementNumber(number_t xEnd, number_t yEnd, number_t zEnd);

	// �P���C���N�������g
	number_t increment();

	// 1�����C���N�������g
	bool increment(number_t &x);

	// 2�����C���N�������g
	bool increment(number_t &x, number_t &y);

	// 3�����C���N�������g
	bool increment(number_t &x, number_t &y, number_t &z);

	void clearCo();

private:
	const	number_t	m_xEnd, m_yEnd, m_zEnd;
			number_t	m_xCo, m_yCo, m_zCo;
	const	int32_t		m_Dim;

	std::mutex			m_mtx;
};

#endif

