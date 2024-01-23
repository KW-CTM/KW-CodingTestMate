#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b);

int main(){
    int cnt, result=0;
    cin >> cnt;

    vector <pair<int, int>> v(cnt);
    for(int i=0; i<cnt; i++){
        int n1, n2;
        cin >> n1 >> n2;
        v[i] = make_pair(n1, n2);
    }
    sort(v.begin(), v.end(), compare);

    int end=0;
    for(int i=0; i<cnt; i++){
        if(v[i].first >= end){
            end = v[i].second;
            result++;
        }
    }
    
    cout << result <<"\n";

}

//second 기준으로 오름차순 정렬
bool compare(const pair<int, int> &a, const pair<int, int> &b){      
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}