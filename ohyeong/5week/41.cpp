#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long n;
    cin >> n;
    long result = n;

    for(long i=2; i<=sqrt(n); i++){
        if(n%i == 0){            //오일러 피 함수 사용
            result = result-result/i;
        }
        while(n%i == 0){
            n = n/i;
        }
    }

    if(n > 1){          //남은 값은 나머지 소인수
        result = result-result/n;
    }

    cout << result <<endl;
}
//구해야 하는 값이 하나이기 때문에 소인수를 구해 소인수만 오일러 피 함수를 적용하면 됨