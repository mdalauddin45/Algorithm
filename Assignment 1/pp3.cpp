#include<bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int target, int searchFirst) {
    int left = 0, right = arr.size() - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            if (searchFirst == 1)
                right = mid - 1;  // Search in the left half
            else
                left = mid + 1;   // Search in the right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    int first = binarySearch(arr, k, 1);
    int last = binarySearch(arr, k, 0);

    if (first != -1 && last != -1 && first != last) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
