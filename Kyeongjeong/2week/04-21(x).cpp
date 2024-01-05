#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, temp, count = 0, total = 0;
    map<int, int> nums;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> temp;
        nums.insert({temp, i});
    }

    for(auto it = nums.begin(); it != nums.end(); it++) {

        total += abs(it->second - count);
        if(it->second - count != 0)
            total -= 1;
        count++;
    }

    cout << total;
}