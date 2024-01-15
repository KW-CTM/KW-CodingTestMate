#include <iostream>
#include <vector>

using namespace std;

int main(){
    int L, B, end=0, start=0, mid;
    cin >> L >> B;
    vector <int> array(L);
    for(int i=0; i<L; i++){
        cin >> array[i];
        if(array[i] > start) start = array[i];      //길이가 큰 순서대로 입력이 되지 않으므로 따로 저장해야 함
        end += array[i];
    }
    
    while(start <= end){
        mid = (start+end)/2;
        int cnt=0, cal=0;
        for(int i=0; i<L; i++){
            if(cal + array[i] > mid){
                cnt += 1;
                cal = 0;
            }
            cal += array[i];
        }

        if(cal > 0){
            cnt += 1;
        }

        if(cnt > B){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    cout << start <<"\n";
}