#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int n, num, result=0, find=false;
    cin >> n;
    priority_queue <int, vector<int>, greater<int>> negative;      //오름차순으로 정렬
    priority_queue<int> positive;                                  //내림차순으로 정렬
    vector<int> data;
    for(int i=0; i<n; i++){
        cin >> num;
        if(num == 0 || num == 1){
            data.push_back(num);
            if(num == 0) find=true;        //0일 경우 find는 true로 변경
        }
        else if(num < 0){
            negative.push(num);
        }
        else{
            positive.push(num);
        }
    }

    while(negative.size()>=2){          //큐가 2개 이상 있을 때까지 반복
        int n1 = negative.top();
        negative.pop();
        int n2 = negative.top();
        negative.pop();
        data.push_back(n1*n2);
    }
    if(negative.size() && !find){       //남은 원소가 존재하고 0이 존재하지 않는다면 추가함
        data.push_back(negative.top());
    }

    while(positive.size()>=2){          //큐가 2개 이상 있을 때까지 반복
        int n1 = positive.top();
        positive.pop();
        int n2 = positive.top();
        positive.pop();
        data.push_back(n1*n2);
    }
    if(positive.size()){               //남은 원소가 존재하면 추가함
        data.push_back(positive.top());
    }

    for(int i=0; i<data.size(); i++){
        result += data.at(i);
    }
    cout << result <<"\n";
}