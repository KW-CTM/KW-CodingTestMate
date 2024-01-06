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

		remains.push_back(temp + remains[i-1]);
	}

	for(i=1; i<=N; i++) {
		remains[i] = remains[i]%M;
		if(remains[i] == 0) { count++; }
		arr[remains[i]]++;
	}

	for(i=0; i<M; i++){
		//나머지값들 등장한 횟수
		//r이 2로 고정된 조합 계산
		/*
		nCr = n! / ((n-r)! r!)
		r이 2로 고정되면 n * n-1 / 2
		*/

		count += arr[i] * (arr[i]-1) / 2;
	}

	cout<<count<<endl;
	delete[] arr;
}