#include <bits/stdc++.h>

using namespace std;
vector<int> children[200001];
int paths[200001];
int c = 0;
map<int,vector<int>> m;	
void dfs(int cur, int color){ 
	paths[cur]=color;
	m[color].push_back(cur);
	if(children[cur].size() == 0 || (children[cur].size() == 1 && children[cur][0]==cur)){ 
		c++;
		return;
	}
	for(int child:children[cur]){ 
		if(cur == child) continue;
		dfs(child, c);
	}
}
void solve(){
	int n;
	cin >> n;
	int p[n];
	int root=0;
	for(int i =0;i<n;i++){
		cin >> p[i];
		children[--p[i]].push_back(i);
		if(p[i] == i) root = i;
	}
	dfs(root, c);
	cout << c << '\n';
	for(auto &[color,vec]:m){
		cout << vec.size() << '\n';
		for(int x:vec){
			cout << x+1 << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	for(int i =0;i<n;i++) paths[i]=0;
	for(int i=0;i<n;i++) children[i]={};
	m={};
	c=0;
}
int main(){
	int tc;
	cin >> tc;

	while(tc--) solve();
}
