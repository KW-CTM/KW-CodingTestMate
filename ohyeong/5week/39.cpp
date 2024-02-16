#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    long n;
    cin >> n;
    //총 범위가 1,000,000이 아니라 입력하는 수의 범위임.
    //그래서 1,000,000가 입력됐을 때 수가 출력이 되어야함.
    vector <int> array(10000001, 1);

    array[1]=0;
    for(int i=2; i<=sqrt(10000001); i++){
        if(array[i]){
            for(int j=i+i; j<=10000001; j+=i){
                array[j]=0;
            }
        }
    }

    for(int i=n; i<=10000001; i++){
        if(array[i]){
            string num = to_string(i);
            int size = num.size();
            int a=1;

            for(int j=0; j<size/2; j++){
                if(num[j] != num[size-j-1]){
                    a=0;
                    break;
                }
            }

            if(a == 1){
                cout << i<<endl;
                break;
            }
        }
    }
}