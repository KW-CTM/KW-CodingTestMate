#include <iostream>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, temp, i, j, total;
    vector<int> num, sum;

    cin >> size;
    for(i = 0; i < size; i++) {
        cin >> temp;
        num.push_back(temp);
    }

    for(i = 1; i < size; i++) {
        temp = num[i];
        for(j = i-1; j >= 0; j--) {
            if(temp < num[j]) 
                num[j+1] = num[j];
            
            else
                break;
        }
        num[j+1] = temp;
    }

    sum.push_back(num[0]);
    total = sum[0];

    for(i = 1; i < size; i++) {
        sum.push_back(sum[i-1] + num[i]);
        total += sum[i];
    }
    
    cout << total;
}