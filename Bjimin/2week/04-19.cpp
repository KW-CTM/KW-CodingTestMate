#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, input, result = 0, K;
    cin>>N>>K;
	vector<int> numbers;

	for(int i=0; i<N; i++) {
		cin>>input;
		numbers.push_back(input);
	}


	//quick sort를 이용해서 정렬하기
	// quickSort(numbers, );
	sort(numbers.begin(), numbers.end());
	cout<<numbers[K-1]<<endl;
}

void quickSort(vector<int> &numbers, int start, int end, int pivot) {

}