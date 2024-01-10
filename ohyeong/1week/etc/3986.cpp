#include <iostream>
#include <stack>

using namespace std;

int main(){
    int cnt, result = 0;
    cin >> cnt;
    
    for(int i=0; i<cnt; i++){
        int num=0;
        stack <char> s;
        string str;
        cin >> str;

        while(num != str.size()){
            if(s.empty() || s.top() != str[num]){
                s.push(str[num++]);
            }
            else{
                s.pop();
                num++;
            }
        }

        if(s.empty()) result++;
    }

    cout<<result<<"\n";
}