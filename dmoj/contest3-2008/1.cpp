#include <bits/stdc++.h>

using namespace std;
void solve(){
	int maxv = 0, winner=0;
	for(int i =0;i<5;i++){
		int cur = 0;
		for(int j =0;j<4;j++){
			int num;
			cin >> num;
			cur +=num;
		}

		if(cur > maxv){
			maxv = cur;
			winner = i+1;

		}
	}
	cout << winner << " " << maxv;
}
int main(){
	solve();
}
