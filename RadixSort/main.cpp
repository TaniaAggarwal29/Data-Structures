#include <iostream>

using namespace std;

void CountSort(int arr[],int n, int exp)
{
    int counter[10];
    int output[n];
    for(int i=0;i<10;i++)
        counter[i]=0;
    for(int i=0;i<n;i++)
    {
        counter[(arr[i]/exp)% 10]++;
    }
    for(int i=1;i<10;i++)
        counter[i]+=counter[i-1];
    for(int i=n-1;i>=0;i--)
    {
        output[counter[(arr[i]/exp)%10]-1] = arr[i];
        counter[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++)
        arr[i]=output[i];
 }
void Radix_Sort(int arr[],int n)
{
    int maxVal = arr[0];
    for(int i=1;i<n;i++)
        maxVal = max(maxVal,arr[i]);
    for(int exp=1;maxVal/exp > 0; exp*=10)
        CountSort(arr,n,exp);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}
int main()
{
    int arr[] = {329,212,6,8,100,50};
    Radix_Sort(arr,6);
    return 0;
}
