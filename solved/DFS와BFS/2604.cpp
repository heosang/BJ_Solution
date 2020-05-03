#include <iostream>
#include <stack>
int cnt=0,comNum;
using namespace std;
stack<int>stk;
bool com[101][101];
bool visit[101];
void func(int);
int main() {
	int pairNum;
	int comA, comB;
	cin >> comNum;
	cin >> pairNum;
	for (int i = 0;i < pairNum;i++) {
		cin >> comA >> comB;
		com[comA][comB] = 1;
		com[comB][comA] = 1;
	}
	func(1);
	cout << cnt;
	return 0;
}
void func(int n) {
	stk.push(n);
	visit[n] = 1;
	for (int i = 1;i <= comNum;i++) {
		if (com[n][i] == 1 && !visit[i]) {
			cnt++;
			func(i);
		}
	}
	stk.pop();
	return;
}