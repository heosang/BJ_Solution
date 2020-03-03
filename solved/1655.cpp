#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <int> vec;
int main(){
    cin.tie(0);
    cout.tie(0);
	cin.sync_with_stdio(false);
    int n;
    int temp;
    cin >>n;
    for (int i = 1;i < n;i++) {
		cin >> temp;
        vec.push_back(temp);
        sort(vec.begin,vec.end);
		if (vec.size()%2==0) {
			cout<<vec[vec.size()/2-1];
			}
		else{
            cout<<vec[vec.size()/2];
        }

	}
    return 0;
}