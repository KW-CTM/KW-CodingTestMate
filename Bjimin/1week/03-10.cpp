#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> node;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int number_length, window_length, i, j, min = INT32_MAX;
    int input;
    vector<int> numbers;
    deque<node> dec;

    cin>>number_length>>window_length;
    for(i=0; i<number_length; i++) {
        cin>>input;
        numbers.push_back(input);
    }

    i=0;j=0;
    i=j-window_length+1;
    while(true) { //for문으로 구현해도 될 것 같은데
        if(j >= number_length) break;

        if(i>0){
            if(dec.size() != 0 && dec.front().first == (i-1)) {
                dec.pop_front();
            }
            // 현재 i값보다 작은 인덱스 deque에서 빼기
            // min을 그 다음걸로 설정하기
        }

        if(dec.size() != 0 && dec.back().second > numbers[j]) {
            while(dec.size() != 0 && dec.back().second > numbers[j]) {
                dec.pop_back();
            }
            //앞에 것들이 본인보다 크면 다 지워버리기
        }
        dec.push_back(node(j, numbers[j]));
        // deque에 직전 값과 비교(직전 값 없으면 그냥 넣기)
        // 하여 더 큰 값이면 추가하고, 아니라면 앞거 버리고 이걸 넣기
        // min값이랑 새로 추가한거랑 비교해서 더 작은걸로 바꾸기

        cout<<dec.front().second<<" ";

        i++;
        j++;
    }
    cout<<endl;

}