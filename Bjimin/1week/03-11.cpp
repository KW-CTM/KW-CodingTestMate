#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<char> result;
    stack<int> numStack;

	int n, input, num = 1;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>input;
        
        while(true) {
            if(numStack.empty()) {
                numStack.push(num++);
                result.push_back('+');
            } else {
                if(numStack.top() != input) {
                    if(numStack.top() > input) {
                        printf("NO\n");
                        return 0;
                    }
                    numStack.push(num++);
                    result.push_back('+');
                } else {
                    numStack.pop();
                    result.push_back('-');
                    break;
                }
            }
        }
    }

    for(int i=0; i<result.size(); i++) {
        printf("%c\n", result[i]);
    }

}