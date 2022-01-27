#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &a, int exp) {
    int n = a.size();

    // Create another array of size 10 initialized with 0
    vector<int> count(10, 0), output(n);

    // Count frequencies
    for(int i=0; i<n; i++)
        count[(a[i]/exp)%10]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

void radixSort(vector<int> &arr) {
    int n = arr.size();
    int max_elt = INT_MIN;

    // Find maximum element of an array
    for(int i=0; i<n; i++) {
        max_elt = max(max_elt, arr[i]);
    }

    for (int exp = 1; max_elt / exp > 0; exp *= 10)
        countSort(arr, exp);
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    // Input Array
    cout << "Enter elements : ";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // Sort Array
//    countSort(arr);
    radixSort(arr);

    // Print Sorted Array
    cout << "Sorted Array : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
