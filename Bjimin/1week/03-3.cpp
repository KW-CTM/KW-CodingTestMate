#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, M, i, l, h, j, temp, sum=0;
	cin >> N >> M;
	vector<int> sums;
	sums.push_back(0);

	for(i=0; i<N; i++) {
		cin>>temp;

		sums.push_back(sums.at(i) + temp);
	}

	for(i=0; i<M; i++) {
		sum = 0;
		cin>>l>>h;
		
		sum = sums.at(h) - sums.at(l-1);

		cout<<sum<<endl;
	}

}