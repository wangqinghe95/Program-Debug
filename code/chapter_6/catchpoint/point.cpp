#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr = {10,4,6,9,7};
    int n = arr.size();
    for(int i = 1; i < n; i++){
        long temp = arr[i];
        int j = i;
        for(; j > 0 && arr[j - 1] > temp; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }
    for (auto& tmp : arr) {
        cout << tmp << " ";
    }
    return 0;
}