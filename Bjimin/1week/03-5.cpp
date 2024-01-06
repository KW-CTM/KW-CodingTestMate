#include <iostream>
#include <vector>
using namespace std;

int combination(int n, int r);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, temp;
	long count=0;
	cin>>N>>M;

	//***long으로 안했더니 틀렸음*** 

	vector<long> remains(N+1, 0); //이건 변경안해도 상관없었음
	vector<long> arr(M, 0); //자동으로 0으로 초기화

	for(i=1; i<=N; i++){
		cin>>temp;

		remains[i] = (temp + remains[i-1]);
	}

	for(i=1; i<=N; i++) {
		temp = remains[i] % M;
		//remains[i] = temp; 그냥 넣어도 괜찮음 but 불필요
		if(temp == 0) { count++; }
		arr[temp]++;
	}

	for(i=0; i<M; i++){
		//나머지값들 등장한 횟수
		//r이 2로 고정된 조합 계산
		/*
		nCr = n! / ((n-r)! r!)
		r이 2로 고정되면 n * n-1 / 2
		*/

		//arr[i]가 1개이거나 0개일 경우는? -> 틀릴 것이라고 예상

		if(arr[i] > 1) 
			count += (arr[i] * (arr[i]-1)) / 2; //무조건 짝수일 것이므로 2로 나누는 것은 상관없음
	}

	cout<<count<<endl;
}