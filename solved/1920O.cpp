#include<iostream>
#include<algorithm>
using namespace std;
int aryN[100000], aryM[100000];
int n, m;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int x = 0;
	bool ans = false;
	int start, last, mid;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> aryN[i];
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> aryM[i];
	}
	sort(aryN, aryN + n);
	while (x < m) {
		ans = false;
		start = 0;
		last = n - 1;
		while (start <= last) {
			mid = (start + last) / 2;
			if (aryN[mid] == aryM[x]) {
				ans = true;
				break;
			}
			else if (aryN[mid] < aryM[x]) {
				start = mid + 1;
			}
			else {
				last = mid - 1;
			}
		}
		if (ans) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
		x++;
	}
	return 0;
}