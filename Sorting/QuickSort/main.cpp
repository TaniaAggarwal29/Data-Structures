#include <iostream>
using namespace std;
int count = 0;

int Partition(int a[], int l, int h) {
    int pivot = a[h];
    int i=l, j=h;

    while (i < j) {
        while (i<=h && a[i]<=pivot) {
            i++;
            count++;
        }
        while (j>=l && a[j]>pivot) {
            j--;
            count++;
        }

        if (i < j)
            swap(a[i], a[j]);
    }
    swap(a[j], a[l]);

    for(int i=l; i<=h; i++){
        cout << a[i] << " ";
    }
    cout << endl;
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

    cout << "\ncount ; " << count << endl;

    return 0;
}
