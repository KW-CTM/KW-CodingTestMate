#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> material_numbers;

	int N, M, i, j, input, cnt = 0;
	cin>>N>>M;

	for(i=0; i<N; i++) {
		cin>>input;
		material_numbers.push_back(input);
	}

	sort(material_numbers.begin(), material_numbers.end());

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			if((material_numbers.at(i) + material_numbers.at(j)) == M) {
				cnt++;
			}
			else if ((material_numbers.at(i) + material_numbers.at(j)) > M) {
				break;
			}
		}
	}

	printf("%d\n", cnt/2);
}