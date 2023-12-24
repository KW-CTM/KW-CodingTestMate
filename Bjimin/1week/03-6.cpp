#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int i, j, temp, cnt = 0;
	for(i=N; i>0; i--) {
		temp = N;
		for(j=i; j>0; j--){
			temp -= j;
			if(temp < 0) {
				break;
			}
			else if(temp == 0){
				cnt++;
				break;
			}
		}
	}

	cout<<cnt<<endl;
}