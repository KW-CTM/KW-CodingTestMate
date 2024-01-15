#include <iostream>
#include <vector>
#include <string>

using namespace std;

void DFS(string str, int digit);
bool CalPrime(int num);

int main(){
    int num, array[4] = {2,3,5,7};
    cin >> num;
    
    for(int i=0; i<4; i++){
        DFS(to_string(array[i]), num);
    }
}

void DFS(string str, int digit){
    if(str.size() == digit){             //특정 자리수가 되면 끝냄
        cout << str << "\n";
        return;
    }

    for(int i=1; i<=9; i+=2){
        string sen = str;
        sen.push_back(i+ '0');

        if(CalPrime(stoi(sen))){        //만든 수가 소수라면 재귀함수 호출
            DFS(sen, digit);
        }
        else{
            continue;
        }
    }
}

bool CalPrime(int num){                 //소수 판별
    for(int i=2; i<=num/2; i++){        //하나씩 나눠가며 확인
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}