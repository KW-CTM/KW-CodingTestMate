#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int dataCount, sumCount, temp, start, end;
    vector<int> sumArr;

    sumArr.push_back(0);
    cin >> dataCount >> sumCount;

    for(int i = 0; i < dataCount; i++) {
        cin >> temp;
        sumArr.push_back(sumArr[i] + temp);
    }

    for(int i = 0; i < sumCount; i++) {
        
        cin >> start >> end;
        cout << sumArr[end] - sumArr[start-1] << "\n";
    }
}