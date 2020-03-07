#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
#include<string>
#include<iostream>
using namespace std;
string str;
int n;
int aryN[51] = { 0, };
char oper[51] = { 0 };

int main() {
	int i = 0;
	int j = 0;
	int t;
	cin >> str;
	for (int i = 0;i < str.length();i++) {
		if (str[i] != '-' && str[i] != '+') {
			aryN[j] = aryN[j] * 10 + str[i]-48;
		}
		else {
			oper[j] = str[i];
			j++;
		}
	}
	int temp = aryN[0];
	for (t = 0;t < j;t++) {
		if (oper[t] == '+') {
			temp += aryN[t+1];
		}
		else {
			for (int i = t;i <= j;i++) {
				temp -= aryN[i+1];
			}
			break;
		}
	}
	printf("%d", temp);
	return 0;
}
