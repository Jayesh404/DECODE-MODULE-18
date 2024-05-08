#include <iostream>
#include <vector>

using namespace std;

int mergeAndCount(vector<int>& nums, vector<int>& temp, int left, int mid, int right) {
    int count = 0;
    int j = mid + 1;

    // Count reverse pairs
    for (int i = left; i <= mid; i++) {
        while (j <= right && nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    // Merge step
    int i = left;
    j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= right) {
        temp[k++] = nums[j++];
    }

    // Copy the sorted elements back into the original array
    for (i = left; i <= right; i++) {
        nums[i] = temp[i];
    }

    return count;
}

int mergeSortAndCount(vector<int>& nums, vector<int>& temp, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += mergeSortAndCount(nums, temp, left, mid);
        count += mergeSortAndCount(nums, temp, mid + 1, right);
        count += mergeAndCount(nums, temp, left, mid, right);
    }
    return count;
}

int reversePairs(vector<int>& nums) {
    int n = nums.size();
    vector<int> temp(n);
    return mergeSortAndCount(nums, temp, 0, n - 1);
}

int main() {
    vector<int> nums = {1, 3, 2, 3, 1};
    cout << "Number of reverse pairs: " << reversePairs(nums) << endl;
    return 0;
}
