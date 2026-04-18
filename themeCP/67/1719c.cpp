#include <bits/stdc++.h>


using namespace std;
void solve(){
	int n, q;
	cin >> n >> q;
	int a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}


	int p[n];

	for(int i =0;i<n;i++){
		p[a[i]-1]=i;
	}

	int suf[n+1];
	suf[n]=n;
	for(int i=n-1;i>=0;i--){
		suf[i] = min(suf[i+1], p[i]);
	}
	int ans[n];
	int cof[n];
	memset(cof,0,sizeof(cof));
	memset(ans,0,sizeof(ans));
	for(int i =0;i<n;i++){
		if(i < suf[a[i]]){
			ans[i]+=max(0,suf[a[i]]-i-1);
		}
	}
	cof[0]=a[0];
	for(int i = 1;i<n;i++){
		cof[i] = max(cof[i-1], a[i]);
	}
	while(q--){
		int t, k;
		cin >> t >> k;
		k = max(k-max(t-2,0),0);
		if(suf[a[t-1]] == n){ 
			cout << k << '\n';
			continue;
		}
		int out = 0;
		if(t!=1 && cof[t-2] < a[t-1]){
			out = max(0,min(k,ans[t-1]+1));
		}else{
			out = max(0,min(k,ans[t-1]));
		}
		cout << out << '\n';
	}
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
