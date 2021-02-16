#include <iostream>
using namespace std;

struct Array
{
	int A[10];
	int size;	//size of array
	int length;	//no. of elements present
};

//reversing an array
void Reverse_array(struct Array *arr)
{
	if (arr->length > 0)
	{
		for (int i=0, j=arr->length-1; i<j; i++, j--)	//swap first element with last element, and so on..
		{
			int temp = arr->A[i];
			arr->A[i] = arr->A[j];
			arr->A[j] = temp;
		}
	}
}

//Left Array rotation
void Left_Rotation(struct Array *arr)
{
	if(arr->length > 0)
	{
		int temp = arr->A[0];	//store first element
		for (int i=1; i<arr->length; i++)	//left shift all the elements from index 1 to n-1
			arr->A[i-1] = arr->A[i];
		arr->A[arr->length-1] = temp;	//assign first element to last index
	}
}

//function to insert element in a sorted array
void Insert_Sorted(struct Array *arr, int element)
{
	if (arr->length > 0 && arr->length<arr->size)
	{
		int i = arr->length-1;
		while(arr->A[i] > element)
		{
			arr->A[i+1] = arr->A[i];
			i--;
		}
		arr->A[i+1] = element;
		arr->length++;
	}
}

//Function to check if elements are sorted
bool is_Sorted(struct Array arr)
{
	if(arr.length > 0)
	{
		for(int i=0; i<arr.length-1; i++)
		{
			if (arr.A[i] > arr.A[i+1])
				return false;
		}
		return true;
	}
}

//Display elements of array
void display(struct Array arr)
{
	int i;
	printf("\nArray elements are :\n");
	for(i=0; i < arr.length; i++)
		printf("%d\t", arr.A[i]);
}

//driver code
int main()
{
	struct Array arr1 = {{1, 2, 3, 4, 5}, 5, 5};
	
	Reverse_array(&arr1);
	display(arr1);
	
	Left_Rotation(&arr1);
	display(arr1);
	
	struct Array arr2 = {{10, 12, 14, 18, 20}, 10, 5};
	Insert_Sorted(&arr2, 16);
	display(arr2);
	
	if (is_Sorted(arr2))
		cout<<"\nTrue";
	else
		cout<<"\nFalse";
	
	return 0;
}












