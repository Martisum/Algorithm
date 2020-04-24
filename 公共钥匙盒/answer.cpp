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
//������ʦȡ��Կ�׵��Ⱥ�˳��
struct Class {
	bool flag;	//1��ʾȡԿ�ף�0��ʾ��Կ��
	int num;	//Կ�ױ��
	int time;	//ʱ���ʶ
	bool operator <(const Class& s)const {
		if (time == s.time) {
			if (flag == s.flag)
				return num > s.num;		//���С���Ȼ�
			else
				return flag > s.flag;	//�Ȼ�Կ��
		} else
			return time > s.time;		//��С��
	}
};
priority_queue<Class> Order;
//����Կ��λ�õ�״̬
struct Key {
	bool flag;	//0��ʶ�ÿ�λ��Կ�ף�1��ʾ��
	int num;	//num��ʾԿ�ױ��
};
int main() {
	int  N, K;
	cin >> N >> K;
	map<int, Key>Array;
	Key k;
	for (int i = 1; i <= N; i++) {	//��ʼ��Կ�׵�λ����Ϣ
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
		if (C.flag == 0) {	//��Կ��
			for (int i = 1; i <= N; i++) {
				if (Array[i].flag == 0) {
					Array[i].flag = 1;
					Array[i].num = C.num;
					break;
				}
			}
		} else {				//ȡԿ��
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

