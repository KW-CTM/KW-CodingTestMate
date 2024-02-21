#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, totalSum, temp, count = 0;
    cin >> N >> totalSum;

    vector<int> numArr;
    for(int i = 0; i < N; i++) {
        cin >> temp;
        numArr.push_back(temp);
    }

    for(int i = N-1; i >= 0; i--) {
        if(numArr[i] <= totalSum) {
            count += (totalSum/numArr[i]);
            numArr[i] = totalSum % numArr[i];
        }
    }  
    cout << count << "\n"; 
}