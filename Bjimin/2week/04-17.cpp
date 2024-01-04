#include <iostream>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string arr;
    cin>>arr;

    int length = arr.length();
    int max, index;

    for(int i=0; i<length-1; i++) {
        max = arr[i]; index = i;
        for(int j=i+1; j<length; j++){
            if(max < arr[j]){ max = arr[j]; index = j; }
        }

        arr[index] = arr[i];
        arr[i] = max;
    }  

    cout<<arr<<endl;
}