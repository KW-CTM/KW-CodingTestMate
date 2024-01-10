#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j, temp, cnt=0;
    vector<int> numbers;

    cin>>N;
    for(i=0; i<N; i++){
        cin>>temp;
        numbers.push_back(temp);
    }

    for(i=0; i<N; i++){
        for(j=0; j<N-i-1; j++){
            if(numbers[j] > numbers[j+1]){
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    for(i=0; i<N; i++){
        cout<<numbers[i]<<endl;
    }
}