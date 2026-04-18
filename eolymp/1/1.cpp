#include <bits/stdc++.h>
#define F first
#define S second
#define int long long
using namespace std;
bool comp(pair<int,int> a, pair<int,int> b){ 
	if(a.second < b.second) return true;
	return false;
}
signed main(){
	int n;
	cin >> n;
	int x[n], y[n];
	for(int i = 0;i<n;i++){
		cin >> x[i];
	}
	for(int i=0;i<n;i++){
		cin >> y[i];
	}
	int ans = 0;
	int dists[n];
	for(int i =0;i<n;i++){
		dists[i]=(x[i]*x[i]) + (y[i]*y[i]);
	}
	sort(dists, dists+n);
	int prev = 0;
	for(int i =0;i<n;i++){
		ans += dists[i] -prev;
		prev=dists[i];
	}
	cout << ans*4<<'\n';

}
