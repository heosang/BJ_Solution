#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	char ary[200];
	cin >> n;
	int mid = n - 1;
	for (int i = 0;i < 2 * n;i++) {
		ary[i] = ' ';
	}
	for (int i = 0;i < n;i++) {
		ary[mid - i] = '*';
		ary[mid + i] = '*';
		for (int j = 0;j < n + i;j++) {
			cout << ary[j];
		}
		cout << "\n";
	}
	for (int i = n - 1;i > 0;i--) {
		ary[mid - i] = ' ';
		ary[mid + i] = ' ';
		for (int j = 0;j < n + i;j++) {
			cout << ary[j];
		}
		
		cout << "\n";
	}
	return 0;
}
