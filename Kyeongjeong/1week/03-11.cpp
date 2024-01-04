#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, temp, count = 1;
    stack<int> num;
    vector<int> arr;
    vector<char> result;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    for(int i = 0; i < size;) {

        if(num.empty() || (num.top() < arr[i])) {
            result.push_back('+');
            num.push(count);
            count++;
        }
        else if(num.top() == arr[i]) {
            result.push_back('-');
            i++;
            num.pop();
        }
        else {
            cout << "NO";
            return 0;
        }
    }

    for(int i = 0; i < result.size(); i++) 
        cout << result[i] << "\n";
}