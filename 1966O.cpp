#include<iostream>
#include<queue>

using namespace std;

queue <int> que[2], tempQue[2];
int ary[10]={0, };//각 중요도 개수
int func(int m, int mImpt) {
	int temp;
    int count=0;//프린트한 문서 수
    int size;
    size=que[1].size();
	while (true) {
            for(int k=0;k<size;k++){
                if(que[1].front()>mImpt+1){
                    que[0].pop();
                    que[1].pop();
                    count++;
                }
                else{
                    temp=que[0].front();
                    que[0].pop();
                    que[0].push(temp);
                    temp=que[1].front();
                    que[1].pop();
                    que[1].push(temp);
                }
            }
            if(que[1].front()==mImpt+1){
                que[0].pop();
                que[1].pop();
                count++;
                ary[mImpt+1]--;
            }
            else if(que[1].front()==mImpt&&ary[mImpt+1]==0){
                if(que[0].front()=m){
                    return ++count;
                }
                else{
                    que[0].pop();
                    que[1].pop();
                    count++;
                    ary[mImpt]--;
                }    
            }
            else{
                temp=que[0].front();
                que[0].pop();
                que[0].push(temp);
                temp=que[1].front();
                que[1].pop();
                que[1].push(temp);
            }
	}
}
int main() {
    int testNum;//testcase 수
	int n;//문서의 수
    int m;//문서의 위치
    int impt;//문서의 중요도
    int mImpt;//선택한 문서의 중요도
    int ans;
    cin>> testNum;
    for(int i=0;i<testNum;i++){
        cin >> n,m;
	    for (int j = 0;i < n;i++) {
            que[0].push(j);
            cin>>impt;
            ary[impt]++;
	    	que[1].push(impt);
            if(j=m) mImpt=impt;
	    }
	    ans=func(m,mImpt);
        cout<< ans<<endl;
    }
	return 0;
}