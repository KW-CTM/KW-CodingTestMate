#include <iostream>
#include <vector>

using namespace std;

int main(){
    int m,n;
    cin >> n >> m;
    vector <int> array(m+1, 1);

    array[1] = 0;
    for(int i=2; i<=m; i++){
        if(array[i] == 1){
            for(int j=i+i; j<=m; j+=i){      //나누기로 확인하지 않고 더하기를 통해 배수 삭제
                array[j] = 0;
            }
        }
    }

    for(int i=n; i<=m; i++){        //출력
        if(array[i]){
            cout<<i<<"\n";
        }
    }
}