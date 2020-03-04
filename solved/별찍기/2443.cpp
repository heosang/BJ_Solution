#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	char ary[200];
	cin >> n;
	int mid = n - 1;
	for (int i = 0;i < 2*n;i++) {
		ary[i] = '*';
	}
	for (int i = n-1;i >= 0;i--) {		
		for (int j = 0;j < n+i;j++) {
			cout << ary[j];
		}
		ary[mid - i] = ' ';
		ary[mid + i] = ' ';
		cout << "\n";
	}
	return 0;
}
