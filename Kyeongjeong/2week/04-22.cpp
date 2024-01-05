#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, temp;
    vector<int> sortedNums(10001, 0);

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> temp;
        ++sortedNums[temp];
    }

    for(int i = 0; i < 10001; i++) {
        if(sortedNums[i] != 0) {
            for(int j = 0; j < sortedNums[i]; j++)
                cout << i << "\n";
        }
    }
}