#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Bucket_Sort(int arr[],int n,int k)
{
    int maxVal=arr[0];
    for(int i=1;i<n;i++)
        maxVal = max(maxVal,arr[i]);
    maxVal++;
    vector<int> bkt[k];
    for(int i=0;i<n;i++)
    {
        int bk_ind = k*arr[i]/maxVal;
        bkt[bk_ind].push_back(arr[i]);
    }
    for(int i=0;i<k;i++)
        sort(bkt[i].begin(),bkt[i].end());
    int index=0;
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<bkt[i].size();j++)
            arr[index++]=bkt[i][j];
    }
}
int main()
{
    int arr[]={20,80,40,30,70};
    Bucket_Sort(arr,5,4);
    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
    return 0;
}
