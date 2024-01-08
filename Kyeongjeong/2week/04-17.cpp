#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {

    string nums;
    vector<int> num;
    int maxIndex;

    cin >> nums;
    for(int i = 0; i < nums.size(); i++)
        num.push_back(stoi(nums.substr(i, 1)));
    
    for(int i = 0; i < num.size() - 1; i++) {
        maxIndex = max_element(num.begin() + i, num.end()) - num.begin();
        swap(num[maxIndex], num[i]);
    }

    for(int i = 0; i < num.size(); i++)
        cout << num[i];
}