#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct cmp{
    bool operator()(int n1, int n2){
        if(abs(n1) > abs(n2)){
            return true;
        }
        else if(abs(n1) == abs(n2)){
            if(n1 > n2){
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};

int main(){
    int cnt, num;
    cin >> cnt;

    priority_queue <int, vector<int>, cmp> pq;
    for(int i=0; i<cnt; i++){
        cin >> num;
        if(num == 0){
            if(!pq.empty()){
                cout << pq.top() <<"\n";
                pq.pop();
            }
            else{
                cout << 0 <<"\n";
            }
        }

        else{
            pq.push(num);
        }
    }
}