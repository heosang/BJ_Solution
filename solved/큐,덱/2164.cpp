#include<iostream>
#include<queue>

using namespace std;

queue <int> que;
void func() {
	int temp;
	while (que.size() != 1) {
		que.pop();
		temp = que.front();
		que.pop();
		que.push(temp);
	}
	return;
}
int main() {
	int n;
	std::cin >> n;
	for (int i = 1;i <= n;i++) {
		que.push(i);
	}
	func();
	std::cout << que.front();
	return 0;
}