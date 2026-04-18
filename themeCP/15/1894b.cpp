#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++) cin >> a[i];
	int cnt[101];
	memset(cnt, 0,sizeof(cnt));
	for(int i =0;i<n;i++){
		cnt[a[i]]++;
	}
	int pos = 0;
	for(int i = 0;i<101;i++){
		if(cnt[i] > 1){
			pos++; 
		}
	}
	if(pos < 2){ 
		cout << -1 << '\n';
		return;
	}
	int cur = 2;
	int c = 1;
	int ans[n];
	for(int i =0;i<101;i++){
		if(cnt[i] == 0) continue;
		int t = cur;	
		for(int j = 0;j<n;j++){
			if(a[j] != i) continue;
			ans[j] = t;
			if(t == 2 && c) t++;
			else if(c) t--;
			if(t == 2 && !c) t--;
			else if(!c) t++;
		}
		if(cnt[i]>1){ 
			c = !c;
			if(cur ==2) cur =1;
			else cur = 2;
		}
	}

	for(int i =0;i<n;i++){
		cout << ans[i] << " ";
	}
	cout << '\n';

}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
