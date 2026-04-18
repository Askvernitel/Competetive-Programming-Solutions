#include <bits/stdc++.h>

using namespace std;
int sum_string(string& s, int ind, int am){
	int sum = 0;
	for(int i =ind;i<ind+am;i++){
		sum+=s[i]-'0';
	}
	return sum;
}
//sum, size pref
void rec(map<pair<pair<int,int>, int>, int>& t, int sum, int depth, int n, set<pair<int,int>> vis){ 
	if(depth == 3){
		return;
	}
	if(vis.find({sum, depth}) == vis.end()){t[{{sum, n+depth}, depth}]++;}
	vis.insert({sum, depth});
	for(int i =1;i<=9;i++){
		rec(t, sum+i, depth+1, n, vis);
	}
}
int main(){
	int n;
	cin >> n;
	int b[n];
	string a[n];
	map<pair<pair<int,int>, int>, int> t;
	for(int i =0;i<n;i++){
		cin >> a[i];
		b[i] = sum_string(a[i], 0, a[i].size());
	}
		
	int ans = 0;
	for(int i =0;i<n;i++){
		set<pair<int,int>> vis = {}; 
		int sum = b[i];
		int sz = a[i].size();
		for(int j= 0;j<sz;j++){
			int s = sum_string(a[i], j, sz-j);
			ans+=t[{{s, sz},j}];
		}
		rec(t,sum,0,sz,vis);
	}
	t = {};
	for(int i =n-1;i>=0;i--){
		set<pair<int,int>> vis = {}; 
		int sum = b[i];
		int sz = a[i].size();
		for(int j= 0;j<sz;j++){
			int s = sum_string(a[i], j, sz-j);
			cout << s << '\n';
			ans+=t[{{s, sz},j}];
		}
		rec(t,sum,0,sz,vis);
	}
	cout << ans << '\n';

}
