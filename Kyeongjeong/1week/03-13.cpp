#include <iostream>
#include <queue>
using namespace std;

int main() {

    int N, flag = 0;
    cin >> N;
    queue<int> num;

    for(int i = 1; i <= N; i++)
        num.push(i);
    
    while(num.size() > 1) {
        
        if(flag == 0)
            flag = 1;      
        else {
            num.push(num.front());
            flag = 0;
        }
        num.pop(); 
    }
    cout << num.front();
}