#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int partition(vector<int> &nums, int low, int high) {
    int pivot = nums[high];
    int left = low;
    int right = high - 1;
    while (true) {
        while (left <= right && nums[left] < pivot) ++left;
        while (right >= left && nums[right] > pivot) --right;
        if (left >= right) break;
        swap(nums[left], nums[right]);
        ++left;
        --right;
    }
    swap(nums[left], nums[high]);
    return left;
}

void quickSort(vector<int> &nums, int low, int high){
    if (low < high) {
        int idx = partition(nums, low, high);
        quickSort(nums, low, idx - 1);
        quickSort(nums, idx + 1, high);
    }
}

int main() {
    int n; 
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    quickSort(nums, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
