#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
void pick(int);
void func();
int n;
int top = -1000000001;
int bot = 1000000001;
int temp = 0;
int aryO[4] = { 0, };//연산자 갯수 저장배열
int aryN[12] = { 0, };
int operOrder[11] = { 0 };

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryN[i]);
	}
	for (int i = 0;i < 4;i++) {
		scanf("%d", &aryO[i]);
	}
	pick(1);
	printf("%d\n", top);
	printf("%d", bot);
	return 0;
}
void pick(int cnt) {//cnt:연산횟수
	if (cnt == n) {
		func();
		return;
	}
	for (int i = 0;i < 4;i++) {
		for (int j = aryO[i];j > 0;j--) {
			aryO[i]--;
			operOrder[cnt] = i;
			pick(cnt + 1);
			aryO[i]++;
		}
	}
	return;
}
void func() {
	int temp;
	if (operOrder[1] == 0) { temp = aryN[1] + aryN[2]; }
	else if (operOrder[1] == 1) { temp = aryN[1] - aryN[2]; }
	else if (operOrder[1] == 2) { temp = aryN[1] * aryN[2]; }
	else { temp = aryN[1] / aryN[2]; }
	for (int i = 2;i < n;i++) {
		if (operOrder[i] == 0) { temp += aryN[i + 1]; }
		else if (operOrder[i] == 1) { temp -= aryN[i + 1]; }
		else if (operOrder[i] == 2) { temp *= aryN[i + 1]; }
		else { temp /= aryN[i + 1]; }
	}
	bot = min(bot, temp);
	top = max(top, temp);
}