#include <iostream>
#include <vector>
using namespace std;

void countSort(vector<int> &a) {
    int n = a.size();
    int max_elt = INT_MIN;

    // Find maximum element of an array
    for(int i=0; i<n; i++) {
        max_elt = max(max_elt, a[i]);
    }

    // Create another array of size max_elt+1 initialized with 0
    vector<int> count(max_elt+1, 0);

    // Count frequencies
    for(int i=0; i<n; i++)
        count[a[i]]++;

    // put elements back in array a in sorted order
    int i=0, j=0;
    while(i < max_elt+1) {
        if (count[i] > 0){
            a[j++] = i;
            count[i]--;
        } else {
            i++;
        }
    }
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
    countSort(arr);

    // Print Sorted Array
    cout << "Sorted Array : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
