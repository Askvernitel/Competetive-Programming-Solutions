#include <bits/stdc++.h>

using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i =0;i<n;i++){
		cin>>a[i];
	}
	int o[n+2];
	memset(o, 0 ,sizeof(o));
	o[a[0]]=1;
	for(int i =1;i<n;i++){
		if(!o[a[i]+1] && !o[a[i]-1]){
			cout << "NO\n";
			return;
		}
		o[a[i]] = 1;
	}
	cout << "YES\n";
}
int main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
