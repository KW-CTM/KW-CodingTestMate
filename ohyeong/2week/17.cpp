#include <iostream>

using namespace std;

int main(){
    int array[11], cnt=0;
    string str;
    cin >> str;
    for(int i=0; str[i]!=0; i++){
        array[i] = str[i] - '0';
        cnt++;
    }

    for(int i=0; i<cnt; i++){
        int max=-1, num;
        for(int j=i; j<cnt; j++){
            if(array[j] > array[max]){
                max = j;
            }
        }
        num = array[i];
        array[i] = array[max];
        array[max] = num;
    }

    for(int i=0; i<cnt; i++){
        cout<<array[i];
    }
}