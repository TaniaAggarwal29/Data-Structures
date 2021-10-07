#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &a, int n) {
    for(int i=0; i<n-1; i++) {
        int flag = 0;
        for(int j=0; j<n-i-1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                flag = 1;
            }
        }
        if(flag == 0) return;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements : ";
    cin >> n;

    vector<int> a;
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        a.push_back(c);
    }

    bubbleSort(a, n);

    cout << "Sorted array: ";
    for(int &x : a)
        cout << x << " ";
    cout << endl;

    return 0;
}
