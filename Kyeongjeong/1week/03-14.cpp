#include <iostream>
#include <queue>
using namespace std;

struct cmp {
    
    bool operator()(int num1, int num2) {
        int abs_num1 = abs(num1);
        int abs_num2 = abs(num2);

        if(abs_num1 == abs_num2)
            return (num1 > num2);
        
        else
            return (abs_num1 > abs_num2);
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, cmp> pq;
    int size, temp;

    cin >> size;
    for(int i = 0; i < size; i++) {
        cin >> temp;

        if(temp == 0) {

            if(pq.empty())
                cout << 0 << "\n";     
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else
            pq.push(temp);
    }
}