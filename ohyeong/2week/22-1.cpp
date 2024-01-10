#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, data, array[10001] = {0,};
    cin >> num;

    for(int i=0; i<num; i++){
        cin >> data;
        array[data]++;
    }

    for(int i=0; i<10001; i++){
        if(array[i] != 0){
            while(array[i] != 0){
                cout << i <<"\n";
                array[i]--;
            }
        }
    }
}