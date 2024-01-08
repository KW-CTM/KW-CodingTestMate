#include <iostream>

using namespace std;

int main(){
    int cnt, array[1000];
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        cin >> array[i];
    }

    for(int i=0; i<cnt; i++){
        for(int j=i+1; j<cnt; j++){
            if(array[i] > array[j]){
                int num = array[i];
                array[i] = array[j];
                array[j] = num;
            }
        }
    }

    for(int i=0; i<cnt; i++){
        cout << array[i]<<"\n";
    }
}