#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int cnt, num=1;
    cin >> cnt;

    vector <int> array(cnt+1);
    vector <int> result(cnt+1, -1);
    for(int i=1; i<=cnt; i++){
        cin >> array[i];
    }

    stack <int> s;
    s.push(num++);
    while(num != cnt+1){
        if(array[s.top()] < array[num]){
            result[s.top()] = array[num];
            s.pop();
            if(s.empty()) {s.push(num++);}
        }
        else{
            s.push(num++);
        }     
    }

    for(int i=1; i<=cnt; i++){
        cout << result[i]<<" ";
    }
    cout<<"\n";

}