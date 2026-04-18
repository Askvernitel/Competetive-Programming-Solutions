#include <bits/stdc++.h>

using namespace std;

vector<int> children[300001];
int mx = 0, f = 0, s =0;
int lastmx = 0;
int p = 1;
map<int,int> maxs;
void dfs(int cur, int par, int cnt){ 
	if(children[cur].size() == 1){
		if(cnt >=mx){
			if(cnt == mx) p = 0;
			lastmx=mx;
			mx = cnt;
			f = cur; s = par;
		}
	}

	for(int x:children[cur]){
		if(x != par){
			dfs(x, cur, cnt+1);
		}
	}
}
int main(){
	int n;
	cin >> n;
	for(int i =0;i<n-1;i++){
		int par, child;
		cin >> par >> child;
		children[par].push_back(child);
		children[child].push_back(par);
	}
	dfs(1, 0, 0 );
	mx -= 1;
	cout << mx + lastmx - p << '\n';	
	cout << s << " " << f << " \n";
	cout << f << " " << 1 << " \n";
}

