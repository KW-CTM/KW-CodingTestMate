#include <iostream>
#include <vector>
using namespace std;

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
    }
    
    int left = 0;
    int right = size/2;
    while(left < right) {

        if(nums[left] < nums[right]) 
            sortedNums.push_back(nums[left++]);
            
        else 
            sortedNums.push_back(nums[right++]);
    }

    for(int i = 0; i < size; i++)
        cout << sortedNums[i] << "\n";
}