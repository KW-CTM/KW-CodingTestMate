#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, i=0, temp, max=0;
	double sum=0;
	cin >> N;
	vector<double> subs;

	for(; i<N; i++){
		cin>>temp;
		subs.push_back(temp);

		if(max < temp){
			max = temp;
		}
	}

	for(i=0; i<N; i++){
		sum += subs.at(i)/max*100;
	}

	printf("%.3f\n", sum/N);

}
