#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCount, windowSize, temp;
    map<int, int> numArr;
    
    cin >> numCount >> windowSize;
    for (int i = 0; i < numCount; i++) {

        cin >> temp;
        numArr.insert({temp, i});

        auto it = numArr.begin();
        while (it != numArr.end() && it->second <= i - windowSize) {
            it = numArr.erase(it);
        }

        cout << numArr.begin()->first << " ";
    }
}