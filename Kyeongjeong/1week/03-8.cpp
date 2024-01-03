#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int numCount, temp, resultCount = 0;
    long key;
    int i, j, k;
    vector<int> numArr;

    cin >> numCount;
    for(i = 0; i < numCount; i++) {

        cin >> temp;
        numArr.push_back(temp);
    }  
    sort(numArr.begin(), numArr.end());

    for(k = 0; k < numCount; k++) {

        key = numArr[k];
        i = 0;
        j = numCount - 1;

        while(i < j) {

            if(numArr[i] + numArr[j] < key) 
                i++;

            else if(numArr[i] + numArr[j] > key) 
                j--;

            else {

                if((i != k) && (j != k)) {
                    resultCount++;
                    break;
                }

                else if(i == k)
                    i++;
                
                else if(j == k)
                    j--;
            }
        }
    }
    cout << resultCount << "\n";
}