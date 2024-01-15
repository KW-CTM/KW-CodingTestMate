#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> array;
    array.resize(n);

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            array[i].push_back(str[j]-'0');      //값 저장
        }
    }

    queue <pair<int, int>> q;
    q.push(make_pair(0,0));

    while(q.front() != make_pair(n-1, m-1)){       //끝에 도달하면 멈춤
        pair <int, int> a = q.front();
        int first = a.first, second = a.second;

        //현재 위치의 상하좌우 값 확인
        if(first-1 >= 0 && array[first-1][second] == 1){
            q.push(make_pair(first-1, second));
            array[first-1][second] = array[first][second]+1;    //이전 거리에서 1 더함
        } 
        if(second-1 >= 0 && array[first][second-1] == 1){
            q.push(make_pair(first, second-1));
            array[first][second-1] = array[first][second]+1;
        }
        if(first+1 < n && array[first+1][second] == 1){
            q.push(make_pair(first+1, second));
            array[first+1][second] = array[first][second]+1;
        }
        if(second+1 < m && array[first][second+1] == 1){
            q.push(make_pair(first, second+1));
            array[first][second+1] = array[first][second]+1;
        }
        q.pop();
    }

    cout << array[n-1][m-1] <<"\n";               //끝부분의 총 거리 출력
}