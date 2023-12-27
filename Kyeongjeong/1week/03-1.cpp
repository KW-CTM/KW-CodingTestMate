#include <iostream>
using namespace std;

int main() {

    int count, num, sum;
    string numbers;

    cin >> count;
    cin >> numbers;
    sum = 0;

    for(int i = 0; i < count; i++) 
        sum += numbers[i]-48;
    
    cout << sum;
}