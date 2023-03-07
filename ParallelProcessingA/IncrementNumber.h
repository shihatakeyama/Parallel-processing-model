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

	// 単純インクリメント用
	IncrementNumber();

	// 1次元インクリメント用
	IncrementNumber(number_t xEnd);

	// 2次元インクリメント用
	IncrementNumber(number_t xEnd, number_t yEnd);

	// 3次元インクリメント用
	IncrementNumber(number_t xEnd, number_t yEnd, number_t zEnd);

	// 単純インクリメント
	number_t increment();

	// 1次元インクリメント
	bool increment(number_t &x);

	// 2次元インクリメント
	bool increment(number_t &x, number_t &y);

	// 3次元インクリメント
	bool increment(number_t &x, number_t &y, number_t &z);

	void clearCo();

private:
	const	number_t	m_xEnd, m_yEnd, m_zEnd;
			number_t	m_xCo, m_yCo, m_zCo;
	const	int32_t		m_Dim;

	std::mutex			m_mtx;
};

#endif

