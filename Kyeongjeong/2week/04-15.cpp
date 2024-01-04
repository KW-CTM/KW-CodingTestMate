#include <iostream>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, temp;
    int num[1000];

    cin >> size;
    for(int i = 0; i < size; i++) 
        cin >> num[i];
    
    for(int i = 0; i < size - 1; i++) {
        for(int j = i; j < size; j++) {
            if(num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    for(int i = 0; i < size; i++) 
        cout << num[i] << "\n";
}