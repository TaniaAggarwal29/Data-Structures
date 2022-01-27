#include <iostream>
using namespace std;

int count=0;

void merge(int a[], int l, int mid, int h) {
    int i = l, j = mid+1, k = l;
    int b[h+1];

    while (i<=mid and j<=h) {
        if(a[i] < a[j]) {
            b[k++] = a[i++];
            count++;
        }
        else {
            b[k++] = a[j++];
            count++;
        }
    }
    for(; i<=mid; i++) {
        b[k++] = a[i];
        count++;
    }
    for(; j<=h; j++){
        b[k++] = a[j];
        count++;
    }

    for(i=l; i<=h; i++)
        a[i] = b[i];
}

void iterMergeSort(int a[], int n) {
    int p;
    for(p=2; p<=n; p*=2) {
        for(int i=0; i+p-1<n; i+=p) {
            int l=i, h=i+p-1, mid=(l+h)/2;
            merge(a, l, mid, h);
        }
    }
    if (p/2 < n){
        merge(a, 0, p/2-1, n-1);
    }
}

void recursiveMergeSort(int a[], int l, int h) {
    if (l<h) {
        int mid = (l+h)/2;
        recursiveMergeSort(a, l, mid);
        recursiveMergeSort(a, mid+1, h);
        merge(a, l, mid, h);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    int a[n];
    cout << "Enter elements : \n";
    for(int i=0; i<n; i++)
        cin >> a[i];

//    iterMergeSort(a, n);
    recursiveMergeSort(a, 0, n-1);
    cout << "Sorted Array : ";
    for (int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl << "count: " << count;

    return 0;
}
