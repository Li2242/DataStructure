#include "tool.h"

void init(DblStack &s, int maxSize){
	s.m = maxSize;
	s.top[0] = -1;
	s.bot[0] = 0;
	s.top[1] = maxSize - 1;
	s.bot[1] = maxSize;
	printf("初始化成功！");
}
bool empty0(DblStack S){
	return S.top[0] == -1;
}

bool empty1(DblStack S){
	return S.top[1] == S.m;
}

bool full(DblStack s){
	return s.top[0] == s.top[1] - 1;
};

bool push0(DblStack &s , int value){
	if(full(s)){
		printf("FULL ERROR!");
		return false;
	}
	s.V[++s.top[0]] = value;
	return true;
}

bool push1(DblStack &s, int value){
	if(full(s)){
			printf("FULL ERROR!");
			return false;
		}
		s.V[--s.top[1]] = value;
		return true;
}
bool pop0(DblStack &s , int& a){
	if(empty0(s)){
		printf("EMPRY ERROR!");
	}
	a = s.V[s.top[0]--];
	return true;
}

bool pop1(DblStack &s , int& a){
	if(empty1(s)){
		printf("EMPRY ERROR!");
	}
	a = s.V[s.top[1]++];
	return true;
}