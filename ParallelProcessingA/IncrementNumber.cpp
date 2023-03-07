// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// IncrementNumber.cpp
//
// USE std::mutex
//
// スレッドへ処理番号を割り当てる。
// 1本のスレッドが複数の処理をする為に番号を割り当てる。
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "stdafx.h"
#include <assert.h>

#include "IncrementNumber.h"


IncrementNumber::IncrementNumber()
: m_xEnd(0), m_yEnd(0), m_zEnd(0)
, m_xCo(0), m_yCo(0), m_zCo(0)
, m_Dim(0)
{}

IncrementNumber::IncrementNumber(number_t xEnd)
: m_xEnd(xEnd), m_yEnd(0), m_zEnd(0)
, m_xCo(0), m_yCo(0), m_zCo(0)
, m_Dim(1)
{}

IncrementNumber::IncrementNumber(number_t xEnd ,number_t yEnd)
: m_xEnd(xEnd), m_yEnd(yEnd), m_zEnd(0)
, m_xCo(0), m_yCo(0), m_zCo(0)
, m_Dim(2)
{}

IncrementNumber::IncrementNumber(number_t xEnd ,number_t yEnd ,number_t zEnd)
: m_xEnd(xEnd), m_yEnd(yEnd), m_zEnd(zEnd)
, m_xCo(0), m_yCo(0), m_zCo(0)
, m_Dim(3)
{}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 単純インクリメント
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int32_t IncrementNumber::increment()
{
	assert(m_Dim == 0);

	std::lock_guard<std::mutex> lock(m_mtx);

	return m_xCo++;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 1次元インクリメント
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
bool IncrementNumber::increment(number_t &x)
{
	assert(m_Dim == 1);

	std::lock_guard<std::mutex> lock(m_mtx);

	if (m_xCo >= m_xEnd)	return false;
	x = m_xCo++;

	return true;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 2次元インクリメント
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
bool IncrementNumber::increment(number_t &x, number_t &y)
{
	assert(m_Dim == 2);

	std::lock_guard<std::mutex> lock(m_mtx);

	if (m_yCo >= m_yEnd)	return false;
	x = m_xCo++;
	if (x >= m_xEnd){
		x = 0;
		m_yCo++;
	}

	return true;
}
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 3次元インクリメント
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
bool IncrementNumber::increment(number_t &x ,number_t &y ,number_t &z)
{
	assert(m_Dim == 3);

	std::lock_guard<std::mutex> lock(m_mtx);

	if (m_zCo >= m_zEnd)	return false;
	x = m_xCo++;
	if (x >= m_xEnd){
		x = 0;
		m_yCo++;
		if (y >= m_yEnd){
			y = 0;
			m_zCo++;
		}
	}

	return true;
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// カウンタクリア
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void IncrementNumber::clearCo()
{
	m_xCo = 0;
	m_yCo = 0;
	m_zCo = 0;
}


