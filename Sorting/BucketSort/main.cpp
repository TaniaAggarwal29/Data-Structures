#include <iostream>
#include <list>
#include <vector>
using namespace std;

void bucketSort(vector<int> &a) {
    int n = a.size();

    // Find maximum element
    int max_elt = -1;
    for(int i=0; i<n; i++)
        max_elt = max(max_elt, a[i]);

    // create an array of pointers initialized to null
    vector< list<int> > buckets(max_elt+1);

    // add elements to array
    for(int i=0; i<n; i++) {
        buckets[a[i]].push_back(a[i]);
    }

    // traverse buckets array
    int i=0, j=0;
    while(i < max_elt+1) {
        while(!buckets[i].empty()) {
            a[j++] = i;
            buckets[i].pop_back();
        }
        i++;
    }

}

int main() {

    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    // Input array
    cout << "Enter the elements : \n";
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];

    // Sort
    bucketSort(arr);

    // Print sorted array
    cout << "Sorted Array : ";
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
