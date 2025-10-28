#include <iostream>
using namespace std;
#include <stdio.h>

void dec2bin(int n){
	int bin[32];
	int temp = n;
	int i = 0;
	if(n == 0){
		printf("0\n");
		return;
	}
	while(temp > 0){
		bin[i++] = temp % 2;
		temp /= 2;
	}
	for(int j = i - 1; j >= 0; j--){
		printf("%d",bin[j]);
	}
	return;
}

int main(){
	int i =0;
	cin >> i;
	dec2bin(i);
	return 0;
}