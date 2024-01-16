#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, input, cnt = 0, temp = 0, num1, num2;
    cin>>N;

    vector<int> numberOfBundles;
    priority_queue<int, vector<int>, greater<int>> numbers;

    for(int i=0; i<N; i++) {
        cin>>input;

        numberOfBundles.push_back(input);
    }

    sort(numberOfBundles.begin(), numberOfBundles.end());
    for(int i=0; i<N; i++) {
        numbers.push(numberOfBundles[i]);
    }

    while(numbers.size() != 1) {
        num1 = numbers.top();
        numbers.pop();
        num2 = numbers.top();
        numbers.pop();

        temp = num1 + num2;
        cnt += temp;

        numbers.push(temp);
    }

    cout<<cnt<<endl;
    // queue에 다 넣고
    // 두개씩 빼서 더하고 다시 queue에 넣기
    // 만약에 queue에 하나 남았다면? -> 엥 하나남는일은 마지막만 있음.. ****
    // queue에서 잠시 빼고 저장

    // 다시 queue에서 두개씩 뺴서 더하..기 전에
    // 하나 뺐는데 잠시 저장한 것보다 큰 값이 있다면 (첫번째는 짜피 꺼내야 함 따라서 두번째)
    // 걔는 queue에서 빼지 말고

    // 임시 저장한 걸로 더해서 다시 queue에 넣는 과정
    // 임시 저장한건 0으로 초기화

    // 또 queue가 홀수라서 마지막 하나가 남았다면?
    // 임시 저장한 애가 있다면 걔랑 더해서 queue에 저장
    // 아니면 임시로 저장

    // queue에 남은게 1개일 때까지 반복

    // -> 우선순위 큐 사용하기
    // queue에 다 넣고, 작은 순서대로 빼서 사용
    // 두개 빼서 더하고 다시 queue에 넣기

    // 만약 queue에 하나가 남았다면 이거 출력
}