#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long m, n;           //입력을 long으로 받아야 함
    int cnt=0;
    cin >> m >> n;
    vector <int> array(10000001, 1);   //범위는 10^7까지

    for(int i=2; i<=sqrt(10000001); i++){  //제곱근까지 반복함
        if(array[i] == 1){
            for(int j=i+i; j < 10000001; j+=i){
                array[j] = 0;
            }
        }
    }

    for(int i=2; i< 10000001; i++){
        if(array[i]){
            long a = i;
            while((double) i <= (double)n/(double)a){    //범위 넘어갈수도 있으니깐 이렇게 계산함
                if((double)i >= (double)m/(double)a) cnt+=1;
                a *= i;
            }
        }
    }

    cout << cnt<<endl;
}