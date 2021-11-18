#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &a){
    int n = a.size();
    for(int i=1; i<n; i++) {
        int temp = a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
        a[++j] = temp;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter array elements : ";
    vector<int> a;
    for(int i=0; i<n; i++) {
        int c;
        cin >> c;
        a.push_back(c);
    }

    insertionSort(a);

    cout << "Sorted Elements : ";
    for(int &x: a)
        cout << x << " ";
    cout << endl;
    return 0;
}


// Time complexity: O(n^2)
// Space complexity : O(n)