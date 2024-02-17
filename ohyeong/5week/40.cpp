#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    long min, max;
    cin >> min >> max;
    vector <int> array(max-min+1, 1);

    for(long i=2; i<=sqrt(max); i++){
        long square = i*i;
        //시간 초과가 안뜨려면 제곱수 처음부터가 아니라 최소 범위부터 제해야 함
        long start = min / square;    //처음 시작을 최소 범위에서 시작함

        if(min%square != 0){          //나누어 떨어지지 않는다면 제곱수를 더함
            start++;
        }

        for(long j=start; j*square<=max; j++){    //곱셈이라 j는 하나씩 늘어남
            array[(j*square)-min]=0;              //시작에서 최소 범위를 뺀 배열을 0으로 설정
        }
    }

    cout << count(array.begin(), array.end(), 1) <<endl;  //vector에서 1만 찾는 함수
}