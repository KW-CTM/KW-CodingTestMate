#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums, vector<int>& sortedNums, int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;

    while (i <= mid && j <= end) {
        if (nums[i] <= nums[j])
            sortedNums[k++] = nums[i++];
        else
            sortedNums[k++] = nums[j++];
    }

    while (i <= mid)
        sortedNums[k++] = nums[i++];
    while (j <= end)
        sortedNums[k++] = nums[j++];

    for (int i = start; i <= end; i++)
        nums[i] = sortedNums[i];
}

void merge_sort(vector<int>& nums, vector<int>& sortedNums, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(nums, sortedNums, start, mid);
        merge_sort(nums, sortedNums, mid + 1, end);
        merge(nums, sortedNums, start, mid, end);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, temp;
    vector<int> nums, sortedNums;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> temp;
        nums.push_back(temp);
        sortedNums.push_back(0);
    }

    merge_sort(nums, sortedNums, 0, size-1);

    for(int i = 0; i < size; i++)
        cout << sortedNums[i] << "\n";
}