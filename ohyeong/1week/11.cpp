#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int cnt, current = 1, num = 1;
    cin >> cnt;
    vector <int> array(cnt+1, 0);
    vector <char> result;
    for(int i=1; i<=cnt; i++){
        cin >> array[i];
    }

    stack <int> s;

    while(current != cnt+1){
        if(num > cnt+1){
            cout<<"NO\n";
            return 0;
        }

        if(s.empty()){
            s.push(num);
            num++;
            result.push_back('+');
        }
        else{
            if(array[current] == s.top()){
                s.pop();
                current++;
                result.push_back('-');
            }
            else{
                s.push(num);
                num++;
                result.push_back('+');
            }
        }
    }

    for(int i=0; result[i] != 0; i++){
        cout<<result[i]<<"\n";
    }

}