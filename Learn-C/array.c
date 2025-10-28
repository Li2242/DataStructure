#include "array.h"


// typedef struct {
// 	int *array;
// 	int size;
// }Array;

Array array_create(int size){
	Array a;
	a.size = size;
	a.array = (int*)malloc(sizeof(int) * a.size);
	//直接返回一个结构体
	return a;
};

void  array_free(Array *a){ 
	free(a);
};

int arrar_size(const Array *a){
	return a->size;
};

int*  array_at(Array *a , int index){
	if(index >= a->size){
		array_inflate(a,index +1);
	}
	return &a->array[index];
};

void  array_inflate(Array *a,int more_size){
	int *p = (int*)malloc(sizeof(int)*(a->size+more_size));
	a->size += more_size;
	for(int i=0; i < a->size; i++){
		p[i] = a->array[i];
	}
	free(a->array);
	a->array = p;
};



