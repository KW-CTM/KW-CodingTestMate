#include <iostream>
#include <vector>
using namespace std;

int combination(int n, int r);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> remains;
	remains.push_back(0);

	int N, M, i, j, temp, count=0;
	cin>>N>>M;

	int *arr = new int[M];
	for(i=0; i<M; i++){
		arr[i] = 0; //initialize
	}

	for(i=1; i<=N; i++){
		cin>>temp;
		remains.push_back((temp + remains[i-1])%M);
		if(remains[i] == 0) { count++; }
		arr[remains[i]]++;
	}

	for(i=0; i<M; i++){
		//나머지값들 등장한 횟수
		//조합 계산
		count += combination(arr[i], 2);
	}

	cout<<count<<endl;
	delete[] arr;
}

int combination(int n, int r) {
	if (n <= 0 || r <= 0) {
		if(r == 0) return 1;
		else return 0;
	} 
	
	if(n == r) {
		return 1;
	} else if (n < r) {
		return 0;
	}

	return combination(n-1, r-1) + combination(n-1, r);
}