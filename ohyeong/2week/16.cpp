#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int cnt, num, result=0;
    cin >> cnt;

    //pair 형태로 저장해서 정렬 전 index 바로 찾을 수 있게 함.
    vector <pair<int, int>> array(cnt);    

    for(int i=0; i<cnt; i++){
        cin >> num;
        array[i] = make_pair(num, i);
    }

    sort(array.begin(), array.end());

    //데이터의 정렬 전 index와 정렬 후 index를 비교해 왼쪽으로 가장 많이 이동한 값을 찾음.
    for(int i=0; i<cnt; i++){
        if(array[i].second - i > result){
            result = array[i].second - i;
        }
    }

    cout << result+1 <<endl;
}