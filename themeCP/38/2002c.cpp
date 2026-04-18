#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
int calc_dist(int xs, int ys, int xt, int yt){ 
	int dist = (abs(yt-ys)*abs(yt-ys)) + (abs(xt-xs)*abs(xt-xs));
	return dist;	
}

void solve(){
	int n;
	cin >> n;
	pair<int,int> coords[n];
	for(int i =0;i<n;i++){
		cin >> coords[i].F >> coords[i].S;
	}

	double xs, ys, xt, yt;
	cin >> xs >> ys >> xt >> yt;	
	int dist = calc_dist(xs, ys, xt, yt);
	bool pos = 1;	
	for(int i =0;i<n;i++){
		if(calc_dist(xt,yt, coords[i].F, coords[i].S) <= dist){
			pos=0;
			break;
		}
	}
	cout << ((pos)?"YES":"NO") << '\n';
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
