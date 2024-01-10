#include <iostream>
#include <queue>

using namespace std;

int main(){
    int num, cnt=1;
    cin >> num;

    queue <int> q;
    for(int i=1; i<=num; i++){
        q.push(i);
    }

    while(q.size() != 1){
        if(cnt%2==0){
            q.push(q.front());
        }
        q.pop();
        cnt++;
    }

    cout<<q.front()<<"\n";
}