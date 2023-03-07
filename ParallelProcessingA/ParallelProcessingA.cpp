// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 並列処理の設計
//
// CPUの数だけスレッドを起動して、スレッドの中で処理番号を取得、
// 全ての処理が終了するまで繰り返す。
// 
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

#include "stdafx.h"

#include <vector>
#include <iostream>

#include "IncrementNumber.h"


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// 適当な処理関数
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
void hoge(std::vector<int32_t> &c ,const int32_t &a )
{
	c[a] = a * 2;	// 配列序数の倍の数値を格納
}

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
// メイン
// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<std::thread> threads;
	std::vector<int32_t>	data(1024);

	// 処理割り振り用データ数格納
	IncrementNumber	na(data.size());

	// スレッド起動
	int32_t i;
	int32_t	end = std::thread::hardware_concurrency();
	for (i = 0; i < end; i++){
		threads.emplace_back([&data,&na](){
			int32_t n;
			while (na.increment(n)){	// 処理番号取得 無ければfalse
				hoge(data ,n);			// 演算
			}
		});
	}

	// 全スレッドの終了ち
	for (auto&& t : threads) {
		t.join();
	}

	// 計算結果
	end = data.size();
	for (i = 0; i < end; i++){
		std::cout << data[i] << ",";
	}

	getchar();

	return 0;
}

