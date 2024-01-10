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

/*
4 입력
스택 empty
push 1

not empty
top != 4
push 2

not empty
top != 4
push 3

not empty
top != 4
push 4

not empty
top == 4
pop

3 입력
스택 not empty
top == 3
pop

6 입력
스택 not empty
top != 6
push 5

not empty
top != 6
push 6

not empty
top == 6
pop

8 입력
...


예제 2
empty
push 1

not empty
top == 1
pop

empty
push 2

not empty
top == 2
pop

empty
push 3

not empty
top != 5
push 4

not empty
top != 5
push 5

not empty
top == 5
pop

not empty
top(4) != 3 (top > input) -> NO

*/