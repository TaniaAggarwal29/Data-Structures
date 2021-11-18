#include <iostream>
using namespace std;
int main()
{
    int n, j=0,k=0 ,i;
    cout<<"Enter number of array elements : ";
    cin>>n;
    int arr[n],neg[n],pos[n];
    cout<<"Enter array elements : \n ";
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            neg[j]=arr[i];
            j++;
        }
        else if(arr[i]>0)
        {
            pos[k]=arr[i];
            k++;
        }
    }
    int neg_size=j;
    int pos_size=k;

    i=0,j=0,k=0;
    while(i<pos_size && j<neg_size)
    {
    	arr[k]=neg[j];
        k++;
        j++;
        arr[k]=pos[i];
        k++;
        i++;
	}
    while(i<pos_size)
    {
        arr[k]=pos[i];
        i++;
        k++;
    }
    while(j<neg_size)
    {
        arr[k]=neg[j];
        j++;
        k++;
    }

    cout<<"Array elements are : \n";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<"\n";


    return 0;
}
