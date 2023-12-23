#include <iostream>
using namespace std;

int main() {

	int num, sum=0, i=0;
	string numbers;
	cin>>num;
	cin>>numbers;

	for(; i<num; i++){
		sum += numbers[i]-48;
	}

	cout<<sum<<endl;
}
