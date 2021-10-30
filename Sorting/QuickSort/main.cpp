#include <iostream>
using namespace std;

int Partition(int a[], int l, int h) {
    int pivot = a[l];
    int i=l, j=h;

    while (i < j) {
        while (i<=h && a[i]<=pivot)
            i++;
        while (j>=l && a[j]>pivot)
            j--;

        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[j], a[l]);
    return j;
}

void quickSort(int a[], int start, int end) {
    if (start < end) {
        int p = Partition(a, start, end);
        quickSort(a, start, p-1);
        quickSort(a, p+1, end);
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

    quickSort(a, 0, n-1);
    cout << "\nSorted Array : ";
    for(int i=0; i<n; i++)
        cout << a[i] << " ";

    cout << endl;

    return 0;
}
