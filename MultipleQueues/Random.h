#pragma once
#include<cstdlib>
#include<ctime>
class Random {
public:
	Random() {
		srand((unsigned)time(NULL));
	}
	int createNum(int range, int lb = 0) {
		return lb + rand() % range;
	}
};