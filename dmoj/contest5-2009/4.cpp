#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
int  u;
map<vector<pair<vector<int>, int>>, int> dp;
int rec(vector<int> cur, int tot, int depth){ 
	if(cur.size() == 0){
		return tot;
	}
	int ans = INT_MAX;
	int n = cur.size();
	int prev = -1;
	vector<pair<vector<int>,int>> c, t;
	int cost = 0;
	vector<int> k;
	for(int i =0;i<n;i++){
		if(prev == cur[i] || prev == -1){
			k.push_back(cur[i]);
			cost++;
		}else {
			c.push_back({k,cost});
			k={};
			k.push_back(cur[i]);
			cost=1;
		}
		prev = cur[i];
	}
	if(k.size() != 0){
		c.push_back({k, cost});
	}

	int m =c.size();	
	for(int i =0;i<m;i++){
		t = c;
		int cst = max(0, u-t[i].S);
		t.erase(t.begin()+i);
		vector<int> nxt;
		for(int j =0;j<t.size();j++){
			for(int x:t[j].F){
				nxt.push_back(x);
			}
		}
		if(dp[t]){

			ans = min(dp[t],ans);
		}else{
			dp[t]= rec(nxt,tot+cst, depth+1);
			ans = min(dp[t],ans);
		}
	}
	return ans;
}
int main(){
	int n;
	cin >> n >> u;
	vector<int> a(n);
	for(int i =0;i<n;i++) cin >> a[i];	
	cout << rec(a, 0,0);


}
