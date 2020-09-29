#include<stdio.h>

struct Array
{
	int A[10];
	int size;	//size of array
	int length;	// no. of elements in array
};

void Display(struct Array arr)
{
	int i;
	printf("\nArray elements are :\n");
	for(i=0; i < arr.length; i++)
		printf("%d\t", arr.A[i]);
}

void Append(struct Array *arr, int element)
{
	//if array is not full, append x
	if(arr->length < arr->size)
		arr->A[arr->length++] = element;
}

void Insert(struct Array *arr, int index, int element)
{
	int i;	
	if(index >= 0 && index <= arr->length)
	{
		for(i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i-1];
		arr->A[index] = element;
		arr->length++;
	}
}

int Delete(struct Array *arr, int index)
{
	int i, item = 0;
	if(index>=0 && index < arr->length)
	{
		item = arr->A[index];
		for(i = index; i < arr->length-1; i++)
			arr->A[i] = arr->A[i+1];
		arr->length--;
	}
	return item;
}
int main()
{
	int item;
	struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
	
	Append(&arr, 6);
	
	Insert(&arr, 1, 7);
	
	Display(arr);
	
	item = Delete(&arr, 3);
	printf("\nDeleted item : %d", item);
	
	Display(arr);
	return 0;
}
