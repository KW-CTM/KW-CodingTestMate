#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input, result = 0, temp;
    vector<int> times;
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>input;
        times.push_back(input);
    }

    //sort - 여기서는 삽입 정렬 사용해보기
    //오름차순 정렬
    for(int i=1; i<N; i++) {
        temp = times[i];
        int j;
        for(j=i; j>0; j--) {
            if(temp < times[j-1]){
                times[j] = times[j-1];
            } else {
                break;
            }
        }

        times[j] = temp;
    }

    for(int i=N; i>0; i--) {
        result += times[N-i] * i;
    }
    cout<<result<<endl;
}