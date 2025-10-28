#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
	int top;
	char *v;
	int m;
}stack;

bool empty (stack s){
	return s.top == -1;
}
bool full (stack s){
	return s.top == s.m - 1;
}

//入栈
bool push(stack &s , char value){
	if(full(s)){
		return false;
	}
	s.v[++s.top] = value;
	return true;
}

//出栈
bool pop(stack &s, char& a){
	if(empty(s)){
		return false;
	}
	a = s.v[s.top--];
	return true;
}

bool isValid(stack &s){
	char str[10001];
	cin >> str;
	int len = strlen(str);
	if(len == 0){
		return true;
	}
	if(len%2 != 0){
		return false;
	}
	for(int i = 0; i < len; i++){
		char c = str[i];
		//检测
		if(c=='(' || c=='[' || c=='{'){
			if(!push(s,c)){
				return false;
			}
		}else{
			if(empty(s)){
				return false;
			}
			char t;
			pop(s , t);
			if((t == '(' && c != ')') || 
				 (t == '[' && c != ']') ||
				 (t == '{' && c != '}') ){
					free(s.v);
					return false;
				}
				
		}
	}
	bool result = empty(s);
	return result;
}

int main(){
	stack s;
	int maxSize = 10000;
	s.m = maxSize;
	s.top = -1;
	s.v = (char*)malloc(maxSize * sizeof(char));
	if (s.v == NULL) {  // 检查内存是否分配成功
    printf("false\n");  // 内存分配失败时，无法处理，返回无效
    return 1;
}
	bool state = isValid(s);
	printf("%s\n",state ? "true":"false");

	free(s.v);
	return 0;
}