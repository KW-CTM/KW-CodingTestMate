#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size, temp;
    vector<int> num;
    stack<int> index;

    cin >> size;
    vector<int> nge(size, -1);

    for(int i = 0; i < size; i++) {
        cin >> temp;
        num.push_back(temp);
    }

    index.push(0);
    for(int i = 0; i < size; i++) {

        while((!index.empty()) && (num[index.top()] < num[i])) {
            nge[index.top()] = num[i];
            index.pop();
        }
        index.push(i);
    }

    for(int i = 0; i < size; i++)
        cout << nge[i] << " ";
}