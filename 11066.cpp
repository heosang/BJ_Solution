#include <iostream>
#include <cstdio>​
#include <algorithm>

using namespace std;
int aryK[501]={0,};//각 장의 크기

int main() {
    int T;//testcase개수
    int k;//소설을 구성하는 장의 수
    int j;
    cin>>T;
    for(int i=0;i<T;i++){
        int ans=0;   
        cin >>k;
        for(j=1;j<=k;j++){
            cin>>aryK[j];
        }
        sort(aryK+1,aryK+1+k);
        int numK=k;//합친 장의 수
        while(numK!=1){
            for(j=1;j<=numK>>1;j++){
                aryK[j]=aryK[j<<1]=aryK[j<<1+1];
            }
            if(numK%2==1){
                aryK[j]=aryK[numK];
            }
            numK=j;
        }
        cout<<aryK[1];
    }
	return 0;
}