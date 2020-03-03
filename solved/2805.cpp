#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>

using namespace std;
int n,m;
int aryN[1000001]={0,};

int ans=0;;

void func() {
    int start=0;
    int last=aryN[n];
    int mid=(start+last)/2;
    int tempN;//임시 합
   while (start<=last) {
		tempN = 0;
		for (int i = 1;i <= n;i++) {
            if(aryN[i]-mid<=0){;}
            else{tempN+=aryN[i]-mid;}
		}
		if (tempN < m) {
			last = mid - 1;
			mid = (start + last) / 2;			
		}
		else {
			if (ans < mid) {
				ans = mid;
			}
			start = mid + 1;
			mid = (start + last) / 2;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryN[i]);
	}
	sort(aryN + 1, aryN + 1 + n);
	func();
	printf("%d\n", ans);
	return 0;
}