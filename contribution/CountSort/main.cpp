#include <iostream>

using namespace std;
void CountSort(int arr[],int n, int k)
{
    int counter[k];
    int output[n];
    for(int i=0;i<k;i++)
        counter[i]=0;
    for(int i=0;i<n;i++)
        counter[arr[i]]++;
    for(int i=1;i<k;i++)
        counter[i]+=counter[i-1];
    for(int i=n-1;i>=0;i--)
    {
        output[counter[arr[i]]-1] = arr[i];
        counter[arr[i]]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[]= {1,1,4,4,5,2,8,2};
    CountSort(arr,8,9);
    return 0;
}
