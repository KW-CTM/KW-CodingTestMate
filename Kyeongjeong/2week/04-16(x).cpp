#include <iostream>
#include <map>
using namespace std;

int main() {

    int N, temp, count = 0, maxCount = 0;
    map<int, int> num;

    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        num.insert({temp, i});
    }

    for(auto it = num.begin(); it != num.end(); it++) {    
        
        if(it->second - count > maxCount)
            maxCount = it->second - count;       
        ++count;
    }
    cout << maxCount + 1;
}