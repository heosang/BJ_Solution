#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 1987654321
using namespace std;
void floyd();
int ary[101][101];
int n, m;
int a, b, c;
int main() {
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		cin >> a >> b >> c;
		if (!ary[a][b]) {
			ary[a][b] = c;
		}
		else {
			ary[a][b] = min(ary[a][b], c);
		}

	}
	floyd();
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			cout << ary[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
void floyd(){
	for (int via = 1; via <= n; via++){
		for (int from = 1; from <= n; from++){
			if (ary[from][via] == 0)
				continue;
			for (int to = 1; to <= n; to++){
				if (ary[via][to] == 0 || from == to)
					continue;
				if (ary[from][to] == 0 || ary[from][to] > ary[from][via] + ary[via][to])
					ary[from][to] = ary[from][via] + ary[via][to];
			}
		}
	}
}
