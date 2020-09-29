#include<stdio.h>

struct Array
{
	int A[10];
	int size;	//size of array
	int length;	// no. of elements in array
};

int LinearSearch(struct Array arr, int item)
{
	int i;
	for(i=0; i<arr.length; i++)
	{
		if(item == arr.A[i])
			return i;
	}
	return -1;
}

int main()
{
	int loc;
	struct Array arr = {{1, 2, 3, 4, 5}, 10, 5};
	
	loc = LinearSearch(arr, 4);
	printf("Location = %d", loc);
	
	return 0;
}
