#include <iostream>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	char ary[100];
	cin >> n;
	for (int i = n;i > 0;i--) {
		for (int j = 1;j <= i;j++) {
			cout << '*';
		}
		cout << endl;
	}
	return 0;
}
