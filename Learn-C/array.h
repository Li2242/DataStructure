#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int *array;
	int size;
}Array;

Array array_create(int size);
void  array_free(Array *a);
int   arrar_size(const Array *a);
int*  array_at(Array *a, int index);
void  array_inflate(Array *a,int more_size);