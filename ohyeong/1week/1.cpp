#include <iostream>

using namespace std;

int main(){
    int cnt, result = 0;
    cin >> cnt;
    char* array = new char[cnt];
    cin >> array;
    for(int i=0; i<cnt; i++){
        result += array[i]-48;
    }
    cout << result;
    delete array;
}