#include <iostream>
#include <cstdio>
using namespace std;

struct Array
{
	int A[10];
	int size;
	int length;
};

//iterative version
int binary_search(struct Array arr, int key)
{
	int beg = 0;
	int end = arr.length-1;
	int mid;
	
	while(beg<=end)
	{
		mid = (beg+end)/2;
		if (arr.A[mid] == key)
			return mid;
		else if (arr.A[mid] < key)
			beg = mid+1;
		else
			end = mid-1;
	}
	return -1;
}

//recursive version
int r_binary_search(int a[], int beg, int end, int key)
{
	if (beg<=end)
	{
		int mid = (beg+end)/2;
		if (a[mid]==key)
			return mid;
		else if (a[mid] < key)
			return r_binary_search(a, mid+1, end, key);
		else
			return r_binary_search(a, beg, mid-1, key);
	}
	return -1;
}

//driver code
int main()
{
	struct Array arr = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10, 10};
	
	int key, index;
	cout<<"Enter the element to be searched : ";
	cin>>key;
	//index = binary_search(arr, key);
	index = r_binary_search(arr.A, 0, arr.length-1, key);
	cout<<"Index of "<<key<<" = "<<index;
	return 0;
}
