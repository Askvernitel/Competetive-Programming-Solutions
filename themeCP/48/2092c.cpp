#include <bits/stdc++.h>
#define int long long
using namespace std;
void solve(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}

	int cnte = 0, cnto=0;
	int sume = 0, sumo=0;
	for(int i = 0;i<n;i++){
		if(a[i]%2){
			cnto++;
			sumo+=a[i];
		}
		else {
			sume+=a[i];
			cnte++;
		}
	}
	int maxv = 0;
	for(int i = 0;i<n;i++){
		maxv = max(a[i], maxv);
	}
	if(maxv%2){
		cnto--;
		sumo-=maxv;
	}else{
		cnte--;
		sume-=maxv;
	}

	if(maxv%2 && !cnte){
		cout << maxv << '\n';
		return;
	}
	if(!(maxv%2) && !cnto){
		cout << maxv << '\n';
		return;
	}

	if(maxv%2){
		if(cnto == 0){
			cout << maxv + sume << '\n';
			return;
		}
		cout << maxv + (sume-1) + (sumo-(cnto-1)) << '\n';
	}else{
		if(cnte == 0){ 
			cout << maxv + (sumo-(cnto-1)) << '\n';
			return;
		}
		cout << maxv + sume + (sumo-(cnto-1)) << '\n';
	}
}
signed main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
