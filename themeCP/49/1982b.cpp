#include <bits/stdc++.h>

using namespace std;
void solve(){
	int x, k,y;
	cin >> x >> y >> k;
	int cur = x;
	int prev = -1;
	while(k > 0 && cur != 1){
		int p = y-cur%y;

		if(p > k){ 
			cur += k;
			break;
		}
		k-=p;
		cur+=p;	
		while(cur!=0 && !(cur%y)){
			cur/=y;
		}
	}
	if(cur == 1){
		cout << cur + k%(y-cur) << '\n';
	}else{ 
		cout << cur << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
