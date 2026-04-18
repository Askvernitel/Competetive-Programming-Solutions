#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	int cnt[101];
	memset(cnt,0,sizeof(cnt));
	int p = 0;
	for(int i = 0;i<n;i++){
		if(cnt[a[i]] == 0){ 
			p++;
		}
		cnt[a[i]]=1;
	}
	if(n == 1){
		cout << 1 << '\n';
		return;
	}
	if( n== 2){
		cout << 2 << '\n';
		return;
	}
	if(p >= 3){ 
		cout << n << '\n';
		return;
	}else{
		cout << n/2 + 1 << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
