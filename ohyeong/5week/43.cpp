#include <iostream>

using namespace std;

int main(){
    long a,b;
    cin >> a >> b;
    
    //입력된 수의 최대공약수를 찾아 1를 그 수만큼 출력함
    while(1){
        long result = a%b;      
        if(result != 0){
            a = b;
            b = result;
        }
        else{
            break;
        }
    }
    
    for(int i=0; i<b; i++){
        cout << 1;
    }
}