#include <bits/stdc++.h>

using namespace std;
void solve(){
	int l, r, x, a, b;
	cin >> l >> r >> x;
	cin >> a >> b;
	
	int k = r-(a+x);
	int p = (a-x-l);
	if(a == b){
		cout << 0;
	}
	else if(a+x > r && a-x <l){
		cout << -1;
	}
	else if((a+x <= r && a+x <= b) || (a-x >= l && a-x >= b)){ 
		cout << 1;
	}else if((a+x <= r && r-b >= x) || (a-x >= l && b-l >= x)){ 
		cout << 2;
	}else if((a-x >= l && r-b >=x) || (a+x <= r && b-l >= x )){
		cout << 3;
	}else{
		cout << -1;
	}

	cout << '\n';
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
