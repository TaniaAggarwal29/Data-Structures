#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &a) {
    unsigned int n = a.size();

    for(int i=0; i<n-1; i++) {
        int j=i, k=i;
        while(j<n){
            if(a[j]<a[k]) k = j;
            j++;
        }
        swap(a[i], a[k]);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Enter elements : ";
    vector<int> a;
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        a.push_back(c);
    }

    selectionSort(a);

    cout << "Sorted Elements : ";
    for(int &x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}


// Time complexity: O(n^2)
// Space complexity: O(1)