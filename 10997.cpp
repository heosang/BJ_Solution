#include <iostream>
using namespace std;
char ary[450][450];
int main() {
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	char temp;
	int n;
	cin >> n;
	if (n == 1) {
		cout << "*";
		return 0;
	}
	int lengthX = 4 * n - 3;
	int lengthY = 4 * n - 1;
	for (int i = 1;i < lengthX;i++) {// 0행과 0열 제외 배열 space로 초기화
		for (int j = 1;j < lengthY;j++) {
			ary[i][j] = ' ';
		}
	}
	for (int i = 0;i < lengthX;i++) {//0행 *
		ary[0][i] = '*';
	}
	for (int i = 1;i < lengthY;i++) {//0열 *
		ary[i][0] = '*';
	}
	for (int i = 2;i <= lengthX / 2;i += 2) {// 좌상우하 대각선으로 나눠 위쪽부분 *변환
		for (int j = i;j < lengthY - i;j++) {
			ary[i][j] = '*';
			ary[j][i] = '*';
		}
	}
	for (int i = lengthX - 1;i > lengthX / 2;i -= 2) {//나머지부분 *변환
		for (int j = 0;j < i * 2 - lengthX + 1;j++) {
			ary[i + 2][i - j] = '*';
			ary[i + 2 - j][i] = '*';
		}
	}
	for (int i = 0;i < lengthY;i++) {//출력
		for (int j = 0;j < lengthX;j++) {
			if (i == 1) {
				cout << "*";
				break;
			}
			cout << ary[i][j];
		}
		cout << "\n";
	}
	return 0;
}
