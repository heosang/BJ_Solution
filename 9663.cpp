#pragma warning(disable:4996)
#include <cstdio>​
#include <algorithm>
using namespace std;
bool aryN[16][16]={true,};//false= 
void func(int ,int );

int n;
int ans=0;

int main() {
	scanf("%d", &n);
    for(int i=0;i<n;i++){
        func(i,0);
    }
        
    0;
}
void func(int row,int col){
    if(row>n||col>n) return;
    for(int i=col;i<n;i++){
        for(int k=0;k<n;k++){
            if(aryN[row][k]==false,aryN[k][col]==false){
                return;
            }
        }
        
            }
        }
    }
    return ;
}