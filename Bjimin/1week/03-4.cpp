#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, i, j, temp;
	cin >> N >> M;

	int** table = new int*[N+1];
	for(i=0; i<N+1; i++){
		table[i] = new int[N+1];
		for(j=0; j<N+1; j++){
			table[i][j] = 0;
		}
	}

	for(i=1; i<N+1; i++){
		for(j=1; j<N+1; j++){
			cin >> temp;
			table[i][j] = table[i-1][j] + table[i][j-1] + temp - table[i-1][j-1];
		}
	}


	int x1, y1, x2, y2;

	for(i=0; i<M; i++){
		cin>>x1>>y1>>x2>>y2;
		int result = (table[x2][y2] - table[x2][y1-1] - table[x1-1][y2] + table[x1-1][y1-1]);
		cout<<result<<"\n";
	}

	for(i=0; i<N+1; i++){
		delete[] table[i];
	}
	delete[] table;
	
}