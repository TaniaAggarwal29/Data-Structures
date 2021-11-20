#include <iostream>
#include <vector>
using namespace std;

void shellSort(vector<int> &a) {
    int n = a.size();

    // take gap = n/2 and keep dividing by 2 for every pass
    for(int gap=n/2; gap>=1; gap /= 2) {

        // Perform Insertion sort for sublist of every gap-th element
        for(int i=gap; i<n; i++) {
            int temp = a[i];
            int j = i-gap;
            while(j>=0 and a[j]>temp) {
                a[j+gap] = a[j];
                j -= gap;
            }
            a[j+gap] = temp;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    // Input Array
    cout << "Enter elements :\n";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // Sort
    shellSort(arr);

    // Print Sorted Array
    cout << "Sorted Array : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}