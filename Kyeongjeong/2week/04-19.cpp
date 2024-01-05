#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quickSort(vector<int>& nums, int start, int end) {
    
    if (start < end) {

        int pivot = nums[(start + end) / 2];
        int left = start;
        int right = end;

        while (left <= right) {
            while (nums[left] < pivot)
                left++;

            while (nums[right] > pivot)
                right--;

            if (left <= right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        quickSort(nums, start, right);
        quickSort(nums, left, end);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, printNum, temp;
    vector<int> nums;

    cin >> size >> printNum;
    for(int i = 0; i < size; i++) {
        cin >> temp;
        nums.push_back(temp);
    }

    quickSort(nums, 0, size-1);
    cout << nums[printNum-1];
}