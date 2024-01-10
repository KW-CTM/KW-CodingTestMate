#include <iostream>

using namespace std;

int main(){
    int size, cnt, sum=0;
    int array[10001];
    cin>>size>>cnt;

    for(int i=1; i<=size; i++){
        cin>>array[i];
    }

    for(int i=size; i>1 && sum<cnt; i--){
        int max = i, num;
        for(int j=i-1; j>0; j--){
            if(array[j] > array[max]){
                max = j;
            }
        }
        if(i != max){
            num = array[i];
            array[i] = array[max];
            array[max] = num;
            sum++;
        }
    }

    if(sum < cnt){
        cout<<-1<<"\n";
    }
    else{
        for(int i=1; i<=size; i++){
            cout<<array[i]<<" ";
        }
    }
}