#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	char ary[100];
	cin >> n;
	for (int i = 0;i < n;i++) {
		ary[i] = '*';
	}
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cout << ary[j];
		}
		ary[i] = ' ';
		cout << "\n";
	}
	return 0;
}
