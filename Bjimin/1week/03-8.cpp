#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, i, j, k, temp, cnt=0;
    vector<int> numbers;

    cin>>N;
    for(i=0; i<N; i++){
        cin>>temp;
        numbers.push_back(temp);
    }

    sort(numbers.begin(), numbers.end());

    k=0, i=0, j=N-1;

    while(true) {
        if(k==N) {cout<<cnt<<endl; return 0;}

        if(i==j) {
            k++; 
            i=0; j=N-1;
        } else if(numbers[i] + numbers[j] > numbers[k]){
            j--;
        } else if(numbers[i] + numbers[j] < numbers[k]){
            i++;
        } else if(numbers[i] + numbers[j] == numbers[k]){
            if(i!=k && j!=k){
                cnt++;
                k++;
                i=0;
                j=N-1;
            }
            else if(i==k) {
                i++;
            } else if(j==k) {
                j--;
            }
        }
    }
}