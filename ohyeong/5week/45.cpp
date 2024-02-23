#include <iostream>
#include <vector>

using namespace std;

long gcd(long a, long b);
void Execute(long a, long b, long& x, long& y);

int main(){
    long a,b,c;
    cin >> a >> b >> c;

    long x, y;
    long value = gcd(a,b);     //최대공약수 찾기
    if(c % value != 0){        //a,b 최대공약수의 배수 형태가 아니라면 -1 출력후 프로그램 종료
        cout << -1 <<endl;
        return 0;
    }
    Execute(a, b, x, y);       //재귀함수 실행
    int k = (int)(c / value);  //ax + by = gcd로 계산했던 걸 다시 원래 식으로 바꾸기 위한 과정
    cout << k*x << " " << k*y << endl;
    
}

long gcd(long a, long b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

void Execute(long a, long b, long& x, long& y){
    if(b == 0){        //최대공약수 구하면 다시 보냄
        x = 1;
        y = 0;
        return;
    }
    long x1, y1;
    Execute(b, a%b, x1, y1);    //최대공약수 구하는 과정
    x = y1;                     //반환된 예전 y1를 x에 업데이트
    y =  x1 - (a/b)*y1;         //반환된 예전 x1와 y1 이용하여 업데이트
}