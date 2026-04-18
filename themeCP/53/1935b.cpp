#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	set<int> z;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i] == 0) z.insert(i);
	}
	int p1[n+1], p2[n+1];
	memset(p1,0,sizeof(p1));
	memset(p2,0,sizeof(p2));
	int pref[n+1];
	pref[0]=-1;
	for(int i =1;i<=n;i++){
		p1[a[i-1]]=1;
		int cur=pref[i-1];
		while(p1[cur+1] != 0) cur++;
		pref[i] = cur;
	}
	int suf[n+1];
	suf[n]=-1;
	for(int i =n-1;i>=0;i--){
		p2[a[i]]=1;
		int cur=suf[i+1];
		while(p2[cur+1] != 0) cur++;
		suf[i] = cur;
	}
	if(z.size() == 0){
		cout << 2 << '\n';
		cout << 1 << ' '<< 1 << '\n';
		cout << 2 << ' '<< n << '\n';
	}else{
		for(int i =0;i<n;i++){
			if(pref[i] == suf[i]){
				cout << 2 << '\n';
				cout << 1 << " " << i << '\n';
				cout << i+1 << " " << n << '\n';
				return;
			}
		}
		cout << -1 << '\n';
		return;
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
