#include <iostream>

using namespace std;
int gcd(int a, int b);

int main(){
    int cnt;
    cin >> cnt;

    for(int i=0; i<cnt; i++){
        int a,b;
        cin >> a >> b;
        cout << a*b/gcd(a, b) <<endl;  //최소공배수는 두 수의 곱에 최대공약수 나눔
    }
}

int gcd(int a, int b){           //최대공약수 구하기
    while(1){
        int result = a%b;
        if(result != 0){
            a = b;
            b = result;
        }
        else{
            break;
        }
    }
    return b;
}