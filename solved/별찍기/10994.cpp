#include <iostream>
using namespace std;
char ary[400][400];
int main() {
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	char temp;
	int n;
	cin >> n;
	int length= 4 * n - 3;
	for (int i = 0;i < length;i++) {
		for (int j = 0;j < length;j++) {
            ary[i][j]=' ';
		}
	}
    for (int i = 0;i < length;i++) {
        if(i%2==0){
            if(i<=length/2){
                for(int j=i;j<length-i;j++){
                    ary[i][j]='*';
                    ary[j][i]='*';
                }
            }
            else{
                 for(int j=length-i;j<=i;j++){
                    ary[i][j]='*';
                    ary[j][i]='*';
                }
            }
        }
	}
    for (int i = 0;i < length;i++) {
		for (int j = 0;j < length;j++) {
            cout<<ary[i][j];
		}
        cout<<"\n";
	}
	return 0;
}
