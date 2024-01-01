#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> sums;
	sums.push_back(0);

	int N, M, i, j, temp, count=0;
	cin>>N>>M;

	for(i=0; i<N; i++){
		cin>>temp;
		sums.push_back(sums.at(i-1) + temp);
	}


	cout<<count<<endl;	
}