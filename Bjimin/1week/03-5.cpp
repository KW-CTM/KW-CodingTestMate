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

	for(i=0; i<N+1; i++){
		for(j=0; j<i; j++){
			if((sums.at(i)-sums.at(j))%M == 0){
				count++;
			}
		}
	}

	cout<<count<<endl;	
}