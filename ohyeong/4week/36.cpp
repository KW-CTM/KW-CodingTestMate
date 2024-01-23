#include <iostream>
#include <vector>

using namespace std;

int main(){
    int result=0;
    vector<int> v;

    string str, num, sign;
    cin >> str;
    
    for(int i=0; str[i]!=0; i++){
        if(str[i] == '-' || str[i] == '+'){
            v.push_back(stoi(num));       //숫자 추가
            num.clear();
            sign.push_back(str[i]);       //부호 추가
        }
        else{
            num.push_back(str[i]);
        }
    }
    v.push_back(stoi(num));

    result += v.at(0);
    for(int i=0; sign[i]!=0; i++){
        if(sign[i] == '-'){           //부호가 -라면 +나올 때까지 뺌
            result -= v.at(i+1);
            while(sign[i+1] == '+'){
                i++;
                result -= v.at(i+1);
            }
        }
        else{
            result += v.at(i+1);
        }
    }
    cout<<result<<"\n";
}