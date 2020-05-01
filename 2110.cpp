#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>

using namespace std;

int n, c;//집의 개수, 공유기의 개수
int temp;
int aryX[200001] = { 0, };//집의 좌표
int ans = 0;
void func() {
	int start=aryX[1], last=aryX[n], mid;
	int tempX=0;//

    int a,b;
    int j;
    if(c==2){
        ans=last-start;
        return ;
    }
    tempX=(last-start)/(c-1);//평균 거리
    if(tempX==1){
        ans=1;
        return;
    }
	int i=1;
	int cnt=1;
    while(i<n){
        for(int j=i+1;j<n;j++){
           	if(aryX[i]+tempX==aryX[j]){
				i=j;
				cnt++;
				break;
			}
			if(aryX[j]<aryX[i]+tempX&&aryX[j+1]>aryX[i]+tempX){
				i=j+1;
				cnt++;
				break;
			}
        }
		if(cnt==c){
			ans=tempX;
			printf("%d",ans);
			break;
		}
		if(j==n&&cnt!=c){
			tempX--;
			i=1;
			cnt=1;
		}
    }



	// start = 1;
	// last = aryX[k];
	// mid = (start + last) / 2;
	// while (start<=last) {
	// 	tempN = 0;
	// 	for (int i = 1;i <= k;i++) {
	// 		tempN += aryN[i] / mid;
	// 	}
	// 	if (tempN < n) {
	// 		last = mid - 1;
	// 		mid = (start + last) / 2;			
	// 	}
	// 	else {
	// 		if (ans < mid) {
	// 			ans = mid;
	// 		}
	// 		start = mid + 1;
	// 		mid = (start + last) / 2;
	// 	}
	// }
	return;
}

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &aryX[i]);
	}
	sort(aryX + 1, aryX + 1 + n);
	func();
	//printf("%d\n", ans);
	return 0;
}