#include<iostream>
#include<queue>
#include<algorithm>
#include<string>

using namespace std;

deque <string> que;
int FR = 0;//R의 홀짝
string cmd;
void func(string cmd, int num) {
	for (int i = 0; i < cmd.size();i++) {
		if (cmd[i] == 'D') {
			if (que.size() == 0) {
				cout << "error" << endl;
				return;
			}
			if (FR % 2 == 0) {
				que.pop_front();
			}
			else {
				que.pop_back();
			}
		}
		else {
			FR++;
		}
	}
	if (que.size() == 0) {
		cout << "[]";
	}
	else if (que.size() == 1) {
		cout << '[' << que.front() << ']';
		que.pop_front();
	}
	else {
		if (FR % 2 == 0) {
			cout << '[' << que.front();
			que.pop_front();
			while (que.size()) {
				cout << ',' << que.front();
				que.pop_front();
			}
		}
		else {
			cout << '[' << que.back();
			que.pop_back();
			while (que.size()) {
				cout << ',' << que.back();
				que.pop_back();
			}
		}
		cout << ']';
	}
	cout << "\n";
}
int main() {
	int testNum;
	int num;//배열에 들어있는 수의 개수
	char x;
	string temp;
	cin >> testNum;
	while (testNum--) {
		cin >> cmd;
		cin >> num;
		temp.clear();
		while (true) {
			cin >> x;
			if (x != '[' && x != ']' && x != ',') {
				temp += x;
			}
			if (x == ',') {
				que.push_back(temp);
				temp.clear();
			}
			if (x == ']') {
				if (temp.size() != 0) {
					que.push_back(temp);
				}			
				break;
			}
		}
		func(cmd, num);
		cmd.clear();
		FR = 0;
	}
	return 0;
}