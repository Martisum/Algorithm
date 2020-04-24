#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
using namespace std;
//定义老师取还钥匙的先后顺序
struct Class {
	bool flag;	//1表示取钥匙，0表示还钥匙
	int num;	//钥匙编号
	int time;	//时间标识
	bool operator <(const Class& s)const {
		if (time == s.time) {
			if (flag == s.flag)
				return num > s.num;		//编号小的先还
			else
				return flag > s.flag;	//先还钥匙
		} else
			return time > s.time;		//最小堆
	}
};
priority_queue<Class> Order;
//定义钥匙位置的状态
struct Key {
	bool flag;	//0标识该空位无钥匙，1表示有
	int num;	//num表示钥匙编号
};
int main() {
	int  N, K;
	cin >> N >> K;
	map<int, Key>Array;
	Key k;
	for (int i = 1; i <= N; i++) {	//初始化钥匙的位置信息
		k.flag = 1;
		k.num = i;
		Array[i] = k;
	}
	int num, start, time;
	Class C;
	for (int i = 1; i <= K; i++) {
		cin >> num >> start >> time;
		C.flag = 1;
		C.num = num;
		C.time = start;
		Order.push(C);
		C.flag = 0;
		C.time = start + time;
		Order.push(C);
	}
	while (!Order.empty()) {
		C = Order.top();
		if (C.flag == 0) {	//还钥匙
			for (int i = 1; i <= N; i++) {
				if (Array[i].flag == 0) {
					Array[i].flag = 1;
					Array[i].num = C.num;
					break;
				}
			}
		} else {				//取钥匙
			for (int i = 1; i <= N; i++) {
				if (Array[i].num == C.num) {
					Array[i].flag = 0;
					break;
				}
			}
		}
		Order.pop();
	}
	for (int i = 1; i <= N; i++) {
		cout << Array[i].num << ' ';
	}
	cin >> N;
	return 0;
}

