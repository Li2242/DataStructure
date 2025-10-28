#include<stdio.h>
#include<iostream>
using namespace std;
typedef struct {
    int top[2], bot[2];
    int *V;
    int m;
} DblStack;

void init(DblStack &s, int maxSize);
bool empty0(DblStack S);
bool empty1(DblStack S);
bool full(DblStack S);
bool push0(DblStack& s , int value);
bool push1(DblStack& s , int value);
bool pop0(DblStack &s , int& a);
bool pop1(DblStack &s , int& a);