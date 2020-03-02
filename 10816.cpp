#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m, temp;
unordered_map <int, int> mapN;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		mapN[temp]++;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		printf("%d ", mapN[temp]);
	}
	return 0;
}