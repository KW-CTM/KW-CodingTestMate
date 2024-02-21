#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {

    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

void DFS(int num, int cnt, int digit) {

    if(cnt == digit) {
        if(isPrime(num))
            cout << num << "\n";
        return;
    }

    for(int i = 1; i < 10; i++) {
        if(i % 2 == 0)
            continue;
        
        if(isPrime(num * 10 + i))
            DFS(num * 10 + i, cnt + 1, digit);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int digit;
    cin >> digit;
    
    DFS(2, 1, digit);
    DFS(3, 1, digit);
    DFS(5, 1, digit);
    DFS(7, 1, digit);
}