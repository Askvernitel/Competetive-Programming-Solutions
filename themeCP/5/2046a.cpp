#include <bits/stdc++.h>
#define F first 
#define S second
#define int long long
using namespace std;

int n;
int a[200001], b[200001];
int bsum = 0;

int rec(int cur, int sum, int sum1, int mx, set<int>& ch, map<pair<int,int>, int>& dp){ 
	if(cur == n){ 
		return sum;
	}
	int maxv = INT_MIN;
	for(int i =0;i<n;i++){
		if(ch.find(i)!=ch.end()) continue;
		if(dp[{i, mx}] != 0){
			maxv = max(dp[{i,mx}], maxv);
			continue;
		}
		ch.insert(i);
		maxv = max(rec(cur+1, sum+a[i], sum1+b[i], max(b[i],mx), ch,dp), maxv);
		ch.erase(i);
	}
	return max(maxv, bsum-sum1+a[cur]);
}
void solve(){
	cin >> n;
	for(int i =0;i<n;i++) cin >> a[i];
	for(int i =0;i<n;i++) cin >> b[i];
	pair<int, int> c[n];
	for(int i = 0;i<n;i++){
		bsum+=b[i];
		c[i] = {a[i], b[i]};
	}
	set<int> ch={};
	map<pair<int,int>, int> dp={};
	sort(c, c+n, greater<pair<int,int>>());
	cout << rec(0,0,0,INT_MIN,ch,dp) << '\n';
	bsum=0;
}
signed main(){
	int tc;
	cin >> tc;
	while(tc--) solve();
}
